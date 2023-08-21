#include "hash_tagform.h"
#include "ui_hash_tagform.h"

Hash_TagForm::Hash_TagForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Hash_TagForm)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));
    ui->btn_like->setStyleSheet("QPushButton{border:none;}");
    ui->btn_mention->setStyleSheet("QPushButton{border:none;}");
    ui->btn_ok->setStyleSheet("QPushButton{border:none;}");
    ui->listWidget->setStyleSheet("QListWidget{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    QPixmap Like(":/icons/img/like.png");
    QPixmap Mention(":/icons/img/mention.png");
    QPixmap Ok(":/icons/img/ok.png");

    QIcon Like_icnon(Like);
    QIcon Mention_icnon(Mention);
    QIcon Ok_icnon(Ok);

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

//bool Hash_TagForm::Get_Text(QString uitext)
//{
//        bool flag=false;
////        hashtagtext = uitext;
//        QFile Tweets("Tweet_file.txt");
//        if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text))
//        {
//            QMessageBox::information(this,"Warning","! File can not open.");
//            return 0;
//        }
//        else
//        {
//            QTextStream file(&Tweets);
//            QStringList list;
//            while(!file.atEnd())
//            {
//                list = file.readLine().split("%$%");
//                QStringList htlist =list.at(7).split(",");
//                for (int i = 0; i < htlist.size(); i++)
//                {
//                    if(htlist.at(i) == uitext)
//                    {
//                        flag = true;
//                        QString myline =Get_Uname_byId(list.at(0).toInt())+"  "+list.at(1)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
//                        QListWidgetItem* myitem = new QListWidgetItem(myline);
//                        QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%";
//                        myitem->setData(Qt::UserRole,mydata);
//                        ui->listWidget->addItem(myitem);

//                    }

//                }
//            }
//            Tweets.close();
//        }
//        QFile MentionF("Mention_file.txt");
//        if(!MentionF.open(QIODevice::ReadWrite|QIODevice::Text))
//        {
//            QMessageBox::information(this,"Warning","! File can not open.");
//            return 0;
//        }
//        else
//        {
//            QTextStream file(&MentionF);
//            QStringList list;
//            while(!file.atEnd())
//            {
//                list = file.readLine().split("%$%");
//                QStringList htlist =list.at(8).split(",");
//                for (int i = 0; i < htlist.size(); i++)
//                {
//                    if(htlist.at(i) == uitext)
//                    {
//                        flag = true;
//                        QString myline =Get_Uname_byId(list.at(6).toInt())+"  "+list.at(7)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
//                        QListWidgetItem* myitem = new QListWidgetItem(myline);
//                        QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%"+list.at(6)+"%$%"+list.at(7)+"%$%";
//                        myitem->setData(Qt::UserRole,mydata);
//                        ui->listWidget->addItem(myitem);

//                    }

//                }
//            }

//            MentionF.close();
//        }
//        if(!flag)
//        {
//            QMessageBox::information(this,"Warning","! Hashtag does not exist.");
//            return 0;
//        }
//        return 1;
//}

QString Hash_TagForm::Get_Uname_byId(int id)
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

void Hash_TagForm::showEvent(QShowEvent *event)
{

    QDialog::showEvent(event);
    Refresh();
}

bool Hash_TagForm::Refresh()
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
                            QString myline =Get_Uname_byId(list.at(0).toInt())+"  "+list.at(1)+"  "+"   like "+list.at(3)+"   "+list.at(2)+"       "+list.at(5);
                            QListWidgetItem* myitem = new QListWidgetItem(myline);
                            QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%";
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
                            QVariant mydata =list.at(0)+"%$%"+list.at(1)+"%$%"+list.at(6)+"%$%"+list.at(7)+"%$%";
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
    }
    else
    {
        QString mytext=ui->listWidget->currentItem()->data(Qt::UserRole).toString();
        QStringList datalist = mytext.split("%$%");
        if(datalist.size() > 3)
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
                        for(int i = 0;i < list.at(4).split(",").size();i++)
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
                                    while(!file.atEnd())
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
            Tweet *t =new Tweet();;
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

                            if((list.at(4).split(",")).at(i).toInt() == C_Userid &&
                                list.at(1).toInt() == datalist.at(1).toInt()&&
                                list.at(0).toInt()==datalist.at(0).toInt())
                            {
                                flag = true;
                                QMessageBox::information(this,"Warning","! You have already liked this tweet.");
                                break;
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
    }
    else
    {
        QString mytext=ui->listWidget->currentItem()->data(Qt::UserRole).toString();
        QStringList datalist = mytext.split("%$%");
        if(datalist.size() > 3)
        {
            QMessageBox::information(this,"Warning","! You can not add mention to one mention.");
        }
        else
        {
            Mention *mentionwindow=new Mention();
            mentionwindow->Get_Mention_userid(C_Userid);
            mentionwindow->Get_Userid(datalist.at(0).toInt());
            mentionwindow->Get_Tweetid(datalist.at(1).toInt());
            mentionwindow->show();
        }

    }
}

