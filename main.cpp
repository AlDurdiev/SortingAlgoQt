#include "mainwindow.h"

#include <QApplication>

#include "algosortinginsertion.h"

int main(int argc, char *argv[])
{
    AlgoSorting* sortingAlgo = new AlgoSortingInsertion();

    QApplication a(argc, argv);
    MainWindow w(sortingAlgo);
    w.show();

    return a.exec();

    delete sortingAlgo;
}
