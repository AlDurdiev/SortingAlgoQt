#ifndef ALGOSORTING_CPP
#define ALGOSORTING_CPP

#include "algosorting.h"

void AlgoSorting::GenerateRandomValues(int nbValues, int minVal, int maxVal)
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

void AlgoSorting::SetValues(std::vector<std::shared_ptr<BarValueDouble>> values)
{
    currentValues = values;
}

std::vector<std::shared_ptr<BarValueDouble>> AlgoSorting::GetValues()
{
    return currentValues;
}

bool AlgoSorting::GetSolvingIsRunning()
{
    return solvingIsRunning;
}

void AlgoSorting::SetSolvingIsRunning(const bool &val)
{
    emit SolvingIsRunningEvent(val);
}

#endif
