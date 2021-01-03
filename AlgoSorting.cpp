#ifndef ALGOSORTING_CPP
#define ALGOSORTING_CPP

#include "algosorting.h"

void AlgoSorting::generateRandomValues(int nbValues, int minVal, int maxVal)
{
    currentValues.clear();

    double val { 0 };
    for(int i=0 ; i < nbValues ; i++)
    {
        val = std::rand() % (maxVal - minVal + 1) + minVal;
        auto barVal { std::make_shared<BarValueDouble>(val) };
        currentValues.push_back(barVal);
    }
}

void AlgoSorting::setValues(std::vector<std::shared_ptr<BarValueDouble>> values)
{
    currentValues = values;
}

std::vector<std::shared_ptr<BarValueDouble>> AlgoSorting::getValues()
{
    return currentValues;
}

bool AlgoSorting::getSolvingIsRunning()
{
    return solvingIsRunning;
}

void AlgoSorting::setSolvingIsRunning(const bool &val)
{
    emit solvingIsRunningEvent(val);
}

#endif
