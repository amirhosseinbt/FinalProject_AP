#include "hash_tagform.h"
#include "ui_hash_tagform.h"

Hash_TagForm::Hash_TagForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hash_TagForm)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);//this avoids from window beings open


    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));//css

    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_mention->setStyleSheet("QPushButton{border:none;}");
    ui->btn_ok->setStyleSheet("QPushButton{border:none;}");
    ui->btn_retweet->setStyleSheet("QPushButton{border:none;}");
    ui->listWidget->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");


    QPixmap Like(":/icons/img/redlike.png");//change btn to custom icon
    QPixmap Mention(":/icons/img/mention.png");
    QPixmap Ok(":/icons/img/ok.png");

    QIcon Like_icnon(Like);
    QIcon Mention_icnon(Mention);
    QIcon Ok_icnon(Ok);

    QPixmap Retweet(":/icons/img/retweet.png");
    QIcon Retweet_icnon(Retweet);
    ui->btn_retweet->setIcon(Retweet_icnon);
    ui->btn_retweet->setIconSize(QSize(80,80));
    ui->btn_retweet->setFixedSize(QSize(80,80));

    ui->btn_ok->setIcon(Ok_icnon);
    ui->btn_ok->setIconSize(QSize(80,80));
    ui->btn_ok->setFixedSize(QSize(80,80));

    ui->btn_like->setIcon(Like_icnon);
    ui->btn_like->setIconSize(QSize(80,80));
    ui->btn_like->setFixedSize(QSize(80,80));

    ui->btn_mention->setIcon(Mention_icnon);
    ui->btn_mention->setIconSize(QSize(80,80));
    ui->btn_mention->setFixedSize(QSize(80,80));
}

bool Hash_TagForm::Set_t(QString text)
{

    Text = text;
    if(Refresh())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
QString Hash_TagForm::Get_Uname_byId(int id)//to find id of one account
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

void Hash_TagForm::Set_C_User_Id(int id)
{
    C_Userid = id;
}

void Hash_TagForm::showEvent(QShowEvent *event)//in every show refresh the tweet list
{

    QDialog::showEvent(event);
    Refresh();
}

void Hash_TagForm::Get_C_User(User *user)
{
    Current_User=user;
}

bool Hash_TagForm::Refresh()//in this method we use listwidgetitem data to send some information about one tweet
{
    bool flag=false;
    ui->listWidget->clear();
    QFile Tweets("Tweet_file.txt");
    if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
        return 0;
    }
    else
    {
        QTextStream file(&Tweets);
        QStringList list;
        while(!file.atEnd())
        {
            list = file.readLine().split("%$%");
            QStringList htlist =list.at(7).split(",");
            for (int i = 0; i < htlist.size(); i++)
            {
                if(htlist.at(i) == Text)
                {
                    flag = true;
                    QString myline="";
                    if(list.at(10).toInt() == 0)
                    {

                        myline =Get_Uname_byId(list.at(0).toInt())+"  "+list.at(1)+"  "+"   like "+list.at(3)+"  "+list.at(2)+"  "+"     "+list.at(5);
                    }
                    else
                    {
                        myline =Get_Uname_byId(list.at(10).toInt())+"  "+list.at(1)+"  "+"   like "+list.at(3)+"  "+list.at(2)+"  "+"     "+list.at(5)
                                 +"     "+" Retweet from  "+Get_Uname_byId(list.at(0).toInt());
                    }
                    QListWidgetItem* myitem = new QListWidgetItem(myline);
                    QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%"+list.at(2);
                    myitem->setData(Qt::UserRole,mydata);
                    ui->listWidget->addItem(myitem);

                }

            }
        }
        Tweets.close();
    }
    QFile MentionF("Mention_file.txt");
    if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
        return 0;
    }
    else
    {
        QTextStream file(&MentionF);
        QStringList list;
        while(!file.atEnd())
        {
            list = file.readLine().split("%$%");
            QStringList htlist =list.at(8).split(",");
            for (int i = 0; i < htlist.size(); i++)
            {
                if(htlist.at(i) == Text)
                {
                    flag = true;
                    QString myline =Get_Uname_byId(list.at(6).toInt())+"  "+list.at(7)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                    QListWidgetItem* myitem = new QListWidgetItem(myline);
                    QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%"+list.at(6)+"%$%"+list.at(7)+"%$%"+list.at(2);
                    myitem->setData(Qt::UserRole,mydata);
                    ui->listWidget->addItem(myitem);

                }

            }
        }

        MentionF.close();
    }
    if(!flag)
    {
        QMessageBox::information(this,"Warning","! Hashtag does not exist.");
        return 0;
    }
    return 1;
}


Hash_TagForm::~Hash_TagForm()
{
    delete ui;
}

