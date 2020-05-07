#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

class QLineEdit;
class QPushButton;

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
    void pushButtonOkClickedHandler();
    void textEditTextCahngedHandler(const QString &str);
    void on_pushButtonOk_clicked();

private:
    void initUI();
    Ui::Widget *ui;
    QLineEdit *m_lineEditFirstName;
    QLineEdit *m_lineEditLastName;
    QLineEdit *m_lineEditCountry;
    QLineEdit *m_lineEditBirthDay;
    QLineEdit *m_lineEditPassword;
    QPushButton *m_pushButtonOK;
    QPushButton *m_pushButtonCancel;
};
#endif // WIDGET_HPP
