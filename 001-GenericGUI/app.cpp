// Base GUI Program in Qt

#include <QApplication>
#include "mainwindow.hpp"

int main(int  argc, char * argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    app.exec();

    return 0;
}
