#include <QList>
#include <QDebug>
#include <QVector>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::lower_bound instead.

//Qt version > 5.0, you should not use Qt::qLowerBound and Qt::qUpperBound
//Qt version < 5.0, you should use Qt::qLowerBound and Qt::qUpperBound

//You should use STL Algorithm.

//The items in the range [begin, end) must be sorted in ascending order; see qSort().
int main()
{
    QList<int> list;
    list << 3 << 3 << 6 << 6 << 6 << 8;

    QList<int>::iterator i = qLowerBound(list.begin(), list.end(), 5);
    list.insert(i, 5);
    // list: [ 3, 3, 5, 6, 6, 6, 8 ]
    qDebug() << list;

    i = qLowerBound(list.begin(), list.end(), 12);
    list.insert(i, 12);
    // list: [ 3, 3, 5, 6, 6, 6, 8, 12 ]
    qDebug() << list;

    qDebug() << "*********************";

    QVector<int> vect;
    vect << 3 << 3 << 6 << 6 << 6 << 8;
    QVector<int>::iterator begin6 = qLowerBound(vect.begin(), vect.end(), 6);
    QVector<int>::iterator end6 = qUpperBound(vect.begin(), vect.end(), 6);

    qDebug() << "begin6: " << *begin6;
    qDebug() << "end6: " << *end6;
    qDebug() << "*********************";
    QVector<int>::iterator k = begin6;
    while (k != end6) {
        *k = 7;
        ++k;
    }
    // vect: [ 3, 3, 7, 7, 7, 8 ]
    qDebug() << vect;
    qDebug() << "*********************";

    return 0;
}
