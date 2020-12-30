#ifndef ALGOSORTINGBUBBLE_CPP
#define ALGOSORTINGBUBBLE_CPP

#include "algosortingbubble.h"

void AlgoSortingBubble::run()
{
    for(int i=currentValues.size()-1 ; i > 0 ; i--)
    {
        for(int y=0 ; y < i ; y++)
        {
            currentValues[y]->SetSelected(true);
            QThread::msleep(compareSpeedMs);

            currentValues[y]->SetSelected(false);
            if(currentValues[y + 1]->Data() < currentValues[y]->Data())
            {
                auto buffer { currentValues[y + 1] };
                currentValues[y + 1] = currentValues[y];
                currentValues[y] = buffer;

                buffer->SetSelected(false);

                emit swapBarGUI(&(*currentValues[y + 1]), y+1);
                emit swapBarGUI(&(*currentValues[y]), y);
            }
        }

        QThread::msleep(resolvingSpeedMs);
        currentValues[i]->SetDone(true);
    }
}

#endif
