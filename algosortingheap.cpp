#include "algosortingheap.h"

void AlgoSortingHeap::run()
{
    SetSolvingIsRunning(true);

    for(auto nbDone = 0 ; nbDone < currentValues.size() ; nbDone++ )
    {
        QThread::msleep(resolvingSpeedMs);

        // Find biggest value by sorting the tree
        for(int i = currentValues.size() - 1 - nbDone ; i > 0 ; i--)
        {
            int parentIndex { FindParentIndex(i) };

            currentValues[i]->SetSelected(true);
            currentValues[parentIndex]->SetComparedChanged(true);

            QThread::msleep(compareSpeedMs);

            currentValues[i]->SetSelected(false);
            currentValues[parentIndex]->SetComparedChanged(false);

            if(!currentValues[i]->Done() && currentValues[parentIndex]->Data() <= currentValues[i]->Data())
            {
                // Swap with parent
                auto buffer { currentValues[parentIndex] };
                currentValues[parentIndex] = currentValues[i];
                currentValues[i] = buffer;
                emit refreshAllGUI();
            }
        }


        // Swap sorted elem to done
        auto buffer { currentValues[currentValues.size() - 1 - nbDone] };
        currentValues[currentValues.size() - 1 - nbDone] = currentValues[0];
        currentValues[0] = buffer;

        currentValues[currentValues.size() - 1 - nbDone]->SetDone(true);

        emit refreshAllGUI();
    }

    SetSolvingIsRunning(false);
}

int AlgoSortingHeap::FindParentIndex(int index)
{
    if(index % 2 == 0)
        return ((index / 2) - 1);
    else
        return (index / 2);
}

