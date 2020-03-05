#include "MyObject.hpp"
#include <QDebug>

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::mySlot(QString &str)
{
    qInfo() << "mySlot String : " << str;
}

void MyObject::mySlot(int integer)
{
    qInfo() << "mySlot integer : " << integer;
}
