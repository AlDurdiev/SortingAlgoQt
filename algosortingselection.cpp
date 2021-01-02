#ifndef ALGOSORTINGSELECTION_CPP
#define ALGOSORTINGSELECTION_CPP

#include "algosortingselection.h"

void AlgoSortingSelection::run()
{
    SetSolvingIsRunning(true);
    for(auto i=0 ; i < currentValues.size() - 1 ; i++)
    {
        int indexMin = i;
        currentValues[i]->SetSelected(true);

        QThread::msleep(resolvingSpeedMs);

        for(auto y=i ; y < currentValues.size(); y++)
        {
            currentValues[y]->SetComparedChanged(true);

            QThread::msleep(compareSpeedMs);
            if(currentValues[y]->Data() < currentValues[indexMin]->Data())
                indexMin = y;

            currentValues[y]->SetComparedChanged(false);
        }

        if(indexMin != i)
        {
            auto buffer { currentValues[indexMin] };
            currentValues[indexMin] = currentValues[i];
            currentValues[i] = buffer;

            emit insertValueGUI(&(*currentValues[indexMin]), indexMin);
            emit insertValueGUI(&(*currentValues[i]), i);

            currentValues[indexMin]->SetSelected(false);

        }

        currentValues[i]->SetSelected(false);
        currentValues[i]->SetDone(true);
    }
    SetSolvingIsRunning(false);
}


#endif