void Hash_TagForm::on_btn_like_clicked()
{
    if(ui->listWidget->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        QString mytext=ui->listWidget->currentItem()->data(Qt::UserRole).toString();
        QStringList datalist = mytext.split("%$%");
        if(datalist.size() > 4)
        {
            Mentions *m =new Mentions();
            QFile MentionF("Mention_file.txt");
            if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
            {
                QMessageBox::information(this,"Warning","! File can not open.");
                return;
            }
            else
            {
                QTextStream file(&MentionF);
                QStringList list;
                bool flag = false;
                while(!file.atEnd())
                {
                        list = file.readLine().split("%$%");
                        for(int i = 0;i < list.at(4).split(",").size();i++)//check for like history
                        {
                            if((list.at(4).split(",")).at(i).toInt() == C_Userid &&
                                list.at(7).toInt() == datalist.at(3).toInt()&&
                                list.at(0).toInt() ==datalist.at(0).toInt() &&
                                list.at(1).toInt()==datalist.at(1).toInt())

                            {
                                flag = true;
                                QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                                break;
                            }
                        }

                        if(!flag)
                        {
                            if(datalist.at(3).toInt() == list.at(7).toInt()&&
                                datalist.at(0).toInt() == list.at(0).toInt()&&
                                list.at(1).toInt()==datalist.at(1).toInt()
                                )
                            {
                                list >> m;
                                m->Set_Who_Like(C_Userid);
                                m->Add_Like();
                                MentionF.close();
                                QFile MentionFF ("Mention_file.txt");
                                if(!MentionFF.open(QIODevice::ReadWrite|QIODevice::Text))
                                {
                                    QMessageBox::information(this,"Warning","! File can not open.");
                                    return;
                                }
                                else
                                {
                                    QTextStream file(&MentionFF );
                                    QString str="";
                                    while(!file.atEnd())//for writing tweet with changes in file
                                    {
                                        QString line = file.readLine();
                                        QStringList list = line.split("%$%");
                                        if(datalist.at(3).toInt() == list.at(7).toInt()&&
                                           datalist.at(0).toInt() == list.at(0).toInt()&&
                                            list.at(1).toInt()== datalist.at(1).toInt()
                                            )
                                        {
                                        }
                                        else
                                        {
                                            str.append(line+'\n');
                                        }
                                    }
                                    MentionFF .resize(0);
                                    file << str;
                                    file << m;
                                    delete m;
                                    MentionFF.close();
                                    QMessageBox::information(this,"Successful","* Tweet successfuly liked.");
                                    MentionFF.close();
                                    Refresh();
                                    return;
                                }
                            }
                        }

                }
                MentionF.close();
            }
        }
        else
        {
            std::vector<Tweet*> tweet_vector;
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
                        Tweet *t =new Tweet();;
                        list = file.readLine().split("%$%");
                        for(int i = 0;i < list.at(4).split(",").size();i++)//check like history
                        {

                            if((list.at(4).split(",")).at(i).toInt() == C_Userid &&
                                list.at(1).toInt() == datalist.at(1).toInt()&&
                                list.at(0).toInt()==datalist.at(0).toInt())
                            {
                                flag = true;
                                QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                                return;//for avoid from continuing method
                            }
                        }

                        if(!flag)
                        {

                            if(datalist.at(1).toInt() == list.at(1).toInt()&&
                                datalist.at(0).toInt() == list.at(0).toInt())
                            {
                                list >> t;
                                t->Set_Who_Like(C_Userid);
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
                        while(!file.atEnd())//write tweet with changes in file
                        {
                            QString line = file.readLine();
                            QStringList list = line.split("%$%");
                            if(list.at(0).toInt() ==datalist.at(0).toInt() &&
                                list.at(1).toInt() == datalist.at(1).toInt())
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
                            delete tw;
                        }
                        Tfile .close();
                        QMessageBox::information(this,"Successful","* Tweet successfuly liked.");
                        Tweets.close();
                        Refresh();
                        return;

                    }
                    Tweets.close();
            }

        }
    }

}





void Hash_TagForm::on_btn_ok_clicked()
{
    this->close();
}


void Hash_TagForm::on_btn_mention_clicked()
{
    if(ui->listWidget->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        QString mytext=ui->listWidget->currentItem()->data(Qt::UserRole).toString();
        QStringList datalist = mytext.split("%$%");
        if(datalist.size() > 4)
        {
            QMessageBox::information(this,"Warning","! You can not add mention to one mention.");
            return;
        }
        else
        {
            Mention *mentionwindow=new Mention();//shows mention window
            mentionwindow->Get_Mention_userid(C_Userid);
            mentionwindow->Get_Userid(datalist.at(0).toInt());
            mentionwindow->Get_Tweetid(datalist.at(1).toInt());
            mentionwindow->Get_C_User(Current_User);
            mentionwindow->show();
            connect(mentionwindow,&Mention::finished,this,[=](){delete mentionwindow;});
        }

    }
}


void Hash_TagForm::on_btn_retweet_clicked()
{
    if(ui->listWidget->selectedItems().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must select one tweet.");
        return;
    }
    else
    {
        QString mytext=ui->listWidget->currentItem()->data(Qt::UserRole).toString();
        QStringList datalist = mytext.split("%$%");
        if(datalist.size() > 4)
        {
            QMessageBox::information(this,"Warning","! You can not retweet or quote tweet a mention.");
            return;
        }
        else
        {
            QStringList list_item = ui->listWidget->currentItem()->text().split("  ");
            re_q_tweet = new Re_Quote_Tweet();
            re_q_tweet->Get_User(Current_User);
            re_q_tweet->Get_Tweet_Text(datalist.at(2));
            re_q_tweet->Get_Tweet_Userid(datalist.at(0).toInt());
            re_q_tweet->Get_Tweet_ID(datalist.at(1).toInt());
            re_q_tweet->show();
            connect(re_q_tweet,&Re_Quote_Tweet::finished,this,[=](){delete re_q_tweet;});
        }
    }
}

