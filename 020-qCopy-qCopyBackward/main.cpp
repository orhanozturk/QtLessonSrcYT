#include <QList>
#include <QDebug>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::copy instead.
//Use std::copy_backward instead.

//Qt version > 5.0, you should not use Qt::qCopy and Qt::qCopyBackward
//Qt version < 5.0, you should use Qt::qCopy and Qt::qCopyBackward

//You should use STL Algorithm.

int main()
{
    QStringList list;
    list << "one" << "two" << "three";

    QVector<QString> vect1(3);
    qCopy(list.begin(), list.end(), vect1.begin());
    // vect: [ "one", "two", "three" ]
    qDebug() << vect1;

    QVector<QString> vect2(8);
    qCopy(list.begin(), list.end(), vect2.begin() + 2);
    // vect: [ "", "", "one", "two", "three", "", "", "" ]
    qDebug() << vect2;

    QVector<QString> vect3(5);
    qCopyBackward(list.begin(), list.end(), vect3.end() - 1);
    // vect: [ "", "", "one", "two", "three" ]
    qDebug() << vect3;

    return 0;
}
