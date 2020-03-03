#include <QHash>
#include <QDebug>
#include <iostream>

//operator==()
int main()
{
    QHash<QString, int> hash;

    //[] operator
    // insert fonksiyonu ile ekleme islemlerini yapabiliriz

    hash["Orhan"] = 1;
    hash["Engin"] = 2;
    hash["Mustafa"] = 3;


    hash.insert("Fikret", 4);

    qDebug() << "hash : " << hash;
    qDebug() << "**********************************";

    int value;

    foreach(value, hash.values()){
        qDebug() << value;
    }

    qDebug() << "**********************************";

    foreach(const QString key, hash.keys()){
        qDebug() << key;
    }

    qDebug() << "**********************************";

    //hash[key] value degerini dondurur
    //hash.value("key") bu key'in value'sunu dondur
    int num1 = hash["Fikret"];
    int num2 = hash.value("Engin");

    qDebug() << "num1 : " << num1;
    qDebug() << "num2 : " << num2;
    qDebug() << "**********************************";

    hash["Hasan"] = 5;
    int tempInt = -1;
    if(hash.contains("Mehmet"))
        tempInt = hash.value("Hasan");

    qDebug() << "tempInt: " << tempInt;
    qDebug() << "**********************************";

    int tempTalha = hash.value("Talha", 6);

    qDebug() << "tempTalha: " << tempTalha;
    qDebug() << hash;
    qDebug() << "**********************************";

    //Not: Eğer aynı anahtar ile yeni bir değer eklersek bu değer geçerli fakat eski deger silinis olur

    hash.insert("Yusuf", 7);
    hash.insert("Yusuf", 8);
    qDebug() << "hash : " << hash;
    qDebug() << "**********************************";


    QMultiHash<QString, int> hash1, hash2, hash3;
    hash1.insert("Orhan", 1);
    hash1.insert("Orhan", 2);
    qDebug() << "size : " << hash1.size();
    qDebug() << "hash1 : " << hash1;
    qDebug() << "**********************************";

    hash2.insert("Orhan", 3);
    hash2.insert("OZTURK", 6);

    hash3 = hash1 + hash2;

    qDebug() << "size : " << hash3.size();
    qDebug() << "hash3 : " << hash3;
    qDebug() << "**********************************";

    QList<int> vals = hash3.values("Orhan");

    qDebug() << "vals : " << vals;
    qDebug() << "**********************************";

    /*STL Style Iterators */

    {
        QHash<QString, int>::iterator i = hash.begin();
        while(i != hash.end()){
            qDebug() << i.key() << " : " << i.value();
            ++i;
        }
    }

    qDebug() << "**********************************";

    {
        QMultiHash<QString, int> hash;
        hash.insert("Orhan", 100);
        hash.insert("Hasan", 44);
        hash.insert("Hasan", 22);
        hash.insert("Mustafa", 150);
        hash.insert("Hasan", 200);
        hash.insert("Ömer", 1000);


        QMultiHash<QString, int>::iterator i = hash.find("Hasan");
        while(i != hash.end() && i.key() == "Hasan"){
            std::cout << i.value() << std::endl;
            ++i;
        }
    }
    qDebug() << "**********************************";

    /* Java Style Iterators */

    {
        QHashIterator<QString, int> hashiter(hash);

        hashiter.toBack();

        while (hashiter.hasPrevious()) {
            hashiter.previous();
            qDebug() << hashiter.key() << ", " << hashiter.value();
        }
    }
    qDebug() << "**********************************";

    {
        int sum = 0;

        QHashIterator<QString, int> i(hash);
        while (i.hasNext()) {
            sum += i.next().value();
        }

        qDebug() << "sum : " << sum;
    }

    qDebug() << "**********************************";


    {
        QString largestKey;
        int largestValue = 0;

        QHashIterator<QString, int> i(hash);
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
        QMutableHashIterator<QString, int> i(hash);
        while (i.hasNext()) {
            if(i.next().value() < 4.0)
                i.setValue(-i.value());
        }
    }

    foreach(QString key, hash.keys()){
        foreach(int value, hash.values(key))
            qDebug() << key << ", " << value;
    }

    qDebug() << "**********************************";

    return 0;
}
