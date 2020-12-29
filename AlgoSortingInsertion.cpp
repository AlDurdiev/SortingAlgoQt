#ifndef ALGOSORTINGINSERTION_CPP
#define ALGOSORTINGINSERTION_CPP

#include "algosortinginsertion.h"

void AlgoSortingInsertion::run()
{
    SetSolvingIsRunning(true);
    currentValues[0]->SetDone(true);
    for(auto i = 1 ; i < currentValues.size() ; i++)
    {
        auto val = currentValues[i];
        val->SetSelected(true);

        QThread::msleep(resolvingSpeedMs);

        auto j = i;
        for(; (j > 0) && (currentValues[j - 1]->Data() > val->Data()) ; j--)
        {
            currentValues[j - 1]->SetComparedChanged(true);

            QThread::msleep(compareSpeedMs);
            currentValues[j] = currentValues[j - 1];

            currentValues[j - 1]->SetComparedChanged(false);
            emit swapBarGUI(&(*currentValues[j]), j);
        }

        currentValues[j] = val;
        emit swapBarGUI(&(*val), j);

        val->SetDone(true);
        val->SetSelected(false);
    }
    SetSolvingIsRunning(false);
}

#endif
