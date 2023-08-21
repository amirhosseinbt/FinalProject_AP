#include "a_signup.h"
#include "ui_a_signup.h"
#include <fstream>
//#include <user.h>
A_Signup::A_Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::A_Signup)
{
    ui->setupUi(this);
    //use css for design windows
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btnsignup->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");


    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));


    Registrant_User = new Anonymous_User();


    //connection for result of each user's method to show suitable message
    connect(Registrant_User,SIGNAL(Validate(QString&,QValidator::State&)),this,SLOT(Validator(QString&,QValidator::State&)));
    ui->lblpassword->hide();
    ui->lblusername->hide();
}

A_Signup::~A_Signup()
{
    delete ui;
    delete Registrant_User;
}

void A_Signup::Get_MainWindow(MainWindow *m)//for sharing mainwindow all over the program
{
    mw = m;
}

void A_Signup::Validator(QString &message, QValidator::State &st)//shows message and get its message from user's method
{
    if(st == QValidator::Invalid)
    {
        QMessageBox::information(this,"Warning",message);
        return;
    }
}

void A_Signup::on_btnsignup_clicked()
{
        if(ui->txtusername->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Username.");
            return;
        }
        else if(ui->txtpassword->text().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must enter Password.");
            return;
        }
        else
        {
            if(Registrant_User->Set_Username(ui->txtusername->text())&&
                Registrant_User->Set_Password(ui->txtpassword->text()))
            {
                Registrant_User->Set_Name("");
                Registrant_User->Set_Type();
                QFile Users("User_file.txt");
                if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
                {
                    QMessageBox::information(this,"Warning","! File can not open.");
                    return;
                }
                else
                {
                    QTextStream file(&Users);
                    QStringList user_list;
                    bool flag = false;
                    while (!file.atEnd())//check for existing username
                    {
                        user_list = file.readLine().split("%$%");
                        if(Registrant_User->Get_Username() == user_list.at(1))
                        {
                            QMessageBox::information(this,"Warning","! Username exists.");
                            flag = true;
                            break;
                        }
                    }
                    if(!flag)
                    {

                        QFile Last_user_id("Last_user_id.txt");
                        if(!Last_user_id.open(QIODevice::ReadWrite|QIODevice::Text))//for set an unique id to each account
                        {
                            QMessageBox::information(this,"Warning","! File can not open.");
                            return;
                        }
                        else
                        {
                            QTextStream file(&Last_user_id);
                            if(Last_user_id.size() == 0)
                            {
                                file << 1 <<"#" <<'\n';
                                Registrant_User->Set_Userid(1);
                            }
                            else
                            {
                                int last = 1;
                                QStringList id;
                                while (!file.atEnd())
                                {
                                    id = file.readLine().split("#");
                                    if(id.at(0).toInt() > last)
                                    {
                                        last = id.at(0).toInt();

                                    }
                                }
                                file << (last+1)<<"#"<<'\n';
                                Registrant_User->Set_Userid(last+1);

                            }
                            Last_user_id.close();
                        }
                       Registrant_User->Set_Password_History(Registrant_User->Get_Password());//set in password history file
                       file << Registrant_User;

                    }
                    else
                    {
                        Users.close();
                        return;
                    }
                    Users.close();
                }

                QMessageBox::information(this,"Successful","* Registration was successful.");
                mw->Get_User(Registrant_User);
                mw->show();
                this->hide();
            }
        }
}

