#include <QList>
#include <QDebug>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::swap instead.

//Qt version > 5.0, you should not use Qt::qSwap
//Qt version < 5.0, you should use Qt::qSwap

//You should use STL Algorithm.

int main()
{

    double pi = 3.14;
    double e = 2.71;

    qSwap(pi, e);
    qDebug() << "pi : " << pi;
    qDebug() << "e : " << e;

    qDebug() << "*****************";

    QList<int> list1;
    list1 << 22 << 12 << 56 << 3 << 7;
    qDebug() << "list1 : " << list1;

    QList<int> list2;
    list2 << 88 << 2 << 6 << 35 << 73;
    qDebug() << "list2 : " << list2;
    qDebug() << "*****************";

    qSwap(list1, list2);
    qDebug() << "list1 : " << list1;
    qDebug() << "list2 : " << list2;
    qDebug() << "*****************";

    return 0;
}
