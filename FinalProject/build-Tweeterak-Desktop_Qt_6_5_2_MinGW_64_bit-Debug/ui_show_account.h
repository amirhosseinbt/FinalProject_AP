/********************************************************************************
** Form generated from reading UI file 'show_account.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOW_ACCOUNT_H
#define UI_SHOW_ACCOUNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Show_Account
{
public:
    QVBoxLayout *verticalLayout_4;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_13;
    QLabel *lbl_profpic;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QLabel *lbl_nfollowers;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *lbl_nfollowings;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_username;
    QLabel *txt_username;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_name;
    QLabel *txt_name;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbl_brthdate;
    QLabel *txt_brth;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_country;
    QLabel *txt_country;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_link;
    QLabel *txt_link;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbl_orgusername;
    QLabel *txt_orguname;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lbl_adminusername;
    QLabel *txt_adminuname;
    QVBoxLayout *verticalLayout_5;
    QLabel *lbl_biography;
    QTextEdit *txt_bio;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_tweets;
    QListWidget *list_tweets;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_mention;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_retweet;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_like;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_follow;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_unfollow;
    QSpacerItem *horizontalSpacer_7;

    void setupUi(QDialog *Show_Account)
    {
        if (Show_Account->objectName().isEmpty())
            Show_Account->setObjectName("Show_Account");
        Show_Account->resize(613, 650);
        verticalLayout_4 = new QVBoxLayout(Show_Account);
        verticalLayout_4->setObjectName("verticalLayout_4");
        widget = new QWidget(Show_Account);
        widget->setObjectName("widget");
        horizontalLayout_13 = new QHBoxLayout(widget);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        lbl_profpic = new QLabel(widget);
        lbl_profpic->setObjectName("lbl_profpic");

        horizontalLayout_13->addWidget(lbl_profpic);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_2->setFont(font);

        verticalLayout_2->addWidget(label_2);

        lbl_nfollowers = new QLabel(widget);
        lbl_nfollowers->setObjectName("lbl_nfollowers");
        QFont font1;
        font1.setBold(true);
        lbl_nfollowers->setFont(font1);
        lbl_nfollowers->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbl_nfollowers);


        horizontalLayout_13->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        lbl_nfollowings = new QLabel(widget);
        lbl_nfollowings->setObjectName("lbl_nfollowings");
        lbl_nfollowings->setFont(font1);
        lbl_nfollowings->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lbl_nfollowings);


        horizontalLayout_13->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);


        verticalLayout_4->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_username = new QLabel(Show_Account);
        lbl_username->setObjectName("lbl_username");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_username->sizePolicy().hasHeightForWidth());
        lbl_username->setSizePolicy(sizePolicy);
        lbl_username->setFont(font1);

        horizontalLayout_2->addWidget(lbl_username);

        txt_username = new QLabel(Show_Account);
        txt_username->setObjectName("txt_username");

        horizontalLayout_2->addWidget(txt_username);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_name = new QLabel(Show_Account);
        lbl_name->setObjectName("lbl_name");
        sizePolicy.setHeightForWidth(lbl_name->sizePolicy().hasHeightForWidth());
        lbl_name->setSizePolicy(sizePolicy);
        lbl_name->setFont(font1);

        horizontalLayout_4->addWidget(lbl_name);

        txt_name = new QLabel(Show_Account);
        txt_name->setObjectName("txt_name");

        horizontalLayout_4->addWidget(txt_name);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lbl_brthdate = new QLabel(Show_Account);
        lbl_brthdate->setObjectName("lbl_brthdate");
        sizePolicy.setHeightForWidth(lbl_brthdate->sizePolicy().hasHeightForWidth());
        lbl_brthdate->setSizePolicy(sizePolicy);
        lbl_brthdate->setFont(font1);

        horizontalLayout_10->addWidget(lbl_brthdate);

        txt_brth = new QLabel(Show_Account);
        txt_brth->setObjectName("txt_brth");

        horizontalLayout_10->addWidget(txt_brth);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lbl_country = new QLabel(Show_Account);
        lbl_country->setObjectName("lbl_country");
        sizePolicy.setHeightForWidth(lbl_country->sizePolicy().hasHeightForWidth());
        lbl_country->setSizePolicy(sizePolicy);
        lbl_country->setFont(font1);

        horizontalLayout_5->addWidget(lbl_country);

        txt_country = new QLabel(Show_Account);
        txt_country->setObjectName("txt_country");

        horizontalLayout_5->addWidget(txt_country);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lbl_link = new QLabel(Show_Account);
        lbl_link->setObjectName("lbl_link");
        sizePolicy.setHeightForWidth(lbl_link->sizePolicy().hasHeightForWidth());
        lbl_link->setSizePolicy(sizePolicy);
        lbl_link->setFont(font1);

        horizontalLayout_7->addWidget(lbl_link);

        txt_link = new QLabel(Show_Account);
        txt_link->setObjectName("txt_link");

        horizontalLayout_7->addWidget(txt_link);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        lbl_orgusername = new QLabel(Show_Account);
        lbl_orgusername->setObjectName("lbl_orgusername");
        sizePolicy.setHeightForWidth(lbl_orgusername->sizePolicy().hasHeightForWidth());
        lbl_orgusername->setSizePolicy(sizePolicy);
        lbl_orgusername->setFont(font1);

        horizontalLayout_8->addWidget(lbl_orgusername);

        txt_orguname = new QLabel(Show_Account);
        txt_orguname->setObjectName("txt_orguname");

        horizontalLayout_8->addWidget(txt_orguname);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        lbl_adminusername = new QLabel(Show_Account);
        lbl_adminusername->setObjectName("lbl_adminusername");
        sizePolicy.setHeightForWidth(lbl_adminusername->sizePolicy().hasHeightForWidth());
        lbl_adminusername->setSizePolicy(sizePolicy);
        lbl_adminusername->setFont(font1);

        horizontalLayout_9->addWidget(lbl_adminusername);

        txt_adminuname = new QLabel(Show_Account);
        txt_adminuname->setObjectName("txt_adminuname");

        horizontalLayout_9->addWidget(txt_adminuname);


        verticalLayout_4->addLayout(horizontalLayout_9);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        lbl_biography = new QLabel(Show_Account);
        lbl_biography->setObjectName("lbl_biography");
        sizePolicy.setHeightForWidth(lbl_biography->sizePolicy().hasHeightForWidth());
        lbl_biography->setSizePolicy(sizePolicy);
        lbl_biography->setFont(font1);
        lbl_biography->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_5->addWidget(lbl_biography);

        txt_bio = new QTextEdit(Show_Account);
        txt_bio->setObjectName("txt_bio");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_bio->sizePolicy().hasHeightForWidth());
        txt_bio->setSizePolicy(sizePolicy1);
        txt_bio->setMinimumSize(QSize(0, 0));
        txt_bio->setMaximumSize(QSize(16777215, 60));
        txt_bio->setReadOnly(true);

        verticalLayout_5->addWidget(txt_bio);


        verticalLayout_4->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_tweets = new QLabel(Show_Account);
        lbl_tweets->setObjectName("lbl_tweets");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        lbl_tweets->setFont(font2);

        verticalLayout->addWidget(lbl_tweets);

        list_tweets = new QListWidget(Show_Account);
        list_tweets->setObjectName("list_tweets");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(list_tweets->sizePolicy().hasHeightForWidth());
        list_tweets->setSizePolicy(sizePolicy2);
        list_tweets->setMaximumSize(QSize(16777215, 200));
        list_tweets->setFont(font);

        verticalLayout->addWidget(list_tweets);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        btn_mention = new QPushButton(Show_Account);
        btn_mention->setObjectName("btn_mention");

        horizontalLayout->addWidget(btn_mention);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        btn_retweet = new QPushButton(Show_Account);
        btn_retweet->setObjectName("btn_retweet");

        horizontalLayout->addWidget(btn_retweet);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_like = new QPushButton(Show_Account);
        btn_like->setObjectName("btn_like");

        horizontalLayout->addWidget(btn_like);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btn_follow = new QPushButton(Show_Account);
        btn_follow->setObjectName("btn_follow");
        btn_follow->setFont(font1);

        horizontalLayout->addWidget(btn_follow);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        btn_unfollow = new QPushButton(Show_Account);
        btn_unfollow->setObjectName("btn_unfollow");
        btn_unfollow->setFont(font1);

        horizontalLayout->addWidget(btn_unfollow);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(Show_Account);

        QMetaObject::connectSlotsByName(Show_Account);
    } // setupUi

    void retranslateUi(QDialog *Show_Account)
    {
        Show_Account->setWindowTitle(QCoreApplication::translate("Show_Account", "Account", nullptr));
        lbl_profpic->setText(QString());
        label_2->setText(QCoreApplication::translate("Show_Account", "Followers", nullptr));
        lbl_nfollowers->setText(QCoreApplication::translate("Show_Account", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("Show_Account", "Followings", nullptr));
        lbl_nfollowings->setText(QCoreApplication::translate("Show_Account", "TextLabel", nullptr));
        lbl_username->setText(QCoreApplication::translate("Show_Account", "Username :", nullptr));
        txt_username->setText(QString());
        lbl_name->setText(QCoreApplication::translate("Show_Account", "Name : ", nullptr));
        txt_name->setText(QString());
        lbl_brthdate->setText(QCoreApplication::translate("Show_Account", "Birthday : ", nullptr));
        txt_brth->setText(QString());
        lbl_country->setText(QCoreApplication::translate("Show_Account", "Country :  ", nullptr));
        txt_country->setText(QString());
        lbl_link->setText(QCoreApplication::translate("Show_Account", "Link :  ", nullptr));
        txt_link->setText(QString());
        lbl_orgusername->setText(QCoreApplication::translate("Show_Account", "Organ  : ", nullptr));
        txt_orguname->setText(QString());
        lbl_adminusername->setText(QCoreApplication::translate("Show_Account", "Admin : ", nullptr));
        txt_adminuname->setText(QString());
        lbl_biography->setText(QCoreApplication::translate("Show_Account", "Bio :", nullptr));
        lbl_tweets->setText(QCoreApplication::translate("Show_Account", "Tweets", nullptr));
        btn_mention->setText(QString());
        btn_retweet->setText(QString());
        btn_like->setText(QString());
        btn_follow->setText(QCoreApplication::translate("Show_Account", "Follow", nullptr));
        btn_unfollow->setText(QCoreApplication::translate("Show_Account", "Unfollow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Show_Account: public Ui_Show_Account {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOW_ACCOUNT_H
