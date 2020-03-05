#include "widgetorhan.hpp"
#include <QLabel>
#include <QPushButton>

WidgetOrhan::WidgetOrhan(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Orhan", this);


    QFont lFont("Times", 25, QFont::Bold);
    QLabel *label1 = new QLabel("Test test test", this);
    label1->setAutoFillBackground(true);
    label1->setFont(lFont);
    label1->move(50,100);

}
