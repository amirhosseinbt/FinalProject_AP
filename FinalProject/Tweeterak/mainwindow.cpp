#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <choose_a_type.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->list_tweets->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_logout->setStyleSheet("QPushButton{border:none;}");
    ui->btn_mention->setStyleSheet("QPushButton{border:none;}");
    ui->btn_search->setStyleSheet("QPushButton{border:none;}");
    ui->btn_setting->setStyleSheet("QPushButton{border:none;}");
    ui->btn_tweet->setStyleSheet("QPushButton{border:none;}");
    ui->btn_retweet->setStyleSheet("QPushButton{border:none;}");


    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString(/*"#9ED9FF"*/"#FFFFFF"));
    QPixmap Setting(":/icons/img/setting.png");
    QPixmap Tweet(":/icons/img/add.png");
    QPixmap Like(":/icons/img/redlike.png");
    QPixmap Mention(":/icons/img/mention.png");
    QPixmap Logout(":/icons/img/logout.png");
    QPixmap Search(":/icons/img/search.png");
    QPixmap Retweet(":/icons/img/retweet.png");

    QIcon Setting_icnon(Setting);
    QIcon Tweet_icnon(Tweet);
    QIcon Like_icnon(Like);
    QIcon Mention_icnon(Mention);
    QIcon Logout_icnon(Logout);
    QIcon Search_icnon(Search);
    QIcon Retweet_icnon(Retweet);

    ui->btn_retweet->setIcon(Retweet_icnon);
    ui->btn_retweet->setIconSize(QSize(80,80));
    ui->btn_retweet->setFixedSize(QSize(80,80));

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

}

void MainWindow::Get_User(User *user)//getting user from login or signup window
{
    Current_User = user;
    Refresh_List();

    QPixmap profile_picture(Current_User->Get_Picture_Path());
    ui->lbl_picture->setFixedSize(100,100);
    ui->lbl_picture->setPixmap(profile_picture.scaled(ui->lbl_picture->width(),ui->lbl_picture->height(),Qt::KeepAspectRatio));
    ui->lbl_nfollowers->setText(QString::number(Current_User->Get_N_Followers()));
    ui->lbl_nfollowings->setText(QString::number(Current_User->Get_N_Followings()));
}

