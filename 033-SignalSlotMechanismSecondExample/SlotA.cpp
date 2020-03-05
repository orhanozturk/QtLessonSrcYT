#include "SlotA.hpp"
#include <QDebug>

SlotA::SlotA(QObject *parent) : QObject(parent)
{}

int SlotA::add(int a, int b)
{
    qDebug() << "SlotA::add";
    return  a + b;
}

int SlotA::div(int a, int b)
{
    qDebug() << "SlotA::div";
    return  a / b;
}

int SlotA::mul(int a, int b)
{
    qDebug() << "SlotA::mul";
    return  a * b;
}
