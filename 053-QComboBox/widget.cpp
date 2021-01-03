#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initComboBox();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initComboBox()
{
    ui->comboBox->addItem(QIcon(":/images/Banana.png"), "Banana");
    ui->comboBox->addItem(QIcon(":/images/Orange.png"), "Orange");
    ui->comboBox->addItem(QIcon(":/images/Cherry.png"), "Cherry");
    ui->comboBox->addItem(QIcon(":/images/Apple.png"), "Apple");

    ui->indexLineEdit->setText("0");

    ui->comboBox->setEditable(true);
    ui->comboBox->setInsertPolicy(QComboBox::InsertAtBottom);
    ui->comboBox->setDuplicatesEnabled(false);
    ui->comboBox->setMaxCount(8);

}

void Widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    qInfo() << "Current index text is : " << arg1;
}

void Widget::on_captureValueBtn_clicked()
{
    qInfo() << "Current select item index is : " << ui->comboBox->currentIndex() <<
               " and text : " << ui->comboBox->currentText();
}

void Widget::on_setValueBtn_clicked()
{
    int index = ui->indexLineEdit->text().toInt();

    if(ui->comboBox->count() > index)
        ui->comboBox->setCurrentIndex(index);
    else
        qInfo() << "Not found index";
}

void Widget::on_getValueBtn_clicked()
{
    qInfo() << "ComboBox has " << ui->comboBox->count() << " item";

    for(int i = 0; i < ui->comboBox->count(); ++i)
    {
        qInfo() << "Combox Index : " << i << "  text: " << ui->comboBox->itemText(i);
    }
}

void Widget::on_findTextBtn_clicked()
{
    QString sFndText = ui->findTextlineEdit->text();

    int index = ui->comboBox->findText(sFndText);

    if(index >= 0 && index < ui->comboBox->count())
    {
        qInfo() << "Found text : " << sFndText << " index : " << index;
    }else{
        qInfo() << "Not found " << sFndText;
    }
}

void Widget::on_removeItemBtn_clicked()
{
    ui->comboBox->removeItem(ui->comboBox->currentIndex());
}
