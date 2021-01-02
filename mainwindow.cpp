#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(AlgoSorting* algo, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , algo_(algo)
{
    ui->setupUi(this);

    // Setup combobox algo choice
    ui->comboBoxAlgoChoice->addItem("AlgoSortingInsertion");
    ui->comboBoxAlgoChoice->addItem("AlgoSortingSelection");
    ui->comboBoxAlgoChoice->addItem("AlgoSortingBubble");
    ui->comboBoxAlgoChoice->addItem("AlgoSortingMerge");
    ui->comboBoxAlgoChoice->addItem("AlgoSortingHeap");
    ui->comboBoxAlgoChoice->addItem("AlgoSortingQuick");
    ui->comboBoxAlgoChoice->setCurrentIndex(0);


    // Connect events
    QObject::connect(ui->btnGenerateRandomDatas, &QPushButton::clicked,
                    this, &MainWindow::GenerateDatas);

    QObject::connect(ui->btnLaunchAlgo, &QPushButton::clicked,
                     this, &MainWindow::LaunchAlgorithm);

}

void MainWindow::GenerateDatas()
{
    if(algo_->GetSolvingIsRunning())
        return;

    const auto nbValues { ui->spinNbValues->value() };
    const auto minValue { ui->spinMinValue->value() };
    const auto maxValue { ui->spinMaxValue->value() };

    algo_->GenerateRandomValues(nbValues,
                                  minValue,
                                  maxValue);

    //
    UpdateView(algo_->GetValues(), minValue, maxValue);

}


void MainWindow::LaunchAlgorithm()
{
    if(algo_->GetSolvingIsRunning())
        return;

    if(algo_->GetValues().size() > 0)
    {
        auto values = algo_->GetValues();
        delete algo_;

        switch(ui->comboBoxAlgoChoice->currentIndex())
        {
            case 0 :
                algo_ = new AlgoSortingInsertion();
                break;
            case 1 :
                algo_ = new AlgoSortingSelection();
                break;
            case 2 :
                algo_ = new AlgoSortingBubble();
                break;
            case 3 :
                algo_ = new AlgoSortingMerge();
                break;
            case 4 :
                algo_ = new AlgoSortingHeap();
                break;
            case 5 :
                algo_ = new AlgoSortingQuick();
                break;
            default:
                return;
                break;
        }

        algo_->SetValues(values);


        QObject::connect(algo_, &AlgoSorting::insertValueGUI,
                         this, &MainWindow::InsertValueGUIHandler);

        QObject::connect(algo_, &AlgoSorting::SolvingIsRunningEvent,
                         this, &MainWindow::SolvingIsRunningHandler);

        QObject::connect(algo_, &AlgoSorting::refreshAllGUI,
                         this, &MainWindow::RefreshAllGUIHandler);

        algo_->start();
    }
}

void MainWindow::UpdateView(std::vector<std::shared_ptr<BarValueDouble>> values, double minVal, double maxVal)
{
    // Remove old view
    QLayoutItem* item;
    while((item = ui->layoutBarGraph->takeAt(0)) != NULL)
        delete item->widget();

    buttons_.clear();

    // Create initial bargraph
    auto layoutHeight { ui->graphContainer->height() };

    for(auto & val : values)
    {
        BarGraphButton* newBtn { new BarGraphButton(val) };

        if(val->Done())
            newBtn->DoneChanged(true);

        if(val->Selected())
            newBtn->SelectedChanged(true);

        if(val->Compared())
            newBtn->ComparedChanged(true);

        double calculatedHeight { (val->Data() / (maxVal - minVal)) * layoutHeight };
        if(calculatedHeight < 0)
            calculatedHeight = -calculatedHeight;

        newBtn->setMinimumHeight(calculatedHeight);

        buttons_.push_back(newBtn);
        ui->layoutBarGraph->addWidget(newBtn);
    }
}

void MainWindow::InsertValueGUIHandler(BarValueDouble* from, int index)
{
    // insert
    auto fromIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&from](BarGraphButton* x){ return &(*x->Val()) == from ;});

    if(fromIteWidget != buttons_.end())
        ui->layoutBarGraph->insertWidget(index, *fromIteWidget);
}


void MainWindow::RefreshAllGUIHandler()
{
    const auto minValue { ui->spinMinValue->value() };
    const auto maxValue { ui->spinMaxValue->value() };

    auto vals { algo_->GetValues()};

    UpdateView(vals, minValue, maxValue);
}

void MainWindow::SolvingIsRunningHandler(const bool& val)
{
    if(val)
    {
        ui->btnGenerateRandomDatas->setEnabled(false);
        ui->btnLaunchAlgo->setEnabled(false);
    }
    else
    {
        ui->btnGenerateRandomDatas->setEnabled(true);
        ui->btnLaunchAlgo->setEnabled(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

