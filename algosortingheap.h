#ifndef ALGOSORTINGHEAP_H
#define ALGOSORTINGHEAP_H

#include "algosorting.h"

class AlgoSortingHeap : public AlgoSorting
{
    Q_OBJECT
public:
    void run() override;

    int FindParentIndex(int index);

};

#endif // ALGOSORTINGHEAP_H
