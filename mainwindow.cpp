#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
    algo_ = new AlgoSortingInsertion();

    // Connect events
    QObject::connect(ui->btnGenerateRandomDatas, &QPushButton::clicked,
                    this, &MainWindow::generateDatasHandler);

    QObject::connect(ui->btnLaunchAlgo, &QPushButton::clicked,
                     this, &MainWindow::launchAlgorithmHandler);

}

void MainWindow::generateDatasHandler()
{
    if(algo_->getSolvingIsRunning())
        return;

    const auto nbValues { ui->spinNbValues->value() };
    const auto minValue { ui->spinMinValue->value() };
    const auto maxValue { ui->spinMaxValue->value() };

    algo_->generateRandomValues(nbValues,
                                  minValue,
                                  maxValue);

    //
    updateView(algo_->getValues(), minValue, maxValue);

}


void MainWindow::launchAlgorithmHandler()
{
    if(!algo_->getSolvingIsRunning() && algo_->getValues().size() > 0)
    {
        auto values = algo_->getValues();
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

        QObject::connect(algo_, &AlgoSorting::insertValueEvent,
                         this, &MainWindow::insertValueGUIHandler);

        QObject::connect(algo_, &AlgoSorting::solvingIsRunningEvent,
                         this, &MainWindow::solvingIsRunningHandler);

        QObject::connect(algo_, &AlgoSorting::refreshAllEvent,
                         this, &MainWindow::refreshAllGUIHandler);

        QObject::connect(algo_, &AlgoSorting::swapValuesEvent,
                         this, &MainWindow::swapValuesGUIHandler);

        algo_->setValues(values);
        algo_->start();
    }
}

void MainWindow::updateView(std::vector<std::shared_ptr<BarValueDouble>> values, double minVal, double maxVal)
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

        if(val->isDone())
            newBtn->doneChangedHandler(true);

        if(val->isSelected())
            newBtn->selectedChangedHandler(true);

        if(val->isCompared())
            newBtn->comparedChangedHandler(true);

        double calculatedHeight { (val->data() / (maxVal - minVal)) * layoutHeight };
        if(calculatedHeight < 0)
            calculatedHeight = -calculatedHeight;

        newBtn->setMinimumHeight(calculatedHeight);

        buttons_.push_back(newBtn);
        ui->layoutBarGraph->addWidget(newBtn);
    }
}

void MainWindow::insertValueGUIHandler(BarValueDouble* from, int index)
{
    // insert
    auto fromIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&from](BarGraphButton* x){ return &(*x->val()) == from ;});

    if(fromIteWidget != buttons_.end())
        ui->layoutBarGraph->insertWidget(index, *fromIteWidget);
}


void MainWindow::refreshAllGUIHandler()
{
    const auto minValue { ui->spinMinValue->value() };
    const auto maxValue { ui->spinMaxValue->value() };

    auto vals { algo_->getValues()};

    updateView(vals, minValue, maxValue);
}

void MainWindow::solvingIsRunningHandler(const bool& val)
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

void MainWindow::move(size_t oldIndex, size_t newIndex)
{
    if (oldIndex > newIndex)
        std::rotate(buttons_.rend() - oldIndex - 1, buttons_.rend() - oldIndex, buttons_.rend() - newIndex);
    else
        std::rotate(buttons_.begin() + oldIndex, buttons_.begin() + oldIndex + 1, buttons_.begin() + newIndex + 1);
}

void MainWindow::swapValuesGUIHandler(BarValueDouble* item1, BarValueDouble* item2)
{
    auto iteItem1 { std::find_if(buttons_.begin(), buttons_.end(), [&item1](BarGraphButton* x){ return &(*x->val()) == item1 ;})};
    auto iteItem2 { std::find_if(buttons_.begin(), buttons_.end(), [&item2](BarGraphButton* x){ return &(*x->val()) == item2 ;})};
    int index1 = iteItem1 - buttons_.begin();
    int index2 = iteItem2 - buttons_.begin();

    if(iteItem1 == buttons_.end() || iteItem2 == buttons_.end() || index1 == index2)
        return;

    //
    if(index1 < index2)
    {
        ui->layoutBarGraph->insertWidget(index1, buttons_[index2]);
        ui->layoutBarGraph->insertWidget(index2, buttons_[index1]);
        move(index2, index1);
        move(index1+1, index2);
    }
    else
    {
        ui->layoutBarGraph->insertWidget(index2, buttons_[index1]);
        ui->layoutBarGraph->insertWidget(index1, buttons_[index2]);
        move(index1, index2);
        move(index2+1, index1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

