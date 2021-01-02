#ifndef ALGOSORTINGQUICK_H
#define ALGOSORTINGQUICK_H

#include "algosorting.h"

class AlgoSortingQuick : public AlgoSorting
{
    Q_OBJECT
public:
    void run() override;
private :
    int solvePartition(int beginIndex, int endIndex);
    void solveAlgo(int beginIndex, int endIndex);
};

#endif // ALGOSORTINGQUICK_H
