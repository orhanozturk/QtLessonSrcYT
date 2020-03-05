#include "Counter.hpp"
#include <QDebug>

/*
QMetaObject::Connection	connect(const QObject *sender, const char *signal, const QObject *receiver, const char *method, Qt::ConnectionType type = Qt::AutoConnection)
QMetaObject::Connection	connect(const QObject *sender, const QMetaMethod &signal, const QObject *receiver, const QMetaMethod &method, Qt::ConnectionType type = Qt::AutoConnection)
QMetaObject::Connection	connect(const QObject *sender, PointerToMemberFunction signal, const QObject *receiver, PointerToMemberFunction method, Qt::ConnectionType type = Qt::AutoConnection)
QMetaObject::Connection	connect(const QObject *sender, PointerToMemberFunction signal, Functor functor)
QMetaObject::Connection	connect(const QObject *sender, PointerToMemberFunction signal, const QObject *context, Functor functor, Qt::ConnectionType type = Qt::AutoConnection)
*/

/*
 *define SLOT(a)    "1"#a
 *define SIGNAL(a)    "2"#a
*/

//QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));


//QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
//QObject::connect(&a, SIGNAL(valueChanged(int)), &c, SLOT(setValue(int)));


//QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SIGNAL(setValue(int)));

int main()
{
      Counter a, b;
      QObject::connect(&a, SIGNAL(valueChanged(int)), &b, SLOT(setValue(int)));
      //QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);  --> Qt 5

      a.setValue(12);     // a.value() == 12, b.value() == 12
      qDebug() << " a: " << a.value();
      qDebug() << " b: " << b.value();

      b.setValue(48);     // a.value() == 12, b.value() == 48

      qDebug() << "************************";
      qDebug() << " a: " << a.value();
      qDebug() << " b: " << b.value();
      qDebug() << "************************";

      /**************************************************/
      QObject::connect(&a, SIGNAL(valueChangedXY(int, int, int)), &b, SLOT(setValueXY(int, int)));

      a.setValueXY(12, 34);
      qDebug() << "************************";
      qDebug() << " a.x: " << a.valueX();
      qDebug() << " a.y: " << a.valueY();
      qDebug() << "************************";

      qDebug() << "************************";
      qDebug() << " b.x: " << b.valueX();
      qDebug() << " b.y: " << b.valueY();
      qDebug() << "************************";


      b.setValueXY(45, 66);
      qDebug() << "************************";
      qDebug() << " a.x: " << a.valueX();
      qDebug() << " a.y: " << a.valueY();
      qDebug() << "************************";

      qDebug() << "************************";
      qDebug() << " b.x: " << b.valueX();
      qDebug() << " b.y: " << b.valueY();
      qDebug() << "************************";

      return 0;
}
