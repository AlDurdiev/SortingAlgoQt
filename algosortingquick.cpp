#include "algosortingquick.h"

void AlgoSortingQuick::run()
{
    SetSolvingIsRunning(true);

    solveAlgo(0, currentValues.size()-1);

    for(auto &val : currentValues)
        val->SetDone(true);

    SetSolvingIsRunning(false);
}

int AlgoSortingQuick::solvePartition(int beginIndex, int endIndex)
{
    int pivot { endIndex };
    int j { beginIndex - 1 };

    currentValues[pivot]->SetSelected(true);
    QThread::msleep(resolvingSpeedMs);

    for(int i = beginIndex ; i < endIndex  ; i++)
    {
        currentValues[i]->SetComparedChanged(true);
        if(currentValues[i]->Data() <= currentValues[pivot]->Data())
        {
            j++;
            currentValues[j]->SetComparedChanged(true);
            swap(i, j);
            currentValues[j]->SetComparedChanged(false);
        }
        currentValues[i]->SetComparedChanged(false);
        QThread::msleep(compareSpeedMs);
    }

    currentValues[pivot]->SetSelected(false);
    currentValues[pivot]->SetDone(true);

    swap(j + 1, pivot);

    emit refreshAllGUI();

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
        auto buffer { currentValues[index1] };
        currentValues[index1] = currentValues[index2];
        currentValues[index2] = buffer;
    }
}
