/********************************************************************************
** Form generated from reading UI file 'hash_tagform.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HASH_TAGFORM_H
#define UI_HASH_TAGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Hash_TagForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_mention;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_like;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_ok;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *Hash_TagForm)
    {
        if (Hash_TagForm->objectName().isEmpty())
            Hash_TagForm->setObjectName("Hash_TagForm");
        Hash_TagForm->resize(400, 353);
        verticalLayout_2 = new QVBoxLayout(Hash_TagForm);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Hash_TagForm);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        listWidget = new QListWidget(Hash_TagForm);
        listWidget->setObjectName("listWidget");
        QFont font1;
        font1.setBold(true);
        listWidget->setFont(font1);

        verticalLayout->addWidget(listWidget);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_mention = new QPushButton(Hash_TagForm);
        btn_mention->setObjectName("btn_mention");

        horizontalLayout->addWidget(btn_mention);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn_like = new QPushButton(Hash_TagForm);
        btn_like->setObjectName("btn_like");

        horizontalLayout->addWidget(btn_like);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn_ok = new QPushButton(Hash_TagForm);
        btn_ok->setObjectName("btn_ok");

        horizontalLayout->addWidget(btn_ok);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Hash_TagForm);

        QMetaObject::connectSlotsByName(Hash_TagForm);
    } // setupUi

    void retranslateUi(QDialog *Hash_TagForm)
    {
        Hash_TagForm->setWindowTitle(QCoreApplication::translate("Hash_TagForm", "HashTag", nullptr));
        label->setText(QCoreApplication::translate("Hash_TagForm", "Tweets", nullptr));
        btn_mention->setText(QString());
        btn_like->setText(QString());
        btn_ok->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Hash_TagForm: public Ui_Hash_TagForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HASH_TAGFORM_H
