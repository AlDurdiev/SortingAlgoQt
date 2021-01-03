#ifndef ALGOSORTING_H
#define ALGOSORTING_H

#include <vector>
#include "barvaluedouble.h"
#include <random>
#include <memory>
#include <QThread>

/**
 * @brief The AlgoSorting class
 * Class which is used as model to the sorting algorithms.
 * This class could be an abstract class because we'll never instanciate it like this but we'll inherit from it.
 */
class AlgoSorting : public QThread
{
    Q_OBJECT
    public:
    /**
         * @brief Method generating random values
         * @param nbValues Number of values to generate randomly.
         * @param minVal Minimal value which can be generate.
         * @param maxVal Maximal value which can be generate.
         * Method which generate random values which are between minimal and maximal value.
         */
        void generateRandomValues(int nbValues, int minVal, int maxVal);
        /**
         * @brief Setter currentValues variable method
         * @param values New vector of shared_ptr<BarValueDouble> to set.
         * Setter method of currentValues variable.
         */
        void setValues(std::vector<std::shared_ptr<BarValueDouble>> values);
        /**
         * @brief Getter currentValues variable method
         * @return currentValues
         * Getter method of currentValues variable.
         */
        std::vector<std::shared_ptr<BarValueDouble>> getValues();
        /**
         * @brief Get the status if an algorithm is currently already running.
         * @return True = an algorithm is already running.
         * Getter method of the status variable solvingIsRunning.
         * It gives the info if an algorithm is already running.
         */
        bool getSolvingIsRunning();

    protected:
        std::vector<std::shared_ptr<BarValueDouble>> currentValues; // We'll use an vector for all our algorithms.
                                                                    // Of course, in some case an array would be faster.
                                                                    // But the purpose of this app is for watching the algorithm in live
                                                                    // and not to solve as fast as possible the sorting algorithm.
                                                                    // So we don't need to be more efficient and vector are more confortable to use.


        int resolveSpeedMs { 300 };
        int compareSpeedMs { 50 };
        /**
         * @brief Set the status to notify the class that an algorithm is already currently running or that it finished.
         * @param val Set true if an algorithm started to run. Set false if an algorithm finished to run.
         * Setter method of the status variable solvingIsRunning.
         */
        void setSolvingIsRunning(const bool& val);

    private:
        bool solvingIsRunning { false };

    signals:
        /**
         * @brief Signal/event insertion value
         * @param val Value that has been inserted.
         * @param index Index where the value has been inserted.
         * Signal/event to notify GUI that the algorithm inserted an value to an index.
         */
        void insertValueEvent(BarValueDouble* val, int index);
        /**
         * @brief Signal/event swap values.
         * @param val1 First value to swap.
         * @param val2 Second value to swap.
         * Signal/event to notify GUI that the algorithm swapped position of 2 values.
         */
        void swapValuesEvent(BarValueDouble* val1, BarValueDouble* val2);

        /**
         * @brief Signal/event whole GUI refresh.
         * Signal/event to notify GUI to refresh the whole graph with the current values.
         */
        void refreshAllEvent();

        /**
         * @brief Signal/event running started or finished.
         * @param val set to true if algorithm started to run, set to false if algorithm finished run.
         * Signal/event to notify GUI that algorithm started or finished.
         * It helps to disable buttons in the HMI.
         */
        void solvingIsRunningEvent(const bool& val);
};


#endif // ALGOSORTING_H
