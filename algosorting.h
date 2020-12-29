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
        std::vector<std::shared_ptr<BarValueDouble>> GetValues();
        bool GetSolvingIsRunning();

    protected:
        std::vector<std::shared_ptr<BarValueDouble>> currentValues;

        int resolvingSpeedMs { 300 };
        int compareSpeedMs { 50 };
        void SetSolvingIsRunning(const bool& val);

    private:
        bool solvingIsRunning { false };

    signals:
        void swapBarGUI(BarValueDouble* from, int index);
        void SolvingIsRunningEvent(const bool& val);
};


#endif // ALGOSORTING_H
