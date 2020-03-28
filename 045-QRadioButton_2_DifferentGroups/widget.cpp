#include "widget.hpp"
#include "ui_widget.h"
#include <QPushButton>
#include <QRadioButton>
#include <QGroupBox>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    groupBox1 = new QGroupBox("Fruit", this);
    groupBox1->move(10, 10);
    groupBox1->resize(150, 90);

    groupBox2 = new QGroupBox("Kg", this);
    groupBox2->move(10, 100);
    groupBox2->resize(150, 90);

    rButton1 = new QRadioButton("Apple", groupBox1);
    rButton2 = new QRadioButton("Banana", groupBox1);
    rButton3 = new QRadioButton("Lemon", groupBox1);
    rButton4 = new QRadioButton("One", groupBox2);
    rButton5 = new QRadioButton("Two", groupBox2);
    rButton6 = new QRadioButton("Three", groupBox2);

    rButton1->move(10, 20);
    rButton2->move(10, 40);
    rButton3->move(10, 60);
    rButton4->move(10, 20);
    rButton5->move(10, 40);
    rButton6->move(10, 60);

    pButton1 = new QPushButton("Sellected", this);
    pButton1->move(10, 200);

    connect(pButton1, &QPushButton::clicked, this, &Widget::pushButtonHandller);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButtonHandller()
{
    QString text = "None";

    if(rButton1->isChecked())
        text = rButton1->text();
    else if(rButton2->isChecked())
        text = rButton2->text();
    else if(rButton3->isChecked())
        text = rButton3->text();

    text += ", ";

    if(rButton4->isChecked())
        text += rButton4->text();
    else if(rButton5->isChecked())
        text += rButton5->text();
    else if(rButton6->isChecked())
        text += rButton6->text();

     text += " Kg.";
    QMessageBox::information(this, "Message", "Sellected : " + text, QMessageBox::Ok);
}


void Widget::on_pButton2_clicked()
{
    QString text = "Zero";

    if(ui->rBtn1->isChecked())
        text = ui->rBtn1->text();
    else if(ui->rBtn2->isChecked())
        text = ui->rBtn2->text();
    else if(ui->rBtn3->isChecked())
        text = ui->rBtn3->text();

    text += ", ";

    if(ui->rBtn4->isChecked())
        text += ui->rBtn4->text();
    else if(ui->rBtn5->isChecked())
        text += ui->rBtn5->text();
    else if(ui->rBtn6->isChecked())
        text += ui->rBtn6->text();

     text += " Kg.";

    QMessageBox::information(this, "Message", "Sellected : " + text, QMessageBox::Ok);

}
