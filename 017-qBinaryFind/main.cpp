#include <QVector>
#include <QDebug>

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::binary_search or std::lower_bound instead.

//Qt version > 5.0, you should not use Qt::qBinaryFind
//Qt version < 5.0, you should use Qt::qBinaryFind

//You should use STL Algorithm.

int main()
{

    QVector<int> vect;
    vect << 3 << 3 << 6 << 6 << 6 << 8;

    QVector<int>::iterator i = qBinaryFind(vect.begin(), vect.end(), 6);
    qDebug() << *i;

    vect.clear();
    vect << 3 << 3 << 5 << 6 << 7 << 8;
    i = qBinaryFind(vect.begin(), vect.end(), 6);
    qDebug() << *i;

    vect.clear();
    vect << 3 << 9 << 5 << 6 << 7 << 8;
    i = qBinaryFind(vect.begin(), vect.end(), 6);
    qDebug() << *i;

    qSort(vect.begin(), vect.end());
    i = qBinaryFind(vect.begin(), vect.end(), 11);
    qDebug() << *i;

    return 0;
}
