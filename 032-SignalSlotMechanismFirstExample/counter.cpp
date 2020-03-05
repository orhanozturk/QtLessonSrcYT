#include "counter.hpp"

//define emit

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);  // --> Signal
    }
}

void Counter::setValueXY(int x, int y)
{
        m_x = x;
        m_y = y;
        emit valueChangedXY(x, y, 0);
}
