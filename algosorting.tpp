
namespace AlgoSorting {
    template <typename T>
    AlgoSorting<T>::AlgoSorting()
    {
    }

    template <typename T>
    void AlgoSorting<T>::GenerateRandomValues(int nbValues, int minVal, int maxVal)
    {
        initialValues.clear();

        T val { 0 };
        for(int i=0 ; i < nbValues ; i++)
        {
            val = std::rand() % (maxVal - minVal + 1) + minVal;
            auto barVal { std::make_shared<BarValue<T>>(val) };
            initialValues.push_back(barVal);
            currentValues.push_back(barVal);
        }
    }

    template <typename T>
    void AlgoSorting<T>::SetValues(std::vector<std::shared_ptr<BarValue<T>>> values)
    {
        initialValues = values;
        currentValues = values;
    }

    template <typename T>
    void AlgoSorting<T>::Reset()
    {

    }

    template <typename T>
    void AlgoSorting<T>::Pause()
    {

    }

    template <typename T>
    void AlgoSorting<T>::NextStep()
    {

    }

    template <typename T>
    void AlgoSorting<T>::PreviousStep()
    {

    }

    template <typename T>
    std::vector<std::shared_ptr<BarValue<T>>> AlgoSorting<T>::GetValues()
    {
        return currentValues;
    }

}

