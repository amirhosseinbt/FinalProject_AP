#include "tweetwindow.h"
#include "ui_tweetwindow.h"

TweetWindow::TweetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TweetWindow)
{
    this->setWindowModality(Qt::ApplicationModal);

    ui->setupUi(this);

    this->setStyleSheet("QLineEdit{border-radius:10px;border:1px solid #2D25A4;background-color:#E1DBED;}"
                        "QTextEdit{border-radius:10px;background: palette(base);border:1px solid #2D25A4;background-color:#E1DBED;}");
    ui->btn_tweet->setStyleSheet("QPushButton{border:2px solid #2D25A4;border-radius:20px;padding:10px;}");

    this->setAutoFillBackground(true);
    this->setPalette(QColor::fromString("#FFFFFF"));

}

void TweetWindow::Get_User(User *user)
{
    Current_User = user;
}

void TweetWindow::Qoute(QString text)
{
    ui->txt_tweet->setText(text);
}

TweetWindow::~TweetWindow()
{
    delete ui;
//    delete tweet;
}

void TweetWindow::on_btn_tweet_clicked()
{

    QFile Tweets("Tweet_file.txt");
    if(!Tweets.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Append))
    {
        QMessageBox::information(this,"Warning","! File can not open.");
        return;
    }
    else
    {
        tweet = new Tweet();
        if(ui->txt_tweet->toPlainText().isEmpty())
        {
            QMessageBox::information(this,"Warning","! You must fill the box.");
            return;
        }
        else
        {
            QString filter="";
            for(int i = 0; i <ui->txt_tweet->toPlainText().size();i++ )
            {
                if(ui->txt_tweet->toPlainText()[i] != '\n')
                {
                    filter.append(ui->txt_tweet->toPlainText()[i]);
                }
            }
            QTextStream file(&Tweets);
            tweet->Add_Tweet(filter);
            QStringList hasht;
            hasht = filter.split("#");

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
            tweet->Set_ID(Current_User->Get_Last_Tweet_id());

            Current_User->Add_Last_Tweet_id();

            tweet->Set_Tweet_Date(QDateTime::currentDateTime());

            tweet->Set_User_id(Current_User->Get_Userid());

            file << tweet;

            QMessageBox::information(this,"Successful","* Tweet done.");
            Tweets.close();

            delete tweet;
            emit accept();//send signal for quote tweet window
        }
        Tweets.close();
    }
}

