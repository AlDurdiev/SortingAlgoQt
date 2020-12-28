#ifndef TESTALGOSORTINGINSERTION_H
#define TESTALGOSORTINGINSERTION_H

#include <QObject>
#include <QtTest/QtTest>
#include "algosortinginsertion.h"

class TestAlgoSortingInsertion : public QObject
{
    Q_OBJECT
public:
    explicit TestAlgoSortingInsertion(QObject *parent = nullptr);

signals:

private slots:
    void TestGenerateRandomValues();
};

#endif // TESTALGOSORTINGINSERTION_H
