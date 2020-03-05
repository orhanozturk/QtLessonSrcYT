#ifndef COUNTER_HPP
#define COUNTER_HPP

/*
 * Note:
 *
 *
 * MOC --> Meta Object Compiler
 *
 * define signals protected     --> Qt 5 <  --> old defination
 *
 * define signals public        --> Qt 5 >  --> new defination
 *
 * define slots
 *
 */


#include <QObject>
#include <QPoint>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter() { m_value = m_x = m_y =0; }

    int value() const { return m_value; }
    int valueX() const { return m_x; }
    int valueY() const { return m_y; }

public slots:
    void setValue(int value);
    void setValueXY(int x, int y);

signals:
    void valueChanged(int newValue);
    void valueChangedXY(int x, int y, int z);

private:
    int m_value;
    int m_x, m_y;
};

#endif // COUNTER_HPP
