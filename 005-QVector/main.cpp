#include <QVector>
#include <QDebug>
#include <iostream>
#include <QList>


/*
QVector(std::initializer_list<T> args)
QVector(QVector<T> &&other)
QVector(const QVector<T> &other)
QVector(int size, const T &value)
QVector(int size)
QVector()
*/

int main()
{
    //ctor
    {
        QVector<QString> vector(10, "Orhan");
        qDebug() << vector;
        QVector<QString> vector1(10);
        qDebug() << vector1;
        qDebug() << "***********************************";

        QVector<int> vector3(10, 2);
        qDebug() << vector3;
        qDebug() << "***********************************";
        QVector<int> vector4(std::move(vector3));
        qDebug() << "vector3 : " << vector3;
        qDebug() << "vector4 : " << vector4;
        qDebug() << "***********************************";

    }

    //move
    //append
    {
        QVector<int> vect;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        qDebug() << "vect : " << vect;

        vect.move(4,8);

        qDebug() << "vect : " << vect;
        qDebug() << "***********************************";
    }

    //at
    //[]
    {
        QVector<int> vect;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        for(int i = 0; i < vect.size(); ++i)
            std::cout << vect.at(i) << " ";
            std::cout << "\n";

        for(int i = 0; i < vect.size(); ++i)
            std::cout << vect[i] << " ";
            std::cout << "\n";

        qDebug() << "***********************************";
    }

    //<<
    {
         QVector<int> vect;

         for(int i = 0; i < 10; ++i)
             vect.append(i);

         vect << 10 << 20 << 30;

         qDebug() << vect;
         qDebug() << "***********************************";
    }

    // random access iterator
    {
        QVector<int> vect;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        vect << 10 << 20 << 30;

        for(QVector<int>::iterator it = vect.begin(); it != vect.end(); ++it)
            std::cout << *it << " ";

        std::cout << std::endl;
        qDebug() << "***********************************";
    }


    {
        QVector<int> vect;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        for(int x : vect)
            std::cout << x << " ";
        std::cout << std::endl;

        qDebug() << "***********************************";
    }

    //foreach
    {
        QVector<int> vect;
        int var;

        vect << 10 << 20 << 30 << 40 << 50 << 60 << 70;


        foreach (var, vect)
            std::cout << var << " ";
        std::cout << std::endl;
        qDebug() << "***********************************";
    }

    //push_back
    //rbegin
    //rend
    //begin
    //end
    //reverse_iterator
    //crbegin
    //crend
    //auto
    {
        QVector<int> vect;

        vect.push_back(10);
        vect.push_back(20);
        vect.push_back(30);
        vect.push_back(40);
        vect.push_back(50);


        for (auto it = vect.rbegin(); it != vect.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        for (std::reverse_iterator<int*> it = vect.rbegin(); it != vect.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        for (QVector<int>::reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;


        qDebug() << "***********************************";


        for (auto it = vect.crbegin(); it != vect.crend(); ++it)
            std::cout << *it  << " ";
        std::cout << std::endl;

        for (const int* it = vect.cbegin(); it != vect.cend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        for (QVector<int>::const_iterator it = vect.cbegin(); it != vect.cend(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        qDebug() << "***********************************";

        for(int x : vect)
            std::cout << x << " ";
        std::cout << std::endl;
        qDebug() << "***********************************";
    }

    //empty
    //isEmpty
    //clear
    {
        QVector<int> vect;

        vect << 10 << 20 << 30 << 40 << 50 << 60 << 70;

        qDebug() << vect;
        qDebug() << "empty : " << vect.empty();
        qDebug() << "isEmpty : " << vect.isEmpty();
        vect.clear();
        qDebug() << "empty : " << vect.empty();
        qDebug() << "isEmpty : " << vect.isEmpty();
        qDebug() << "***********************************";

    }

    //erase
    {
        QVector<int> vect;

        vect << 10 << 20 << 30 << 40 << 50 << 60 << 70;
        qDebug() << "vect : " << vect;
        vect.erase(vect.begin() + 3);
        qDebug() << "vect : " << vect;

        vect.erase(vect.begin() + 2, vect.begin() + 4);
        qDebug() << "vect : " << vect;
        qDebug() << "***********************************";
    }

    //first
    //front
    //last
    {
        QVector<int> vect;

        vect << 10 << 20 << 30 << 40 << 50 << 60 << 70;

        qDebug() << "vect frist: " << vect.first();
        qDebug() << "vect front: " << vect.front();
        qDebug() << "vect last: " << vect.last();
        qDebug() << "***********************************";
    }

    // indexOf lastIndexOf
    {
        QVector<QString> vect;
        vect << "A" << "B" << "C" << "B" << "C" << "C" << "A";
        qDebug() << vect;

        qDebug() << vect.indexOf("C");
        qDebug() << vect.indexOf("C", 1);
        qDebug() << vect.indexOf("C", 2);
        qDebug() << vect.indexOf("C", 3);
        qDebug() << vect.indexOf("C", 4);
        qDebug() << vect.indexOf("C", 5);
        qDebug() << vect.indexOf("Z");

        qDebug() << "***********************************";

        qDebug() << vect.lastIndexOf("C");
        qDebug() << vect.lastIndexOf("C", 6);
        qDebug() << vect.lastIndexOf("C", 5);
        qDebug() << vect.lastIndexOf("C", 4);
        qDebug() << vect.lastIndexOf("C", 3);
        qDebug() << vect.lastIndexOf("C", 2);
        qDebug() << vect.lastIndexOf("C", 1);
        qDebug() << vect.lastIndexOf("Z");

        qDebug() << "***********************************";
    }

    //removeAt
    {
        QVector<int> vect;

        vect << 10 << 20 << 30 << 40 << 50 << 60 << 70;
        qDebug() << vect;
        vect.removeAt(4);
        qDebug() << vect;


        QVector<QString> vectString;
        vectString << "A" << "B" << "C" << "B" << "C" << "C" << "A";
        qDebug() << vectString;
        vectString.removeAt(2);
        qDebug() << vectString;
        qDebug() << "***********************************";
    }

    //mid
    {
        QVector<int> vect, result1, result2;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        result1 = vect.mid(3, 4);
        qDebug() << result1;

        result2 = vect.mid(3, -4);
        qDebug() << "result2 : " << result2;
        result2 = vect.mid(3);
        qDebug() << "result2 : " << result2;
        result2 = vect.mid(3, 0);
        qDebug() << "result2 : " << result2;
        qDebug() << "***********************************";
    }

    //insert
    //prepend
    //append
    {
        QVector<QString> vector;
        vector.prepend("one");
        vector.prepend("two");
        vector.prepend("three");
        qDebug() << "vector : " << vector;
        qDebug() << "***********************************";

        QVector<QString> vector1;
        vector1.append("one");
        vector1.append("two");
        vector1.append("three");
        qDebug() << "vector1 : " << vector1;

        qDebug() << "***********************************";
        QVector<QString> vector2;
        vector2.append("one");
        vector2.append("two");
        QString three = "three";
        qDebug() << "vector2 : " << vector2;
        qDebug() << "three : " << three;
        vector2.append(std::move(three));
        qDebug() << "vector2 : " << vector2;
        qDebug() << "three : " << three;


        qDebug() << "***********************************";
        QVector<QString> vector3;
        vector3 << "alpha" << "beta" << "delta";
        vector3.insert(2, "gamma");
        qDebug() << "vector3 : " << vector3;

        qDebug() << "***********************************";
    }

    //back
    //count
    //last
    {
        QVector<QString> vector;
        vector.prepend("one");
        vector.prepend("two");
        vector.prepend("three");

        qDebug() << vector.last();
        qDebug() << vector.back();
        qDebug() << vector.count();
        qDebug() << "***********************************";

        QString str(vector.first());
        qDebug() << str;
        qDebug() << "***********************************";

    }

    //data
    {
        QVector<int> vector(10);
        int *data = vector.data();

        for (int i = 0; i < 10; ++i)
            data[i] = 2 * i;

        for(int i = 0; i < 10; ++i)
            std::cout << data[i] << " ";
        std::cout << std::endl;

        for(int i = 0; i < 10; ++i)
            std::cout << vector[i] << " ";
        std::cout << std::endl;

        qDebug() << "***********************************";
    }

    //fill
    {
        QVector<QString> vector(5);
        vector.fill("Orhan");
        qDebug() << vector;

        vector.fill("OZTURK", 7);
        qDebug() << vector;
        qDebug() << "***********************************";
    }

    //fromList
    {
        QStringList list;
        list << "Orhan" << "Fikret" << "Engin" << "Mustafa";

        qDebug() << list;

        QVector<QString> vect = QVector<QString>::fromList(list);
        qDebug() << vect;
        qDebug() << "***********************************";
    }

    //toVector
    {
        QStringList list;
        list << "Orhan" << "Fikret" << "Engin" << "Mustafa";

        qDebug() << list;

        QVector<QString> vect = list.toVector();
        qDebug() << vect;
        qDebug() << "***********************************";

    }

    //toList
    {
        QStringList listStr;
        listStr << "Orhan" << "Fikret" << "Engin" << "Mustafa";

        qDebug() << listStr;

        QVector<QString> vect = listStr.toVector();
        qDebug() << vect;

        QList<QString> list = vect.toList();
        qDebug() << list;
        qDebug() << "***********************************";
    }

    //fromStdVector
    //toStdVector
    {
        std::vector<double> stdvector;
        stdvector.push_back(1.2);
        stdvector.push_back(0.5);
        stdvector.push_back(3.14);

        QVector<double> vector = QVector<double>::fromStdVector(stdvector);
        qDebug() << vector;

        QVector<double> vector1;
        vector1 << 1.2 << 0.5 << 3.14;

        std::vector<double> stdvector1 = vector1.toStdVector();
        for(int i = 0; i < vector1.size(); ++i)
            std::cout << vector1.at(i) << " ";
        std::cout << std::endl;
        qDebug() << "***********************************";
    }

    //size
    //push_back
    //pop_back
    //push_front
    //pop_front
    {
        QVector<int> vector;
        vector.push_back(10);
        vector.push_back(20);
        vector.push_back(30);
        vector.push_back(40);

        int n = vector.size();

        std::cout << "The last element is : " << vector[n - 1] << std::endl;

        vector.pop_back(); //removes last element

        qDebug() << vector;

        vector.push_front(88); // begin add
        qDebug() << vector;
        vector.pop_front();
        qDebug() << vector;
        qDebug() << "***********************************";
    }

    //size
    //capacity
    //resize
    //reserve
    //shrink_to_fit
    //squeeze
    {
        QVector<int> vect;

        for(int i = 0; i < 10; ++i)
            vect.append(i);

        qDebug() << "size : " << vect.size();
        qDebug() << "capacity : " << vect.capacity();

        for(int i = 0; i < 10; ++i)
            std::cout << vect[i] << " ";
        std::cout << std::endl;

        vect.resize(5);
        vect.reserve(30);

        qDebug() << "size : " << vect.size();
        qDebug() << "capacity : " << vect.capacity();


        for(int i = 0; i < 10; ++i)
            std::cout << vect[i] << " ";
        std::cout << std::endl;

        //vect.shrink_to_fit();
        vect.squeeze();

        for(int i = 0; i < 10; ++i)
            std::cout << vect[i] << " ";

        std::cout << std::endl;
        qDebug() << "size : " << vect.size();
        qDebug() << "capacity : " << vect.capacity();
        qDebug() << "***********************************";
    }

    //swap
    {
        QVector<int> vect1, vect2;

        for(int i = 0; i < 10; ++i){
            vect1.append(i);
            vect2.prepend(i);
        }

        std::cout << "vect1 : ";
        for(int i = 0; i < 10; ++i)
            std::cout << vect1[i] << " ";
        std::cout << std::endl;

        std::cout << "vect2 : ";
        for(int i = 0; i < 10; ++i)
            std::cout << vect2[i] << " ";
        std::cout << std::endl;

        vect1.swap(vect2);

        std::cout << "vect1 : ";
        for(int i = 0; i < 10; ++i)
            std::cout << vect1[i] << " ";
        std::cout << std::endl;

        std::cout << "vect2 : ";
        for(int i = 0; i < 10; ++i)
            std::cout << vect2[i] << " ";
        std::cout << std::endl;


        qDebug() << "***********************************";

    }

    return 0;
}
