#include <QStringList>
#include <QVector>
#include <QDebug>


//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::equal instead.

//Qt version > 5.0, you should not use Qt::qSort
//Qt version < 5.0, you should use Qt::qSort

//You should use STL Algorithm.

int main()
{
    QStringList list;
    list << "one" << "two" << "three";

    QVector<QString> vect(3);
    vect[0] = "one";
    vect[1] = "two";
    vect[2] = "three";

    bool ret1 = qEqual(list.begin(), list.end(), vect.begin());
    // ret1 == true
    qDebug() << ret1;


    vect[2] = "seven";
    bool ret2 = qEqual(list.begin(), list.end(), vect.begin());
    // ret2 == false
    qDebug() << ret2;

    return 0;
}
