#ifndef MYOBJECT_HPP
#define MYOBJECT_HPP

#include <QObject>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = nullptr);

signals:
    void mySignal(QString &str);
    void mySignal(int integer);

public slots:
    void mySlot(QString &str);
    void mySlot(int integer);
};

#endif // MYOBJECT_HPP
