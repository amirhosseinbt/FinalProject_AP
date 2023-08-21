#ifndef O_SIGNUP_H
#define O_SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QColor>
#include <QPalette>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "user.h"
#include "mainwindow.h"
namespace Ui {
class O_Signup;
}

class O_Signup : public QDialog
{
    Q_OBJECT

public:
    explicit O_Signup(QWidget *parent = nullptr);
    ~O_Signup();
    void Get_MainWindow(MainWindow* m);

private slots:
    void on_btn_signup_clicked();
    void Validator(QString& message,QValidator::State &st);

private:
    Ui::O_Signup *ui;
    //User * user = new Organization_User();
    Organization_User* Registrant_User;
    MainWindow* mw;
};

#endif // O_SIGNUP_H
