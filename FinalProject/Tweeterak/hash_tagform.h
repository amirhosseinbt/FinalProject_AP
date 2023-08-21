#ifndef HASH_TAGFORM_H
#define HASH_TAGFORM_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include <QIcon>
#include <QPixmap>
#include <QPalette>
#include "Tweet.hpp"
#include "mention.h"
#include "re_quote_tweet.h"
namespace Ui {
class Hash_TagForm;
}

class Hash_TagForm : public QDialog
{
    Q_OBJECT

public:
    explicit Hash_TagForm(QWidget *parent = nullptr);
//    bool Get_Text(QString uitext);
    bool Set_t(QString text);
    QString Get_Uname_byId(int id);
    void Set_C_User_Id(int id);
    void showEvent(QShowEvent * event);
    void Get_C_User(User* user);
    bool Refresh();
    ~Hash_TagForm();

private slots:
    void on_btn_like_clicked();

    void on_btn_ok_clicked();

    void on_btn_mention_clicked();

    void on_btn_retweet_clicked();

private:
    Ui::Hash_TagForm *ui;
    int C_Userid = 0;
    QString Text;
    Re_Quote_Tweet * re_q_tweet;
    User* Current_User;
};

#endif // HASH_TAGFORM_H
