#include "widget.hpp"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Market");

    QButtonGroup *buttonGroup = new QButtonGroup(this);
    buttonGroup->addButton(ui->checkBox1);
    buttonGroup->addButton(ui->checkBox2);
    buttonGroup->addButton(ui->checkBox3);

    buttonGroup->setExclusive(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonBuy_clicked()
{
    QString fruit = getChose(ui->groupBoxFruitNonExclusive);
    QString kg = getChose(ui->groupBoxKgExclusive);

    QString shopOrder;

    shopOrder += "Fruit : " + fruit + "\r";
    shopOrder += kg + "\n";

    QMessageBox::information(this, "Order", "Shop List: \n" + shopOrder, QMessageBox::Ok);
}

QString Widget::getChose(QObject *obj)
{
    QString shop = "";

    QList<QCheckBox*> shopList = obj->findChildren<QCheckBox*>(QString(), Qt::FindDirectChildrenOnly);

    for(QCheckBox *rObj: shopList)
    {
        if(rObj->isChecked())
        {
            shop += rObj->text() + " ";
        }
    }

    return shop;
}
