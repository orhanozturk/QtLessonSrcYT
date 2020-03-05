#include "SignalA.hpp"
#include <QDebug>

SignalA::SignalA(QObject *parent) : QObject(parent)
{}

void SignalA::makeOperationSignal()
{
    int result = 0;

    result = emit onOperation(30, 10);
    qDebug() << "result : " << result;
}
