#include <QString>
#include <QDebug>

#include <iostream>
#include <string>

/*
QString()
QString(const QChar *unicode, int size = -1)
QString(QChar ch)
QString(int size, QChar ch)
QString(QLatin1String str)
QString(const QString &other)
QString(QString &&other)
QString(const char *str)
QString(const QByteArray &ba)
*/

int main()
{
    //Ctor
    {
        QString str("Gunun Konusu QString");
        QString str1 = "Gunun Konusu QString"; //Copy Assigment
        QString str2(10, QChar('A'));
        QString str3(10, 'A');

        qDebug() << "str : " << str;
        qDebug() << "str1 : " << str1;
        qDebug() << "str2 : " << str2;
        qDebug() << "str3 : " << str3;

        qDebug() << "*****************************************************";
    }

    //isNull : Returns true if this string is null; otherwise returns false
    //isEmpty : Returns true if the string has no characters; otherwise returns false
    {
        QString str;
        QString str1("");
        QString str2("Orhan");

        qDebug() << "str.isNull() : " << str.isNull(); // true
        qDebug() << "str.isEmpty() : " << str.isEmpty(); // true

        qDebug() << "str1.isNull() : " << str1.isNull(); // false
        qDebug() << "str1.isEmpty() : " << str1.isEmpty(); // true

        qDebug() << "str2.isNull() : " << str2.isNull();  // false
        qDebug() << "str2.isEmpty() : " << str2.isEmpty(); // false


        qDebug() << QString().isEmpty();            // returns true
        qDebug() << QString("").isEmpty();          // returns true
        qDebug() << QString("x").isEmpty();         // returns false
        qDebug() << QString("abc").isEmpty();       // returns false

        qDebug() << QString().isNull();             // returns true
        qDebug() << QString("").isNull();           // returns false
        qDebug() << QString("abc").isNull();        // returns false

        qDebug() << "*****************************************************";
    }

    //Insert: Inserts the string str at the given index position and returns a reference to this string.
    {
        QString str = "Meal";
        str.insert(1, QString("ontr"));
        // str == "Montreal"

        qDebug() << "str : " << str;

        QString str1("Oz");
        str1.insert(2,"turk");
        qDebug() << "str1 : " << str1;

        QString str2("Oztu");
        str2.insert(4, 'r');
        str2.insert(5, 'k');
        qDebug() << "str2 : " << str2;

        qDebug() << "*****************************************************";
    }

    //remove
    {
        QString str("Gunun Konusu QString");
        qDebug() << "str.remove(5, 7)" << str.remove(5, 7);
        qDebug() << "str" << str;

        QString t = "Ali Baba";
        qDebug() << t.remove(QChar('a'), Qt::CaseInsensitive);// t == "li Bb"

        qDebug() << "*****************************************************";
    }

    //leftRef
    //rightRef
    {
        QString x = "Pineapple";
        QStringRef y = x.leftRef(4);        // y == "Pine"
        qDebug() << "x : " << y;

        QString x1 = "Pineapple";
        QStringRef y1 = x1.rightRef(5);       // y == "apple"
        qDebug() << "x : " << y1;

        qDebug() << "*****************************************************";
    }

    //section
    {
        QString str;
        QString csv = "forename,middlename,surname,phone";
        QString path = "/usr/local/bin/myapp"; // First field is empty
        QString::SectionFlag flag = QString::SectionSkipEmpty;

        str = csv.section(',', 2, 2);   // str == "surname"
        qDebug() << str;
        str = path.section('/', 3, 4);  // str == "bin/myapp"
        qDebug() << str;
        str = path.section('/', 3, 3, flag); // str == "myapp"
        qDebug() << str;

        str = csv.section(',', -3, -2);  // str == "middlename,surname"
        qDebug() << str;
        str = path.section('/', -1); // str == "myapp"
        qDebug() << str;

        qDebug() << "*****************************************************";
    }

    //replace
    {
        QString str = "Orhan; Fikret; Engin; Mustafa";
        str.replace(';', ',');
        qDebug() << str;
        str.replace("fikreT", "OZTURK", Qt::CaseSensitive);
        qDebug() << str;

        QString x = "Say yes!";
        QString y = "no";
        qDebug() << x.replace(4, 3, y);
        // x == "Say no!"

        qDebug() << "*****************************************************";
    }

    //indexOf
    {
        QString str("Gunun Konusu QString");
        int index;

        index = str.indexOf("Konusu");
        qDebug() << "index : " << index;

        index = str.lastIndexOf('u');
        qDebug() << "index : " << index;
        index = str.indexOf('u');
        qDebug() << "index : " << index;


        QString x = "sticky question";
        QString y = "sti";
        qDebug() << x.indexOf(y);               // returns 0
        qDebug() << x.indexOf(y, 1);            // returns 10

        qDebug() << "*****************************************************";
    }

    //mid
    {
        QString str("Gunun Konusu QString");
        QString strOut;

        strOut = str.mid(6, 6);
        qDebug() << "strOut : " << strOut;

        strOut = str.mid(6);
        qDebug() << "strOut : " << strOut;
        qDebug() << "*****************************************************";
    }

    //rightJustified
    //leftJustified
    {
        QString s = "apple";
        QString t = s.leftJustified(8, '.');    // t == "apple..."
        qDebug() << "t : " << t;

        QString s1 = "apple";
        QString t1 = s.rightJustified(8, '.');    // t == "...apple"
        qDebug() << "t1 : " << t1;

        QString str = "Pineapple";
        str = str.leftJustified(5, '.', true);    // str == "Pinea"
        qDebug() << "str : " << str;

        QString str1 = "Pineapple";
        str1 = str1.rightJustified(5, '.', true);    // str == "Pinea"
        qDebug() << "str1 : " << str1;

        QString str2 = "Orhan";
        qDebug() << str2.rightJustified(10, '*');
        qDebug() << str2.leftJustified(10, '*');

        qDebug() << "str2 : " << str2;

        qDebug() << "*****************************************************";
    }

    //trimmed
    {
        QString str = "  lots\t of\nwhitespace\r\n ";
        str = str.trimmed();
        // str == "lots\t of\nwhitespace"

        qDebug() << "str : " << str;

        qDebug() << "*****************************************************";
    }

    //truncate
    {
        QString str = "Vladivostok";
        str.truncate(4);
        // str == "Vlad"
        qDebug() << "str: " << str;
        qDebug() << "*****************************************************";
    }

    //repeated
    {
        QString str = "Orhan";
        QString strTimes = str.repeated(5);

        qDebug() << "str : " << str;
        qDebug() << "strTimes : " << strTimes;
        qDebug() << "*****************************************************";
    }

    //contains
    {

        QString str = "Peter Pan";
        qDebug() << "str.contains : " << str.contains("peter", Qt::CaseInsensitive);    // returns true
        qDebug() << "*****************************************************";
    }

    //number static
    {
        long a = 63;
        QString s = QString::number(a, 16);             // s == "3f"
        QString t = QString::number(a, 16).toUpper();     // t == "3F"
        qDebug() << "s : " << s;
        qDebug() << "t : " << t;


        QString str;

        str = QString::number(342);
        qDebug() << "str : " << str;

        str = QString::number(33.42);
        qDebug() << "str : " << str;
        qDebug() << "*****************************************************";
    }

    //toInt, toLong, toDouble....
    {
        QString str("234.45");
        double result;

        result = str.toDouble();
        qDebug() << "result : " << result;

        QString str1("233");
        int result1;

        result1 = str1.toInt();
        qDebug() << "result1 : " << result1;


        QString str2 = "FF";
        bool ok;
        int hex = str2.toInt(&ok, 16);       // hex == 255, ok == true
        qDebug() << "ok : " << ok;
        int dec = str2.toInt(&ok, 10);       // dec == 0, ok == false
        qDebug() << "ok : " << ok;

        qDebug() << "hex : " << hex;
        qDebug() << "dec : " << dec;

        qDebug() << "*****************************************************";
    }

    //toStdString
    {
        QString str = "Orhan OZTURK";
        std::string cppStr;

        cppStr = str.toStdString();
        std::cout << "cppStr : " << cppStr << std::endl ;
        qDebug() << "*****************************************************";
    }

    //toUpper and toLower
    {
        QString name = "ORHAN";
        QString lastName = "ozturk";

        qDebug() <<name.toLower() << "  " << lastName.toUpper();
        qDebug() << "*****************************************************";
    }

    //compare static
    {
        QString str = "ankara";
        QString str1 = "ankera";

        int result = QString::compare(str, str1);  // a = 97 - e = 101
        qDebug() << "result : " << result;

        int x = QString::compare("aUtO", "AuTo", Qt::CaseInsensitive);  // x == 0
        int y = QString::compare("auto", "Car", Qt::CaseSensitive);     // y > 0  a = 97 -  C= 67
        int z = QString::compare("auto", "Car", Qt::CaseInsensitive);   // z < 0  a = 97 - c = 99
        int w = QString::compare("auto", "auzo", Qt::CaseInsensitive);   // w < 0  t = 116 - z = 122
        qDebug() << "x : " << x;
        qDebug() << "y : " << y;
        qDebug() << "z : " << z;
        qDebug() << "w : " << w;
        qDebug() << "*****************************************************";
    }

    //append and prepend
    {
        QString x = "free";
        QString y = "dom";

        x.append(y);
        // x == "freedom"

        qDebug() << "x : " << x;


        QString x1 = "ship";
        QString y1 = "air";
        x1.prepend(y1);
        // x == "airship"

        qDebug() << "x1 : " << x1;
        qDebug() << "y1 : " << y1;
        qDebug() << "*****************************************************";
    }

    // <, > <= ,>= , ==, != .....
    {
        QString str = "orhan";
        QString str1 = "orh";

        if(str > str1)
           qDebug() << str << " > " << str1;
        else if(str < str1)
           qDebug() << str << " < " << str1;
        else
           qDebug() << str << " == " << str1;

         qDebug() << "*****************************************************";
    }

    //+ and += operators
    {
        QString str1("Orhan");
        QString str2("OZTURK");
        QString result;

        result = str1 + str2;
        std::cout << result.toStdString() << std::endl;

        result += QString("Kastamonu");
        std::cout << result.toStdString() << std::endl;

        result += "Ankara";
        std::cout << result.toStdString() << std::endl;
        qDebug() << "*****************************************************";
    }

    //split
    {
        QString str = "Ankara,,Kastamonu,Orhan";

        QStringList list1 = str.split(',');

        foreach(QString item, list1){
            qDebug() << item;
        }
        qDebug() << "*****************************************************";

        QStringList list2 = str.split(',', QString::SkipEmptyParts);

        foreach(QString item, list2){
            qDebug() << item;
        }

        qDebug() << "*****************************************************";

        QStringListIterator i(list2);
        while(i.hasNext()){
            qDebug() << i.next();
        }
        qDebug() << "*****************************************************";

        for (int i = 0; i < list2.size(); ++i)
        {
            qDebug() << list2[i];
        }
    }

    //arg   %n
    {
        int  a = 5, b =10;

        QString str1("a = %1, b = %2");
        QString str2;
        QString str3;

        qDebug() << "str1 : " << str1;

        str2 = str1.arg(a);
        qDebug() << "str2 : " << str2;  // a = 5

        str3 = str2.arg(b);
        qDebug() << "str3 : " << str3;  // a = 5 b = 10

        qDebug() << "*****************************************************";

        QString str4("b = %2, a = %1");
        QString str5;
        QString str6;

        qDebug() << "str4 : " << str4;

        str5 = str4.arg(a);
        qDebug() << "str5 : " << str5; // b = %2 a = 5

        str6 = str5.arg(b);
        qDebug() << "str6 : " << str6;  // b = 10 a = 5
        qDebug() << "*****************************************************";

        qDebug() << QString("a = %1, b = %2").arg(a).arg(b);
        qDebug() << "*****************************************************";
        qDebug() << QString("a = %1, b = %1, c = %2, d = %2").arg(a).arg(b);
        qDebug() << "*****************************************************";

        QString i = "10";           // current file's number
        QString total = "150";       // number of files to process
        QString fileName = "Orhan";    // current file's name

        QString status = QString("Processing file %1 of %2: %3")
                        .arg(i).arg(total).arg(fileName);
        qDebug() << "status : " << status;
        qDebug() << "*****************************************************";
    }

    //simplified
    {
        QString str = "  lots\t of\nwhitespace\r\n ";
        str = str.simplified();
        // str == "lots of whitespace";
        qDebug() << "str : " << str;
        qDebug() << "*****************************************************";
    }

     //nextTime review QTextStream
    {
        QTextStream qStr(stdin);
        QString str;

        str = qStr.readLine();
        qDebug() << "str : " << str;
        qDebug() << "*****************************************************";
    }


    //capacity - size
    //reserve - resize
    {
        QString str = "Orhan OZTURK";

        qDebug() << "str.size() : " << str.size();
        qDebug() << "str.capacity() : " << str.capacity();

        str.reserve(30);
        qDebug() << "str : " << str;
        str.resize(8);
        qDebug() << "str : " << str;

        qDebug() << "str.size() : " << str.size();
        qDebug() << "str.capacity() : " << str.capacity();
        qDebug() << "*****************************************************";

    }

    return 0;
}
