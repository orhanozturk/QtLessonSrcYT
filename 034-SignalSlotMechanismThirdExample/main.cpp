#include <QCoreApplication>
#include "AObject.hpp"
#include "BObject.hpp"
#include <QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    auto a = new AObject;
    auto b = new BObject;

    //QObject::connect(a, SIGNAL(signalFunction(QString)), b, SLOT(recieveBObject(QString))); // String method
    //QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject); //Function adress method
    //QObject::connect(a, &AObject::signalFunction, [&](const QString & msg){qInfo() << " message for a lambda : " << msg;}); // Lambda method


    //a->signalFunction("Hiii");

    /*
    //Disconnect everything connected to an object's signals:
    QObject::disconnect(a, 0, 0, 0);
    //equivalent to the non-static overloaded function
    a->disconnect();

    //Disconnect everything connected to a specific signal:
    QObject::disconnect(a, SIGNAL(signalFunction()), 0, 0);
    //equivalent to the non-static overloaded function
    a->disconnect(SIGNAL(signalFunction()));

    //Disconnect a specific receiver:
    QObject::disconnect(a, 0, b, 0);
    //equivalent to the non-static overloaded function
    a->disconnect(b);

    QObject::disconnect(a, SIGNAL(signalFunction(QString)), b, SLOT(recieveBObject(QString)));
    */


    /*
    QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject , Qt::QueuedConnection); //Function adress method
    a->signalFunction("Hiii");
    */


    // Each Example is executed individually
    // Example 1
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject);
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject);
    // prints:
    // true
    // true
    qInfo() << "********************************";

    // Example 2
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));
    // prints:
    // true
    // false

    qInfo() << "********************************";

    // Example 3
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject);
    // prints:
    // true
    // true

    qInfo() << "********************************";

    // Example 4
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject);
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));
    // prints:
    // true
    // false
    qInfo() << "********************************";

    // Example 5 (Different connection types)
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection));
    //qDebug() <<QObject::connect(a, &AObject::signalFunction, b, &BObject::recieveBObject, static_cast<Qt::ConnectionType>(Qt::DirectConnection | Qt::UniqueConnection));
    // prints:
    // true
    // false

    return app.exec();
}
