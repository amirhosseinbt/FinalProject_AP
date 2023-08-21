/********************************************************************************
** Form generated from reading UI file 'o_signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_O_SIGNUP_H
#define UI_O_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_O_Signup
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_username;
    QLineEdit *txt_username;
    QLabel *lbl_password;
    QLineEdit *txt_password;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_name;
    QLineEdit *txt_name;
    QLabel *lbl_country;
    QLineEdit *txt_country;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_phonenumber;
    QLineEdit *txt_phonenumber;
    QLabel *lbl_link;
    QLineEdit *txt_link;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_biography;
    QTextEdit *txt_biography;
    QLabel *lbl_adminusername;
    QLineEdit *txt_adminusername;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_signup;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *O_Signup)
    {
        if (O_Signup->objectName().isEmpty())
            O_Signup->setObjectName("O_Signup");
        O_Signup->resize(775, 377);
        verticalLayout = new QVBoxLayout(O_Signup);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_username = new QLabel(O_Signup);
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

        txt_username = new QLineEdit(O_Signup);
        txt_username->setObjectName("txt_username");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txt_username->sizePolicy().hasHeightForWidth());
        txt_username->setSizePolicy(sizePolicy1);
        txt_username->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(txt_username);

        lbl_password = new QLabel(O_Signup);
        lbl_password->setObjectName("lbl_password");
        sizePolicy.setHeightForWidth(lbl_password->sizePolicy().hasHeightForWidth());
        lbl_password->setSizePolicy(sizePolicy);
        lbl_password->setFont(font);

        horizontalLayout->addWidget(lbl_password);

        txt_password = new QLineEdit(O_Signup);
        txt_password->setObjectName("txt_password");
        sizePolicy1.setHeightForWidth(txt_password->sizePolicy().hasHeightForWidth());
        txt_password->setSizePolicy(sizePolicy1);
        txt_password->setMinimumSize(QSize(0, 0));
        txt_password->setMaximumSize(QSize(16777215, 30));
        txt_password->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(txt_password);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_name = new QLabel(O_Signup);
        lbl_name->setObjectName("lbl_name");
        sizePolicy.setHeightForWidth(lbl_name->sizePolicy().hasHeightForWidth());
        lbl_name->setSizePolicy(sizePolicy);
        lbl_name->setFont(font);

        horizontalLayout_2->addWidget(lbl_name);

        txt_name = new QLineEdit(O_Signup);
        txt_name->setObjectName("txt_name");
        sizePolicy1.setHeightForWidth(txt_name->sizePolicy().hasHeightForWidth());
        txt_name->setSizePolicy(sizePolicy1);
        txt_name->setMinimumSize(QSize(0, 0));
        txt_name->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(txt_name);

        lbl_country = new QLabel(O_Signup);
        lbl_country->setObjectName("lbl_country");
        sizePolicy.setHeightForWidth(lbl_country->sizePolicy().hasHeightForWidth());
        lbl_country->setSizePolicy(sizePolicy);
        lbl_country->setFont(font);

        horizontalLayout_2->addWidget(lbl_country);

        txt_country = new QLineEdit(O_Signup);
        txt_country->setObjectName("txt_country");
        sizePolicy1.setHeightForWidth(txt_country->sizePolicy().hasHeightForWidth());
        txt_country->setSizePolicy(sizePolicy1);
        txt_country->setMinimumSize(QSize(0, 30));
        txt_country->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(txt_country);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_phonenumber = new QLabel(O_Signup);
        lbl_phonenumber->setObjectName("lbl_phonenumber");
        sizePolicy.setHeightForWidth(lbl_phonenumber->sizePolicy().hasHeightForWidth());
        lbl_phonenumber->setSizePolicy(sizePolicy);
        lbl_phonenumber->setFont(font);

        horizontalLayout_3->addWidget(lbl_phonenumber);

        txt_phonenumber = new QLineEdit(O_Signup);
        txt_phonenumber->setObjectName("txt_phonenumber");
        sizePolicy1.setHeightForWidth(txt_phonenumber->sizePolicy().hasHeightForWidth());
        txt_phonenumber->setSizePolicy(sizePolicy1);
        txt_phonenumber->setMinimumSize(QSize(0, 0));
        txt_phonenumber->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(txt_phonenumber);

        lbl_link = new QLabel(O_Signup);
        lbl_link->setObjectName("lbl_link");
        sizePolicy.setHeightForWidth(lbl_link->sizePolicy().hasHeightForWidth());
        lbl_link->setSizePolicy(sizePolicy);
        lbl_link->setFont(font);

        horizontalLayout_3->addWidget(lbl_link);

        txt_link = new QLineEdit(O_Signup);
        txt_link->setObjectName("txt_link");
        sizePolicy1.setHeightForWidth(txt_link->sizePolicy().hasHeightForWidth());
        txt_link->setSizePolicy(sizePolicy1);
        txt_link->setMinimumSize(QSize(0, 30));
        txt_link->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(txt_link);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_biography = new QLabel(O_Signup);
        lbl_biography->setObjectName("lbl_biography");
        sizePolicy.setHeightForWidth(lbl_biography->sizePolicy().hasHeightForWidth());
        lbl_biography->setSizePolicy(sizePolicy);
        lbl_biography->setFont(font);

        horizontalLayout_4->addWidget(lbl_biography);

        txt_biography = new QTextEdit(O_Signup);
        txt_biography->setObjectName("txt_biography");
        sizePolicy1.setHeightForWidth(txt_biography->sizePolicy().hasHeightForWidth());
        txt_biography->setSizePolicy(sizePolicy1);
        txt_biography->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_4->addWidget(txt_biography);

        lbl_adminusername = new QLabel(O_Signup);
        lbl_adminusername->setObjectName("lbl_adminusername");
        sizePolicy.setHeightForWidth(lbl_adminusername->sizePolicy().hasHeightForWidth());
        lbl_adminusername->setSizePolicy(sizePolicy);
        lbl_adminusername->setFont(font);

        horizontalLayout_4->addWidget(lbl_adminusername);

        txt_adminusername = new QLineEdit(O_Signup);
        txt_adminusername->setObjectName("txt_adminusername");
        sizePolicy1.setHeightForWidth(txt_adminusername->sizePolicy().hasHeightForWidth());
        txt_adminusername->setSizePolicy(sizePolicy1);
        txt_adminusername->setMinimumSize(QSize(0, 0));
        txt_adminusername->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(txt_adminusername);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        btn_signup = new QPushButton(O_Signup);
        btn_signup->setObjectName("btn_signup");
        btn_signup->setFont(font);

        horizontalLayout_5->addWidget(btn_signup);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(O_Signup);

        QMetaObject::connectSlotsByName(O_Signup);
    } // setupUi

    void retranslateUi(QDialog *O_Signup)
    {
        O_Signup->setWindowTitle(QCoreApplication::translate("O_Signup", "Sign Up", nullptr));
        lbl_username->setText(QCoreApplication::translate("O_Signup", "Username :         ", nullptr));
        lbl_password->setText(QCoreApplication::translate("O_Signup", "Password :", nullptr));
        lbl_name->setText(QCoreApplication::translate("O_Signup", "Name :                ", nullptr));
        lbl_country->setText(QCoreApplication::translate("O_Signup", "Country :   ", nullptr));
        lbl_phonenumber->setText(QCoreApplication::translate("O_Signup", "Phone Number :", nullptr));
        lbl_link->setText(QCoreApplication::translate("O_Signup", "Link :          ", nullptr));
        lbl_biography->setText(QCoreApplication::translate("O_Signup", "Biography :         ", nullptr));
        lbl_adminusername->setText(QCoreApplication::translate("O_Signup", "Admin Username :", nullptr));
        btn_signup->setText(QCoreApplication::translate("O_Signup", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class O_Signup: public Ui_O_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_O_SIGNUP_H
