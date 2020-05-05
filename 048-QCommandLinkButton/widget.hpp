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
    void on_commandLinkButton_clicked();

    void on_commandLinkButton_2_clicked();

    void on_commandLinkButton_3_clicked();

    void on_pushButtonOk_clicked();

    void on_pushButtonClose_clicked();

private:
    Ui::Widget *ui;
    void selectionOption(QObject *sender);
    QString qclBtnText;

};
#endif // WIDGET_HPP
