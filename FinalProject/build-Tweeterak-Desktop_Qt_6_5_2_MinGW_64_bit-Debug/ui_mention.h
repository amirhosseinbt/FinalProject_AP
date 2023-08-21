/********************************************************************************
** Form generated from reading UI file 'mention.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENTION_H
#define UI_MENTION_H

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

QT_BEGIN_NAMESPACE

class Ui_Mention
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_mention;
    QListWidget *mentionlist;
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_yourmention;
    QTextEdit *txt_mention;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_tweet;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_like;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Mention)
    {
        if (Mention->objectName().isEmpty())
            Mention->setObjectName("Mention");
        Mention->resize(590, 443);
        verticalLayout_3 = new QVBoxLayout(Mention);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lbl_mention = new QLabel(Mention);
        lbl_mention->setObjectName("lbl_mention");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        lbl_mention->setFont(font);

        verticalLayout->addWidget(lbl_mention);

        mentionlist = new QListWidget(Mention);
        mentionlist->setObjectName("mentionlist");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        mentionlist->setFont(font1);

        verticalLayout->addWidget(mentionlist);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_yourmention = new QLabel(Mention);
        lbl_yourmention->setObjectName("lbl_yourmention");
        QFont font2;
        font2.setBold(true);
        lbl_yourmention->setFont(font2);

        verticalLayout_2->addWidget(lbl_yourmention);

        txt_mention = new QTextEdit(Mention);
        txt_mention->setObjectName("txt_mention");
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txt_mention->sizePolicy().hasHeightForWidth());
        txt_mention->setSizePolicy(sizePolicy);
        txt_mention->setMaximumSize(QSize(16777215, 100));

        verticalLayout_2->addWidget(txt_mention);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_tweet = new QPushButton(Mention);
        btn_tweet->setObjectName("btn_tweet");
        btn_tweet->setFont(font2);

        horizontalLayout->addWidget(btn_tweet);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_like = new QPushButton(Mention);
        btn_like->setObjectName("btn_like");

        horizontalLayout->addWidget(btn_like);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btn_ok = new QPushButton(Mention);
        btn_ok->setObjectName("btn_ok");

        horizontalLayout->addWidget(btn_ok);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(Mention);

        QMetaObject::connectSlotsByName(Mention);
    } // setupUi

    void retranslateUi(QDialog *Mention)
    {
        Mention->setWindowTitle(QCoreApplication::translate("Mention", "Mention", nullptr));
        lbl_mention->setText(QCoreApplication::translate("Mention", "Mentions", nullptr));
        lbl_yourmention->setText(QCoreApplication::translate("Mention", "Add your mention :", nullptr));
        btn_tweet->setText(QCoreApplication::translate("Mention", "Tweet", nullptr));
        btn_like->setText(QString());
        btn_ok->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Mention: public Ui_Mention {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENTION_H
