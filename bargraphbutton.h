#ifndef BARGRAPHBUTTON_H
#define BARGRAPHBUTTON_H

#include "QPushButton"
#include "barvaluedouble.h"
#include <memory>

/**
 * @brief The BarGraphButton class
 * Custom class of QPushButton which represent one value in our Bargraph.
 */
class BarGraphButton : public QPushButton
{
public:
    /**
     * @brief Class constructor
     * @param val
     * Class constructor which define the button's linked value.
     */
    BarGraphButton(std::shared_ptr<BarValueDouble>& val);

private:
    std::shared_ptr<BarValueDouble> val_;

public slots:
    /**
     * @brief Event handler of selected value
     * @param val True = selected --> red color
     * Event handler which is called when selected attribut has been changed in the linked value.
     * It changes the color of the button to red when the value is selected (=True).
     * It means that this bar value is selected to determine its position.
     */
    void selectedChangedHandler(const bool& val);
    /**
     * @brief Event handler of done value
     * @param val True = done --> gray color
     * Event handler which is called when done attribut has been changed in the linked value.
     * It changes the color of the button to gray when the value is done (=True).
     * It means that this bar value has its final position.
     */
    void doneChangedHandler(const bool& val);
    /**
     * @brief Event handler of compared value
     * @param val True = compared --> blue color
     * Event handler which is called when compared attribut has been changed in the linked value.
     * It changes the color of the button to blue when the value is compared (=True).
     * It means that this bar value is used to be compared with the selected value.
     */
    void comparedChangedHandler(const bool& val);

    /**
     * @brief Getter of val
     * @return Value shared pointer.
     * Getter of the value. It returns a shared_ptr to the linked value to this bar.
     */
    std::shared_ptr<BarValueDouble> val();
};

#endif // BARGRAPHBUTTON_H
