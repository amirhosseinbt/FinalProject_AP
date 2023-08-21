#include "mainwindow.h"
#include "login.h"
#include <QApplication>



// I use %$% for seperating account's , tweet's and .... items in file and use split and QStringList for this goal
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/img/twitter.png"));
    Login l;
    l.show();
    return a.exec();
}
