#include "choose_a_type.h"
#include "ui_choose_a_type.h"
Choose_A_Type::Choose_A_Type(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Choose_A_Type)
{
    ui->setupUi(this);
//    this->setStyleSheet("QLineEdit{border-radius:10px;}");
    ui->btn_confirm->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
}

void Choose_A_Type::Access_MainWindow(MainWindow *m)
{
    Mainw = m;
}

Choose_A_Type::~Choose_A_Type()
{
    delete ui;
}

void Choose_A_Type::on_btn_confirm_clicked()
{
    if(ui->rbtn_personal->isChecked())
    {
        this->close();
        P_su = new P_SignUp();
        P_su->Get_MainWindow(Mainw);
        P_su->show();
    }
    else if (ui->rbtn_organ->isChecked())
    {
        this->close();
        O_su = new O_Signup;
        O_su->Get_MainWindow(Mainw);
        O_su->show();
    }
    else if(ui->rbtn_anonymous->isChecked())
    {
        this->close();
        A_su = new A_Signup();
        A_su->Get_MainWindow(Mainw);
        A_su->show();
    }
    else
    {
        QMessageBox::information(this,"Warning","! You must choose one type.");
        return;
    }
}

