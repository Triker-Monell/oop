#include "qt_mainwindow.h"
#include <QApplication>
#include "python2.7/Python.h"
#include <dirent.h>
#include "ObjRanking/allObj.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();


    return a.exec();
}
