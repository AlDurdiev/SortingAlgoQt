#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(AlgoSorting* algo, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , algo_(algo)
{
    ui->setupUi(this);

    QObject::connect(ui->btnGenerateRandomDatas, &QPushButton::clicked,
                    this, &MainWindow::GenerateDatas);

    QObject::connect(ui->btnLaunchAlgo, &QPushButton::clicked,
                     this, &MainWindow::LaunchAlgorithm);


    QObject::connect(algo_, &AlgoSorting::swapBarGUI,
                     this, &MainWindow::SwapUIEvent);

    QObject::connect(algo_, &AlgoSorting::SolvingIsRunningEvent,
                     this, &MainWindow::SolvingIsRunningHandler);

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
        algo_->start();
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

        double calculatedHeight { (val->Data() / (maxVal - minVal)) * layoutHeight };
        if(calculatedHeight < 0)
            calculatedHeight = -calculatedHeight;

        newBtn->setMinimumHeight(calculatedHeight);

        buttons_.push_back(newBtn);
        ui->layoutBarGraph->addWidget(newBtn);

        int size = ui->layoutBarGraph->count();
    }
}

void MainWindow::SwapUIEvent(BarValueDouble* from, int index)
{
    // insert
    auto fromIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&from](BarGraphButton* x){ return &(*x->Val()) == from ;});

    if(fromIteWidget != buttons_.end())
        ui->layoutBarGraph->insertWidget(index, *fromIteWidget);
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

