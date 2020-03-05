#include <QObject>
#include "SignalA.hpp"
#include "SlotA.hpp"
#include <QDebug>

int main()
{
    SignalA sigA;
    SlotA slotA;

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(add(int, int)));
    sigA.makeOperationSignal();

    qDebug() << "*************************************";

    //QObject::disconnect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(add(int, int)));
    //sigA.makeOperationSignal();

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(div(int, int)));
    sigA.makeOperationSignal();

    qDebug() << "*************************************";

    QObject::connect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(mul(int, int)));
    sigA.makeOperationSignal();

    qDebug() << "*************************************";

    QObject::disconnect(&sigA, SIGNAL(onOperation(int, int)), &slotA, SLOT(mul(int, int)));
    sigA.makeOperationSignal();

    qDebug() << "*************************************";


    return 0;
}
