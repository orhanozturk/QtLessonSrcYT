#include <QVector>
#include <QList>
#include <QLinkedList>
#include <QString>
#include <QDebug>

//STL tarzı yenileyiciler
//1. C<T>::iterator  --> read-write
//2. C<T>::const_iterator --> read_only



// begin() --> list[0]
// end()  --> list[5]
// 0 - 1 - 2 - 3 - 4 - 5

// Bir konteynar boş ise --> begin() == end()
// isEmpty()

//Sonraki ögeye geçmek için ++
//Önceki Öğeye geçmek için --
//Geçerli bir öğeye erişmek içinde unary (*)

int main()
{
    QList<QString> list;
    list << "A" << "B" << "C" << "D";

    {
        QList<QString>::iterator i;

        for (i = list.begin(); i != list.end(); ++i) {
            qDebug() << " " << *i;

        }

        qDebug() << "*************************************";

        for (i = list.begin(); i != list.end(); ++i) {
            *i = (*i).toLower();
        }

        for (i = list.begin(); i != list.end(); ++i) {
            qDebug() << " " << *i;
        }
        qDebug() << "*************************************";
    }

    list << "E";
    {
        QList<QString>::iterator i = list.end();
        while(i != list.begin()){
            --i;
            *i = (*i).toLower();
        }

        QList<QString>::const_iterator k;
        for (k = list.constBegin(); k != list.constEnd(); ++k) {
            qDebug() << " " << *k;
        }
        qDebug() << "*************************************";
    }

    QList<int> list1;

    for (int i = 0; i < 10; ++i) {
        if(i % 2 == 0)
            list1.append(-i);
        list1.append(i);
    }

    list1 << -3 << -6 << 8;
    {
        QList<int>::iterator i;

        for (i = list1.begin(); i != list1.end(); ++i) {
            qDebug() << " " << *i;
        }
        qDebug() << "*************************************";

        i = list1.begin();
        while (i != list1.end()) {
            *i = qAbs(*i);
            ++i;
        }

        for (i = list1.begin(); i != list1.end(); ++i) {
            qDebug() << " " << *i;
        }
        qDebug() << "*************************************";

    }

    {
        QList<QString>::reverse_iterator i;

        for (i = list.rbegin(); i != list.rend(); ++i) {
            *i = i->toLower();
        }


        QList<QString>::const_reverse_iterator k;
        for (k = list.crbegin(); k != list.crend(); ++k) {
            qDebug() << " " << *k;
        }
        qDebug() << "*************************************";
    }


    return 0;
}
