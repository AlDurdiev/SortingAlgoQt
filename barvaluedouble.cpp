#ifndef BARVALDOUBLE_CPP
#define BARVALDOUBLE_CPP

#include "barvaluedouble.h"

BarValueDouble::BarValueDouble(double val)
    : data_(val)
{
}

double BarValueDouble::data()
{
    return data_;
}

bool BarValueDouble::isSelected()
{
    return isSelected_;
}

bool BarValueDouble::isDone()
{
    return isDone_;
}


bool BarValueDouble::isCompared()
{
    return isCompared_;
}

void BarValueDouble::setData(const double& val)
{
    data_ = val;
}


void BarValueDouble::setSelectedHandler(const bool& val)
{
    if(val != isSelected_)
    {
        isSelected_ = val;
        emit selectedChangedEvent(val);
    }
}

void BarValueDouble::setDoneHandler(const bool& val)
{
    if(val != isDone_)
    {
        isDone_ = val;
        emit doneChangedEvent(val);
    }
}

void BarValueDouble::setComparedHandler(const bool& val)
{
    if(val != isCompared_)
    {
        isCompared_ = val;
        emit comparedChangedEvent(val);
    }
}


#endif

