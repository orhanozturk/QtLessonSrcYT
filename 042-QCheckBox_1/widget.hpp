#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void doSomething(int state);
    void doTask(int state);

private:
    Ui::Widget *ui;
    QCheckBox *c_Box1;
    QCheckBox *c_Box2;
};
#endif // WIDGET_HPP
