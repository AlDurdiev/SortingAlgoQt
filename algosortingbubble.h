#ifndef ALGOSORTINGBUBBLE_H
#define ALGOSORTINGBUBBLE_H

#include "algosorting.h"

/**
 * @brief The AlgoSortingBubble class
 * This class implements the Bubble Sort Algorithm.
 */
class AlgoSortingBubble : public AlgoSorting
{
    Q_OBJECT

public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Bubble sort algorithm.
     */
    void run() override;
};

#endif // ALGOSORTINGBUBBLE_H
