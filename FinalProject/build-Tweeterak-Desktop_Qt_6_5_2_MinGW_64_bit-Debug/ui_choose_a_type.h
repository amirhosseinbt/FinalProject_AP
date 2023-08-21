/********************************************************************************
** Form generated from reading UI file 'choose_a_type.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSE_A_TYPE_H
#define UI_CHOOSE_A_TYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Choose_A_Type
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *lbl_txt;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_organ;
    QRadioButton *rbtn_personal;
    QRadioButton *rbtn_anonymous;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_confirm;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *Choose_A_Type)
    {
        if (Choose_A_Type->objectName().isEmpty())
            Choose_A_Type->setObjectName("Choose_A_Type");
        Choose_A_Type->resize(300, 200);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Choose_A_Type->sizePolicy().hasHeightForWidth());
        Choose_A_Type->setSizePolicy(sizePolicy);
        Choose_A_Type->setMinimumSize(QSize(300, 200));
        verticalLayout_2 = new QVBoxLayout(Choose_A_Type);
        verticalLayout_2->setObjectName("verticalLayout_2");
        lbl_txt = new QLabel(Choose_A_Type);
        lbl_txt->setObjectName("lbl_txt");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lbl_txt->sizePolicy().hasHeightForWidth());
        lbl_txt->setSizePolicy(sizePolicy1);
        QFont font;
        font.setBold(true);
        lbl_txt->setFont(font);

        verticalLayout_2->addWidget(lbl_txt);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        rbtn_organ = new QRadioButton(Choose_A_Type);
        rbtn_organ->setObjectName("rbtn_organ");
        rbtn_organ->setFont(font);

        verticalLayout->addWidget(rbtn_organ);

        rbtn_personal = new QRadioButton(Choose_A_Type);
        rbtn_personal->setObjectName("rbtn_personal");
        rbtn_personal->setFont(font);

        verticalLayout->addWidget(rbtn_personal);

        rbtn_anonymous = new QRadioButton(Choose_A_Type);
        rbtn_anonymous->setObjectName("rbtn_anonymous");
        rbtn_anonymous->setFont(font);

        verticalLayout->addWidget(rbtn_anonymous);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_confirm = new QPushButton(Choose_A_Type);
        btn_confirm->setObjectName("btn_confirm");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_confirm->sizePolicy().hasHeightForWidth());
        btn_confirm->setSizePolicy(sizePolicy2);
        btn_confirm->setFont(font);

        horizontalLayout->addWidget(btn_confirm);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Choose_A_Type);

        QMetaObject::connectSlotsByName(Choose_A_Type);
    } // setupUi

    void retranslateUi(QDialog *Choose_A_Type)
    {
        Choose_A_Type->setWindowTitle(QCoreApplication::translate("Choose_A_Type", "Account Type", nullptr));
        lbl_txt->setText(QCoreApplication::translate("Choose_A_Type", " Choose your account type :", nullptr));
        rbtn_organ->setText(QCoreApplication::translate("Choose_A_Type", "Organization", nullptr));
        rbtn_personal->setText(QCoreApplication::translate("Choose_A_Type", "Personal", nullptr));
        rbtn_anonymous->setText(QCoreApplication::translate("Choose_A_Type", "Anonymous", nullptr));
        btn_confirm->setText(QCoreApplication::translate("Choose_A_Type", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Choose_A_Type: public Ui_Choose_A_Type {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSE_A_TYPE_H
