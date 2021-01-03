#ifndef ALGOSORTINGINSERTION_CPP
#define ALGOSORTINGINSERTION_CPP

#include "algosortinginsertion.h"

void AlgoSortingInsertion::run()
{
    setSolvingIsRunning(true);

    for(unsigned long i = 1 ; i < currentValues.size() ; i++)
    {
        auto val = currentValues[i];
        val->setSelectedHandler(true);

        QThread::msleep(resolveSpeedMs);

        auto j = i;
        for(; (j > 0) && (currentValues[j - 1]->data() > val->data()) ; j--)
        {
            currentValues[j - 1]->setComparedHandler(true);

            QThread::msleep(compareSpeedMs);
            currentValues[j] = currentValues[j - 1];

            currentValues[j - 1]->setComparedHandler(false);
            emit insertValueEvent(&(*currentValues[j]), j);
        }

        val->setSelectedHandler(false);

        currentValues[j] = val;
        emit insertValueEvent(&(*val), j);

    }

    for(auto& val : currentValues)
        val->setDoneHandler(true);

    setSolvingIsRunning(false);
}

#endif
