#include "mention.h"
#include "ui_mention.h"

Mention::Mention(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mention)
{
    ui->setupUi(this);
    QPixmap Like(":/icons/img/like.png");
    QPixmap Ok(":/icons/img/ok.png");
    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}"
                        "QTextEdit{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_ok->setStyleSheet("QPushButton{border:none;}");
    ui->btn_tweet->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");
    ui->mentionlist->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");

    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
    QIcon Like_icnon(Like);
    QIcon Ok_icnon(Ok);

    ui->btn_like->setIcon(Like_icnon);
    ui->btn_like->setIconSize(QSize(80,80));
    ui->btn_like->setFixedSize(QSize(80,80));

    ui->btn_ok->setIcon(Ok_icnon);
    ui->btn_ok->setIconSize(QSize(80,80));
    ui->btn_ok->setFixedSize(QSize(80,80));
    ui->btn_tweet->setFixedSize(QSize(60,50));
}

void Mention::Get_Userid(int id)
{
    userid=id;
}

void Mention::Get_Tweetid(int id)
{
    tweetid=id;

}

void Mention::Get_Mention_userid(int id)
{
    mention_userid=id;
}

void Mention::Refresh()
{
    ui->mentionlist->clear();
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
            if(list.at(0).toInt() == userid && list.at(1).toInt()==tweetid)
            {
                QString line =list.at(7)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                ui->mentionlist->addItem(line);
            }
        }

    }
    ui->txt_mention->clear();
    MentionF.close();
}

Mention::~Mention()
{
    delete ui;
}

void Mention::Mention::showEvent(QShowEvent *event)
{
    QDialog::showEvent(event);
    Refresh();
}

void Mention::on_btn_tweet_clicked()
{
    Mentions* m = new Mentions();
    Tweet *tweet = new Tweet();
    if(ui->txt_mention->toPlainText().isEmpty())
    {
        QMessageBox::information(this,"Warning","! You must fill the box.");
        return;
    }
    else
    {
        QFile Tweets("Tweet_file.txt");
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
                if(list.at(0).toInt()==userid && list.at(1).toInt()==tweetid)
                {
                    list >> tweet;
                    m->Set_mention_id(list.at(6).toInt());
                    tweet->Add_last_mentionid();
                    break;
                }
            }
            Tweets.close();

        }
        if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
        {
            QMessageBox::information(0,"Warning","! File can not open.");
            return;
        }
        else
        {
            QString str="";
            QTextStream file(&Tweets);
            while(!file.atEnd())
            {
                QString line = file.readLine();
                QStringList list = line.split("%$%");
                if(!(list.at(0).toInt()==userid && list.at(1).toInt()==tweetid))
                {
                    str.append(line+'\n');
                }
            }
            Tweets.resize(0);
            file << str;
            file << tweet;
            Tweets.close();
        }
        QFile MentionF("Mention_file.txt");
        if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
        {
            QMessageBox::information(this,"Warning","! File can not open.");
            return;
        }
        else
        {

                QString filter="";
                for(int i = 0; i <ui->txt_mention->toPlainText().size();i++ )
                {
                    if(ui->txt_mention->toPlainText()[i] != '\n')
                    {
                        filter.append(ui->txt_mention->toPlainText()[i]);
                    }
                }
                QTextStream file(&MentionF);
                m->Add_Tweet(filter);
                QStringList hasht;
                hasht = filter.split("#");
                for (int i = 0; i < hasht.size(); i++)
                {
                    QString HT;
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
                            m->Set_Hashtag(HT);
                        }
                    }
                }
                m->Set_ID(tweetid);
                m->Set_Tweet_Date(QDateTime::currentDateTime());
                m->Set_User_id(userid);
                m->Set_mention_user_id(mention_userid);
                file << m;
                MentionF.close();
                QMessageBox::information(this,"Successful","* Mention done.");
                Refresh();
        }
    }
}


void Mention::on_btn_like_clicked()
{
    Mentions *m =new Mentions();
    if(ui->mentionlist->currentItem() == nullptr)
    {
            QMessageBox::information(this,"Warning","! You must select one tweet.");
            return;
    }
    else
    {

            QStringList list_item = ui->mentionlist->currentItem()->text().split("  ");
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
                    for(int i = 0;i < list.at(4).split(",").size();i++)
                    {
                        if((list.at(4).split(",")).at(i).toInt() == mention_userid && list.at(7).toInt() == list_item.at(0).toInt()&&
                            list.at(0).toInt() == userid &&list.at(1).toInt()==tweetid
                            )
                        {
                            flag = true;
                            QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                            break;
                        }
                    }

                    if(!flag)
                    {
                        if(list_item.at(0).toInt() == list.at(7).toInt()&& userid == list.at(0).toInt()&&list.at(1).toInt()==tweetid/*&&
                            list.at(6).toInt()==mention_userid*/)
                        {
                            list >> m;
                            m->Set_Who_Like(mention_userid);
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
                                while(!file.atEnd())
                                {
                                    QString line = file.readLine();
                                    QStringList list = line.split("%$%");
                                    if(list_item.at(0).toInt() == list.at(7).toInt()&& userid == list.at(0).toInt()&&list.at(1).toInt()==tweetid/*&&
                                        list.at(6).toInt()==mention_userid*/)
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
}


void Mention::on_btn_ok_clicked()
{
    this->close();
}

