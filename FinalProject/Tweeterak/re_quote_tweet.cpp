#include "re_quote_tweet.h"
#include "ui_re_quote_tweet.h"

Re_Quote_Tweet::Re_Quote_Tweet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Re_Quote_Tweet)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    ui->btn_retweet->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->btn_quotetweet->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
}

void Re_Quote_Tweet::Get_User(User *user)
{
    Current_User = user;
}

void Re_Quote_Tweet::Get_Tweet_Text(QString text)
{
    T_text = text;
}

void Re_Quote_Tweet::Get_Tweet_Userid(int id)
{
    T_Userid = id;
}

void Re_Quote_Tweet::Get_Tweet_ID(int id)
{
    T_id = id;
}

void Re_Quote_Tweet::Get_Mention_Userid(int id)
{
    M_Userid = id;
}

void Re_Quote_Tweet::Get_Mention_ID(int id)
{
    M_id = id;
}

Re_Quote_Tweet::~Re_Quote_Tweet()
{
    delete ui;
}
void Re_Quote_Tweet::on_btn_retweet_clicked()
{

    if(M_id != 0)
    {
        Mentions *m =new Mentions();
        QFile MentionF("Mention_file.txt");
        bool mention_flag = false;
        if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&MentionF);
            QStringList list;
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                for(int i = 0;i < list.at(9).split(",").size();i++)
                {
                    if((list.at(9).split(",")).at(i).toInt() == Current_User->Get_Userid() &&
                        list.at(7).toInt() == M_id&&
                        list.at(0).toInt() ==T_Userid &&
                        list.at(1).toInt()==T_id &&
                        list.at(6).toInt() == M_Userid)
                    {
                        mention_flag = true;
                        QMessageBox::information(this,"Warning","! You have already retweet this tweet.");
                        break;
                    }
                }

                if(!mention_flag)
                {
                    if(M_id == list.at(7).toInt()&&
                        T_Userid == list.at(0).toInt()&&
                        list.at(1).toInt()==T_id&&
                        list.at(6).toInt()==M_Userid)
                    {
                        list >> m;
                        m->Set_Who_Retweet(Current_User->Get_Userid());
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
                            while(!file.atEnd())
                            {
                                QString line = file.readLine();
                                QStringList list = line.split("%$%");
                                if(M_id == list.at(7).toInt()&&
                                    T_Userid== list.at(0).toInt()&&
                                    list.at(1).toInt()== T_id&&
                                    list.at(6).toInt()==M_Userid
                                    )
                                {
                                }
                                else
                                {
                                    str.append(line+'\n');
                                }
                            }
                            MentionFF.resize(0);
                            file << str;
                            file << m;
                            MentionFF.close();

                        }
                    }
                }
            }
            MentionF.close();
            if(!mention_flag)
            {
//                Tweet* tweet = new Tweet();
//                QFile Tweets("Tweet_file.txt");
//                if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
//                {
//                    QMessageBox::information(this,"Warning","! File can not open.");
//                    return;
//                }
//                else
//                {
//                    QTextStream file(&Tweets);
//                    tweet->Add_Tweet(T_text);
//                    QStringList hasht;
//                    hasht = T_text.split("#");
//                    for (int i = 0; i < hasht.size(); i++)
//                    {
//                        QString HT="";

//                        if(i != 0)
//                        {
//                            for (int j = 0; j < hasht.at(i).size(); j++)
//                            {
//                                if(hasht.at(i).at(j).isLetterOrNumber())
//                                {
//                                    HT.append(hasht.at(i).at(j));
//                                }
//                                else
//                                {
//                                    break;
//                                }
//                            }
//                            if(!HT.isEmpty())
//                            {
//                                tweet->Set_Hashtag(HT);
//                            }
//                        }
//                    }
//                    tweet->Set_ID(Current_User->Get_Last_Tweet_id());
//                    Current_User->Add_Last_Tweet_id();
//                    tweet->Set_Tweet_Date(QDateTime::currentDateTime());
//                    tweet->Set_User_id(Current_User->Get_Userid());
//                    file << tweet;

//                    QMessageBox::information(this,"Successful","* Retweet done.");
//                    Tweets.close();
//                    this->close();

//                }
                Tweet* tweet = new Tweet();
                QFile Tweets("Tweet_file.txt");
                if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
                {
                    QMessageBox::information(this,"Warning","! File can not open.");
                    return;
                }
                else
                {
                    QTextStream file(&Tweets);
                    tweet->Add_Tweet(T_text);
                    QStringList hasht;
                    hasht = T_text.split("#");
                    for (int i = 0; i < hasht.size(); i++)
                    {
                        QString HT="";

                        if(i != 0)
                        {
                            for (int j = 0; j < hasht.at(i).size(); j++)
                            {
                                if(hasht.at(i).at(j).isLetterOrNumber())
                                {
                                    HT.append(hasht.at(i).at(j));
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if(!HT.isEmpty())
                            {
                                tweet->Set_Hashtag(HT);
                            }
                        }
                    }
                    tweet->Set_ID(T_id);
                    Current_User->Add_Last_Tweet_id();
                    tweet->Set_Tweet_Date(QDateTime::currentDateTime());
                    tweet->Set_User_id(T_Userid);
                    tweet->Set_RetweetUser_id(Current_User->Get_Userid());
                    tweet->Set_last_mentionid(m->Get_last_mentionid());
                    tweet->Set_N_Like(m->Get_N_Like());
                    for(auto& whlike:m->Get_Who_Like())
                    {
                        tweet->Set_Who_Like(whlike);
                    }
                    for(auto& whretweet:m->Get_Who_Retweet())
                    {
                        tweet->Set_Who_Retweet(whretweet);
                    }
                    for(auto& whquotetweet : m->Get_Who_Quote_t())
                    {
                        tweet->Set_who_Quote_tweet(whquotetweet);
                    }
                    file << tweet;

                    QMessageBox::information(this,"Successful","* Retweet done.");
                    Tweets.close();
                    this->close();

                }
            }
        }
    }
    else
    {
        std::vector<Tweet*>tweet_vector;
        QFile Tweets ("Tweet_file.txt");
        bool flag = false;
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
                for(int i = 0;i < list.at(8).split(",").size();i++)
                {

                    if((list.at(8).split(",")).at(i).toInt() == Current_User->Get_Userid() &&
                        list.at(1).toInt() ==T_id&&
                        list.at(0).toInt()==T_Userid)
                    {
                        flag = true;
                        QMessageBox::information(this,"Warning","! You have already retweet this tweet.");
                        return;
                    }
                }

                if(!flag)
                {
                    if(T_id == list.at(1).toInt()&&
                        T_Userid == list.at(0).toInt())
                    {
                        list >> t;
                        t->Set_Who_Retweet(Current_User->Get_Userid());
                        tweet_vector.push_back(t);
                        Tweets.close();

                    }
                }
            }
            Tweets.close();
        }
        Tweet* main_tweet;
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
                if(list.at(0).toInt() ==T_Userid &&
                    list.at(1).toInt() == T_id)
                {
                }
                else
                {
                    str.append(line+'\n');
                }
            }
            Tfile .resize(0);
            file << str;
            for(auto & tw:tweet_vector)
            {
                file << tw;
                if(tw->Get_RetweetUser_id()==0)
                {
                    main_tweet = tw;
                }
            }
            Tfile.close();
            Tweets.close();

        }
        Tweet* tweet = new Tweet();
