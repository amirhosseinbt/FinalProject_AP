#include "show_account.h"
#include "ui_show_account.h"

void Show_Account::Get_username(QString username)
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
        while(!file.atEnd())
        {
            user_list = file.readLine().split("%$%");
            if(username == user_list.at(1))
            {
                if(user_list.at(0) == "O")
                {
                    user = new Organization_User();

                        user_list >> user;

                }
                else if(user_list.at(0) == "P")
                {
                    user = new Personal_User();
                    user_list >> user;
                }
                else
                {
                    user = new Anonymous_User();

                    user_list >> user;
                }
            }
        }
        Users.close();
    }
    ui->txt_username->setText(user->Get_Username());
    ui->txt_name->setText(user->Get_Name());
    ui->txt_country->setText(user->Get_Country());
    ui->txt_bio->setText(user->Get_Biography());
    ui->txt_brth->setText(user->Get_Birthday().toString("yyyy/MM/dd"));
    ui->txt_link->setText(user->Get_Link());
    if(user->Get_Type()=="O")
    {
        ui->txt_adminuname->setText(dynamic_cast<Organization_User*>(user)->Get_Admin_Username());
    }
    if(user->Get_Type()=="P")
    {
        ui->txt_orguname->setText(dynamic_cast<Personal_User*>(user)->Get_Organ_Uname());
    }
    QPixmap profile_picture(user->Get_Picture_Path());
    ui->lbl_profpic->setFixedSize(100,100);
    ui->lbl_profpic->setPixmap(profile_picture.scaled(ui->lbl_profpic->width(),ui->lbl_profpic->height(),Qt::KeepAspectRatio));
    ui->widget->setAutoFillBackground(true);
    ui->widget->setPalette(QColor::fromString(user->Get_Header()));
    ui->lbl_nfollowers->setText(QString::number(user->Get_N_Followers()));
    ui->lbl_nfollowings->setText(QString::number(user->Get_N_Followings()));
    QFile Tweets ("Tweet_file.txt");
    if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
        return;
    }
    else
    {
        QTextStream file(&Tweets);
        QStringList list;
        while(!file.atEnd())
        {
            list = file.readLine().split("%$%");
            if(list.at(0).toInt() == user->Get_Userid())
            {
                QString line =user->Get_Username()+"  "+list.at(1)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                ui->list_tweets->addItem(line);
            }
        }

    }
    Tweets.close();

}

void Show_Account::Get_Current_User(User *user)
{
    Current_User = user;
}

Show_Account::Show_Account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Show_Account)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}"
                        "QTextEdit{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_mention->setStyleSheet("QPushButton{border:none;}");
    ui->btn_follow->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->btn_unfollow->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->list_tweets->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");

    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
    QPixmap Like(":/icons/img/like.png");
    QPixmap Mention(":/icons/img/mention.png");

    QIcon Like_icnon(Like);
    QIcon Mention_icnon(Mention);

    ui->btn_like->setIcon(Like_icnon);
    ui->btn_like->setIconSize(QSize(80,80));
    ui->btn_like->setFixedSize(QSize(80,80));

    ui->btn_mention->setIcon(Mention_icnon);
    ui->btn_mention->setIconSize(QSize(80,80));
    ui->btn_mention->setFixedSize(QSize(80,80));

}

Show_Account::~Show_Account()
{
    delete ui;
}

void Show_Account::Refresh()
{
    if(user == nullptr)
    {
        return;
    }
    ui->lbl_nfollowers->setText(QString::number(user->Get_N_Followers()));
    ui->lbl_nfollowings->setText(QString::number(user->Get_N_Followings()));
    ui->list_tweets->clear();
    QFile Tweets ("Tweet_file.txt");
    if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
        return;
    }
    else
    {
        QTextStream file(&Tweets);
        QStringList list;
        while(!file.atEnd())
        {
            list = file.readLine().split("%$%");
            if(list.at(0).toInt() == user->Get_Userid())
            {
                QString line =user->Get_Username()+"  "+list.at(1)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                ui->list_tweets->addItem(line);

            }
        }

    }
    Tweets.close();

}

