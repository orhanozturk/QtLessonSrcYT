#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    c_Box1 = new QCheckBox("Save", this);
    c_Box2 = new QCheckBox("Record", this);

    c_Box1->move(20, 20);
    c_Box2->move(20, 40);

    c_Box2->setTristate(true);

    connect(c_Box1, &QCheckBox::stateChanged, this, &Widget::doSomething);
    connect(c_Box2, &QCheckBox::stateChanged, this, &Widget::doTask);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::doSomething(int state)
{
    //qDebug() << c_Box1->isChecked();

    QStringList states;
    states << "Unchecked" << "Undertermined" <<"Checked";


    qDebug() << states.at(state);

}

void Widget::doTask(int state)
{
    QStringList states;
    states << "Unchecked" << "Undertermined" <<"Checked";


    qDebug() << states.at(state);
    qDebug() << c_Box2->checkState();
}

