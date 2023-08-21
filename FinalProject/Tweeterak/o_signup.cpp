#include "o_signup.h"
#include "ui_o_signup.h"

//#include<user.h>
O_Signup::O_Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::O_Signup)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}}"
                        "QTextEdit,QDateEdit{border-radius:10px;background: palette(base); border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_signup->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
    Registrant_User  = new Organization_User();
    connect(Registrant_User,SIGNAL(Validate(QString&,QValidator::State&)),this,SLOT(Validator(QString&,QValidator::State&)));
}

O_Signup::~O_Signup()
{
    delete ui;
}

void O_Signup::Get_MainWindow(MainWindow *m)
{
    mw = m;
}
void O_Signup::Validator(QString &message, QValidator::State &st)
{
    if(st == QValidator::Invalid)
    {
        QMessageBox::information(this,"Warning",message);
        return;
    }
}
void O_Signup::on_btn_signup_clicked()
{
    if(ui->txt_username->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Username.");
        return;
    }
    else if(ui->txt_password->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Password.");
        return;
    }
    else if(ui->txt_name->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Name.");
        return;
    }
    else if(ui->txt_phonenumber->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Phonenumber.");
        return;
    }
    else if(ui->txt_adminusername->text().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must enter Admin Username.");
        return;
    }
    else
    {
        if(Registrant_User == nullptr)
        {
            QMessageBox::information(this,"Warning","! User does not construct.");
            return;
        }
        else
        {
            QString filter="";
            for(int i = 0; i <ui->txt_biography->toPlainText().size();i++ )
            {
                if(ui->txt_biography->toPlainText()[i] != '\n')
                {
                    filter.append(ui->txt_biography->toPlainText()[i]);
                }
            }
            if(Registrant_User->Set_Username(ui->txt_username->text())&&
                Registrant_User->Set_Password(ui->txt_password->text()) &&
                Registrant_User->Set_Phonenumber(ui->txt_phonenumber->text()) &&
                Registrant_User->Set_Biography(filter))
            {
                Registrant_User->Set_Country(ui->txt_country->text());
                Registrant_User->Set_Name(ui->txt_name->text());
                Registrant_User->Set_Link(ui->txt_link->text());
                Registrant_User->Set_Type();
                QFile Users ("User_file.txt");
                if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
                {
                    QMessageBox::information(this,"Warning","! File can not open.");
                    return;
                }
                else
                {
                    QTextStream file(&Users);
                    QStringList user_list;
                    bool flag_check_admin_uname = false;
                    bool flag_check_username = false;
                    while(!file.atEnd())
                    {
                        user_list = file.readLine().split("%$%");
                        if(Registrant_User->Get_Username() == user_list.at(1))
                        {
                            flag_check_username =true;
                            QMessageBox::information(this,"Warning","! Username exists");
                            break;
                        }
                        if(ui->txt_adminusername->text() == user_list.at(1) && user_list.at(0)!="O" && user_list.at(0)!="A")
                        {
                            flag_check_admin_uname = true;
                            Registrant_User->Set_Admin_id(user_list.at(15).toInt());
                        }
                    }
                    if(!flag_check_username && flag_check_admin_uname)
                    {
                        QFile Last_user_id("Last_user_id.txt");
                        if(!Last_user_id.open(QIODevice::ReadWrite|QIODevice::Text))
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
                        Registrant_User->Set_Password_History(Registrant_User->Get_Password());
                        file << Registrant_User;
                    }
                    else if(flag_check_username)
                    {
                        Users.close();
                        return;
                    }
                    else
                    {
                        QMessageBox::information(this,"Warning","! AdminUsername does not exist Or it is not Personal account.");
                        Users.close();
                        return;
                    }
                    Users.close();
                }
                QMessageBox::information(this,"Successful","* Registration was successful.");
                mw->Get_User(Registrant_User);
                mw->show();
                this->close();
            }
            else
            {
                return;
            }
        }
    }
}

