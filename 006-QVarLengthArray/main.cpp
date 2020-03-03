#include <QVarLengthArray>
#include <QDebug>
#include <iostream>


/*
int myfunc(int n)
{
    int table[n + 1];  // WRONG
    return table[n];
}

int myfunc1(int n)
{
    int *table = new int[n + 1];

    int ret = table[n];
    delete[] table;
    return ret;
}

*/

void myfunc2(int n)
{
    QVarLengthArray<int, 1024> array(n + 1);


    qDebug() << " size : " << array.size();
    qDebug() << " capacity : " << array.capacity();

    //return array[n];
}


/*
QVarLengthArray(std::initializer_list<T> args)
QVarLengthArray(const QVarLengthArray<T, Prealloc> &other = ...)
QVarLengthArray(int size = 0)
 */
int main()
{
    //size
    //capacity
    {
        QVarLengthArray<int> array;

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        array << 10 << 20 << 30 << 40;

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();


        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";
        qDebug() << "*****************************************";
    }

    //append
    {
       QVarLengthArray<int, 1000> array;

       for (int i = 0; i < 10; ++i) {
            array.append(i);
       }

       for(auto it = array.cbegin(); it != array.end(); ++it)
           std::cout << *it << " ";
       std::cout << "\n";

       qDebug() << " size : " << array.size();
       qDebug() << " capacity : " << array.capacity();
       qDebug() << "*****************************************";

    }

    //prepend
    {
        QVarLengthArray<int, 1000> array;

        for (int i = 0; i < 10; ++i) {
             array.prepend(i);
        }

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();
        qDebug() << "*****************************************";

    }

    //push_back
    //pop_back
    {
        QVarLengthArray<int, 1000> array;

        for (int i = 0; i < 10; ++i) {
             array.push_back(i);
        }

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";


        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        array.pop_back();

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";


        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        qDebug() << "*****************************************";
    }

    {
        myfunc2(2000);
        qDebug() << "*****************************************";
    }

    //resize
    //reserve
    //squeeze
    //shrink_to_fit
    {
        QVarLengthArray<int, 100> array;

        for (int i = 0; i < 10; ++i) {
             array.push_back(i);
        }

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        array.resize(5);
        array.reserve(500);
        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();


        array.shrink_to_fit();
        //array.squeeze();

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        qDebug() << "*****************************************";
    }


    //indexOf
    //lastIndexOf
    //isEmpty
    //first
    //last
    //data
    //erase
    {
        QVarLengthArray<int, 100> array;

        for (int i = 0; i < 10; ++i) {
             array.prepend(i);
        }

        array << 1 << 1 << 2 << 3 << 3 << 4;

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();

        qDebug() << " isEmpty : " << array.isEmpty();
        qDebug() << "indexOf : " << array.indexOf(3);
        qDebug() << "lastIndexOf : " << array.lastIndexOf(3);

        qDebug() << "first : " << array.first();
        qDebug() << "last : " << array.last();

        int *tempArray = array.data();

        std::cout << "*tempArray : " << *tempArray << "\n";

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        array.erase(array.begin() + 2, array.begin() + 5);

        for(auto it = array.cbegin(); it != array.end(); ++it)
            std::cout << *it << " ";
        std::cout << "\n";

        array.squeeze();
        qDebug() << " size : " << array.size();
        qDebug() << " capacity : " << array.capacity();
        qDebug() << "*****************************************";
    }

    return 0;
}
