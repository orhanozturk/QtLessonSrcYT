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
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_captureValueBtn_clicked();

    void on_setValueBtn_clicked();

    void on_getValueBtn_clicked();

    void on_findTextBtn_clicked();

    void on_removeItemBtn_clicked();

private:
    Ui::Widget *ui;
    void initComboBox();

};
#endif // WIDGET_HPP
