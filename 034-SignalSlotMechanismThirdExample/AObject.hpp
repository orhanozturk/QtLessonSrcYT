#ifndef AOBJECT_HPP
#define AOBJECT_HPP

#include <QObject>

class AObject : public QObject
{
    Q_OBJECT
public:
    explicit AObject(QObject *parent = nullptr);

signals:
    void signalFunction(QString param);

public slots:
    void slotFunction(QString param);
};

#endif // AOBJECT_HPP
