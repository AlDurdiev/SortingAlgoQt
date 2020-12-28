#ifndef BARVALUE_H
#define BARVALUE_H

template<typename T>
struct BarValue
{
    BarValue(T val) : data(val)
    { }

    T data;
    bool selected;
    bool done;
};

#endif // BARVALUE_H
