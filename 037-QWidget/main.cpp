#include "widget.hpp"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qDebug() << "wpos : " << w.pos();
    qDebug() << "wposx : " << w.pos().x();
    qDebug() << "wposy : " << w.pos().y();
    qDebug() << "w.x : " << w.x();
    qDebug() << "w.y : " << w.y();

    /*******************************************/

    //Çalışma  alanı --> client area
    qDebug() << "width : " << w.width();
    qDebug() << "height : " << w.height();

    /**********************************/

    w.move(0, 0);
    qDebug() << "wpos : " << w.pos();
    qDebug() << "wposx : " << w.pos().x();
    qDebug() << "wposy : " << w.pos().y();
    qDebug() << "w.x : " << w.x();
    qDebug() << "w.y : " << w.y();
    /**********************************/

    qDebug() << "w rect : " << w.rect();

    qDebug() << "w size : " << w.size();

    w.move(200, 300);
    qDebug() << "w rect : " << w.rect();

    qDebug() << "w geometry : " << w.geometry();
    //setGeometry()

    qDebug() << "w frameGeometry : " << w.frameGeometry();

    qDebug() << "w frameSize : " << w.frameSize();
    /**********************************/

    qDebug() << "windowTitel : " << w.windowTitle();

    qDebug() << "isVisible : " << w.isVisible();
    w.hide();
    qDebug() << "isVisible : " << w.isVisible();
    //w.setVisible(true);
    w.show();
    qDebug() << "isVisible : " << w.isVisible();

    /**********************************/

    qDebug() << "isMaximized : " << w.isMaximized();
    //w.showMaximized();
    qDebug() << "isMaximized : " << w.isMaximized();
    //w.showMinimized();
    qDebug() << "isMaximized : " << w.isMinimized();

    //w.showFullScreen();
    qDebug() << "isFullSecreen : " << w.isFullScreen();

    w.showNormal();
    //qDebug() << "normalGeometry : " << w.normalGeometry();

    /**********************************/

    qDebug() << "isModal : " << w.isModal();

    /**********************************/

    w.setMaximumWidth(500);
    w.setMinimumWidth(100);
    w.setMaximumHeight(600);
    w.setMinimumHeight(100);

    //w.setMaximumSize(600, 600);
    //w.setMinimumSize(100, 100);

    /**********************************/

    qDebug() << "maximumWidth : " << w.maximumWidth();
    qDebug() << "minimumWidth :" << w.minimumWidth();
    qDebug() << "maximumHeight :" << w.maximumHeight();
    qDebug() << "minimumHeight :" << w.minimumHeight();

    qDebug() << "maximumSize : " << w.maximumSize();
    qDebug() << "minimumSize : " << w.minimumSize();

    return a.exec();
}
