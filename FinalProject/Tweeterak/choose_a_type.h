#ifndef CHOOSE_A_TYPE_H
#define CHOOSE_A_TYPE_H

#include <QDialog>
#include <o_signup.h>
#include <p_signup.h>
#include <a_signup.h>
#include <QMessageBox>
#include <QObject>
#include <QString>
#include <QColor>
#include <QPalette>
#include <mainwindow.h>
namespace Ui {
class Choose_A_Type;
}

class Choose_A_Type : public QDialog
{
    Q_OBJECT

public:
    explicit Choose_A_Type(QWidget *parent = nullptr);
    void Access_MainWindow(MainWindow* m);
    ~Choose_A_Type();
private slots:
    void on_btn_confirm_clicked();

private:
    Ui::Choose_A_Type *ui;
    O_Signup *O_su;
    P_SignUp *P_su;
    A_Signup *A_su;
    MainWindow * Mainw;
};

#endif // CHOOSE_A_TYPE_H
