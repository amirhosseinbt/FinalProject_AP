#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit{border-radius:10px; border:1px solid #2D25A4; background-color:#E1DBED;}");
    ui->btn_login->setStyleSheet("QPushButton{border:none;}");
    ui->btn_signup->setStyleSheet("QPushButton{border:none;}");
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
    QPixmap Login(":/icons/img/login.png");
    QIcon Login_icnon(Login);
    ui->btn_login->setIcon(Login_icnon);
    ui->btn_login->setIconSize(QSize(80,80));
    ui->btn_login->setFixedSize(QSize(80,80));
    QPixmap Signup(":/icons/img/signup.png");
    QIcon Signup_icnon(Signup);
    ui->btn_signup->setIcon(Signup_icnon);
    ui->btn_signup->setIconSize(QSize(80,80));
    ui->btn_signup->setFixedSize(QSize(80,80));
    QPixmap Logo(":/icons/img/twitter.png");
    ui->lbl_logo->setFixedSize(144,144);
    ui->lbl_logo->setPixmap(Logo.scaled(ui->lbl_logo->width(),ui->lbl_logo->height(),Qt::KeepAspectRatio));
    m = new MainWindow();
    connect(m,SIGNAL(Logout()),this,SLOT(show()));
    ui->lbl_password->hide();
    ui->lbl_username->hide();

}

Login::~Login()
{
    delete ui;
}





void Login::on_btn_signup_clicked()
{
    ui->txt_username->clear();
    ui->txt_password->clear();
    hide();
    choose = new Choose_A_Type();
    choose->Access_MainWindow(m);
    choose->show();
}


void Login::on_btn_login_clicked()
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
    else
    {
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
            bool flag = false;
            while(!file.atEnd())
            {
                user_list = file.readLine().split("%$%");
                SHA256 secret;
                if(ui->txt_username->text() == user_list.at(1) &&QString::fromStdString( secret(ui->txt_password->text().toStdString()))  == user_list.at(2))
                {
                    if(user_list.at(0) == "O")
                    {
                        Current_User = new Organization_User();
                        Current_User = dynamic_cast<Organization_User*>(Current_User);
                        if(Current_User)
                        {

                            user_list >> Current_User;
                            flag = true;
                        }
                        break;
                    }
                    else if(user_list.at(0) == "P")
                    {
                        Current_User = new Personal_User();
                        Current_User = dynamic_cast<Personal_User*>(Current_User);
                        if(Current_User)
                        {

                            user_list >> Current_User;
                            flag = true;
                        }
                        break;
                    }
                    else
                    {
                        Current_User = new Anonymous_User();
                        Current_User = dynamic_cast<Anonymous_User*>(Current_User);
                        if(Current_User)
                        {

                            user_list >> Current_User;
                            flag = true;
                        }
                        break;
                    }
                }

            }
            if(!flag)
            {
                QMessageBox::information(this,"Warning","! Username or Password is incorrect.");
                return;
            }
            else
            {

                QMessageBox::information(this,"Successful","* Log In was successful.");
                m->Get_User(Current_User);
                m->show();
            }
            Users.close();
            ui->txt_password->clear();
            ui->txt_username->clear();
            this->close();

        }

    }

}

