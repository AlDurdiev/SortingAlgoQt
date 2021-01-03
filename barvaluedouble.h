#ifndef BARVALUEDOUBLE_H
#define BARVALUEDOUBLE_H

#include <QObject>

/**
 * @brief The BarValueDouble class
 * Class which contains datas and status of each value.
 */
class BarValueDouble : public QObject
{
    Q_OBJECT

protected:
    double data_ { 0 };
    bool isSelected_ { false };
    bool isCompared_ { false };
    bool isDone_ { false };

public:
    /**
     * @brief Constructor of this class
     * @param val Value linked to this object.
     * Constructor which define the value.
     */
    BarValueDouble(double val);

    /**
     * @brief data's getter
     * @return data's value
     */
    double data();
    /**
     * @brief isSelected's getter
     * @return true if this object is selected to determine its position.
     */
    bool isSelected();
    /**
     * @brief isDone's getter
     * @return true if this object is done (its position has been determined)
     */
    bool isDone();
    /**
     * @brief isCompared's getter
     * @return true if this object is currently being compared to the selected value.
     */
    bool isCompared();

    /**
     * @brief data's setter
     * @param val
     * data's setter which gives the possibility to change its value.
     */
    void setData(const double& val);

public slots:
    /**
     * @brief Handler selected status value
     * @param val Current selected status value
     * Handler which should be called when selected status value has been changed.
     */
    void setSelectedHandler(const bool& val);
    /**
     * @brief Handler done status value
     * @param val Current done status value
     * Handler which should be called when done status value has been changed.
     */
    void setDoneHandler(const bool& val);
    /**
     * @brief Handler compared status value
     * @param val Current compared status value
     * Handler which should be called when compared status value has been changed.
     */
    void setComparedHandler(const bool& val);

signals:
    /**
     * @brief Signal/event selected status value.
     * @param val Current selected status value.
     * Signal/event to notify GUI that an algorithm changed the status of this object
     * to selected or unselected.
     */
    void selectedChangedEvent(const bool& val);
    /**
     * @brief Signal/event done status value.
     * @param val Current done status value.
     * Signal/event to notify GUI that an algorithm changed the status of this object
     * to done.
     */
    void doneChangedEvent(const bool& val);
    /**
     * @brief Signal/event compared status value.
     * @param val Current compared status value.
     * Signal/event to notify GUI that an algorithm changed the status of this object
     * to compared.
     */
    void comparedChangedEvent(const bool& val);
};

#endif // BARVALUEDOUBLE_H
