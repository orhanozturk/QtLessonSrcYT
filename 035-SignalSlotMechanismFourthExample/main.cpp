#include <QCoreApplication>
#include "MyObject.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // using pointers to make connect calls just a little simpler
    auto a = new MyObject;
    auto b = new MyObject;

    // COMPILE ERROR! the compiler does not know which overloads to pick :(
    //QObject::connect(a, &MyObject::mySignal, b, &MyObject::mySlot);

    // this works, now the compiler knows which overload to pick, it is very ugly and hard to remember though...
    /*
    QObject::connect(a,
                     static_cast<void(MyObject::*)(int)>(&MyObject::mySignal),
                     b,
                     static_cast<void(MyObject::*)(int)>(&MyObject::mySlot)
                     );

    a->mySignal(10);
    */

    // this is slightly longer, but works in C++11:
    QObject::connect(
                     a,
                     QOverload<int>::of(&MyObject::mySignal),
                     b,
                     QOverload<int>::of(&MyObject::mySlot)
                     );

    a->mySignal(10);

    // ...so starting in Qt 5.7 we can use qOverload and friends:
    // this requires C++14 enabled:
    /*
    QObject::connect(
                     a,
                     QOverload<int>(&MyObject::mySignal),
                     b,
                     QOverload<int>(&MyObject::mySlot));

    a->mySignal(10);
    */
    return app.exec();
}