//        QFile Tweets("Tweet_file.txt");
        if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&Tweets);
            tweet->Add_Tweet(T_text);
            QStringList hasht;
            hasht = T_text.split("#");
            for (int i = 0; i < hasht.size(); i++)
            {
                QString HT="";

                if(i != 0)
                {
                    for (int j = 0; j < hasht.at(i).size(); j++)
                    {
                        if(hasht.at(i).at(j).isLetterOrNumber())
                        {
                            HT.append(hasht.at(i).at(j));
                        }
                        else
                        {
                            break;
                        }
                    }
                    if(!HT.isEmpty())
                    {
                        tweet->Set_Hashtag(HT);
                    }
                }
            }
            tweet->Set_ID(T_id);
            Current_User->Add_Last_Tweet_id();
            tweet->Set_Tweet_Date(QDateTime::currentDateTime());
            tweet->Set_User_id(T_Userid);
            tweet->Set_RetweetUser_id(Current_User->Get_Userid());
            tweet->Set_last_mentionid(main_tweet->Get_last_mentionid());
            tweet->Set_N_Like(main_tweet->Get_N_Like());
            for(auto& whlike:main_tweet->Get_Who_Like())
            {
                tweet->Set_Who_Like(whlike);
            }
            for(auto& whretweet:main_tweet->Get_Who_Retweet())
            {
                tweet->Set_Who_Retweet(whretweet);
            }
            for(auto& whquotetweet : main_tweet->Get_Who_Quote_t())
            {
                tweet->Set_who_Quote_tweet(whquotetweet);
            }
            file << tweet;

            QMessageBox::information(this,"Successful","* Retweet done.");
            Tweets.close();
            this->close();

        }
        if(!flag)
        {
//            Tweet* tweet = new Tweet();
//            QFile Tweetsfile("Tweet_file.txt");
//            if(!Tweetsfile.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
//            {
//                QMessageBox::information(this,"Warning","! File can not open.");
//                return;
//            }
//            else
//            {
//                QTextStream file(&Tweetsfile);
//                tweet->Add_Tweet(T_text);
//                QStringList hasht;
//                hasht = T_text.split("#");
//                for (int i = 0; i < hasht.size(); i++)
//                {
//                    QString HT="";

//                    if(i != 0)
//                    {
//                        for (int j = 0; j < hasht.at(i).size(); j++)
//                        {
//                            if(hasht.at(i).at(j).isLetterOrNumber())
//                            {
//                                HT.append(hasht.at(i).at(j));
//                            }
//                            else
//                            {
//                                break;
//                            }
//                        }
//                        if(!HT.isEmpty())
//                        {
//                            tweet->Set_Hashtag(HT);
//                        }
//                    }
//                }

//                tweet->Set_ID(Current_User->Get_Last_Tweet_id());
//                Current_User->Add_Last_Tweet_id();
//                tweet->Set_Tweet_Date(QDateTime::currentDateTime());
//                tweet->Set_User_id(Current_User->Get_Userid());
//                file << tweet;

//                QMessageBox::information(this,"Successful","* Retweet done.");
//                Tweetsfile.close();
//                this->close();
//        }


        }

    }

}

