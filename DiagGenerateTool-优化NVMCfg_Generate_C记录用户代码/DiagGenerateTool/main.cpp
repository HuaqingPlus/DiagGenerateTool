#include "mainwindow.h"
#include <QApplication>

MainWindow* MW;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MW = new MainWindow;
    MW->show();
    return a.exec();
}
