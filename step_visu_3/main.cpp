#include "cls_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cls_MainWindow w;
    w.show();

    return a.exec();
}
