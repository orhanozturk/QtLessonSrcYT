#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("OrhanOZTURK");

    //Pencerenin sol üst pozisyonunu döndürüyor
    //qDebug() << "pos : " << pos();

    //qDebug() << "isVisible : " << isVisible();
}

Widget::~Widget()
{
    delete ui;
}

