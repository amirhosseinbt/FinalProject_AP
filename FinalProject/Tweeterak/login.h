#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "choose_a_type.h"
#include "user.h"
#include <mainwindow.h>
#include <QFile>
#include <QColor>
#include <QPalette>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
signals:
private slots:
    void on_btn_signup_clicked();

    void on_btn_login_clicked();

private:
    Ui::Login *ui;
    Choose_A_Type * choose;
    User* Current_User = nullptr;
    MainWindow * m;
};

#endif // LOGIN_H
