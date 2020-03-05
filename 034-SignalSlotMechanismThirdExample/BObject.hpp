#ifndef BOBJECT_HPP
#define BOBJECT_HPP

#include <QObject>

class BObject : public QObject
{
    Q_OBJECT
public:
    explicit BObject(QObject *parent = nullptr);

signals:

public slots:
    void recieveBObject(QString param);
};

#endif // BOBJECT_HPP
