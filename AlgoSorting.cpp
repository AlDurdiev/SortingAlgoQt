#ifndef ALGOSORTING_CPP
#define ALGOSORTING_CPP

#include "algosorting.h"

void AlgoSorting::GenerateRandomValues(int nbValues, int minVal, int maxVal)
{
    initialValues.clear();
    currentValues.clear();

    double val { 0 };
    for(int i=0 ; i < nbValues ; i++)
    {
        val = std::rand() % (maxVal - minVal + 1) + minVal;
        auto barVal { std::make_shared<BarValueDouble>(val) };
        initialValues.push_back(barVal);
        currentValues.push_back(barVal);
    }
}
void AlgoSorting::SetValues(std::vector<std::shared_ptr<BarValueDouble>> values)
{
    initialValues = values;
    currentValues = values;
}
void AlgoSorting::Reset()
{

}
void AlgoSorting::Pause()
{

}

void AlgoSorting::NextStep()
{

}
void AlgoSorting::PreviousStep()
{

}
std::vector<std::shared_ptr<BarValueDouble>> AlgoSorting::GetValues()
{
    return currentValues;
}

#endif
