#ifndef ALGOSORTINGSELECTION_H
#define ALGOSORTINGSELECTION_H

#include "algosorting.h"

/**
 * @brief The AlgoSortingSelection class
 * This class implements the Selection Sort Algorithm.
 */
class AlgoSortingSelection : public AlgoSorting
{
    Q_OBJECT
public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Selection sort algorithm.
     */
    void run() override;
};

#endif // ALGOSORTINGSELECTION_H
