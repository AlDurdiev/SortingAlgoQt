#ifndef ALGOSORTINGMERGE_CPP
#define ALGOSORTINGMERGE_CPP

#include "algosortingmerge.h"

void AlgoSortingMerge::run()
{
    currentValues = sortFusion(currentValues);
}

std::vector<std::shared_ptr<BarValueDouble>> AlgoSortingMerge::sortFusion(std::vector<std::shared_ptr<BarValueDouble>> tab)
{
    if(tab.size() <= 1)
        return tab;
    else
    {
        std::vector<std::shared_ptr<BarValueDouble>> partA(tab.begin(), tab.begin() + (tab.size()/2));
        std::vector<std::shared_ptr<BarValueDouble>> partB(tab.begin() + tab.size()/2, tab.end() );
        return fusion(sortFusion(partA), sortFusion(partB));
    }
}

std::vector<std::shared_ptr<BarValueDouble>> AlgoSortingMerge::fusion(std::vector<std::shared_ptr<BarValueDouble>> tabA,
                                                                        std::vector<std::shared_ptr<BarValueDouble>> tabB)
{
    if(tabA.size() == 0)
        return tabB;
    else if(tabB.size() == 0)
        return tabA;
    else if(tabA[0]->Data() <= tabB[0]->Data())
    {
        std::vector<std::shared_ptr<BarValueDouble>> solo(tabA.begin(), tabA.begin()+1);

        std::vector<std::shared_ptr<BarValueDouble>> part(tabA.begin()+1, tabA.end());
        auto fusionResult { fusion(part, tabB) };

        solo.insert(solo.end(), fusionResult.begin(), fusionResult.end());
        return solo;
    }
    else
    {
        std::vector<std::shared_ptr<BarValueDouble>> solo(tabB.begin(), tabB.begin()+1);

        std::vector<std::shared_ptr<BarValueDouble>> part(tabB.begin()+1, tabB.end());
        auto fusionResult { fusion(tabA, part) };

        solo.insert(solo.end(), fusionResult.begin(), fusionResult.end());
        return solo;
    }
}

#endif
