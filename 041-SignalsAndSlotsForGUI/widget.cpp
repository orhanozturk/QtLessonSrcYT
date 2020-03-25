#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->btnConnect, &QPushButton::clicked, this, &Widget::doSomething);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnEditor_clicked()
{
    doSomething();
}

void Widget::doSomething()
{
    qDebug() << "do something";
}
