#ifndef BARGRAPHBUTTON_H
#define BARGRAPHBUTTON_H

#include "QPushButton"
#include "barvaluedouble.h"
#include <memory>

template <typename T>
class BarGraphButton : public QPushButton
{
public:
    BarGraphButton(std::shared_ptr<BarValueDouble>& val)
        : val_(val)
    {
        QObject::connect(&(*val_), &BarValueDouble::valueSelectedChanged,
                         this, &BarGraphButton::SelectedChanged);
    }

private:
    std::shared_ptr<BarValueDouble> val_;

public slots:
    void SelectedChanged(const bool& val)
    {
        if(val)
        {
            this->setStyleSheet("QPushButton { background-color: red; }\n");
        }
        else
        {
            this->setStyleSheet("QPushButton { background-color: grey; }\n");
        }
    }

    std::shared_ptr<BarValueDouble> Val()
    {
        return val_;
    }
};

#endif // BARGRAPHBUTTON_H
