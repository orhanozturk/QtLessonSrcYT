#include "widget.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>

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

void Widget::on_pushButton_clicked()
{

    QMessageBox msgBox;
    msgBox.setMinimumSize(300, 200);
    msgBox.setWindowTitle("Window Title");
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setDetailedText("Do you want to save your changes !!!");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);

    //msgBox.exec();

    int ret = msgBox.exec();

    switch (ret) {
        case QMessageBox::Yes:
            qDebug() << "User said Yes";
            break;
        case QMessageBox::No:
            qDebug() << "USer said No";
            break;
        case QMessageBox::Cancel:
            qDebug() << "USer said Cancel";
            break;
    }




    /*
    QMessageBox::information(this, "Window Title", "The document has been modified.",
                             QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::No);
                             */

    /*
    int ret = QMessageBox::question(this, "Window Title", "The document has been modified.",
                             QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::No);

    switch (ret) {
        case QMessageBox::Yes:
            qDebug() << "User said Yes";
            break;
        case QMessageBox::No:
            qDebug() << "USer said No";
            break;
        case QMessageBox::Cancel:
            qDebug() << "USer said Cancel";
            break;
    }
    */


}
