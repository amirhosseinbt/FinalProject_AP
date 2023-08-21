/********************************************************************************
** Form generated from reading UI file 'a_signup.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_A_SIGNUP_H
#define UI_A_SIGNUP_H

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

class Ui_A_Signup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblusername;
    QLineEdit *txtusername;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lblpassword;
    QLineEdit *txtpassword;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnsignup;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *A_Signup)
    {
        if (A_Signup->objectName().isEmpty())
            A_Signup->setObjectName("A_Signup");
        A_Signup->resize(400, 200);
        A_Signup->setMinimumSize(QSize(400, 200));
        verticalLayout = new QVBoxLayout(A_Signup);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lblusername = new QLabel(A_Signup);
        lblusername->setObjectName("lblusername");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblusername->sizePolicy().hasHeightForWidth());
        lblusername->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        lblusername->setFont(font);

        horizontalLayout->addWidget(lblusername);

        txtusername = new QLineEdit(A_Signup);
        txtusername->setObjectName("txtusername");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtusername->sizePolicy().hasHeightForWidth());
        txtusername->setSizePolicy(sizePolicy1);
        txtusername->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(txtusername);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lblpassword = new QLabel(A_Signup);
        lblpassword->setObjectName("lblpassword");
        sizePolicy.setHeightForWidth(lblpassword->sizePolicy().hasHeightForWidth());
        lblpassword->setSizePolicy(sizePolicy);
        lblpassword->setFont(font);

        horizontalLayout_2->addWidget(lblpassword);

        txtpassword = new QLineEdit(A_Signup);
        txtpassword->setObjectName("txtpassword");
        sizePolicy1.setHeightForWidth(txtpassword->sizePolicy().hasHeightForWidth());
        txtpassword->setSizePolicy(sizePolicy1);
        txtpassword->setMaximumSize(QSize(16777215, 30));
        txtpassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(txtpassword);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnsignup = new QPushButton(A_Signup);
        btnsignup->setObjectName("btnsignup");
        btnsignup->setFont(font);

        horizontalLayout_3->addWidget(btnsignup);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(A_Signup);

        QMetaObject::connectSlotsByName(A_Signup);
    } // setupUi

    void retranslateUi(QDialog *A_Signup)
    {
        A_Signup->setWindowTitle(QCoreApplication::translate("A_Signup", "Sign Up", nullptr));
        lblusername->setText(QCoreApplication::translate("A_Signup", "Username :", nullptr));
        lblpassword->setText(QCoreApplication::translate("A_Signup", "Password :  ", nullptr));
        btnsignup->setText(QCoreApplication::translate("A_Signup", "Sign Up", nullptr));
    } // retranslateUi

};

namespace Ui {
    class A_Signup: public Ui_A_Signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_A_SIGNUP_H
