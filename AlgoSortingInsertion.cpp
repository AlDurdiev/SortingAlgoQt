#ifndef ALGOSORTINGINSERTION_CPP
#define ALGOSORTINGINSERTION_CPP

#include "algosortinginsertion.h"

void AlgoSortingInsertion::run()
{
    SetSolvingIsRunning(true);

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
            emit insertValueGUI(&(*currentValues[j]), j);
        }

        val->SetSelected(false);

        currentValues[j] = val;
        emit insertValueGUI(&(*val), j);

    }

    for(auto& val : currentValues)
        val->SetDone(true);

    SetSolvingIsRunning(false);
}

#endif
