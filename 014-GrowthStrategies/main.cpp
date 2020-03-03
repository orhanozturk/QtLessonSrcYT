#include <QString>
#include <QDebug>

QString onlyLetters(const QString &in)
{
    QString out;
    for (int j = 0; j < in.size(); ++j) {
        if (in[j].isLetter())
            out += in[j];
        qDebug() << "size : " << out.size();
        qDebug() << "capacity : " << out.capacity();
    }

    out.squeeze();
    //out.shrink_to_fit();

    qDebug() << "**************************";

    qDebug() << "size : " << out.size();
    qDebug() << "capacity : " << out.capacity();
    return out;
}

int main()
{
    QString in(60, QChar('a'));

    onlyLetters(in);

    return 0;
}
