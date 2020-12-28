#include "testalgosortinginsertion.h"

TestAlgoSortingInsertion::TestAlgoSortingInsertion(QObject *parent) : QObject(parent)
{

}


void TestAlgoSortingInsertion::TestGenerateRandomValues()
{
    AlgoSortingInsertion<double> algoSorting;

    double nbValues { 10 };
    double minVal { 15 };
    double maxVal { 100 };

    algoSorting.GenerateRandomValues(nbValues, minVal, maxVal);

    QVERIFY(algoSorting.GetValues().size() == nbValues);

    for(const auto& val : algoSorting.GetValues())
        QVERIFY((val->data >= minVal) && (val->data <= maxVal));
}
