/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_picture;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *lbl_nfollowers;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLabel *lbl_nfollowings;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btn_search;
    QLineEdit *txt_search;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *btn_logout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_setting;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_tweets;
    QListWidget *list_tweets;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_mention;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_like;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_tweet;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(929, 600);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_picture = new QLabel(centralwidget);
        lbl_picture->setObjectName("lbl_picture");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_picture->sizePolicy().hasHeightForWidth());
        lbl_picture->setSizePolicy(sizePolicy);
        lbl_picture->setMinimumSize(QSize(0, 0));
        lbl_picture->setSizeIncrement(QSize(0, 0));

        horizontalLayout_2->addWidget(lbl_picture);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        lbl_nfollowers = new QLabel(centralwidget);
        lbl_nfollowers->setObjectName("lbl_nfollowers");
        QFont font1;
        font1.setBold(true);
        lbl_nfollowers->setFont(font1);
        lbl_nfollowers->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lbl_nfollowers);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        verticalLayout_3->addWidget(label_3);

        lbl_nfollowings = new QLabel(centralwidget);
        lbl_nfollowings->setObjectName("lbl_nfollowings");
        lbl_nfollowings->setFont(font1);
        lbl_nfollowings->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(lbl_nfollowings);


        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_9);

        btn_search = new QPushButton(centralwidget);
        btn_search->setObjectName("btn_search");

        horizontalLayout_2->addWidget(btn_search);

        txt_search = new QLineEdit(centralwidget);
        txt_search->setObjectName("txt_search");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_search->sizePolicy().hasHeightForWidth());
        txt_search->setSizePolicy(sizePolicy1);
        txt_search->setMinimumSize(QSize(250, 35));

        horizontalLayout_2->addWidget(txt_search);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        btn_logout = new QPushButton(centralwidget);
        btn_logout->setObjectName("btn_logout");

        horizontalLayout_2->addWidget(btn_logout);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btn_setting = new QPushButton(centralwidget);
        btn_setting->setObjectName("btn_setting");

        horizontalLayout_2->addWidget(btn_setting);


        verticalLayout_4->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_tweets = new QLabel(centralwidget);
        lbl_tweets->setObjectName("lbl_tweets");
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setStrikeOut(false);
        lbl_tweets->setFont(font2);

        verticalLayout->addWidget(lbl_tweets);

        list_tweets = new QListWidget(centralwidget);
        list_tweets->setObjectName("list_tweets");
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe UI")});
        font3.setPointSize(11);
        font3.setBold(true);
        list_tweets->setFont(font3);
        list_tweets->setFrameShape(QFrame::StyledPanel);
        list_tweets->setFrameShadow(QFrame::Sunken);
        list_tweets->setAlternatingRowColors(false);

        verticalLayout->addWidget(list_tweets);


        verticalLayout_4->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_mention = new QPushButton(centralwidget);
        btn_mention->setObjectName("btn_mention");

        horizontalLayout->addWidget(btn_mention);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btn_like = new QPushButton(centralwidget);
        btn_like->setObjectName("btn_like");

        horizontalLayout->addWidget(btn_like);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_tweet = new QPushButton(centralwidget);
        btn_tweet->setObjectName("btn_tweet");

        horizontalLayout->addWidget(btn_tweet);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl_picture->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Followers", nullptr));
        lbl_nfollowers->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Followings", nullptr));
        lbl_nfollowings->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        btn_search->setText(QString());
        txt_search->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        btn_logout->setText(QString());
        btn_setting->setText(QString());
        lbl_tweets->setText(QCoreApplication::translate("MainWindow", "Tweets", nullptr));
        btn_mention->setText(QString());
        btn_like->setText(QString());
        btn_tweet->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