void Re_Quote_Tweet::quote_message()
{
    QMessageBox::information(this,"Successful","* Quote tweet done.");
}


void Re_Quote_Tweet::on_btn_quotetweet_clicked()
{
    T_Window = new TweetWindow();
    T_Window->Get_User(Current_User);
    T_Window->Qoute(T_text);
    if(M_id != 0)
    {
        Mentions *m =new Mentions();
        QFile MentionF("Mention_file.txt");
        bool mention_flag = false;
        if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {
            QTextStream file(&MentionF);
            QStringList list;
            while(!file.atEnd())
            {
                list = file.readLine().split("%$%");
                for(int i = 0;i < list.at(10).split(",").size();i++)
                {
                    if((list.at(10).split(",")).at(i).toInt() == Current_User->Get_Userid() &&
                        list.at(7).toInt() == M_id&&
                        list.at(0).toInt() ==T_Userid &&
                        list.at(1).toInt()==T_id &&
                        list.at(6).toInt() == M_Userid)
                    {
                        mention_flag = true;
                        QMessageBox::information(this,"Warning","! You have already quote tweet this tweet.");
                        break;
                    }
                }
            }
            MentionF.close();
            if(!mention_flag)
            {
                T_Window->show();
                connect(T_Window,SIGNAL(accepted()),this,SLOT(quote_a_mention()));
                connect(T_Window,SIGNAL(accepted()),this,SLOT(close()));
                connect(T_Window,SIGNAL(accepted()),this,SLOT(quote_message()));
            }
        }
    }
    else
    {
        Tweet *t =new Tweet();
        QFile Tweets ("Tweet_file.txt");
        bool flag = false;
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
                for(int i = 0;i < list.at(9).split(",").size();i++)
                {

                    if((list.at(9).split(",")).at(i).toInt() == Current_User->Get_Userid() &&
                        list.at(1).toInt() ==T_id&&
                        list.at(0).toInt()==T_Userid)
                    {
                        flag = true;
                        QMessageBox::information(this,"Warning","! You have already quote tweet this tweet.");
                        break;
                    }
                }   
            }
            Tweets.close();
        }
        if(!flag)
        {
            T_Window->show();
            connect(T_Window,SIGNAL(accepted()),this,SLOT(quote_a_tweet()));
            connect(T_Window,SIGNAL(accepted()),this,SLOT(close()));
            connect(T_Window,SIGNAL(accepted()),this,SLOT(quote_message()));
        }

    }

}

void Re_Quote_Tweet::quote_a_mention()
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
        while(!file.atEnd())
        {
            list = file.readLine().split("%$%");
            if(M_id == list.at(7).toInt()&&
                T_Userid == list.at(0).toInt()&&
                list.at(1).toInt()==T_id&&
                list.at(6).toInt()==M_Userid)
            {
                list >> m;
                m->Set_who_Quote_tweet(Current_User->Get_Userid());
                MentionF.close();
                QFile MentionFF ("Mention_file.txt");
                if(!MentionFF.open(QIODevice::ReadWrite|QIODevice::Text))
                {
                    QMessageBox::information(this,"Warning","! File can not open.");
                    return;
                }
                else
                {
                    QTextStream file(&MentionFF);
                    QString str="";
                    while(!file.atEnd())
                    {
                        QString line = file.readLine();
                        QStringList list = line.split("%$%");
                        if(M_id == list.at(7).toInt()&&
                            T_Userid== list.at(0).toInt()&&
                            list.at(1).toInt()== T_id&&
                            list.at(6).toInt()==M_Userid
                            )
                        {
                        }
                        else
                        {
                            str.append(line+'\n');
                        }
                    }
                    MentionFF.resize(0);
                    file << str;
                    file << m;
                    MentionFF.close();

                }
            }

        }
    }   MentionF.close();
}

void Re_Quote_Tweet::quote_a_tweet()
{
    Tweet *t =new Tweet();
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

                if(T_id == list.at(1).toInt()&&
                    T_Userid == list.at(0).toInt())
                {
                    list >> t;
                    t->Set_who_Quote_tweet(Current_User->Get_Userid());
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
                            if(list.at(0).toInt() ==T_Userid &&
                                list.at(1).toInt() == T_id)
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
                        Tfile.close();
                    }
                }

        }
        Tweets.close();
    }
}


