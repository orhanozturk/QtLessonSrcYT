#include "BObject.hpp"
#include <QDebug>

BObject::BObject(QObject *parent) : QObject(parent)
{

}

void BObject::recieveBObject(QString param)
{
    qInfo() << " Reciever side : " << param;
}
