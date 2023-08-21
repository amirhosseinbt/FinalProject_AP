#ifndef P_SIGNUP_H
#define P_SIGNUP_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QColor>
#include <QPalette>
#include "mainwindow.h"
#include "user.h"
namespace Ui {
class P_SignUp;
}

class P_SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit P_SignUp(QWidget *parent = nullptr);
    ~P_SignUp();
    void Get_MainWindow(MainWindow* m);
private slots:
    void on_btn_signup_clicked();
    void Validator(QString& message,QValidator::State &st);

private:
    Ui::P_SignUp *ui;
    Personal_User * Registrant_User;
    MainWindow* mw;
};

#endif // P_SIGNUP_H
