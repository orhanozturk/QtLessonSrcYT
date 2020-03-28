#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

class QRadioButton;
class QPushButton;
class QGroupBox;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void pushButtonHandller();

    void on_pButton2_clicked();

private:
    Ui::Widget *ui;

    QRadioButton *rButton1;
    QRadioButton *rButton2;
    QRadioButton *rButton3;
    QRadioButton *rButton4;
    QRadioButton *rButton5;
    QRadioButton *rButton6;

    QGroupBox *groupBox1;
    QGroupBox *groupBox2;

    QPushButton *pButton1;

};
#endif // WIDGET_HPP
