#ifndef MENTION_H
#define MENTION_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>
#include <QColor>
#include <QPalette>
#include <QPixmap>
#include <QIcon>
#include "Tweet.hpp"
#include "user.h"
#include "re_quote_tweet.h"
namespace Ui {
class Mention;
}

class Mention : public QDialog
{
    Q_OBJECT

public:
    explicit Mention(QWidget *parent = nullptr);
    void Get_Userid(int id);
    void Get_Tweetid(int id);
    void Get_Mention_userid(int id);
    void Get_C_User(User* user);
    void Refresh();
    ~Mention();
    void showEvent(QShowEvent * event);
private slots:
    void on_btn_tweet_clicked();

    void on_btn_like_clicked();

    void on_btn_ok_clicked();

    void on_btn_retweet_clicked();

private:
    Ui::Mention *ui;
    int userid=0,tweetid=0,mention_userid=0;
    User* Current_User;
    Re_Quote_Tweet * re_q_tweet;

};

#endif // MENTION_H
