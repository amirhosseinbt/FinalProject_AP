#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <ctime>
#include "Date.hpp"
#include "Tweet.hpp"
#include <QString>
#include <QValidator>
#include <QObject>
#include <QDate>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>
#include "vector"
class User:public QObject
{
    Q_OBJECT
public:
    friend inline QTextStream & operator<<(QTextStream &out,User * user);
    friend inline operator >>(QStringList &list,User* user);
    User();
    virtual ~User();

    bool Set_Username(const QString &username);
    QString Get_Username();

    virtual void Set_Name(const QString &name) =0;
    QString Get_Name();

    virtual bool Set_Biography(const QString biography) =0;
    QString Get_Biography();

    void Set_Country(const QString country);
    QString Get_Country();

    void Set_Link(QString link);
    QString Get_Link();

    virtual void Set_Birthday(QDate birthday)=0;
    QDate Get_Birthday();

    bool Set_Phonenumber(QString phonenumber);
    QString Get_Phonenumber();

    bool Set_Password(QString password);
    QString Get_Password();

    void Change_N_Followers();
    void Set_N_Followers(int num);
    int Get_N_Followers();
    void Set_Followers(int id);
    std::vector<int> Get_Followers();

    void Change_N_Followings();
    void Set_N_Followings(int num);
    int Get_N_Followings();
    void Set_Followings(int id);
    std::vector<int> Get_Followings();

    virtual void Set_Type()=0;
    QString Get_Type();

    virtual void My_overload(QTextStream & out) = 0;
    virtual void My_Read_Overload(QStringList &list)=0;

    virtual void Set_Picture_Path(QString path)=0;
    QString Get_Picture_Path();
    virtual void Set_Header(QString color)=0;
    QString Get_Header();
    void Set_Last_Tweet_id(int id);
    void Add_Last_Tweet_id();
    int Get_Last_Tweet_id();
    void Set_Userid(int id);
    int Get_Userid();

    bool Check_Password_History(QString pass);
    void Set_Password_History(QString pass);

    void Erase_Follower(int id);
    void Erase_Following(int id);
//    bool set_header(std::string header);
//    int get_header_id();
//    std::string get_header();

//    void tweet(std::string content);

//    std::vector<Tweet*> get_tweets();

//    void earase_tweet(int id);

//    void edit_tweet(int id,std::string con);

//    void like(int id,std::string* wh);
//    std::vector<std::string*> who(int id);

//    void dlike(int id,std::string* wh);

//    void retweet(int id,User *& user);
//    std::vector<std::string*> who_re(int id);
signals:
    void Validate(QString &message,QValidator::State &st);
private:

protected:
    QString  Username ,Password ,Name="",PhoneNumber="",Biography,Country="",Link="",Header="#ffffff",Picture_path=":/icons/img/Anonymous.png",User_Type;
    QDate BirthdayDate;
    std::vector<int> Followers,Followings;
    int N_Followings=0,N_Followers=0,Last_Tweet_id =1,User_id;
};

class Organization_User:public User
{
public:

    Organization_User();
    virtual~Organization_User();

    virtual bool Set_Biography(const QString biography)override;
    virtual void Set_Birthday(QDate birthday) override;
    virtual void Set_Name(const QString &name) override;
    void Set_Admin_id(int userid);
    int Get_Admin_id();
    QString Get_Admin_Username();
    virtual void Set_Type() override;
    virtual void My_overload(QTextStream & out) override;
    virtual void My_Read_Overload(QStringList &list) override;
    virtual void Set_Picture_Path(QString path) override;
    virtual void Set_Header(QString color) override;
private:

    int Admin_id=0;
};



class Personal_User:public User
{
public:

    Personal_User();
    virtual~Personal_User();

    virtual bool Set_Biography(const QString biography)override;
    virtual void Set_Birthday(QDate birthday) override;
    virtual void Set_Name(const QString& name) override;
    virtual void Set_Type() override;
    void Set_Organ_id(int userid);
    int Get_Organ_id();
    QString Get_Organ_Uname();
    virtual void My_overload(QTextStream & out) override;
    virtual void My_Read_Overload(QStringList &list) override;
    virtual void Set_Picture_Path(QString path) override;
    virtual void Set_Header(QString path) override;



private:
    int Organid=0;
};




class Anonymous_User:public User
{

public:

    Anonymous_User();
    virtual~Anonymous_User();

    virtual bool Set_Biography(const QString biography)override;
    virtual void Set_Birthday(QDate birthday) override;
    virtual void Set_Name(const QString& name) override;
    virtual void Set_Type() override;
    virtual void My_overload(QTextStream & out) override;
    virtual void My_Read_Overload(QStringList &list) override;
    virtual void Set_Picture_Path(QString path) override;
    virtual void Set_Header(QString path) override;

private:


};
inline QTextStream & operator<<(QTextStream &out,User * user)
{
    user->My_overload(out);
    return out;
}
inline operator >>(QStringList &list,User* user)
{
    user->My_Read_Overload(list);
}
#endif // USER_H
