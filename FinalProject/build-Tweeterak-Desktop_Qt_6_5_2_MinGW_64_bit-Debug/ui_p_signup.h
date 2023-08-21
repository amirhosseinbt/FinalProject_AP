/********************************************************************************
** Form generated from reading UI file 'p_signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_P_SIGNUP_H
#define UI_P_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_P_SignUp
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_username;
    QLineEdit *txt_username;
    QLabel *lbl_password;
    QLineEdit *txt_password;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_name;
    QLineEdit *txt_name;
    QLabel *lbl_country;
    QLineEdit *txt_country;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_phonenumber;
    QLineEdit *txt_phonenumber;
    QLabel *lbl_link;
    QLineEdit *txt_link;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_organusername;
    QLineEdit *txt_organusername;
    QLabel *lbl_date;
    QDateEdit *bth_date;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbl_biography;
    QTextEdit *txt_biography;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_signup;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_7;

    void setupUi(QDialog *P_SignUp)
    {
        if (P_SignUp->objectName().isEmpty())
            P_SignUp->setObjectName("P_SignUp");
        P_SignUp->resize(826, 434);
        verticalLayout = new QVBoxLayout(P_SignUp);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_username = new QLabel(P_SignUp);
        lbl_username->setObjectName("lbl_username");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_username->sizePolicy().hasHeightForWidth());
        lbl_username->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        lbl_username->setFont(font);

        horizontalLayout->addWidget(lbl_username);

        txt_username = new QLineEdit(P_SignUp);
        txt_username->setObjectName("txt_username");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_username->sizePolicy().hasHeightForWidth());
        txt_username->setSizePolicy(sizePolicy1);
        txt_username->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(txt_username);

        lbl_password = new QLabel(P_SignUp);
        lbl_password->setObjectName("lbl_password");
        sizePolicy.setHeightForWidth(lbl_password->sizePolicy().hasHeightForWidth());
        lbl_password->setSizePolicy(sizePolicy);
        lbl_password->setFont(font);

        horizontalLayout->addWidget(lbl_password);

        txt_password = new QLineEdit(P_SignUp);
        txt_password->setObjectName("txt_password");
        sizePolicy1.setHeightForWidth(txt_password->sizePolicy().hasHeightForWidth());
        txt_password->setSizePolicy(sizePolicy1);
        txt_password->setMinimumSize(QSize(0, 30));
        txt_password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(txt_password);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_name = new QLabel(P_SignUp);
        lbl_name->setObjectName("lbl_name");
        sizePolicy.setHeightForWidth(lbl_name->sizePolicy().hasHeightForWidth());
        lbl_name->setSizePolicy(sizePolicy);
        lbl_name->setFont(font);

        horizontalLayout_2->addWidget(lbl_name);

        txt_name = new QLineEdit(P_SignUp);
        txt_name->setObjectName("txt_name");
        sizePolicy1.setHeightForWidth(txt_name->sizePolicy().hasHeightForWidth());
        txt_name->setSizePolicy(sizePolicy1);
        txt_name->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(txt_name);

        lbl_country = new QLabel(P_SignUp);
        lbl_country->setObjectName("lbl_country");
        sizePolicy.setHeightForWidth(lbl_country->sizePolicy().hasHeightForWidth());
        lbl_country->setSizePolicy(sizePolicy);
        lbl_country->setFont(font);

        horizontalLayout_2->addWidget(lbl_country);

        txt_country = new QLineEdit(P_SignUp);
        txt_country->setObjectName("txt_country");
        sizePolicy1.setHeightForWidth(txt_country->sizePolicy().hasHeightForWidth());
        txt_country->setSizePolicy(sizePolicy1);
        txt_country->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(txt_country);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_phonenumber = new QLabel(P_SignUp);
        lbl_phonenumber->setObjectName("lbl_phonenumber");
        sizePolicy.setHeightForWidth(lbl_phonenumber->sizePolicy().hasHeightForWidth());
        lbl_phonenumber->setSizePolicy(sizePolicy);
        lbl_phonenumber->setFont(font);

        horizontalLayout_3->addWidget(lbl_phonenumber);

        txt_phonenumber = new QLineEdit(P_SignUp);
        txt_phonenumber->setObjectName("txt_phonenumber");
        sizePolicy1.setHeightForWidth(txt_phonenumber->sizePolicy().hasHeightForWidth());
        txt_phonenumber->setSizePolicy(sizePolicy1);
        txt_phonenumber->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(txt_phonenumber);

        lbl_link = new QLabel(P_SignUp);
        lbl_link->setObjectName("lbl_link");
        sizePolicy.setHeightForWidth(lbl_link->sizePolicy().hasHeightForWidth());
        lbl_link->setSizePolicy(sizePolicy);
        lbl_link->setFont(font);

        horizontalLayout_3->addWidget(lbl_link);

        txt_link = new QLineEdit(P_SignUp);
        txt_link->setObjectName("txt_link");
        sizePolicy1.setHeightForWidth(txt_link->sizePolicy().hasHeightForWidth());
        txt_link->setSizePolicy(sizePolicy1);
        txt_link->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(txt_link);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lbl_organusername = new QLabel(P_SignUp);
        lbl_organusername->setObjectName("lbl_organusername");
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_organusername->sizePolicy().hasHeightForWidth());
        lbl_organusername->setSizePolicy(sizePolicy2);
        lbl_organusername->setFont(font);

        horizontalLayout_6->addWidget(lbl_organusername);

        txt_organusername = new QLineEdit(P_SignUp);
        txt_organusername->setObjectName("txt_organusername");
        sizePolicy1.setHeightForWidth(txt_organusername->sizePolicy().hasHeightForWidth());
        txt_organusername->setSizePolicy(sizePolicy1);
        txt_organusername->setMinimumSize(QSize(0, 30));

        horizontalLayout_6->addWidget(txt_organusername);

        lbl_date = new QLabel(P_SignUp);
        lbl_date->setObjectName("lbl_date");
        sizePolicy2.setHeightForWidth(lbl_date->sizePolicy().hasHeightForWidth());
        lbl_date->setSizePolicy(sizePolicy2);
        lbl_date->setFont(font);

        horizontalLayout_6->addWidget(lbl_date);

        bth_date = new QDateEdit(P_SignUp);
        bth_date->setObjectName("bth_date");
        sizePolicy1.setHeightForWidth(bth_date->sizePolicy().hasHeightForWidth());
        bth_date->setSizePolicy(sizePolicy1);
        bth_date->setMinimumSize(QSize(0, 30));
        bth_date->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_6->addWidget(bth_date);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        lbl_biography = new QLabel(P_SignUp);
        lbl_biography->setObjectName("lbl_biography");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lbl_biography->sizePolicy().hasHeightForWidth());
        lbl_biography->setSizePolicy(sizePolicy3);
        lbl_biography->setFont(font);

        horizontalLayout_4->addWidget(lbl_biography);

        txt_biography = new QTextEdit(P_SignUp);
        txt_biography->setObjectName("txt_biography");
        sizePolicy1.setHeightForWidth(txt_biography->sizePolicy().hasHeightForWidth());
        txt_biography->setSizePolicy(sizePolicy1);
        txt_biography->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_4->addWidget(txt_biography);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_signup = new QPushButton(P_SignUp);
        btn_signup->setObjectName("btn_signup");
        btn_signup->setFont(font);

        horizontalLayout_5->addWidget(btn_signup);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);


        retranslateUi(P_SignUp);

        QMetaObject::connectSlotsByName(P_SignUp);
    } // setupUi

    void retranslateUi(QDialog *P_SignUp)
    {
        P_SignUp->setWindowTitle(QCoreApplication::translate("P_SignUp", "Sign Up", nullptr));
        lbl_username->setText(QCoreApplication::translate("P_SignUp", "Username :            ", nullptr));
        txt_username->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Username", nullptr));
        lbl_password->setText(QCoreApplication::translate("P_SignUp", "Password :", nullptr));
        txt_password->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Password", nullptr));
        lbl_name->setText(QCoreApplication::translate("P_SignUp", "Name :                   ", nullptr));
        txt_name->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Name", nullptr));
        lbl_country->setText(QCoreApplication::translate("P_SignUp", "Country :   ", nullptr));
        txt_country->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Country", nullptr));
        lbl_phonenumber->setText(QCoreApplication::translate("P_SignUp", "PhoneNumber :   ", nullptr));
        txt_phonenumber->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Phone number", nullptr));
        lbl_link->setText(QCoreApplication::translate("P_SignUp", "Link :          ", nullptr));
        txt_link->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Link", nullptr));
        lbl_organusername->setText(QCoreApplication::translate("P_SignUp", "Organ Username :", nullptr));
        txt_organusername->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Organ Username", nullptr));
        lbl_date->setText(QCoreApplication::translate("P_SignUp", "Birthday :   ", nullptr));
        lbl_biography->setText(QCoreApplication::translate("P_SignUp", "Biograhy :    ", nullptr));
        txt_biography->setPlaceholderText(QCoreApplication::translate("P_SignUp", "Biography", nullptr));
        btn_signup->setText(QCoreApplication::translate("P_SignUp", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class P_SignUp: public Ui_P_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_P_SIGNUP_H
