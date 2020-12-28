#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "algosortinginsertion.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, AlgoSorting<double> *algo = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AlgoSorting<double> *algo_;

public slots:
    void GenerateDatas();

};
#endif // MAINWINDOW_H
