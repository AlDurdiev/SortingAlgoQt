#ifndef ALGOSORTINGQUICK_H
#define ALGOSORTINGQUICK_H

#include "algosorting.h"

/**
 * @brief The AlgoSortingQuick class
 * This class implements the Quick Sort Algorithm.
 */
class AlgoSortingQuick : public AlgoSorting
{
    Q_OBJECT
public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Quick sort algorithm.
     */
    void run() override;

private :
    /**
     * @brief Solve the position of the pivot in this subarray.
     * @param beginIndex Start index for the subarray.
     * @param endIndex Start index for the subarray.
     * @return The index of the choosen pivot (choosen pivot is always = endIndex in the begin of the method).
     */
    int solvePartition(int beginIndex, int endIndex);
    /**
     * @brief main method --> divide && conqueer algorithm type.
     * @param beginIndex Start index for the subarray.
     * @param endIndex Start index for the subarray.
     * Main method which divide recursivly the array and resolve with pivot method all the subarrays.
     * It calls itself recursively.
     */
    void solveAlgo(int beginIndex, int endIndex);

    /**
     * @brief Swap two items.
     * @param index1 First item to swap.
     * @param index2 Second item to swap.
     * Swap two items in our list (could be an array..).
     */
    void swap(int index1, int index2);
};

#endif // ALGOSORTINGQUICK_H
