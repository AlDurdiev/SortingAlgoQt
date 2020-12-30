#ifndef ALGOSORTINGMERGE_H
#define ALGOSORTINGMERGE_H

#include "algosorting.h"
#include <memory>

class AlgoSortingMerge : public AlgoSorting
{
    Q_OBJECT
public:
    void run() override;

private:
    void sortMerge(int beginIndex, int endIndex);

    void merge(int beginIndex, int middleIndex, int endIndex);

};

#endif // ALGOSORTINGMERGE_H
