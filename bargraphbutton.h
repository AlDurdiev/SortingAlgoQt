#ifndef BARGRAPHBUTTON_H
#define BARGRAPHBUTTON_H

#include "QPushButton"
#include "barvaluedouble.h"
#include <memory>

class BarGraphButton : public QPushButton
{
public:
    BarGraphButton(std::shared_ptr<BarValueDouble>& val);

private:
    std::shared_ptr<BarValueDouble> val_;

public slots:
    void SelectedChanged(const bool& val);
    void DoneChanged(const bool& val);
    void ComparedChanged(const bool& val);
    std::shared_ptr<BarValueDouble> Val();
};

#endif // BARGRAPHBUTTON_H
