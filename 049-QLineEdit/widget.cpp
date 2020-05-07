#include "widget.hpp"
#include "ui_widget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QLineEdit Demo");
    initUI();

    connect(m_pushButtonOK, &QPushButton::clicked, this, &Widget::pushButtonOkClickedHandler);
    connect(m_pushButtonOK, &QPushButton::clicked, m_lineEditFirstName, &QLineEdit::clear);
    connect(m_pushButtonOK, &QPushButton::clicked, m_lineEditLastName, &QLineEdit::clear);
    connect(m_pushButtonOK, &QPushButton::clicked, m_lineEditCountry, &QLineEdit::clear);
    connect(m_pushButtonOK, &QPushButton::clicked, m_lineEditBirthDay, &QLineEdit::clear);
    connect(m_pushButtonOK, &QPushButton::clicked, m_lineEditPassword, &QLineEdit::clear);

    //QObject::connect(m_lineEditFirstName, SIGNAL(textChanged(QString)),
    //                 this, SLOT(textEditTextCahngedHandler(QString)));



//    connect(m_lineEditFirstName, &QLineEdit::cursorPositionChanged, [=](){
//         qDebug() << "Cursor position changed is : " << m_lineEditFirstName->cursorPosition();
//    });

//    connect(m_lineEditFirstName, &QLineEdit::editingFinished, [=](){
//         qDebug() << "Editing Finished";
//    });

//    connect(m_lineEditFirstName, &QLineEdit::returnPressed, [=](){
//         qDebug() << "Return Pressed";
//    });

//    connect(m_lineEditFirstName, &QLineEdit::selectionChanged, [=](){
//         qDebug() << "Selection Changed";
//    });

//    connect(m_lineEditFirstName, &QLineEdit::textChanged, [=](){
//         qDebug() << "Text Changed :" << m_lineEditFirstName->text();
//    });

//    connect(m_lineEditFirstName, &QLineEdit::textEdited, [=](){
//         qDebug() << "Text Edited :" << m_lineEditFirstName->text();
//    });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::pushButtonOkClickedHandler()
{
    /*
    QString firstLastName;
    firstLastName = QString("Fist-Last Name : %1 %2").arg(m_lineEditFirstName->text()).arg(m_lineEditLastName->text());

    qDebug() << firstLastName;
    */

    //m_lineEditFirstName->setCursorPosition(5);
    //m_lineEditFirstName->paste();

    QString firstName = m_lineEditFirstName->text();
    QString lastName = m_lineEditLastName->text();
    QString country = m_lineEditCountry->text();
    QString birthDay = m_lineEditBirthDay->text();
    QString password = m_lineEditPassword->text();

    if(!firstName.isEmpty() && !lastName.isEmpty() && !country.isEmpty() && !birthDay.isEmpty() && !password.isEmpty())
    {
        qDebug() <<"First Name: " << firstName;
        qDebug() <<"Last Name: " << lastName;
        qDebug() <<"Country: " << country;
        qDebug() <<"BirthDay : " << birthDay;
        qDebug() <<"PassWord : " << password;
    }else {
        qDebug() <<"Failed";
    }

}

void Widget::textEditTextCahngedHandler(const QString &str)
{
    qDebug() << str;
}

void Widget::initUI()
{
    //resize(280, 320);

    m_lineEditFirstName = new QLineEdit(this);
    m_lineEditFirstName->move(10, 10);
    m_lineEditFirstName->setMinimumSize(250, 40);
    //m_lineEditFirstName->setMaxLength(10);
    m_lineEditFirstName->setFont(QFont("Concolas", 13));
    //m_lineEditFirstName->setText("Orhan");
    m_lineEditFirstName->setPlaceholderText("Please, Enter first name");
    m_lineEditFirstName->setReadOnly(false);
    m_lineEditFirstName->setClearButtonEnabled(true);


    m_lineEditLastName = new QLineEdit(this);
    m_lineEditLastName->move(10, 60);
    m_lineEditLastName->setMinimumSize(250, 40);
    m_lineEditLastName->setFont(QFont("Concolas", 13));
    m_lineEditLastName->setPlaceholderText("Please, Enter last name");
    m_lineEditLastName->setClearButtonEnabled(true);



    m_lineEditCountry = new QLineEdit(this);
    m_lineEditCountry->move(10, 110);
    m_lineEditCountry->setMinimumSize(250, 40);
    m_lineEditCountry->setFont(QFont("Concolas", 13));
    m_lineEditCountry->setPlaceholderText("Please, Enter your country");
    m_lineEditCountry->setClearButtonEnabled(true);


    m_lineEditBirthDay = new QLineEdit(this);
    m_lineEditBirthDay->move(10, 160);
    m_lineEditBirthDay->setMinimumSize(250, 40);
    m_lineEditBirthDay->setFont(QFont("Concolas", 13));
    m_lineEditBirthDay->setInputMask("00/00/0000");


    m_lineEditPassword = new QLineEdit(this);
    m_lineEditPassword->move(10, 210);
    m_lineEditPassword->setMinimumSize(250, 40);
    m_lineEditPassword->setFont(QFont("Concolas", 13));
    m_lineEditPassword->setEchoMode(QLineEdit::Password);


    m_pushButtonOK = new QPushButton("OK", this);
    m_pushButtonOK->move(10, 260);
    m_pushButtonOK->setMinimumSize(120, 40);

    m_pushButtonCancel = new QPushButton("Cancel", this);
    m_pushButtonCancel->move(135, 260);
    m_pushButtonCancel->setMinimumSize(125, 40);
}


void Widget::on_pushButtonOk_clicked()
{
    QString firstName = ui->lineEditFirstName->text();
    QString lastName = ui->lineEditLastName->text();
    QString country = ui->lineEditCountry->text();
    QString birthDay = ui->lineEditBirthDay->text();
    QString password = ui->lineEditPassword->text();

    if(!firstName.isEmpty() && !lastName.isEmpty() && !country.isEmpty() && !birthDay.isEmpty() && !password.isEmpty())
    {
        qDebug() <<"First Name: " << firstName;
        qDebug() <<"Last Name: " << lastName;
        qDebug() <<"Country: " << country;
        qDebug() <<"BirthDay : " << birthDay;
        qDebug() <<"PassWord : " << password;
    }else {
        qDebug() <<"Failed";
    }

}
