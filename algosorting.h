#ifndef ALGOSORTING_H
#define ALGOSORTING_H

#include <vector>
#include "BarValue.h"
#include <random>
#include <memory>

template <typename T>
class AlgoSorting
{
    public:
        AlgoSorting();
        void GenerateRandomValues(int nbValues, int minVal, int maxVal);
        void SetValues(std::vector<std::shared_ptr<BarValue<T>>> values);
        void Reset();
        void Pause();
        virtual void Solve() = 0;
        void NextStep();
        void PreviousStep();
        std::vector<std::shared_ptr<BarValue<T>>> GetValues();

    private:
        std::vector<std::shared_ptr<BarValue<T>>> initialValues;
        std::vector<std::shared_ptr<BarValue<T>>> currentValues;
        bool solvingIsRunning;
        int resolvingSpeed;

};

#endif // ALGOSORTING_H
