#ifndef SLOTA_HPP
#define SLOTA_HPP

#include <QObject>

class SlotA : public QObject
{
    Q_OBJECT
public:
    explicit SlotA(QObject *parent = nullptr);

signals:

public slots:
    int add(int a, int b);
    int div(int a, int b);
    int mul(int a, int b);

};

#endif // SLOTA_HPP
