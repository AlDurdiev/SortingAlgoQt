#ifndef BARGRAPHBUTTON_CPP
#define BARGRAPHBUTTON_CPP

#include "bargraphbutton.h"


BarGraphButton::BarGraphButton(std::shared_ptr<BarValueDouble>& val)
    : val_(val)
{
    QObject::connect(&(*val_), &BarValueDouble::valueSelectedChanged,
                     this, &BarGraphButton::SelectedChanged);

    QObject::connect(&(*val_), &BarValueDouble::valueDoneChanged,
                     this, &BarGraphButton::DoneChanged);

    QObject::connect(&(*val_), &BarValueDouble::valueComparedChanged,
                     this, &BarGraphButton::ComparedChanged);
}


void BarGraphButton::SelectedChanged(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: red; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

void BarGraphButton::DoneChanged(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: grey; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

void BarGraphButton::ComparedChanged(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: blue; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

std::shared_ptr<BarValueDouble> BarGraphButton::Val()
{
    return val_;
}

#endif
