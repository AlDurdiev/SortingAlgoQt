#ifndef ALGOSORTINGMERGE_CPP
#define ALGOSORTINGMERGE_CPP

#include "algosortingmerge.h"

void AlgoSortingMerge::run()
{
    setSolvingIsRunning(true);
    sortMerge(0, currentValues.size() - 1);

    for(auto & val : currentValues)
    {
        val->setDoneHandler(true);
    }

    setSolvingIsRunning(false);
}

void AlgoSortingMerge::sortMerge(int beginIndex, int endIndex)
{
    if(endIndex > beginIndex)
    {
        int middleIndex { beginIndex + (endIndex - beginIndex)/2 };
        sortMerge(beginIndex, middleIndex);
        sortMerge(middleIndex + 1, endIndex);

        for(int i=beginIndex ; i < endIndex ; i++)
            currentValues[i]->setSelectedHandler(true);

        QThread::msleep(resolveSpeedMs);
        merge(beginIndex, middleIndex, endIndex);
        emit refreshAllEvent();

        for(int i=beginIndex ; i <= endIndex ; i++)
            currentValues[i]->setSelectedHandler(false);
    }
}

void AlgoSortingMerge::merge(int beginIndex, int middleIndex, int endIndex)
{
    int k { 0 };
    int leftPartSize { middleIndex - beginIndex + 1};
    int rightPartSize { endIndex - middleIndex };

    std::vector<std::shared_ptr<BarValueDouble>> leftPart;
    std::vector<std::shared_ptr<BarValueDouble>> rightPart;

    for(int i=0 ; i < leftPartSize ; i++)
        leftPart.push_back(currentValues[beginIndex + i]);
    for(int i=0 ; i < rightPartSize ; i++)
        rightPart.push_back(currentValues[middleIndex + 1 + i]);

    int i { 0 };
    int j { 0 };
    k = beginIndex;

    while(i < leftPartSize && j < rightPartSize)
    {
        if(leftPart[i]->data() <= rightPart[j]->data())
        {
            currentValues[k] = leftPart[i];
            i++;
        }
        else
        {
            currentValues[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while(i < leftPartSize)
    {
        currentValues[k] = leftPart[i];
        i++;
        k++;
    }

    while(j < rightPartSize)
    {
        currentValues[k] = rightPart[j];
        j++;
        k++;
    }
}

#endif
