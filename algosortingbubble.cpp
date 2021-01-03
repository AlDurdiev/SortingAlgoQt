#ifndef ALGOSORTINGBUBBLE_CPP
#define ALGOSORTINGBUBBLE_CPP

#include "algosortingbubble.h"

void AlgoSortingBubble::run()
{
    setSolvingIsRunning(true);
    for(int i=currentValues.size()-1 ; i > 0 ; i--)
    {
        for(int y=0 ; y < i ; y++)
        {
            currentValues[y]->setSelectedHandler(true);
            QThread::msleep(compareSpeedMs);

            currentValues[y]->setSelectedHandler(false);
            if(currentValues[y + 1]->data() < currentValues[y]->data())
            {
                auto buffer { currentValues[y + 1] };
                currentValues[y + 1] = currentValues[y];
                currentValues[y] = buffer;

                buffer->setSelectedHandler(false);

                emit insertValueEvent(&(*currentValues[y + 1]), y+1);
                emit insertValueEvent(&(*currentValues[y]), y);
            }
        }

        QThread::msleep(resolveSpeedMs);
        currentValues[i]->setDoneHandler(true);
    }
    currentValues[0]->setDoneHandler(true);
    setSolvingIsRunning(false);
}

#endif
