/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbl_logo;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_username;
    QLineEdit *txt_username;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_password;
    QLineEdit *txt_password;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_login;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_signup;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(363, 445);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Login);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lbl_logo = new QLabel(Login);
        lbl_logo->setObjectName("lbl_logo");
        lbl_logo->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(lbl_logo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_username = new QLabel(Login);
        lbl_username->setObjectName("lbl_username");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_username->sizePolicy().hasHeightForWidth());
        lbl_username->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        lbl_username->setFont(font);

        horizontalLayout->addWidget(lbl_username);

        txt_username = new QLineEdit(Login);
        txt_username->setObjectName("txt_username");
        sizePolicy.setHeightForWidth(txt_username->sizePolicy().hasHeightForWidth());
        txt_username->setSizePolicy(sizePolicy);
        txt_username->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(txt_username);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_password = new QLabel(Login);
        lbl_password->setObjectName("lbl_password");
        sizePolicy1.setHeightForWidth(lbl_password->sizePolicy().hasHeightForWidth());
        lbl_password->setSizePolicy(sizePolicy1);
        lbl_password->setFont(font);

        horizontalLayout_2->addWidget(lbl_password);

        txt_password = new QLineEdit(Login);
        txt_password->setObjectName("txt_password");
        sizePolicy.setHeightForWidth(txt_password->sizePolicy().hasHeightForWidth());
        txt_password->setSizePolicy(sizePolicy);
        txt_password->setMinimumSize(QSize(0, 30));
        txt_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txt_password);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btn_login = new QPushButton(Login);
        btn_login->setObjectName("btn_login");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_login->sizePolicy().hasHeightForWidth());
        btn_login->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(btn_login);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btn_signup = new QPushButton(Login);
        btn_signup->setObjectName("btn_signup");
        sizePolicy2.setHeightForWidth(btn_signup->sizePolicy().hasHeightForWidth());
        btn_signup->setSizePolicy(sizePolicy2);

        horizontalLayout_3->addWidget(btn_signup);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Log In", nullptr));
        lbl_logo->setText(QString());
        lbl_username->setText(QCoreApplication::translate("Login", "Username :", nullptr));
        txt_username->setPlaceholderText(QCoreApplication::translate("Login", "Username", nullptr));
        lbl_password->setText(QCoreApplication::translate("Login", "Password :  ", nullptr));
        txt_password->setPlaceholderText(QCoreApplication::translate("Login", "Password", nullptr));
        btn_login->setText(QString());
        btn_signup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
