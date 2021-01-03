#ifndef ALGOSORTINGSELECTION_CPP
#define ALGOSORTINGSELECTION_CPP

#include "algosortingselection.h"

void AlgoSortingSelection::run()
{
    setSolvingIsRunning(true);
    for(unsigned long i=0 ; i < currentValues.size() - 1 ; i++)
    {
        int indexMin = i;
        currentValues[i]->setSelectedHandler(true);

        QThread::msleep(resolveSpeedMs);

        for(unsigned long y=i ; y < currentValues.size(); y++)
        {
            currentValues[y]->setComparedHandler(true);

            QThread::msleep(compareSpeedMs);
            if(currentValues[y]->data() < currentValues[indexMin]->data())
                indexMin = y;

            currentValues[y]->setComparedHandler(false);
        }

        if(indexMin != i)
        {
            auto buffer { currentValues[indexMin] };
            currentValues[indexMin] = currentValues[i];
            currentValues[i] = buffer;

            emit insertValueEvent(&(*currentValues[indexMin]), indexMin);
            emit insertValueEvent(&(*currentValues[i]), i);

            currentValues[indexMin]->setSelectedHandler(false);

        }

        currentValues[i]->setSelectedHandler(false);
        currentValues[i]->setDoneHandler(true);
    }
    currentValues[currentValues.size() - 1]->setDoneHandler(true);

    setSolvingIsRunning(false);
}


#endif
