#ifndef BARVALDOUBLE_CPP
#define BARVALDOUBLE_CPP

#include "barvaluedouble.h"

BarValueDouble::BarValueDouble(double val)
    : data(val)
{
}

double BarValueDouble::Data()
{
    return data;
}

bool BarValueDouble::Selected()
{
    return selected;
}

bool BarValueDouble::Done()
{
    return done;
}


void BarValueDouble::SetData(const double& val)
{
    data = val;
}


void BarValueDouble::SetSelected(const bool& val)
{
    if(val != selected)
    {
        selected = val;
        emit valueSelectedChanged(val);
    }
}

void BarValueDouble::SetDone(const bool& val)
{
    if(val != done)
    {
        done = val;
        emit valueDoneChanged(val);
    }
}

void BarValueDouble::SetComparedChanged(const bool& val)
{
    if(val != compared)
    {
        compared = val;
        emit valueComparedChanged(val);
    }
}


#endif

