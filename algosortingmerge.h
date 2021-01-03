#ifndef ALGOSORTINGMERGE_H
#define ALGOSORTINGMERGE_H

#include "algosorting.h"
#include <memory>

/**
 * @brief The AlgoSortingMerge class
 * This class implements the Merge Sort Algorithm.
 */
class AlgoSortingMerge : public AlgoSorting
{
    Q_OBJECT
public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Merge sort algorithm.
     */
    void run() override;

private:

    /**
     * @brief main method --> divide & conqueer algorithm type.
     * @param beginIndex Start index for the subarray.
     * @param endIndex Start index for the subarray.
     * Main method which divide recursively the array and then resolve with merge method all the subarrays.
     * It calls itself recursively.
     */
    void sortMerge(int beginIndex, int endIndex);
    /**
     * @brief Sort subarray
     * @param beginIndex Start index for the subarray.
     * @param middleIndex Middle index for the subarray.
     * @param endIndex End index for the subarray.
     * Submethod which resolve subarray to put elements sorted.
     */
    void merge(int beginIndex, int middleIndex, int endIndex);

};

#endif // ALGOSORTINGMERGE_H
