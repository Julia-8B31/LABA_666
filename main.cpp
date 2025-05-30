#include "mainwindow.h"

#include <QApplication>

extern void test_start();

int main(int argc, char *argv[])
{
    test_start();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
