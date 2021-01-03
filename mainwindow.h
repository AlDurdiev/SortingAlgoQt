#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "algosortinginsertion.h"
#include "algosortingselection.h"
#include "algosortingbubble.h"
#include "algosortingmerge.h"
#include "algosortingheap.h"
#include "algosortingquick.h"
#include "bargraphbutton.h"
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class
 * Main UI class which represents our main window.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui { nullptr };
    AlgoSorting* algo_ { nullptr };         // Current used sorting algorithm pointer
    std::vector<BarGraphButton*> buttons_;  //

    /**
     * @brief Method to update the view by cleaning the bargraph and generating the new values.
     * @param values New values that has been generated and that we need to create the bargraph buttons.
     * @param minVal Minimal value that can be generated randomly.
     * @param maxVal Maximal value that can be generated randomly.
     */
    void updateView(std::vector<std::shared_ptr<BarValueDouble>> values, double minVal, double maxVal);
    /**
     * @brief Method to move an button from one index to another in the same list.
     * @param oldIndex
     * @param newIndex
     */
    void move(size_t oldIndex, size_t newIndex);


public slots:
    /**
     * @brief Generated random datas handler.
     * Method which should be called when we press on Generate Datas button.
     */
    void generateDatasHandler();
    /**
     * @brief Launch algorithm handler.
     * Method which should be called when we press on Launch algorithm button.
     */
    void launchAlgorithmHandler();
    /**
     * @brief Insert value handler.
     * @param from Value to find in the bargraph and to move.
     * @param index Index where to insert/move the value in the bargraph.
     */
    void insertValueGUIHandler(BarValueDouble* from, int index);
    /**
     * @brief Solving is running handler
     * @param val True = an algorithm is currently running
     * Handler which enable/disabled buttons when an algorithm started or finish to run.
     */
    void solvingIsRunningHandler(const bool& val);
    /**
     * @brief Refresh the whole bragraph handler
     * When this method is called, it refresh the whole bargraph.
     */
    void refreshAllGUIHandler();
    /**
     * @brief Swap two values in the bargraph.
     * @param item1 First value to swap.
     * @param item2 Second value to swap.
     * This method finds the linked buttons to those values and then swap them in the array/list.
     */
    void swapValuesGUIHandler(BarValueDouble* item1, BarValueDouble* item2);

};
#endif // MAINWINDOW_H
