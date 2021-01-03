#include "algosortingheap.h"

void AlgoSortingHeap::run()
{
    setSolvingIsRunning(true);

    for(unsigned long nbDone = 0 ; nbDone < currentValues.size() ; nbDone++ )
    {
        QThread::msleep(resolveSpeedMs);

        // Find biggest value by sorting the tree
        for(int i = currentValues.size() - 1 - nbDone ; i > 0 ; i--)
        {
            int parentIndex { findParentIndex(i) };

            currentValues[i]->setSelectedHandler(true);
            currentValues[parentIndex]->setComparedHandler(true);

            QThread::msleep(compareSpeedMs);

            currentValues[i]->setSelectedHandler(false);
            currentValues[parentIndex]->setComparedHandler(false);

            if(!currentValues[i]->isDone() && currentValues[parentIndex]->data() <= currentValues[i]->data())
            {
                // Swap with parent
                auto buffer { currentValues[parentIndex] };
                currentValues[parentIndex] = currentValues[i];
                currentValues[i] = buffer;
                emit refreshAllEvent();
            }
        }


        // Swap sorted elem to done
        auto buffer { currentValues[currentValues.size() - 1 - nbDone] };
        currentValues[currentValues.size() - 1 - nbDone] = currentValues[0];
        currentValues[0] = buffer;

        currentValues[currentValues.size() - 1 - nbDone]->setDoneHandler(true);

        emit refreshAllEvent();
    }

    setSolvingIsRunning(false);
}

int AlgoSortingHeap::findParentIndex(int index)
{
    if(index % 2 == 0)
        return ((index / 2) - 1);
    else
        return (index / 2);
}

