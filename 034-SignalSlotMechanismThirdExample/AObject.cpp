#include "AObject.hpp"
#include <QDebug>

AObject::AObject(QObject *parent) : QObject(parent)
{

}

void AObject::slotFunction(QString param)
{
    qInfo() << "slotQString AObject : " << param;
}


