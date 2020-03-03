#include <QVector>
#include <QLinkedList>
#include <QList>
#include <QDebug>

//#include <QMutableVectorIterator>

/*
#include <QVectorIterator>
#include <QListIterator>
#include <QLinkedListIterator>
*/

//Java tarzı yenileyiciler ikiye ayrılır
//1. read-only --> QVectorIterator<T>, QListIterator<T> ve QLinkedListIterator<T>
//2. read-write --> QMutableVectorIterator<T>, QMutableListIterator<T> ve QMutableLinkedListIterator<T>

int main()
{
    /***********************************************/

    qDebug() << "******* QVectorIterators **************";

    QVector<int> vector;

    for (int i = 0; i < 10; ++i) {
        vector.append(i);
    }

    {
        QVectorIterator<int> i(vector);
        while(i.hasNext())
            qDebug() <<" " << i.next();
        qDebug() << "******************************************";
    }

    {
        QVectorIterator<int> i(vector);
        i.toBack();
        while(i.hasPrevious())
            qDebug() << " " << i.previous();
        qDebug() << "******************************************";

    }

    {
        QMutableVectorIterator<int> i(vector);
        while(i.hasNext())
            qDebug() <<" " << i.next();
        qDebug() << "******************************************";

    }

    vector << -2 << -3 << 0 << -10 << 0 << 15 << 22;

    {
        QMutableVectorIterator<int> i(vector);
        while(i.hasNext()){
            int val = i.next();
            if(val < 0)
                i.setValue(-val);
            else if(val == 0){
                i.remove();
            }
        }

        QMutableVectorIterator<int> k(vector);
        while(k.hasNext())
            qDebug() <<" " << k.next();
        qDebug() << "******************************************";
    }

    {
        QMutableVectorIterator<int> i(vector);

        if(i.findNext(5))
            i.insert(44);

        QMutableVectorIterator<int> k(vector);
        while(k.hasNext())
            qDebug() <<" " << k.next();
        qDebug() << "******************************************";
    }

    {
        QVectorIterator<int> i(vector);
        QVectorIterator<int> k = i;

        while(k.hasNext())
            qDebug() <<" " << k.next();
        qDebug() << "******************************************";

    }

    /***********************************************/

    qDebug() << "******* QLinkedListIterators **************";

    QLinkedList<int> llist;

    for (int i = 0; i < 10; ++i) {
        llist.append(i);
    }

    {
        QLinkedListIterator<int> i(llist);
        while(i.hasNext())
            qDebug() <<" " << i.next();
        qDebug() << "******************************************";
    }

    {
        QMutableLinkedListIterator<int> i(llist);
        while(i.hasNext()){
            int val = i.next();
            if(val % 2 == 0)
                i.setValue(0);
        }

        QLinkedListIterator<int> k(llist);
        while(k.hasNext())
            qDebug() <<" " << k.next();
        qDebug() << "******************************************";
    }

    /***********************************************/

    qDebug() << "******* QListIterators **************";

    QList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.append(i);
    }

    {
        QListIterator<int> i(list);
        while(i.hasNext())
            qDebug() <<" " << i.next();
        qDebug() << "******************************************";
    }

    {
        QMutableListIterator<int> i(list);
        while(i.hasNext()){
            int val = i.next();
            if(val % 2 == 0)
                i.setValue(0);
        }

        QMutableListIterator<int> k(list);
        while(k.hasNext())
            qDebug() <<" " << k.next();
        qDebug() << "******************************************";
    }


    return 0;
}
