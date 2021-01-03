#include "algosortingquick.h"

void AlgoSortingQuick::run()
{
    setSolvingIsRunning(true);

    solveAlgo(0, currentValues.size()-1);

    for(auto &val : currentValues)
        val->setDoneHandler(true);

    setSolvingIsRunning(false);
}

int AlgoSortingQuick::solvePartition(int beginIndex, int endIndex)
{
    int pivot { endIndex };
    int j { beginIndex - 1 };

    currentValues[pivot]->setSelectedHandler(true);
    QThread::msleep(resolveSpeedMs);

    for(int i = beginIndex ; i < endIndex  ; i++)
    {
        currentValues[i]->setComparedHandler(true);
        if(currentValues[i]->data() <= currentValues[pivot]->data())
        {
            j++;
            currentValues[j]->setComparedHandler(true);
            swap(i, j);
            currentValues[j]->setComparedHandler(false);
        }
        currentValues[i]->setComparedHandler(false);
        QThread::msleep(compareSpeedMs);
    }

    currentValues[pivot]->setSelectedHandler(false);
    currentValues[pivot]->setDoneHandler(true);

    swap(j + 1, pivot);
    //emit refreshAllGUI();

    return (j + 1);
}


void AlgoSortingQuick::solveAlgo(int beginIndex, int endIndex)
{
    if(beginIndex < endIndex)
    {
        int pivotIndex = solvePartition(beginIndex, endIndex);
        solveAlgo(beginIndex, pivotIndex-1);
        solveAlgo(pivotIndex+1, endIndex);
    }
}

void AlgoSortingQuick::swap(int index1, int index2)
{
    if(index1 != index2)
    {
        emit swapValuesEvent(&(*currentValues[index1]), &(*currentValues[index2]));
        auto buffer { currentValues[index1] };
        currentValues[index1] = currentValues[index2];
        currentValues[index2] = buffer;
    }
}
