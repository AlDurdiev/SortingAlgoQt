#ifndef TESTALGOSORTING_H
#define TESTALGOSORTING_H

#include <QObject>

class TestAlgoSorting : public QObject
{
    Q_OBJECT
public:
    explicit TestAlgoSorting(QObject *parent = nullptr);

    signals:

private slots:
    void TestGenerateRandomValues();

};

#endif // TESTALGOSORTING_H
