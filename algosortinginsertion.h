#ifndef ALGOSORTINGINSERTION_H
#define ALGOSORTINGINSERTION_H

#include "algosorting.h"
#include <QThread>

/**
 * @brief The AlgoSortingInsertion class
 * This class implements the Insertion Sort Algorithm.
 */
class AlgoSortingInsertion : public AlgoSorting
{

    Q_OBJECT
public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Insertion sort algorithm.
     */
    void run() override;

};

#endif // ALGOSORTINGINSERTION_H
