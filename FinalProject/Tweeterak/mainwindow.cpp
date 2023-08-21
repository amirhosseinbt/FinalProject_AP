#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <choose_a_type.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->list_tweets->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_logout->setStyleSheet("QPushButton{border:none;}");
    ui->btn_mention->setStyleSheet("QPushButton{border:none;}");
    ui->btn_search->setStyleSheet("QPushButton{border:none;}");
    ui->btn_setting->setStyleSheet("QPushButton{border:none;}");
    ui->btn_tweet->setStyleSheet("QPushButton{border:none;}");
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString(/*"#9ED9FF"*/"#FFFFFF"));
    QPixmap Setting(":/icons/img/setting.png");
    QPixmap Tweet(":/icons/img/add.png");
    QPixmap Like(":/icons/img/like.png");
    QPixmap Mention(":/icons/img/mention.png");
    QPixmap Logout(":/icons/img/logout.png");
    QPixmap Search(":/icons/img/search.png");

    QIcon Setting_icnon(Setting);
    QIcon Tweet_icnon(Tweet);
    QIcon Like_icnon(Like);
    QIcon Mention_icnon(Mention);
    QIcon Logout_icnon(Logout);
    QIcon Search_icnon(Search);

    ui->btn_search->setIcon(Search_icnon);
    ui->btn_search->setIconSize(QSize(80,80));
    ui->btn_search->setFixedSize(QSize(80,80));


    ui->btn_setting->setIcon(Setting_icnon);
    ui->btn_setting->setIconSize(QSize(80,80));
    ui->btn_setting->setFixedSize(QSize(80,80));

    ui->btn_tweet->setIcon(Tweet_icnon);
    ui->btn_tweet->setIconSize(QSize(80,80));
    ui->btn_tweet->setFixedSize(QSize(80,80));

    ui->btn_like->setIcon(Like_icnon);
    ui->btn_like->setIconSize(QSize(80,80));
    ui->btn_like->setFixedSize(QSize(80,80));

    ui->btn_mention->setIcon(Mention_icnon);
    ui->btn_mention->setIconSize(QSize(80,80));
    ui->btn_mention->setFixedSize(QSize(80,80));

    ui->btn_logout->setIcon(Logout_icnon);
    ui->btn_logout->setIconSize(QSize(80,80));
    ui->btn_logout->setFixedSize(QSize(80,80));

//    ui->list_tweets->item
//    ui->list_tweets->
}

void MainWindow::Get_User(User *user)
{
    Current_User = user;
    Refresh_List();
    QPixmap profile_picture(Current_User->Get_Picture_Path());
    ui->lbl_picture->setFixedSize(100,100);
    ui->lbl_picture->setPixmap(profile_picture.scaled(ui->lbl_picture->width(),ui->lbl_picture->height(),Qt::KeepAspectRatio));
    ui->lbl_nfollowers->setText(QString::number(Current_User->Get_N_Followers()));
    ui->lbl_nfollowings->setText(QString::number(Current_User->Get_N_Followings()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Refresh_List()
{
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
            if(list.at(0).toInt() == Current_User->Get_Userid())
            {
                QString line =Current_User->Get_Username()+"  "+list.at(1)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                ui->list_tweets->addItem(line);
            }
        }

    }
    Tweets.close();
}

void MainWindow::Change_user(User *user)
{
    if(user == nullptr)
    {
        Current_User = nullptr;
        this->close();
        emit Logout();
    }
    else
    {
        this->close();
        this->Get_User(user);
        this->show();
    }
}

void MainWindow::on_btn_tweet_clicked()
{
    T_Window = new TweetWindow();
    T_Window->Get_User(Current_User);
    T_Window->show();
    connect(T_Window,&TweetWindow::finished,this,&MainWindow::Refresh_List);
}


void MainWindow::on_btn_logout_clicked()
{
    Current_User = nullptr;
    this->close();
    emit Logout();
}


void MainWindow::on_btn_setting_clicked()
{
    set_win = new SettingW();
    set_win->Get_User(Current_User);
    set_win->show();
    connect(set_win,SIGNAL(Send_Current_User(User*)),this,SLOT(Change_user(User*)));
}


void MainWindow::on_btn_like_clicked()
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
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                bool flag = false;
                for(int i = 0;i < list.at(4).split(",").size();i++)
                {
                    if((list.at(4).split(",")).at(i).toInt() == Current_User->Get_Userid() && list.at(1).toInt() == list_item.at(1).toInt()
                        &&list.at(0).toInt() == Current_User->Get_Userid())
                    {
                        flag = true;
                        QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                        break;
                    }
                }
                if(!flag)
                {

                    if(list_item.at(1).toInt() == list.at(1).toInt()&& Current_User->Get_Userid() == list.at(0).toInt())
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
                                if(list.at(0).toInt() == Current_User->Get_Userid() && list.at(1).toInt() == list_item.at(1).toInt())
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
                            Refresh_List();
                            return;
                        }
                    }
                }
                else
                {
                    break;
                }
            }


            Tweets.close();
        }

        Refresh_List();
    }

}


void MainWindow::on_btn_search_clicked()
{

    if(ui->txt_search->text().contains("#"))
    {
        Hash_TagForm *myfirst=new Hash_TagForm();
        myfirst->Set_C_User_Id(Current_User->Get_Userid());
        if(myfirst->Set_t(ui->txt_search->text()))
        {
            ui->txt_search->clear();
            myfirst->show();

        }

    }
    else if(!ui->txt_search->text().isEmpty())
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
                if(ui->txt_search->text() == user_list.at(1))
                {
                    flag = true;
                }
            }
            if(!flag)
            {
                QMessageBox::information(this,"Warning","! Username does not exist.");
                Users.close();
                return;
            }
            else
            {
                Users.close();
                account = new Show_Account();
                account->Get_username(ui->txt_search->text());
                account->Get_Current_User(Current_User);
                ui->txt_search->clear();
                account->show();
            }
        }

    }
    else
    {
        QMessageBox::information(this,"Warning","! You must fill search box.");
        return;
    }

}


void MainWindow::on_btn_mention_clicked()
{
    Mwindow = new Mention();
    Mwindow->Get_Mention_userid(Current_User->Get_Userid());
    Mwindow->Get_Userid(Current_User->Get_Userid());
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

