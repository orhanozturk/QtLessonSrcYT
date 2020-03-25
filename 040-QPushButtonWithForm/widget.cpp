#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_btnCheckable_clicked()
{
    qDebug() << "checkbaled : " << ui->btnCheckable->isChecked();
}

void Widget::on_btnIsCheckabled_clicked()
{
    QString msg;
    if(ui->btnCheckable->isChecked())
    {
        msg = "Yes, checked";
    } else {
        msg = "No, not checked";
    }

    QMessageBox::information(this, "Warning Checked", msg);
}

void Widget::on_btnAutoRepate_clicked()
{
    qDebug() << "User cliked";

}

void Widget::on_btnAutoRepateToggle_clicked()
{
    bool flag = !ui->btnAutoRepate->autoRepeat();
    ui->btnAutoRepate->setAutoRepeat(flag);
    qDebug() << "AutoRepate : " << ui->btnAutoRepate->autoRepeat();
}

void Widget::on_btnDefualt_clicked()
{
    qDebug() << "default button clicked";
}

void Widget::on_btnDefualtToggle_clicked()
{
    bool flag = !ui->btnDefualt->isDefault();
    ui->btnDefualt->setDefault(flag);
    qDebug() << "Defualt : " << ui->btnDefualt->isDefault();
}

void Widget::on_btnFlat_clicked()
{
    qDebug() << "clicked isFlat : " << ui->btnFlat->isFlat();
}

void Widget::on_btnFlatToggle_clicked()
{
    bool flag = !ui->btnFlat->isFlat();
    ui->btnFlat->setFlat(flag);
    qDebug() << "isFlat : " << ui->btnFlat->isFlat();
}

void Widget::on_btnQuit_clicked()
{
    qDebug() << "close";
    close();
}
