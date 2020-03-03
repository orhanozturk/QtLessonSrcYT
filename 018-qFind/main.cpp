#include <QList>
#include <QDebug>


//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::find instead.

//Qt version > 5.0, you should not use Qt::qFind
//Qt version < 5.0, you should use Qt::qFind

//You should use STL Algorithm.
//If the items in the range are in ascending order, you can get faster results by using qLowerBound() or qBinaryFind() instead of qFind(
int main()
{
    //QList<QStirng>
    QStringList list;
    list << "one" << "two" << "three";

    QStringList::iterator i1 = qFind(list.begin(), list.end(), "two");
    // i1 == list.begin() + 1
    qDebug() << *i1;

    qDebug() << "********************";
    //QStringList::iterator i2 = qFind(list.begin(), list.end(), "seventy");
    // i2 == list.end()
    //qDebug() << *i2;

    qDebug() << "********************";

    QList<int> list1;
    list1 << 33 << 12 << 6 << 6 << 12 << 45 << 13;

    QList<int>::iterator k = qFind(list1.begin(), list1.end(), 45);
    qDebug() << *k;

    return 0;
}
