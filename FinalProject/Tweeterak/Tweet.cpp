#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Tweet.hpp"
Tweet::Tweet()
{
}

Tweet::~Tweet()
{

}

void Tweet::Set_User_id(int userid)
{
    Userid = userid;
}

int Tweet::Get_User_id()
{
    return Userid;
}

void Tweet::Add_Tweet(QString tweet_text)
{
    Tweet_Text = tweet_text;
}

QString Tweet::Get_Tweet_Text()
{
    return Tweet_Text;
}

void Tweet::Set_ID(int id)
{
    ID = id;
}

int Tweet::Get_ID()
{
    return ID;
}

void Tweet::Add_Like()
{
    N_Like++;
}

void Tweet::Dislike()
{
    N_Like--;
}

void Tweet::Set_N_Like(int num)
{
    N_Like = num;
}

int Tweet::Get_N_Like()
{
    return N_Like;
}

void Tweet::Set_Who_Like(int userid)
{
    Who_Like.push_back(userid);
}

std::vector<int> Tweet::Get_Who_Like()
{
    return Who_Like;
}

void Tweet::Erase_Who_Like(int id)
{
    N_Like--;
    for (int i = 0; i < Who_Like.size(); i++)
    {
        if (Who_Like[i] == id)
        {
            Who_Like.erase(Who_Like.begin()+i);
        }
    }
}

//void Tweet::Earase_Who_Like(QString username)
//{
//    for (int i = 0; i < Who_Like.size(); i++)
//    {
//        if (Who_Like[i] == username)
//        {
//            Who_Like.erase(Who_Like.begin()+i);
//        }

//    }
//}

void Tweet::My_overload(QTextStream &out)
{
    out << Userid <<"%$%"<< ID<<"%$%"<<Tweet_Text<<"%$%"<<N_Like<<"%$%";
    for(auto &T : Who_Like)
    {
        if(T != 0)
        {
            out << T <<",";
        }
    }
    out <<"%$%"<<Tweet_Date.toString("dd/MM/yyyy hh:mm:ss")<<"%$%"<<last_mention_id<<"%$%";
    for(auto & H : Hashtag)
    {
        if(H!="")
        {
            if(H.contains("#"))
            {
                out <<H<<",";
            }
            else
            {
                out <<"#"<<H<<",";
            }

        }
    }
    out<<"%$%"<<'\n';

}

void Tweet::My_Read_Overload(QStringList &list)
{
    this->Set_User_id(list.at(0).toInt());
    this->Set_ID(list.at(1).toInt());
    this->Add_Tweet(list.at(2));
    this->Set_N_Like(list.at(3).toInt());
    QStringList who_like;
    who_like =list.at(4).split(",");
    for(int i = 0; i < who_like.size() ;i++)
    {
        this->Set_Who_Like(who_like.at(i).toInt());
    }

    this->Set_Tweet_Date(QDateTime::fromString(list.at(5),"dd/MM/yyyy hh:mm:ss"));
    this->Set_last_mentionid(list.at(6).toInt());
    QStringList HashT;
    HashT = list.at(7).split(",");
    for(int i = 0; i < HashT.size() ; i++)
    {
        this->Set_Hashtag(HashT.at(i));
    }
}

void Tweet::Set_Tweet_Date(QDateTime date)
{
    Tweet_Date = date;
}

QDateTime Tweet::Get_Tweet_Date()
{
    return Tweet_Date;
}

void Tweet::Set_last_mentionid(int id)
{
    last_mention_id = id;
}

int Tweet::Get_last_mentionid()
{
    return last_mention_id;
}

void Tweet::Add_last_mentionid()
{
    last_mention_id++;
}

void Tweet::Set_Hashtag(QString text)
{
    Hashtag.push_back(text);
}

std::vector<QString> Tweet::Get_Hashtag()
{
    return Hashtag;
}


void Mentions::Set_mention_user_id(int id)
{
    mention_user_id = id;
}

int Mentions::Get_mention_user_id()
{
    return mention_user_id;
}

void Mentions::Set_mention_id(int id)
{
    mention_id = id;
}

int Mentions::Get_mention_id()
{
    return mention_id;
}

void Mentions::My_overload(QTextStream &out)
{
    out << Userid <<"%$%"<< ID<<"%$%"<<Tweet_Text<<"%$%"<<N_Like<<"%$%";
    for(auto &T : Who_Like)
    {
        if(T != 0)
        {
            out << T <<",";
        }
    }
    out <<"%$%"<<Tweet_Date.toString("dd/MM/yyyy hh:mm:ss")<<"%$%"<<mention_user_id<<"%$%"<<mention_id<<"%$%";
    for(auto & H : Hashtag)
    {
        if(H!="")
        {
            if(H.contains("#"))
            {
                out <<H<<",";
            }
            else
            {
                out <<"#"<<H<<",";
            }

        }
    }
    out<<"%$%"<<'\n';
}
void Mentions::My_Read_Overload(QStringList &list)
{
    this->Set_User_id(list.at(0).toInt());
    this->Set_ID(list.at(1).toInt());
    this->Add_Tweet(list.at(2));
    this->Set_N_Like(list.at(3).toInt());
    QStringList who_like;
    who_like =list.at(4).split(",");
    for(int i = 0; i < who_like.size() ;i++)
    {
        this->Set_Who_Like(who_like.at(i).toInt());
    }

    this->Set_Tweet_Date(QDateTime::fromString(list.at(5),"dd/MM/yyyy hh:mm:ss"));
    this->Set_mention_user_id(list.at(6).toInt());
    this->Set_mention_id(list.at(7).toInt());
    QStringList HashT;
    HashT = list.at(8).split(",");
    for(int i = 0; i < HashT.size() ; i++)
    {
        this->Set_Hashtag(HashT.at(i));
    }
}
