#include <QList>
#include <QDebug>

//Attemtion!
//Warning!

//This function is obsolete. It is provided to keep old source code working. We strongly advise against using it in new code.

//Use std::count instead.

//Qt version > 5.0, you should not use Qt::qCount
//Qt version < 5.0, you should use Qt::qCount

//You should use STL Algorithm.

int main()
{
    QList<int> list;
    list << 3 << 3 << 6 << 6 << 6 << 8;

    int countOf6 = 0;
    qCount(list.begin(), list.end(), 6, countOf6);
    // countOf6 == 3
    qDebug() << countOf6;

    int countOf7 = 0;
    qCount(list.begin(), list.end(), 7, countOf7);
    // countOf7 == 0
    qDebug() << countOf7;

    return 0;
}
