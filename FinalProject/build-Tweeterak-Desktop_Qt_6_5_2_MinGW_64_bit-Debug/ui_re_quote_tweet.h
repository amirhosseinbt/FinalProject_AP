/********************************************************************************
** Form generated from reading UI file 're_quote_tweet.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RE_QUOTE_TWEET_H
#define UI_RE_QUOTE_TWEET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Re_Quote_Tweet
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_retweet;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_quotetweet;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Re_Quote_Tweet)
    {
        if (Re_Quote_Tweet->objectName().isEmpty())
            Re_Quote_Tweet->setObjectName("Re_Quote_Tweet");
        Re_Quote_Tweet->resize(179, 138);
        verticalLayout = new QVBoxLayout(Re_Quote_Tweet);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_retweet = new QPushButton(Re_Quote_Tweet);
        btn_retweet->setObjectName("btn_retweet");
        QFont font;
        font.setBold(true);
        btn_retweet->setFont(font);

        horizontalLayout->addWidget(btn_retweet);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_quotetweet = new QPushButton(Re_Quote_Tweet);
        btn_quotetweet->setObjectName("btn_quotetweet");
        btn_quotetweet->setFont(font);

        horizontalLayout_2->addWidget(btn_quotetweet);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Re_Quote_Tweet);

        QMetaObject::connectSlotsByName(Re_Quote_Tweet);
    } // setupUi

    void retranslateUi(QDialog *Re_Quote_Tweet)
    {
        Re_Quote_Tweet->setWindowTitle(QCoreApplication::translate("Re_Quote_Tweet", "Dialog", nullptr));
        btn_retweet->setText(QCoreApplication::translate("Re_Quote_Tweet", "Retweet", nullptr));
        btn_quotetweet->setText(QCoreApplication::translate("Re_Quote_Tweet", "Quote tweet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Re_Quote_Tweet: public Ui_Re_Quote_Tweet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RE_QUOTE_TWEET_H
