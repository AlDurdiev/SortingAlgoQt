#ifndef ALGOSORTING_H
#define ALGOSORTING_H

#include <vector>
#include "barvaluedouble.h"
#include <random>
#include <memory>
#include <QThread>

class AlgoSorting : public QThread
{
    Q_OBJECT
    public:
        void GenerateRandomValues(int nbValues, int minVal, int maxVal);
        void SetValues(std::vector<std::shared_ptr<BarValueDouble>> values);
        void Reset();
        void Pause();
        //virtual void Run() = 0;
        void NextStep();
        void PreviousStep();
        std::vector<std::shared_ptr<BarValueDouble>> GetValues();

    protected:
        std::vector<std::shared_ptr<BarValueDouble>> initialValues;
        std::vector<std::shared_ptr<BarValueDouble>> currentValues;
        bool solvingIsRunning;
        int resolvingSpeed;

    signals:
        void swapBarGUI(std::shared_ptr<BarValueDouble> from, std::shared_ptr<BarValueDouble> to);
};


#endif // ALGOSORTING_H
