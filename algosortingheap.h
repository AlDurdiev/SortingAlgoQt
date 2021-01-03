#ifndef ALGOSORTINGHEAP_H
#define ALGOSORTINGHEAP_H

#include "algosorting.h"

/**
 * @brief The AlgoSortingHeap class
 * This class implements the Heap Sort Algorithm.
 */
class AlgoSortingHeap : public AlgoSorting
{
    Q_OBJECT
public:
    /**
     * @brief run
     * Inherited from AlgoSorting which inherited from Thread.
     * This is the method which will run the Heap sort algorithm.
     */
    void run() override;

private:
    /**
     * @brief Find parent "node" index
     * @param index Index of the current node.
     * @return Parent index found.
     * Private method which find parent "node" index from "node" index if we considere our tab like an binary tree.
     */
    int findParentIndex(int index);

};

#endif // ALGOSORTINGHEAP_H
