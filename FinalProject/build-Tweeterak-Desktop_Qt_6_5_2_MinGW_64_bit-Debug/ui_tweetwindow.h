/********************************************************************************
** Form generated from reading UI file 'tweetwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TWEETWINDOW_H
#define UI_TWEETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TweetWindow
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QTextEdit *txt_tweet;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_tweet;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *TweetWindow)
    {
        if (TweetWindow->objectName().isEmpty())
            TweetWindow->setObjectName("TweetWindow");
        TweetWindow->resize(503, 254);
        verticalLayout = new QVBoxLayout(TweetWindow);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        txt_tweet = new QTextEdit(TweetWindow);
        txt_tweet->setObjectName("txt_tweet");

        horizontalLayout->addWidget(txt_tweet);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_tweet = new QPushButton(TweetWindow);
        btn_tweet->setObjectName("btn_tweet");
        QFont font;
        font.setBold(true);
        btn_tweet->setFont(font);

        horizontalLayout_2->addWidget(btn_tweet);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(TweetWindow);

        QMetaObject::connectSlotsByName(TweetWindow);
    } // setupUi

    void retranslateUi(QDialog *TweetWindow)
    {
        TweetWindow->setWindowTitle(QCoreApplication::translate("TweetWindow", "Tweet", nullptr));
        txt_tweet->setPlaceholderText(QCoreApplication::translate("TweetWindow", "What's happening ?", nullptr));
        btn_tweet->setText(QCoreApplication::translate("TweetWindow", "Tweet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TweetWindow: public Ui_TweetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TWEETWINDOW_H