void Show_Account::on_btn_like_clicked()
{
    Tweet *t =new Tweet();
    if(ui->list_tweets->currentItem() == nullptr)
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {

        QStringList list_item = ui->list_tweets->currentItem()->text().split("  ");
        QFile Tweets ("Tweet_file.txt");
        if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&Tweets);
            QStringList list;
            bool flag = false;
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                for(int i = 0;i < list.at(4).split(",").size();i++)
                {
                    if((list.at(4).split(",")).at(i).toInt() == Current_User->Get_Userid() && list.at(1).toInt() == list_item.at(1).toInt()&&
                        list.at(0).toInt()==user->Get_Userid())
                    {
                        flag = true;
                        QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                        break;
                    }
                }

                if(!flag)
                {
                    if(list_item.at(1).toInt() == list.at(1).toInt()&& user->Get_Userid() == list.at(0).toInt())
                    {
                        list >> t;
                        t->Set_Who_Like(Current_User->Get_Userid());
                        t->Add_Like();
                        Tweets.close();
                        QFile Tfile ("Tweet_file.txt");
                        if(!Tfile .open(QIODevice::ReadWrite|QIODevice::Text))
                        {
                            QMessageBox::information(this,"Warning","! File can not open.");
                            return;
                        }
                        else
                        {
                            QTextStream file(&Tfile );
                            QString str="";
                            while(!file.atEnd())
                            {
                                QString line = file.readLine();
                                QStringList list = line.split("%$%");
                                if(list.at(0).toInt() == user->Get_Userid() && list.at(1).toInt() == list_item.at(1).toInt())
                                {
                                }
                                else
                                {
                                    str.append(line+'\n');
                                }
                            }
                            Tfile .resize(0);
                            file << str;
                            file << t;
                            Tfile .close();
                            QMessageBox::information(this,"Successful","* Tweet successfuly liked.");
                            Tweets.close();
                            Refresh();
                            return;

                        }
                    }

                }
            }
            Tweets.close();
        }
    }
}


void Show_Account::on_btn_follow_clicked()
{
    if(user->Get_Type()=="A"||user->Get_Userid() == Current_User->Get_Userid())
    {
        QMessageBox::information(this,"Warning","! You Can not follow this user.");
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
            QStringList list;
            bool flag = false;
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                if(Current_User->Get_Type()=="A")
                {
                    for(int i = 0;i < list.at(16).split(",").size();i++)
                    {
                        if((list.at(16).split(",")).at(i).toInt() == user->Get_Userid()&& list.at(14).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            QMessageBox::information(this,"Warning","! You have already followed this account.");
                            break;
                        }
                    }
                }
                else
                {

                    for(int i = 0;i < list.at(17).split(",").size();i++)
                    {
                        if((list.at(17).split(",")).at(i).toInt() == user->Get_Userid()&&list.at(15).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            QMessageBox::information(this,"Warning","! You have already followed this account.");
                            break;
                        }
                    }

                }
            }
            if(!flag)
            {

                Current_User->Set_Followings(user->Get_Userid());
                user->Set_Followers(Current_User->Get_Userid());
                Current_User->Change_N_Followings();
                user->Change_N_Followers();
                QMessageBox::information(this,"Successful","* Account successfuly Followed.");
                Refresh();

            }
            Users.close();
        }
    }
}


void Show_Account::on_btn_mention_clicked()
{
    Mwindow = new Mention();
    Mwindow->Get_Mention_userid(Current_User->Get_Userid());
    Mwindow->Get_Userid(user->Get_Userid());
    if(ui->list_tweets->currentItem() == nullptr)
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        QStringList list_item = ui->list_tweets->currentItem()->text().split("  ");
        Mwindow->Get_Tweetid(list_item.at(1).toInt());
        Mwindow->show();
    }

}


void Show_Account::on_btn_unfollow_clicked()
{
    if(user->Get_Type()=="A"||user->Get_Userid() == Current_User->Get_Userid())
    {
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
            QStringList list;
            bool flag = false;
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                if(Current_User->Get_Type()=="A")
                {
                    for(int i = 0;i < list.at(16).split(",").size();i++)
                    {
                        if((list.at(16).split(",")).at(i).toInt() == user->Get_Userid()&& list.at(14).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            Current_User->Erase_Following(user->Get_Userid());
                            user->Erase_Follower(Current_User->Get_Userid());
                            QMessageBox::information(this,"Successful","* Account Unfollowed.");
                            Refresh();
                            break;
                        }
                    }
                }
                else
                {

                    for(int i = 0;i < list.at(17).split(",").size();i++)
                    {
                        if((list.at(17).split(",")).at(i).toInt() == user->Get_Userid()&&list.at(15).toInt() == Current_User->Get_Userid())
                        {
                            flag = true;
                            Current_User->Erase_Following(user->Get_Userid());
                            user->Erase_Follower(Current_User->Get_Userid());
                            QMessageBox::information(this,"Successful","* Account Unfollowed.");
                            Refresh();
                            break;
                        }
                    }

                }
            }
            if(!flag)
            {
                QMessageBox::information(this,"Warning","! You didn't follow this account.");

            }
            Users.close();
        }
    }
}

