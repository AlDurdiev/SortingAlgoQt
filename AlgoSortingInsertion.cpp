#ifndef ALGOSORTINGINSERTION_CPP
#define ALGOSORTINGINSERTION_CPP

#include "algosortinginsertion.h"

void AlgoSortingInsertion::run()
{
    for(auto i = 1 ; i < currentValues.size() ; i++)
    {
        auto val = currentValues[i];
        val->SetSelected(true);

        QThread::msleep(500);

        auto j = i;
        for(; (j > 0) && (currentValues[j - 1]->Data() > val->Data()) ; j--)
        {
            currentValues[j] = currentValues[j - 1];
            emit AlgoSorting::swapBarGUI(currentValues[j], currentValues[j - 1]);
        }

        currentValues[j] = val;
        emit AlgoSorting::swapBarGUI(currentValues[j], val);

        val->SetDone(true);
        val->SetSelected(false);
    }
}

#endif
