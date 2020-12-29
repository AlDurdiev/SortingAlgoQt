#ifndef BARVALUEDOUBLE_H
#define BARVALUEDOUBLE_H

#include <QObject>

class BarValueDouble : public QObject
{
    Q_OBJECT

protected:
    double data;
    bool selected;
    bool done;

public:
    BarValueDouble(double val);

    double Data();
    bool Selected();
    bool Done();

    void SetData(const double& val);

public slots:
    void SetSelected(const bool& val);
    void SetDone(const bool& val);

signals:
    void valueSelectedChanged(const bool& val);
    void valueDoneChanged(const bool& val);
};

#endif // BARVALUEDOUBLE_H
