#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "algosortinginsertion.h"
#include "bargraphbutton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(AlgoSorting* algo, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    AlgoSorting* algo_;
    std::vector<BarGraphButton<double>*> buttons_;

    void UpdateView(std::vector<std::shared_ptr<BarValueDouble>> values, double minVal, double maxVal);

public slots:
    void GenerateDatas();
    void LaunchAlgorithm();
    void UpdateUIEvent();
    void SwapUIEvent(std::shared_ptr<BarValueDouble> from, std::shared_ptr<BarValueDouble> to);

};
#endif // MAINWINDOW_H