QString MainWindow::Get_Uname_byID(int id)
{
    QFile Users ("User_file.txt");
    QString uname="";
    if(!Users.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
    }
    else
    {
        QTextStream file(&Users);
        QStringList user_list;
        while(!file.atEnd())
        {
            user_list = file.readLine().split("%$%");
            if(user_list.at(0)=="A")
            {
                if(user_list.at(14).toInt() == id)
                {

                    uname = user_list.at(1);
                    break;
                }
            }
            else if(user_list.at(15).toInt() == id)
            {
                uname = user_list.at(1);
                break;
            }
        }
        Users.close();
    }
    return uname;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Refresh_List()//set id of user that tweet and tweet id and id of user that maybe retweet one tweet as
                               //a listwidgetitem data
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
            if((list.at(0).toInt() == Current_User->Get_Userid()&&(list.at(10).toInt() == Current_User->Get_Userid()||list.at(10).toInt() == 0))
                ||list.at(10).toInt() == Current_User->Get_Userid())
            {
                if(list.at(10).toInt() == 0)
                {
                    QString line =Current_User->Get_Username()+"  "+list.at(1)+"  "+"    like "+list.at(3)+"  "+list.at(2)+"  "+"     "+list.at(5);
                    QListWidgetItem * myitem = new QListWidgetItem(line);
                    QVariant mydata =list.at(0)+"%$%"+list.at(10)+"%$%"+list.at(1);
                    myitem->setData(Qt::UserRole,mydata);
                    ui->list_tweets->addItem(myitem);
                }
                else
                {

                    QString line =Current_User->Get_Username()+"  "+list.at(1)+"  "+"    like "+list.at(3)+"  "+list.at(2)+"  "+"     "+list.at(5)+
                                   "        "+"  Retweet from   "+Get_Uname_byID(list.at(0).toInt());
                    QListWidgetItem * myitem = new QListWidgetItem(line);
                    QVariant mydata =list.at(0)+"%$%"+list.at(10)+"%$%"+list.at(1);
                    myitem->setData(Qt::UserRole,mydata);
                    ui->list_tweets->addItem(myitem);
                }
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
    ui->txt_search->clear();
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

    std::vector<Tweet*> tweet_vector;
    if(ui->list_tweets->currentItem() == nullptr)
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {

        QStringList list_item = ui->list_tweets->currentItem()->text().split("  ");
        QStringList list_data = (ui->list_tweets->currentItem()->data(Qt::UserRole).toString()).split("%$%");
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
                Tweet *t =new Tweet();
                list = file.readLine().split("%$%");
                bool flag = false;
                for(int i = 0;i < list.at(4).split(",").size();i++)//check for like history
                {
                    if((list.at(4).split(",")).at(i).toInt() == Current_User->Get_Userid() &&
                        list.at(1).toInt() == list_item.at(1).toInt()
                        &&list.at(0).toInt() ==list_data.at(0).toInt())
                    {
                        flag = true;
                        QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                        return;//return for endig method
                    }
                }
                if(!flag)
                {

                    if(list_data.at(2).toInt() == list.at(1).toInt()&& list_data.at(0).toInt() == list.at(0).toInt())
                    {

                        list >> t;
                        t->Set_Who_Like(Current_User->Get_Userid());
                        t->Add_Like();
                        tweet_vector.push_back(t);
                        Tweets.close();

                    }
                }
            }
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

                while(!file.atEnd())//write tweets because of changing
                {
                    QString line = file.readLine();
                    QStringList list = line.split("%$%");
                    if(list.at(0).toInt() == list_data.at(0).toInt()&& list.at(1).toInt() == list_data.at(2).toInt())
                    {

                    }
                    else
                    {
                        str.append(line+'\n');
                    }
                }
                Tfile .resize(0);
                file << str;
                for(auto &tw:tweet_vector)
                {
                    file << tw;
                }
                Tfile .close();
                QMessageBox::information(this,"Successful","* Tweet successfuly liked.");
                Tweets.close();
                Refresh_List();
            }


            Tweets.close();
        }

        Refresh_List();
    }

}


void MainWindow::on_btn_search_clicked()
{

    if(ui->txt_search->text().contains("#"))//check for hashtag
    {
        Hash_TagForm *myfirst=new Hash_TagForm();
        myfirst->Set_C_User_Id(Current_User->Get_Userid());
        if(myfirst->Set_t(ui->txt_search->text()))
        {
            myfirst->Get_C_User(Current_User);
            ui->txt_search->clear();
            myfirst->show();
            connect(myfirst,&Hash_TagForm::finished,this,&MainWindow::Refresh_List);

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
            if(!flag)//if username does not exist
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
                connect(account,&Show_Account::finished,this,&MainWindow::Refresh_List);
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
    if(ui->list_tweets->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        Mwindow = new Mention();
        QStringList list_item = ui->list_tweets->currentItem()->text().split("  ");
        QStringList data_list = (ui->list_tweets->currentItem()->data(Qt::UserRole).toString()).split("%$%");

        Mwindow->Get_Mention_userid(Current_User->Get_Userid());
        Mwindow->Get_Userid(data_list.at(0).toInt());
        Mwindow->Get_Tweetid(list_item.at(1).toInt());
        Mwindow->Get_C_User(Current_User);
        Mwindow->show();
        //we need refreshing list after mention
        connect(Mwindow,&Mention::finished,this,&MainWindow::Refresh_List);
    }

}


void MainWindow::on_btn_retweet_clicked()
{
    if(ui->list_tweets->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        QStringList list_item = ui->list_tweets->currentItem()->text().split("  ");
        QStringList list_data = (ui->list_tweets->currentItem()->data(Qt::UserRole).toString()).split("%$%");
        re_q_tweet = new Re_Quote_Tweet();
        re_q_tweet->Get_User(Current_User);
        re_q_tweet->Get_Tweet_Text(list_item.at(5));
        re_q_tweet->Get_Tweet_Userid(list_data.at(0).toInt());
        re_q_tweet->Get_Tweet_ID(list_item.at(1).toInt());
        re_q_tweet->show();
        connect(re_q_tweet,&Re_Quote_Tweet::finished,this,&MainWindow::Refresh_List);//we need refreshing list after retweet
    }
}

