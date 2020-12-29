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

}

void MainWindow::GenerateDatas()
{
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
    algo_->start();
}

void MainWindow::UpdateUIEvent()
{
    //const auto minValue { ui->spinMinValue->value() };
    //const auto maxValue { ui->spinMaxValue->value() };

    //UpdateView(algo_->GetValues(), minValue, maxValue);
}

void MainWindow::UpdateView(std::vector<std::shared_ptr<BarValueDouble>> values, double minVal, double maxVal)
{
    // Remove old view
    for(auto &val : buttons_)
        ui->layoutBarGraph->removeWidget(val);

    buttons_.clear();

    // Create initial bargraph
    auto layoutHeight { ui->layoutBarGraph->contentsRect().height() };

    for(auto & val : values)
    {
        BarGraphButton<double>* newBtn { new BarGraphButton<double>(val) };

        double calculatedHeight { (val->Data() / (maxVal - minVal)) * layoutHeight };
        if(calculatedHeight < 0)
            calculatedHeight = -calculatedHeight;

        newBtn->setMinimumHeight(calculatedHeight);

        buttons_.push_back(newBtn);
        ui->layoutBarGraph->addWidget(newBtn);
    }
}

void MainWindow::SwapUIEvent(std::shared_ptr<BarValueDouble> from, std::shared_ptr<BarValueDouble> to)
{
    if(to->Selected())
    {
        // insert
        auto fromIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&from](BarGraphButton<double>* x){ return x->Val() == from ;});
        auto toIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&to](BarGraphButton<double>* x){ return x->Val() == to ;});

        if(fromIteWidget != buttons_.end() && toIteWidget != buttons_.end())
        {
            int index = fromIteWidget - buttons_.begin();

            //ui->layoutBarGraph->replaceWidget(*fromIteWidget, *toIteWidget);
            ui->layoutBarGraph->insertWidget(index, *toIteWidget);
        }
    }
    else{
        // swap
        auto fromIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&from](BarGraphButton<double>* x){ return x->Val() == from ;});
        auto toIteWidget = std::find_if(buttons_.begin(), buttons_.end(), [&to](BarGraphButton<double>* x){ return x->Val() == to ;});

        if(fromIteWidget != std::end(buttons_) && toIteWidget != std::end(buttons_))
        {
            ui->layoutBarGraph->replaceWidget(*fromIteWidget, *toIteWidget);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

