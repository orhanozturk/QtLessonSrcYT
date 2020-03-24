#include "widget.hpp"
#include <QPushButton>
#include <QDebug>

/*
QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
QPushButton(const QString &text, QWidget *parent = nullptr)
QPushButton(QWidget *parent = nullptr)
*/

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn1 = new QPushButton("Download", this);
    //btn1->move(50, 100);
    //btn1->resize(100, 200);
    //btn1->setGeometry(50, 50, 500,500);


    QPushButton *btn2 = new QPushButton("Save", this);
    btn2->move(100 , 0);
    btn2->setFlat(true);

    btn2->setAutoFillBackground(true);
    QPalette pal = btn2->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    btn2->setPalette(pal);
    btn2->update();

    QPushButton *btn3 = new QPushButton("Cancel", this);

    btn3->move(300 , 0);

    QFont buttonFont("Times", 10, QFont::Bold);
    btn3->setMinimumSize(200,100);
    btn3->setFont(buttonFont);

    connect(btn3, &QPushButton::clicked, [=](){ qDebug() << "clicked";});

    QPushButton *btn4 = new QPushButton("NEXT", this);

    btn4->move(200 , 400);

    connect(btn4, &QPushButton::pressed, [=](){ qDebug() << "pressed";});
    connect(btn4, &QPushButton::released, [=](){ qDebug() << "released";});
}

Widget::~Widget()
{
}

