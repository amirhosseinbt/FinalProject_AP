#include "mainwindow.h"
#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/img/twitter.png"));
//    MainWindow w;
//    w.show();
    Login l;
    l.show();
    return a.exec();
}
