#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QListWidget>
#include <QStringList>
#include <QColor>
#include <QPalette>
#include "user.h"
#include "tweetwindow.h"
#include "settingw.h"
#include "show_account.h"
#include "Tweet.hpp"
#include "mention.h"
#include "hash_tagform.h"
#include "re_quote_tweet.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Get_User(User * user);
signals:
    void Logout();
private slots:
    void Refresh_List();
    void Change_user(User* user);
    void on_btn_tweet_clicked();

    void on_btn_logout_clicked();

    void on_btn_setting_clicked();

    void on_btn_like_clicked();

    void on_btn_search_clicked();

    void on_btn_mention_clicked();

    void on_btn_retweet_clicked();

private:
    Ui::MainWindow *ui;
    User * Current_User=nullptr;
    TweetWindow* T_Window;
    SettingW* set_win;
    Show_Account* account;
    Mention* Mwindow;
    Re_Quote_Tweet * re_q_tweet;
};
#endif // MAINWINDOW_H
