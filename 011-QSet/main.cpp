#include <QSet>
#include <QDebug>

int main()
{
    QSet<QString> set;

    set.insert("Orhan");
    set.insert("Mustafa");
    set.insert("Engin");

    set << "Fikret" << "Hasan" << "Ayse";

    qDebug() << "count : " << set.count();
    qDebug() << "*************************************";

    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";

    QSet<QString> set1;
    set1.insert("Nuri");
    set1.insert("Mustafa");
    set1.insert("Nur");

    set1 << "Mehmet" << "Hasan" << "Ayse";

    foreach(const QString &i, set1){
        qDebug() << i;
    }

    qDebug() << "*************************************";

    set.swap(set1);

    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";

    qDebug() << "empty :"  << set.empty();
    qDebug() << "*************************************";

    set.setSharable(false); // set paylaşılamaz yaptım
    QSet<QString> set2;
    qDebug() << "isDetached : " << set.isDetached();
    qDebug() << "*************************************";
    set2 = set; // deep copy
    qDebug() << "isDetached : " << set2.isDetached();
    qDebug() << "*************************************";
    foreach(const QString &i, set2){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    qDebug() << "*************************************";

    if(set.contains("Fatma"))
        qDebug() << "True";
    else {
        qDebug() << "False";
    }
    qDebug() << "*************************************";

    //intersect // AYNI OLAN ELEMANLAR VERİDE KALIR

    set.swap(set1);

    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set1){
        qDebug() << i;
    }
    qDebug() << "*************************************";

    QSet<QString> set3;

    set3 = set.intersect(set1);

    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set1){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set3){
        qDebug() << i;
    }
    qDebug() << "*************************************";


    //subtract  // AYNI OLMAYAN ELEMANLAR VERİDE KALIR
    qDebug() << "-------- subtract ---------";
    set.insert("Orhan");
    set.insert("Mustafa");
    set.insert("Engin");

    set << "Fikret" << "Hasan" << "Ayse";

    QSet<QString> set4;
    set4 = set.subtract(set1);

    qDebug() << "*************************************";
    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set1){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set4){
        qDebug() << i;
    }
    qDebug() << "*************************************";

    //unite
    qDebug() << "-------- unite ---------";

    set << "Kerim" << "Hasan" << "Ayse";

    qDebug() << "*************************************";
    qDebug() << "set : ";
    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    qDebug() << "set1 : ";
    foreach(const QString &i, set1){
        qDebug() << i;
    }

    QSet<QString> set5;
    set5 = set.unite(set1);

    qDebug() << "*************************************";
    qDebug() << "new set : ";
    qDebug() << "*************************************";
    foreach(const QString &i, set){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set1){
        qDebug() << i;
    }
    qDebug() << "*************************************";
    foreach(const QString &i, set5){
        qDebug() << i;
    }
    qDebug() << "*************************************";

    QStringList list;
    list << "bir" << "iki" << "uc";

    QSet<QString> set6 = QSet<QString>::fromList(list);
    foreach(const QString &i, set6){
        qDebug() << i;
    }

    qDebug() << "*************************************";
    qDebug() << "*************************************";

    //toList

    /*
        QSet<int> set7;
        //set7
        for (int i = 0; i < 20000; ++i) {
            set7.insert(i);
            qDebug() << "size : " << set7.size();
            qDebug() << "capacity : " << set7.capacity();
        }
    */


    //Java tarzı iterator
    qDebug() << "Java tarzi iterator";
    QSetIterator<QString> i(set); // read-only
    QMutableSetIterator<QString> k(set); // read-write

    i.toBack();

    while (i.hasPrevious()) {
        qDebug() << i.previous();
    }

    qDebug() << "*************************************";
    //STL tarzı iterator
    qDebug() << "STL tarzi iterator";
    QSet<QString>::const_iterator m; // read-only
    QSet<QString>::iterator n; // read-write

    for (m = set.constBegin(); m != set.constEnd(); ++m) {
        qDebug() << *m;
    }

    qDebug() << "*************************************";

    return 0;
}
