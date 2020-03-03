//UNICODE --> Universal Code

#include <QChar>
#include <QDebug>

/*
QChar()
QChar(ushort code)
QChar(uchar cell, uchar row)
QChar(short code)
QChar(uint code)
QChar(int code)
QChar(QChar::SpecialCharacter ch)
QChar(QLatin1Char ch)
QChar(char16_t ch)
QChar(wchar_t ch)
QChar(char ch)
QChar(uchar ch)
*/

int main()
{
    //ctor
    {
        QChar ch1('a');
        qDebug() << "ch1 : " << ch1;

        QChar ch2('7');
        qDebug() << "ch2 : " << ch2;

        QChar ch3(122);
        qDebug() << "ch3 : " << ch3;

        qDebug() << "QChar::Null : " << QChar::Null;
        qDebug() << QChar::Category(QChar::Script_Batak);

        QChar ch4(QChar::Null);
        qDebug() << "ch4 : " << ch4;

    }

    //isNumber: Returns true if the character is a number (Number_* categories, not just 0-9); otherwise returns false
    {
        QChar ch5('6');
        qDebug() << "ch5 : " << ch5.isNumber();

        QChar ch6('-2');
        qDebug() << "ch6 : " << ch6.isNumber();

        QChar ch7('34');
        qDebug() << "ch7 : " << ch7.isNumber();

        QChar ch8('a');
        qDebug() << "ch8 : " << ch8.isNumber();
    }

    //isNull: Returns true if the character is the Unicode character 0x0000 ('\0'); otherwise returns false.
    {
        QChar ch9('z');
        QChar ch10('\0');

        qDebug() << "ch9 : " << ch9.isNull();
        qDebug() << "ch10 : " << ch10.isNull();

    }

    //toLower: Returns the lowercase equivalent if the character is uppercase or titlecase; otherwise returns the character itself.
    //toUpper: Returns the uppercase equivalent if the character is lowercase or titlecase; otherwise returns the character itself.
    {
        QChar ch11('a');
        QChar ch12;

        ch12 = ch11.toUpper();

        qDebug() << "ch11 : " << ch11;
        qDebug() << "ch12 : " << ch12;

        QChar ch16(ch11.toUpper());
        qDebug() << "ch16 : " << ch16;
    }

    //isLower: Returns true if the character is a lowercase letter, for example category() is Letter_Lowercase.
    //isUpper: Returns true if the character is an uppercase letter, for example category() is Letter_Uppercase.
    {
        QChar ch13('z');
        qDebug() << "ch13 : " << ch13.isLower();
        qDebug() << "QChar::isUpper(122) : " << QChar::isUpper(122);

    }

    //Operators < -- >
    {
        QChar ch14('a');
        QChar ch15('z');

        if( ch14 > ch15)
            qDebug() << ch14 << " > " << ch15;
        else if(ch14 < ch15)
            qDebug() << ch14 << " < " << ch15;
        else {
            qDebug() << ch14 << " == " << ch15;
        }
    }
    return 0;
}
