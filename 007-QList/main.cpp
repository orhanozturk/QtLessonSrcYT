#include <QList>
#include <QDebug>
#include <iostream>


int main()
{
    QList<QString> names;
    names << "Orhan" << "Fikret" << "Engin";

    qDebug() << names;

    names.append("Mustafa");

    qDebug() << names;

    names.insert(0, "Hasan");
    qDebug() << names;

    names.insert(names.size(), "OZTURK");
    qDebug() << names;

    QString lastName = names.takeLast();
    qDebug() << names;
    qDebug() << lastName;

    QString firstName = names.takeFirst();
    qDebug() << names;
    qDebug() << firstName;

    QString anyName = names.takeAt(3);
    qDebug() << names;

    if((names.isEmpty() == false) && names.size() >= 2)
            names.removeAt(3);
    else
        qDebug() << "List is empty";

    qDebug() << names;

    names.insert(2,"OZTURK");

    int lastIndex = names.lastIndexOf("Orhan");

    if(-1 != lastIndex)
        qDebug() << names.at(lastIndex) << " : " << lastIndex;
    else
        qDebug() << "does not found";

    qDebug() << names;
    qDebug() << "***************************************";

    for(int i = 0; i < names.count(); ++i)
            qDebug() << names.at(i);

    if(names.endsWith("Orhan"))
        qDebug() << "endWith item";
    else
        qDebug() << "does not endWith item";


    if(names.startsWith("Orhan"))
        qDebug() << "endWith item";
    else
        qDebug() << "does not endWith item";


    if(names.contains("OZTURK"))
        qDebug() << "endWith item";
    else
        qDebug() << "does not endWith item";

    if(names.size() > 0)
        names.replaceInStrings("engin", "Mustafa", Qt::CaseInsensitive);

    qDebug() << names;
    qDebug() << "***************************************";

    for(auto it = names.begin(); it != names.end(); ++it)
        qDebug() << *it;


    return 0;
}
