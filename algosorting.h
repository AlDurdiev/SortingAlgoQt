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
        std::vector<std::shared_ptr<BarValueDouble>> currentValues; // We'll use an vector for all our algorithms.
                                                                    // Of course, sometimes an array is faster.
                                                                    // But the purpose of this app is for watching the algorithm in live.
                                                                    // So we don't need to be more efficient and vector are more confortable.

        int resolvingSpeedMs { 300 };
        int compareSpeedMs { 50 };
        void SetSolvingIsRunning(const bool& val);

    private:
        bool solvingIsRunning { false };

    signals:
        void insertValueGUI(BarValueDouble* from, int index);
        void swapValuesGUI(BarValueDouble* val1, BarValueDouble* val2);
        void refreshAllGUI();
        void SolvingIsRunningEvent(const bool& val);
};


#endif // ALGOSORTING_H
