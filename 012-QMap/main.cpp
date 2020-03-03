#include <QMap>
#include <QDebug>
#include <iostream>


// operator<()
int main()
{
    QMap<QString, int> map;

    //[] operator
    // insert fonksiyonu ile ekleme islemlerini yapabiliriz

    map["Orhan"] = 1;
    map["Engin"] = 2;
    map["Mustafa"] = 3;

    map.insert("Fikret", 4);

    qDebug() << "map : " << map;
    qDebug() << "**********************************";
    int value;

    foreach(value, map.values()){
        qDebug() << value;
    }

    qDebug() << "**********************************";

    QString key;

    foreach(key, map.keys()){
        qDebug() << key;
    }
    qDebug() << "**********************************";

    int num1 = map["Fikret"];
    int num2 = map.value("Engin");

    qDebug() << "num1 : " << num1;
    qDebug() << "num2 : " << num2;
    qDebug() << "**********************************";

    map["Hasan"] = 5;
    int tempInt = -1;
    if(map.contains("Hasan"))
        tempInt = map.value("Hasan");

    qDebug() << "tempInt: " << tempInt;
    qDebug() << "**********************************";

    int tempTalha = map.value("Talha", 6);

    qDebug() << "tempTalha: " << tempTalha;
    qDebug() << "**********************************";

    //Not: Eğer aynı anahtar ile yeni bir değer eklersek bu değer geçerli fakat eski deger silinis olur

    map.insert("Yusuf", 7);
    map.insert("Yusuf", 8);
    qDebug() << "map : " << map;
    qDebug() << "**********************************";

    QMultiMap<QString, int> map1, map2, map3;
    map1.insert("Orhan", 1);
    map1.insert("Orhan", 2);
    qDebug() << "size : " << map1.size();
    qDebug() << "map1 : " << map1;
    qDebug() << "**********************************";

    map2.insert("Orhan", 3);

    map3 = map1 + map2;

    qDebug() << "size : " << map3.size();
    qDebug() << "map3 : " << map3;
    qDebug() << "**********************************";

    QList<int> vals = map3.values("Orhan");

    qDebug() << "vals : " << vals;
    qDebug() << "**********************************";

    /*STL Style Iterators */

    {
        QMap<QString, int>::iterator i = map.begin();
        while(i != map.end()){
            qDebug() << i.key() << " : " << i.value();
            ++i;
        }
    }
    qDebug() << "**********************************";

    {
        QMultiMap<QString, int> map;
        map.insert("Orhan", 100);
        map.insert("Hasan", 44);
        map.insert("Hasan", 22);
        map.insert("Mustafa", 150);
        map.insert("Hasan", 200);
        map.insert("Ömer", 1000);


        QMultiMap<QString, int>::iterator i = map.find("Hasan");
        while(i != map.end() && i.key() == "Hasan"){
            std::cout << i.value() << std::endl;
            ++i;
        }
    }
    qDebug() << "**********************************";


    /* Java Style Iterators */

    {
        QMapIterator<QString, int> mapiter(map);

        mapiter.toBack();

        while (mapiter.hasPrevious()) {
            mapiter.previous();
            qDebug() << mapiter.key() << ", " << mapiter.value();
        }
    }
    qDebug() << "**********************************";

    {
        int sum = 0;

        QMapIterator<QString, int> i(map);
        while (i.hasNext()) {
            sum += i.next().value();
        }

        qDebug() << "sum : " << sum;
    }

    qDebug() << "**********************************";


    {
        QString largestKey;
        int largestValue = 0;

        QMapIterator<QString, int> i(map);
        while (i.hasNext()) {
            i.next();
            if(i.value() > largestValue)
                largestKey = i.key();
                largestValue = i.value();
        }
        qDebug() << "largestKey : " << largestKey;
        qDebug() << "largestValue : " << largestValue;
    }
    qDebug() << "**********************************";
    {
        QMutableMapIterator<QString, int> i(map);
        while (i.hasNext()) {
            if(i.next().value() < 4.0)
                i.setValue(-i.value());
        }
    }

    foreach(QString key, map.keys()){
        foreach(int value, map.values(key))
            qDebug() << key << ", " << value;
    }


    qDebug() << "**********************************";

    //lowerBound
    //upperBound

    {
        QMap<int, QString> map;
        map.insert(1, "one");
        map.insert(5, "five");
        map.insert(10, "ten");

       // map.lowerBound(0);      // returns iterator to (1, "one")
       // map.lowerBound(1);      // returns iterator to (1, "one")
       // map.lowerBound(2);      // returns iterator to (5, "five")
       // map.lowerBound(10);     // returns iterator to (10, "ten")
       // map.lowerBound(999);    // returns end()

        QMap<int, QString>::const_iterator i = map.lowerBound(11);
        if(i != map.end())
            qDebug() << i.value();

    }
    qDebug() << "**********************************";

    {
        QMap<int, QString> map;
        map.insert(1, "one");
        map.insert(5, "five");
        map.insert(10, "ten");

        //map.upperBound(0);      // returns iterator to (1, "one")
        //map.upperBound(1);      // returns iterator to (5, "five")
        //map.upperBound(2);      // returns iterator to (5, "five")
        //map.upperBound(10);     // returns end()
        //map.upperBound(999);    // returns end()

        QMap<int, QString>::const_iterator i = map.upperBound(10);
        if(i != map.end())
            qDebug() << i.value();
    }

    qDebug() << "**********************************";

    {
        QMap<int, QString> map;
        map.insert(1, "one");
        map.insert(5, "five");
        map.insert(7, "seven");
        map.insert(10, "ten");

        QMap<int, QString>::const_iterator i = map.lowerBound(1);
        QMap<int, QString>::const_iterator upperBound = map.upperBound(10);

        while (i != upperBound) {
            qDebug() << i.value();
            ++i;
        }

    }

    qDebug() << "**********************************";

    return 0;
}
