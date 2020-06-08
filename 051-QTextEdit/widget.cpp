#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->textEdit->setPlaceholderText("This is a QTextEdit");

    connect(ui->pushButtonSelectAll, &QPushButton::clicked, [=](){
        ui->textEdit->selectAll();
    });

    connect(ui->pushButtonCopy, &QPushButton::clicked, [=](){
        ui->textEdit->copy();
    });

    connect(ui->pushButtonCut, &QPushButton::clicked, [=](){
        ui->textEdit->cut();
    });

    connect(ui->pushButtonPaste, &QPushButton::clicked, [=](){
        ui->textEdit->paste();
    });

    connect(ui->pushButtonUndo, &QPushButton::clicked, [=](){
        ui->textEdit->undo();
    });

    connect(ui->pushButtonRedo, &QPushButton::clicked, [=](){
        ui->textEdit->redo();
    });

    connect(ui->pushButtonPlainText, &QPushButton::clicked, [=](){
        ui->textEdit->setPlainText("<h1>Country</h1><p>Turkey : </br> <ul> <li>İstanbul</li> <li>Kocaeli</li><li>Kastamonu</li><li>Ankara</li><li>İzmir</li><li>Trabzon</li><li>Erzurum</li></ul></p>");

    });

    connect(ui->pushButtonHtml, &QPushButton::clicked, [=](){
        ui->textEdit->setHtml("<h1>Country</h1><p>Turkey : </br> <ul> <li>İstanbul</li> <li>Kocaeli</li><li>Kastamonu</li><li>Ankara</li><li>İzmir</li><li>Trabzon</li><li>Erzurum</li></ul></p>");
    });


    connect(ui->pushButtonGrapText, &QPushButton::clicked, [=](){
        qDebug() << "The plain text is a text : " << ui->textEdit->toPlainText();
    });

    connect(ui->pushButtonGrapHtml, &QPushButton::clicked, [=](){
      qDebug() << "The plain text is a html : " << ui->textEdit->toHtml();
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonReadOnly_clicked()
{
    if(ui->textEdit->isReadOnly())
    {
        ui->textEdit->setReadOnly(false);
        ui->pushButtonReadOnly->setText("Disable");
    } else {
        ui->textEdit->setReadOnly(true);
        ui->pushButtonReadOnly->setText("Enable");
    }
}
