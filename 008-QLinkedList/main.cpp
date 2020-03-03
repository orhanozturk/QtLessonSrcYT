#include <QLinkedList>
#include <QDebug>
#include <iostream>

int main()
{
    QLinkedList<int> llist;

    for (int i = 0; i < 10; ++i) {
            llist << i;
    }

    for (QLinkedList<int>::iterator iter = llist.begin(); iter != llist.end(); ++iter) {
        //qDebug() << *iter;
        std::cout << *iter;
    }

    std::cout << std::endl;

    /*******************************************/

    // toStdList

    std::list<int> stdList = llist.toStdList();

    for (std::list<int>::iterator iter = stdList.begin(); iter != stdList.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    /*******************************************/

    QLinkedList<int> llist1(llist);

    llist += llist1;

    for (QLinkedList<int>::iterator iter = llist.begin(); iter != llist.end(); ++iter) {
        //qDebug() << *iter;
        std::cout << *iter;
    }
    std::cout << std::endl;
    /*******************************************/

    if(llist == llist1)
        qDebug() << "equal";
    else
        qDebug() << "not equal";

    /*******************************************/

    QLinkedList<int> llist2(llist);
    if(llist == llist2)
        qDebug() << "equal";
    else
        qDebug() << "not equal";

    /*******************************************/

    //std::move

    QLinkedList<int> llist3(std::move(llist));

    if(llist == llist3)
        qDebug() << "equal";
    else
        qDebug() << "not equal";

    qDebug() << "size : " << llist.size();
    qDebug() << "size : " << llist3.size();
    /*******************************************/
    return 0;
}
