#ifndef BARGRAPHBUTTON_CPP
#define BARGRAPHBUTTON_CPP

#include "bargraphbutton.h"


BarGraphButton::BarGraphButton(std::shared_ptr<BarValueDouble>& val)
    : val_(val)
{
    QObject::connect(&(*val_), &BarValueDouble::selectedChangedEvent,
                     this, &BarGraphButton::selectedChangedHandler);

    QObject::connect(&(*val_), &BarValueDouble::doneChangedEvent,
                     this, &BarGraphButton::doneChangedHandler);

    QObject::connect(&(*val_), &BarValueDouble::comparedChangedEvent,
                     this, &BarGraphButton::comparedChangedHandler);
}


void BarGraphButton::selectedChangedHandler(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: red; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

void BarGraphButton::doneChangedHandler(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: grey; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

void BarGraphButton::comparedChangedHandler(const bool& val)
{
    if(val)
        this->setStyleSheet("QPushButton { background-color: blue; }\n");
    else
        this->setStyleSheet("QPushButton { background-color: white; }\n");
}

std::shared_ptr<BarValueDouble> BarGraphButton::val()
{
    return val_;
}

#endif
