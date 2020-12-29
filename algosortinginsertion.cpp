#include "algosortinginsertion.h"

template <typename T>
AlgoSortingInsertion<T>::AlgoSortingInsertion()
{

}

template <typename T>
void AlgoSortingInsertion<T>::Solve()
{
    for(unsigned long i = 1 ; i < this->currentValues.size() ; i++)
    {
        auto val = this->currentValues[i];
        val->selected = true;
        this->currentValues.erase(std::begin(this->currentValues) + i);

        auto j = i;
        for(; (j > 0) && (this->currentValues[j - 1]->data > val->data) ; j--);

        this->currentValues.insert(std::begin(this->currentValues) + j, val);
        val->done = true;
        val->selected = false;
    }
}

