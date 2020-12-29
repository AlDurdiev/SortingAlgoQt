#ifndef ALGOSORTINGINSERTION_H
#define ALGOSORTINGINSERTION_H

#include "algosorting.h"
#include <QThread>

class AlgoSortingInsertion : public AlgoSorting
{

    Q_OBJECT
public:
    void run() override;

};

#endif // ALGOSORTINGINSERTION_H
