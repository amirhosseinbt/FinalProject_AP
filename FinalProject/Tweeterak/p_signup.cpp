#include "p_signup.h"
#include "ui_p_signup.h"

//#include <user.h>
P_SignUp::P_SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::P_SignUp)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}"
                        "QTextEdit,QDateEdit{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_signup->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");

    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));

    Registrant_User = new Personal_User();

    //connection for showing result of user's method
    connect(Registrant_User,SIGNAL(Validate(QString&,QValidator::State&)),this,SLOT(Validator(QString&,QValidator::State&)));


    ui->lbl_biography->hide();
    ui->lbl_country->hide();
    ui->lbl_link->hide();
    ui->lbl_name->hide();
    ui->lbl_password->hide();
    ui->lbl_phonenumber->hide();
    ui->lbl_username->hide();
    ui->lbl_organusername->hide();
    ui->txt_phonenumber->setText("98");
}

P_SignUp::~P_SignUp()
{
    delete ui;
    delete Registrant_User;
}

void P_SignUp::Get_MainWindow(MainWindow *m)
{
    mw = m;
}
void P_SignUp::Validator(QString &message, QValidator::State &st)
{
    if(st == QValidator::Invalid)
    {
        QMessageBox::information(this,"Warning",message);
        return;
    }
}
void P_SignUp::on_btn_signup_clicked()
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
    else
    {
        if(Registrant_User == nullptr)
        {
            QMessageBox::information(this,"Warning","! User does not construct.");
            return;
        }
        else
        {
            QString filter=""; //for deleting \n form text
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
                Registrant_User->Set_Birthday(ui->bth_date->date());
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
                    bool flag_check_organ_uname = false;
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
                        if(ui->txt_organusername->text() == user_list.at(1) && user_list.at(0)=="O")//check organ username existence
                        {
                            flag_check_organ_uname = true;
                            Registrant_User->Set_Organ_id(user_list.at(15).toInt());
                        }
                    }
                    if(!flag_check_username && (flag_check_organ_uname||ui->txt_organusername->text().isEmpty()))
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
                    else if(!ui->txt_organusername->text().isEmpty())
                    {
                        QMessageBox::information(this,"Warning","! OrganUsername does not exist Or it is not an Organization account.");
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
}

