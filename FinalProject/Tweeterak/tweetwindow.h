#ifndef TWEETWINDOW_H
#define TWEETWINDOW_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>
#include <QMessageBox>
#include <QDebug>
#include <QColor>
#include <QPalette>
#include "user.h"
#include "Tweet.hpp"
namespace Ui {
class TweetWindow;
}

class TweetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TweetWindow(QWidget *parent = nullptr);
    void Get_User(User * user);
    ~TweetWindow();

private slots:
    void on_btn_tweet_clicked();

private:
    Ui::TweetWindow *ui;
    User * Current_User = nullptr;
    Tweet* tweet;
};

#endif // TWEETWINDOW_H
