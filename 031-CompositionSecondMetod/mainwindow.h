#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
//#include <QPushButton>

//incomplete
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QPushButton *m_pushButton;
};

#endif // MAINWINDOW_H
