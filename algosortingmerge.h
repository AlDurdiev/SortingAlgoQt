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
    std::vector<std::shared_ptr<BarValueDouble>> sortFusion(std::vector<std::shared_ptr<BarValueDouble>> tab);

    std::vector<std::shared_ptr<BarValueDouble>> fusion(std::vector<std::shared_ptr<BarValueDouble>> tabA,
                                                        std::vector<std::shared_ptr<BarValueDouble>> tabB);

};

#endif // ALGOSORTINGMERGE_H
