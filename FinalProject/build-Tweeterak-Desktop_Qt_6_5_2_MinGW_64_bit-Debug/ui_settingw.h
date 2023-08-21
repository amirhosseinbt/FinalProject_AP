/********************************************************************************
** Form generated from reading UI file 'settingw.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGW_H
#define UI_SETTINGW_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingW
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_13;
    QLabel *lbl_profpic;
    QPushButton *btn_changepic;
    QSpacerItem *horizontalSpacer_4;
    QLabel *lbl_header;
    QPushButton *btn_headerchange;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_username;
    QLineEdit *txt_username;
    QSpacerItem *verticalSpacer_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_password;
    QLineEdit *txt_password;
    QSpacerItem *verticalSpacer_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_name;
    QLineEdit *txt_name;
    QSpacerItem *verticalSpacer_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_country;
    QLineEdit *txt_country;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_phonenumber;
    QLineEdit *txt_phonenumber;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *lbl_link;
    QLineEdit *txt_link;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbl_orgusername;
    QLineEdit *txt_orgusername;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lbl_adminusername;
    QLineEdit *txt_adminusername;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbl_brthdate;
    QDateEdit *brthdate;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *lbl_biography;
    QTextEdit *txt_biography;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_change;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_delaccount;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_12;

    void setupUi(QDialog *SettingW)
    {
        if (SettingW->objectName().isEmpty())
            SettingW->setObjectName("SettingW");
        SettingW->resize(830, 584);
        verticalLayout = new QVBoxLayout(SettingW);
        verticalLayout->setObjectName("verticalLayout");
        widget = new QWidget(SettingW);
        widget->setObjectName("widget");
        horizontalLayout_13 = new QHBoxLayout(widget);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        lbl_profpic = new QLabel(widget);
        lbl_profpic->setObjectName("lbl_profpic");

        horizontalLayout_13->addWidget(lbl_profpic);

        btn_changepic = new QPushButton(widget);
        btn_changepic->setObjectName("btn_changepic");

        horizontalLayout_13->addWidget(btn_changepic);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);

        lbl_header = new QLabel(widget);
        lbl_header->setObjectName("lbl_header");
        QFont font;
        font.setBold(true);
        lbl_header->setFont(font);

        horizontalLayout_13->addWidget(lbl_header);

        btn_headerchange = new QPushButton(widget);
        btn_headerchange->setObjectName("btn_headerchange");

        horizontalLayout_13->addWidget(btn_headerchange);


        verticalLayout->addWidget(widget);

        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_username = new QLabel(SettingW);
        lbl_username->setObjectName("lbl_username");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_username->sizePolicy().hasHeightForWidth());
        lbl_username->setSizePolicy(sizePolicy);
        lbl_username->setFont(font);

        horizontalLayout_2->addWidget(lbl_username);

        txt_username = new QLineEdit(SettingW);
        txt_username->setObjectName("txt_username");
        txt_username->setMinimumSize(QSize(0, 30));
        txt_username->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(txt_username);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_password = new QLabel(SettingW);
        lbl_password->setObjectName("lbl_password");
        sizePolicy.setHeightForWidth(lbl_password->sizePolicy().hasHeightForWidth());
        lbl_password->setSizePolicy(sizePolicy);
        lbl_password->setFont(font);

        horizontalLayout_3->addWidget(lbl_password);

        txt_password = new QLineEdit(SettingW);
        txt_password->setObjectName("txt_password");
        txt_password->setMinimumSize(QSize(0, 30));
        txt_password->setMaximumSize(QSize(16777215, 30));
        txt_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(txt_password);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_9);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_name = new QLabel(SettingW);
        lbl_name->setObjectName("lbl_name");
        sizePolicy.setHeightForWidth(lbl_name->sizePolicy().hasHeightForWidth());
        lbl_name->setSizePolicy(sizePolicy);
        lbl_name->setFont(font);

        horizontalLayout_4->addWidget(lbl_name);

        txt_name = new QLineEdit(SettingW);
        txt_name->setObjectName("txt_name");
        txt_name->setMinimumSize(QSize(0, 30));
        txt_name->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(txt_name);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lbl_country = new QLabel(SettingW);
        lbl_country->setObjectName("lbl_country");
        sizePolicy.setHeightForWidth(lbl_country->sizePolicy().hasHeightForWidth());
        lbl_country->setSizePolicy(sizePolicy);
        lbl_country->setFont(font);

        horizontalLayout_5->addWidget(lbl_country);

        txt_country = new QLineEdit(SettingW);
        txt_country->setObjectName("txt_country");
        txt_country->setMinimumSize(QSize(0, 30));
        txt_country->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(txt_country);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lbl_phonenumber = new QLabel(SettingW);
        lbl_phonenumber->setObjectName("lbl_phonenumber");
        sizePolicy.setHeightForWidth(lbl_phonenumber->sizePolicy().hasHeightForWidth());
        lbl_phonenumber->setSizePolicy(sizePolicy);
        lbl_phonenumber->setFont(font);

        horizontalLayout_6->addWidget(lbl_phonenumber);

        txt_phonenumber = new QLineEdit(SettingW);
        txt_phonenumber->setObjectName("txt_phonenumber");
        txt_phonenumber->setMinimumSize(QSize(0, 30));
        txt_phonenumber->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_6->addWidget(txt_phonenumber);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        lbl_link = new QLabel(SettingW);
        lbl_link->setObjectName("lbl_link");
        sizePolicy.setHeightForWidth(lbl_link->sizePolicy().hasHeightForWidth());
        lbl_link->setSizePolicy(sizePolicy);
        lbl_link->setFont(font);

        horizontalLayout_7->addWidget(lbl_link);

        txt_link = new QLineEdit(SettingW);
        txt_link->setObjectName("txt_link");
        txt_link->setMinimumSize(QSize(0, 30));
        txt_link->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_7->addWidget(txt_link);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        lbl_orgusername = new QLabel(SettingW);
        lbl_orgusername->setObjectName("lbl_orgusername");
        sizePolicy.setHeightForWidth(lbl_orgusername->sizePolicy().hasHeightForWidth());
        lbl_orgusername->setSizePolicy(sizePolicy);
        lbl_orgusername->setFont(font);

        horizontalLayout_8->addWidget(lbl_orgusername);

        txt_orgusername = new QLineEdit(SettingW);
        txt_orgusername->setObjectName("txt_orgusername");
        txt_orgusername->setMinimumSize(QSize(0, 30));
        txt_orgusername->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_8->addWidget(txt_orgusername);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        lbl_adminusername = new QLabel(SettingW);
        lbl_adminusername->setObjectName("lbl_adminusername");
        sizePolicy.setHeightForWidth(lbl_adminusername->sizePolicy().hasHeightForWidth());
        lbl_adminusername->setSizePolicy(sizePolicy);
        lbl_adminusername->setFont(font);

        horizontalLayout_9->addWidget(lbl_adminusername);

        txt_adminusername = new QLineEdit(SettingW);
        txt_adminusername->setObjectName("txt_adminusername");
        txt_adminusername->setMinimumSize(QSize(0, 30));
        txt_adminusername->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_9->addWidget(txt_adminusername);


        verticalLayout->addLayout(horizontalLayout_9);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        lbl_brthdate = new QLabel(SettingW);
        lbl_brthdate->setObjectName("lbl_brthdate");
        sizePolicy.setHeightForWidth(lbl_brthdate->sizePolicy().hasHeightForWidth());
        lbl_brthdate->setSizePolicy(sizePolicy);
        lbl_brthdate->setFont(font);

        horizontalLayout_10->addWidget(lbl_brthdate);

        brthdate = new QDateEdit(SettingW);
        brthdate->setObjectName("brthdate");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(brthdate->sizePolicy().hasHeightForWidth());
        brthdate->setSizePolicy(sizePolicy1);
        brthdate->setMinimumSize(QSize(0, 30));
        brthdate->setMaximumSize(QSize(16777215, 30));
        brthdate->setFrame(true);
        brthdate->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        brthdate->setButtonSymbols(QAbstractSpinBox::NoButtons);
        brthdate->setMaximumDateTime(QDateTime(QDate(2023, 12, 31), QTime(9, 59, 59)));
        brthdate->setMinimumDateTime(QDateTime(QDate(1900, 9, 13), QTime(9, 30, 0)));

        horizontalLayout_10->addWidget(brthdate);


        verticalLayout->addLayout(horizontalLayout_10);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        lbl_biography = new QLabel(SettingW);
        lbl_biography->setObjectName("lbl_biography");
        sizePolicy.setHeightForWidth(lbl_biography->sizePolicy().hasHeightForWidth());
        lbl_biography->setSizePolicy(sizePolicy);
        lbl_biography->setFont(font);
        lbl_biography->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_11->addWidget(lbl_biography);

        txt_biography = new QTextEdit(SettingW);
        txt_biography->setObjectName("txt_biography");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(txt_biography->sizePolicy().hasHeightForWidth());
        txt_biography->setSizePolicy(sizePolicy2);
        txt_biography->setMaximumSize(QSize(16777215, 60));

        horizontalLayout_11->addWidget(txt_biography);


        verticalLayout->addLayout(horizontalLayout_11);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer);

        btn_change = new QPushButton(SettingW);
        btn_change->setObjectName("btn_change");
        btn_change->setFont(font);

        horizontalLayout_12->addWidget(btn_change);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        btn_delaccount = new QPushButton(SettingW);
        btn_delaccount->setObjectName("btn_delaccount");
        btn_delaccount->setFont(font);

        horizontalLayout_12->addWidget(btn_delaccount);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_12);

        verticalSpacer_12 = new QSpacerItem(20, 25, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_12);


        retranslateUi(SettingW);

        QMetaObject::connectSlotsByName(SettingW);
    } // setupUi

    void retranslateUi(QDialog *SettingW)
    {
        SettingW->setWindowTitle(QCoreApplication::translate("SettingW", "Setting", nullptr));
        lbl_profpic->setText(QString());
        btn_changepic->setText(QString());
        lbl_header->setText(QCoreApplication::translate("SettingW", "Choose header color :", nullptr));
        btn_headerchange->setText(QString());
        lbl_username->setText(QCoreApplication::translate("SettingW", "Username :", nullptr));
        txt_username->setPlaceholderText(QCoreApplication::translate("SettingW", "Username", nullptr));
        lbl_password->setText(QCoreApplication::translate("SettingW", "Password : ", nullptr));
        txt_password->setPlaceholderText(QCoreApplication::translate("SettingW", "Password", nullptr));
        lbl_name->setText(QCoreApplication::translate("SettingW", "Name :       ", nullptr));
        txt_name->setPlaceholderText(QCoreApplication::translate("SettingW", "Name", nullptr));
        lbl_country->setText(QCoreApplication::translate("SettingW", "Country :   ", nullptr));
        txt_country->setPlaceholderText(QCoreApplication::translate("SettingW", "Country", nullptr));
        lbl_phonenumber->setText(QCoreApplication::translate("SettingW", "Phone :      ", nullptr));
        txt_phonenumber->setPlaceholderText(QCoreApplication::translate("SettingW", "Phone", nullptr));
        lbl_link->setText(QCoreApplication::translate("SettingW", "Link :          ", nullptr));
        txt_link->setPlaceholderText(QCoreApplication::translate("SettingW", "Link", nullptr));
        lbl_orgusername->setText(QCoreApplication::translate("SettingW", "Organ  :     ", nullptr));
        txt_orgusername->setPlaceholderText(QString());
        lbl_adminusername->setText(QCoreApplication::translate("SettingW", "Admin :     ", nullptr));
        txt_adminusername->setPlaceholderText(QString());
        lbl_brthdate->setText(QCoreApplication::translate("SettingW", "Birthday :  ", nullptr));
        lbl_biography->setText(QCoreApplication::translate("SettingW", "Bio :           ", nullptr));
        txt_biography->setPlaceholderText(QCoreApplication::translate("SettingW", "Biography", nullptr));
        btn_change->setText(QCoreApplication::translate("SettingW", "Save Changes", nullptr));
        btn_delaccount->setText(QCoreApplication::translate("SettingW", "Delete Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingW: public Ui_SettingW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGW_H
