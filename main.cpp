#include "mainwindow.h"
#include "idlefilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.installEventFilter(new IdleFilter());
    MainWindow w;
    w.show();
    return a.exec();
}
