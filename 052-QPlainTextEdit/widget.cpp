#include "widget.hpp"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlaceholderText("This is a QPlainTextEdit");
    //ui->plainTextEdit->setUndoRedoEnabled(false);
    //ui->plainTextEdit->setMaximumBlockCount(0);
    blockCount = 0;

    connect(ui->pushButtonSelectAll, &QPushButton::clicked, [=](){
        ui->plainTextEdit->selectAll();
    });

    connect(ui->pushButtonCopy, &QPushButton::clicked, [=](){
        ui->plainTextEdit->copy();
    });

    connect(ui->pushButtonCut, &QPushButton::clicked, [=](){
        ui->plainTextEdit->cut();
    });

    connect(ui->pushButtonPaste, &QPushButton::clicked, [=](){
        ui->plainTextEdit->paste();
    });

    connect(ui->pushButtonUndo, &QPushButton::clicked, [=](){
        ui->plainTextEdit->undo();
    });

    connect(ui->pushButtonRedo, &QPushButton::clicked, [=](){
        ui->plainTextEdit->redo();
    });

    connect(ui->pushButtonAppend, &QPushButton::clicked, [=](){
        ui->plainTextEdit->appendPlainText("Orhan");
    });

    connect(ui->plainTextEdit, &QPlainTextEdit::blockCountChanged, [=](){
        qDebug() << "blockCount : " << ui->plainTextEdit->blockCount();
    });

    connect(ui->pushButtonCountPlus, &QPushButton::clicked, [=](){
        ui->plainTextEdit->setMaximumBlockCount(++blockCount);
    });

    connect(ui->pushButtonCountIn, &QPushButton::clicked, [=](){
        ui->plainTextEdit->setMaximumBlockCount(--blockCount);
    });

    connect(ui->pushButtonOverwriteMode, &QPushButton::clicked, [=](){

        if(ui->plainTextEdit->overwriteMode())
        {
            ui->pushButtonOverwriteMode->setText("OverwriteMode Enable");
            ui->plainTextEdit->setOverwriteMode(false);
        }else {
            ui->pushButtonOverwriteMode->setText("OverwriteMode Disable");
            ui->plainTextEdit->setOverwriteMode(true);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonReadOnly_clicked()
{
    if(ui->plainTextEdit->isReadOnly())
    {
        ui->plainTextEdit->setReadOnly(false);
        ui->pushButtonReadOnly->setText("Disable");
    } else {
        ui->plainTextEdit->setReadOnly(true);
        ui->pushButtonReadOnly->setText("Enable");
    }
}
