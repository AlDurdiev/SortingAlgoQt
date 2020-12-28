#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, AlgoSorting<double> *algo)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , algo_(algo)
{
    ui->setupUi(this);

    QObject::connect(ui->btnGenerateRandomDatas, &QPushButton::clicked,
                    this, &MainWindow::GenerateDatas);
}

void MainWindow::GenerateDatas()
{
    std::unique_ptr<AlgoSorting<double>> ptrAlgo { new AlgoSortingInsertion<double>() };

    const auto nbValues { ui->spinNbValues->value() };
    const auto minValue { ui->spinMinValue->value() };
    const auto maxValue { ui->spinMaxValue->value() };

    ptrAlgo->GenerateRandomValues(nbValues,
                                  minValue,
                                  maxValue);


    // Create initial bargraph
    auto generatedValues { ptrAlgo->GetValues()};

    auto layoutHeight { ui->layoutBarGraph->contentsRect().height() };


    // NOTE POUR CE SOIR : Créer un QPUSHBUTTON personnalisé qui prend en paramètre un pointeur (shared_ptr) vers le BarValue
    //                     Faire en sorte que ce bouton change de couleur en fonction de sa sélection.
    //                     Puis implémenter ci-dessous : le nouveau bouton créé
    //                     Créer un signal à partir (signal) qui surveille la valeur de BarValue->selected & BarValue->done et qui emit cela lorsque c'est nécessaire

    for(const auto & val : generatedValues)
    {
        QPushButton* newBtn { new QPushButton() };

        double calculatedHeight { (val->data / (maxValue - minValue)) * layoutHeight };

        newBtn->setMinimumHeight(calculatedHeight);

        ui->layoutBarGraph->addWidget(newBtn);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

