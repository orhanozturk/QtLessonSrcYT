#include <QList>
#include <QDebug>
#include <iostream>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::stable_sort instead.

//Qt version > 5.0, you should not use Qt::qStableSort
//Qt version < 5.0, you should use Qt::qStableSort

//You should use STL Algorithm.


bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}

int main()
{
    {
        QList<int> list;
        list << 33 << 12 << 6 << 6 << 12;
        qDebug() << list;
        qStableSort(list.begin(), list.end());
        // list: [ 6, 12, 12, 33, 68 ]
        qDebug() << list;

        qDebug() << "**********************";

        for (QList<int>::iterator i = list.begin(); i != list.end(); ++i) {
            std::cout << *i << ", ";
        }

        std::cout << "\n";
    }

    qDebug() << "**********************";
    {
        //QList<QString>
        QStringList list;
        list << "AlPha" << "beTA" << "gamma" << "DELTA";
        qDebug() << list;
        qStableSort(list.begin(), list.end(), caseInsensitiveLessThan);
        //qStableSort(list.begin(), list.end(), qLess<QString>());
        // list: [ "AlPha", "beTA", "DELTA", "gamma" ]
        qDebug() << list;
    }

    qDebug() << "**********************";
    {
        QList<int> list;
        list << 33 << 12 << 68 << 6 << 12;
        qDebug() << list;
        qStableSort(list.begin(), list.end(), qGreater<int>());
        // list: [ 68, 33, 12, 12, 6 ]
        qDebug() << list;
        //qStableSort(list.begin(), list.end(), qLess<int>());
    }
    qDebug() << "**********************";

    return 0;
}
