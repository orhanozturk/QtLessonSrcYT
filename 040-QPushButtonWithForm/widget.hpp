#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

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
    void on_btnCheckable_clicked();

    void on_btnIsCheckabled_clicked();

    void on_btnAutoRepate_clicked();

    void on_btnAutoRepateToggle_clicked();

    void on_btnDefualt_clicked();

    void on_btnDefualtToggle_clicked();

    void on_btnFlat_clicked();

    void on_btnFlatToggle_clicked();

    void on_btnQuit_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_HPP
