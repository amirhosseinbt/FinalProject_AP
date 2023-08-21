#ifndef SHOW_ACCOUNT_H
#define SHOW_ACCOUNT_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QIcon>
#include <QPixmap>
#include <QColor>
#include <vector>
#include "user.h"
#include "Tweet.hpp"
#include "mention.h"
#include "re_quote_tweet.h"

namespace Ui {
class Show_Account;
}

class Show_Account : public QDialog
{
    Q_OBJECT

public:
    void Get_username(QString username);
    void Get_Current_User(User* user);
    QString Get_Uname_byID(int id);

    explicit Show_Account(QWidget *parent = nullptr);
    ~Show_Account();
    void Refresh();

private slots:
    void on_btn_like_clicked();

    void on_btn_follow_clicked();

    void on_btn_mention_clicked();

    void on_btn_unfollow_clicked();

    void on_btn_retweet_clicked();

private:
    Ui::Show_Account *ui;
    User* user;
    User* Current_User;
    Mention* Mwindow;
    Re_Quote_Tweet * re_q_tweet;

};

#endif // SHOW_ACCOUNT_H
