#include "algosortingquick.h"

void AlgoSortingQuick::run()
{
    SetSolvingIsRunning(true);

    solveAlgo(0, currentValues.size()-1);

    SetSolvingIsRunning(false);
}

int AlgoSortingQuick::solvePartition(int beginIndex, int endIndex)
{
    int pivot { endIndex };
    int j { beginIndex - 1 };

    for(int i = beginIndex ; i < endIndex  ; i++)
    {
        if(currentValues[i]->Data() <= currentValues[pivot]->Data())
        {
            j++;
            auto buffer = currentValues[i] ;
            currentValues[i] = currentValues[j];
            currentValues[j] = buffer;
        }
    }

    auto buffer = currentValues[j];
    currentValues[j] = currentValues[pivot];
    currentValues[pivot] = buffer;

    return j;
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

