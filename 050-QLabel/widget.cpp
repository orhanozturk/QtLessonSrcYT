#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){

        QString firstName = ui->lineEditFirstName->text();
        QString lastName = ui->lineEditLastName->text();

        if(!firstName.isEmpty() && !lastName.isEmpty())
        {
            qDebug() << "First Name : " <<firstName;
            qDebug() << "Last Name : " << lastName;
        }else {
            qDebug() << "Failed";
        }

    });


    QPixmap supermanPixmap(":/images/Superman.png");
    ui->labelPixmap->setPixmap(supermanPixmap.scaled(450, 300));

}

Widget::~Widget()
{
    delete ui;
}

