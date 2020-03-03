#include <QDebug>
#include <QFile>
#include <iostream>
#include <QPoint>
#include <QDate>
#include <QRect>


// <<
// qDebug()

//QDebug& operator <<(const QDebug &, const QXXXX &);

/*
QDebug(const QDebug &o)
QDebug(QtMsgType t)
QDebug(QString *string)
QDebug(QIODevice *device)
*/

int main()
{
    QFile file("out.txt");

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        std::cout << "cannot open file" << std::endl;
        exit(EXIT_FAILURE);
    }

    QDebug debug(&file);

    debug << "Orhan OZTURK" << 999;

    qDebug() << "debug.autoInsertSpaces : " << debug.autoInsertSpaces();
    debug.setAutoInsertSpaces(false);
    qDebug() << "debug.autoInsertSpaces : " << debug.autoInsertSpaces();
    debug.setAutoInsertSpaces(true);
    debug << "111111111";
    debug << "222222222";
    debug.setAutoInsertSpaces(false);
    debug << "333333333";
    debug << "444444444";

    qDebug() << "verbosity : " << debug.verbosity();
    debug.setVerbosity(7);
    qDebug() << "verbosity : " << debug.verbosity();
    debug.resetFormat();
    qDebug() << "debug.autoInsertSpaces : " << debug.autoInsertSpaces();
    qDebug() << "verbosity : " << debug.verbosity();
    qDebug() << "**************************************************";

    int a = 5, b = 10;
    qDebug() << "a: " << a << "b : " << b; // "a: 10 b: 20"
    qDebug().nospace() << "a: " << a << "b : " << b; // a: 10b: 20
    qDebug().maybeSpace() << a << b;
    qDebug() << "**************************************************";
    qDebug().maybeQuote() << a << b;
    qDebug() << "**************************************************";
    qDebug().quote() <<QString("Orhan OZTURK");
    qDebug().noquote() <<QString("Orhan OZTURK");
    qDebug() << "**************************************************";

    QPoint point(5, 10);
    qDebug() << point;

    qDebug() << "**************************************************";

    qDebug() << "Date:" << QDate::currentDate();
    qDebug() << "Types:" << QString("String") << QChar('x') << QRect(0, 10, 50, 40);
    qDebug() << "Custom coordinate type:" << point;

    qDebug() << "**************************************************";

    qDebug("Test %d %d", 10, 20);

    return 0;
}
