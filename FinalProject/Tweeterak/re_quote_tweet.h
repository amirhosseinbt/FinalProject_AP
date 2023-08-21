#ifndef RE_QUOTE_TWEET_H
#define RE_QUOTE_TWEET_H

#include <QDialog>
#include <QPalette>
#include <QDebug>
#include <QStringList>
#include <vector>
#include "user.h"
#include "Tweet.hpp"
#include "tweetwindow.h"
namespace Ui {
class Re_Quote_Tweet;
}

class Re_Quote_Tweet : public QDialog
{
    Q_OBJECT

public:
    explicit Re_Quote_Tweet(QWidget *parent = nullptr);
    void Get_User(User * user);
    void Get_Tweet_Text(QString text);
    void Get_Tweet_Userid(int id);
    void Get_Tweet_ID(int id);
    void Get_Mention_Userid(int id);
    void Get_Mention_ID(int id);
    ~Re_Quote_Tweet();

private slots:
    void on_btn_retweet_clicked();
    void quote_message();
    void on_btn_quotetweet_clicked();
    void quote_a_mention();
    void quote_a_tweet();
private:
    Ui::Re_Quote_Tweet *ui;
    User * Current_User = nullptr;
    QString T_text="";
    TweetWindow* T_Window;
    int T_Userid =0,T_id=0,M_Userid = 0,M_id = 0;
};

#endif // RE_QUOTE_TWEET_H
