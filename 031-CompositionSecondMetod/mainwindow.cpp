#include "mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    m_pushButton = new QPushButton("Cancel", this);
}

MainWindow::~MainWindow()
{
    //Buna ihtiyacımız yok!!!
    //delete m_pushButton;
}
