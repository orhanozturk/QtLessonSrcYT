#include "widget.hpp"
#include "ui_widget.h"
#include <QMessageBox>
#include <QRadioButton>
#include <QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Market");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonOk_clicked()
{
    QString provisions = getChose(ui->groupBoxProvisions);
    QString fruit = getChose(ui->groupBoxFruit);
    QString kg = getChose(ui->groupBoxKg);
    QString secure = getChose(ui->groupBoxSecure);

    QString shopOrder;

    shopOrder += "Provisions : " + provisions + "\n";
    shopOrder += "Fruit : " + fruit + "\r";
    shopOrder += kg + "\n";
    shopOrder += "Secure : " + secure + "\n";

    QMessageBox::information(this, "Order", "Shop List: \n" + shopOrder, QMessageBox::Ok);
}

void Widget::on_pushButtonCancel_clicked()
{
    QMessageBox::critical(this, "Critical Message", "Don't you want to shop?");
    close();
}

QString Widget::getChose(QObject *obj)
{
    QString shop = "NoN";

    QList<QRadioButton*> shopList = obj->findChildren<QRadioButton*>(QString(), Qt::FindDirectChildrenOnly);

    for(QRadioButton *rObj: shopList)
    {
        if(rObj->isChecked())
        {
            shop = rObj->text();
            break;
        }
    }

    return shop;
}
