#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDateTime>
#include <QMessageBox>
class Tweet
{
protected:
    QString Tweet_Text;
    int ID,N_Like = 0,Userid,last_mention_id=1,retweet_userid=0;
    std::vector<int> Who_Like;
    QDateTime Tweet_Date;
    std::vector<QString> Hashtag;
    std::vector<int> Who_Retweet;
    std::vector<int> Who_Quote_Tweet;
public:
    friend inline QTextStream & operator<<(QTextStream &out,Tweet* tweet);
    friend inline operator >>(QStringList &list,Tweet* tweet);
    Tweet();
    virtual~Tweet();
    void Set_User_id(int userid);
    int Get_User_id();
    void Set_RetweetUser_id(int userid);
    int Get_RetweetUser_id();
    void Add_Tweet(QString tweet_text);
    QString Get_Tweet_Text();
    void Set_ID(int id);
    int Get_ID();
    void Add_Like();
    void Dislike();
    void Set_N_Like(int num);
    int Get_N_Like();
    void Set_Who_Like(int userid);
    std::vector<int> Get_Who_Like();
    void Erase_Who_Like(int id);
    virtual void My_overload(QTextStream & out);
    virtual void My_Read_Overload(QStringList &list);
    void Set_Tweet_Date(QDateTime date);
    QDateTime Get_Tweet_Date();
    void Set_last_mentionid(int id);
    int Get_last_mentionid();
    void Add_last_mentionid();
    void Set_Hashtag(QString text);
    std::vector<QString> Get_Hashtag();
    void Set_Who_Retweet(int id);
    std::vector<int>Get_Who_Retweet();
    void Set_who_Quote_tweet(int id);
    std::vector<int>Get_Who_Quote_t();

    

};
class Mentions : public Tweet
{
public:
    friend inline QTextStream & operator<<(QTextStream &out,Mentions * m);
    friend inline operator >>(QStringList &list,Mentions * m);

    Mentions() {}
    void Set_mention_user_id(int id);
    int Get_mention_user_id();

    void Set_mention_id(int id);
    int Get_mention_id();
    virtual void My_overload(QTextStream & out)override;
    virtual void My_Read_Overload(QStringList &list)override;
private:
    int mention_user_id,mention_id;

};
inline QTextStream & operator<<(QTextStream &out,Tweet* tweet)
{
    tweet->My_overload(out);
    return out;
}
inline operator >>(QStringList &list,Tweet* tweet)
{
    tweet->My_Read_Overload(list);
}
inline QTextStream & operator<<(QTextStream &out,Mentions * m)
{
    m->My_overload(out);
    return out;
}
inline operator >>(QStringList &list,Mentions * m)
{
    m->My_Read_Overload(list);
}
