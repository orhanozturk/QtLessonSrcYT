#include <QList>
#include <QDebug>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::fill instead.

//Qt version > 5.0, you should not use Qt::qSort
//Qt version < 5.0, you should use Qt::qSort

//You should use STL Algorithm.

int main()
{

    QStringList list;
    list << "one" << "two" << "three";

    qFill(list.begin(), list.end(), "eleven");
    // list: [ "eleven", "eleven", "eleven" ]
    qDebug() << list;

    qFill(list.begin() + 1, list.end(), "six");
    // list: [ "eleven", "six", "six" ]
    qDebug() << list;

    return 0;
}
