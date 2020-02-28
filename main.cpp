#include "mainwindow.h"
#include "idlefilter.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.installEventFilter(new IdleFilter());
    w.show();
    return a.exec();
}
