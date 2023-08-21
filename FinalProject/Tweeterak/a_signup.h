#ifndef A_SIGNUP_H
#define A_SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QValidator>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QColor>
#include <QPalette>
#include "mainwindow.h"
#include "user.h"
namespace Ui {
class A_Signup;
}

class A_Signup : public QDialog
{
    Q_OBJECT

public:
    explicit A_Signup(QWidget *parent = nullptr);
    ~A_Signup();
    void Get_MainWindow(MainWindow* m);
private slots:
    void Validator(QString& message,QValidator::State &st);
    void on_btnsignup_clicked();

private:
    Ui::A_Signup *ui;
    User * Registrant_User;
    MainWindow * mw;
};

#endif // A_SIGNUP_H
