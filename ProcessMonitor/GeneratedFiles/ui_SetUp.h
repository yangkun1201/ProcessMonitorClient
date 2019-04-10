/********************************************************************************
** Form generated from reading UI file 'SetUp.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SetUp
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *text;
    QVBoxLayout *verticalLayout;
    QCheckBox *soft_1;
    QCheckBox *soft_2;
    QCheckBox *soft_3;
    QCheckBox *soft_4;
    QCheckBox *soft_5;
    QCheckBox *soft_6;
    QCheckBox *soft_7;
    QCheckBox *soft_8;
    QCheckBox *soft_9;
    QCheckBox *soft_10;
    QCheckBox *soft_11;
    QCheckBox *soft_12;
    QCheckBox *soft_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;

    void setupUi(QDialog *SetUp)
    {
        if (SetUp->objectName().isEmpty())
            SetUp->setObjectName(QStringLiteral("SetUp"));
        SetUp->resize(261, 355);
        verticalLayout_2 = new QVBoxLayout(SetUp);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        text = new QLabel(SetUp);
        text->setObjectName(QStringLiteral("text"));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(12);
        text->setFont(font);

        verticalLayout_2->addWidget(text);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        soft_1 = new QCheckBox(SetUp);
        soft_1->setObjectName(QStringLiteral("soft_1"));

        verticalLayout->addWidget(soft_1);

        soft_2 = new QCheckBox(SetUp);
        soft_2->setObjectName(QStringLiteral("soft_2"));

        verticalLayout->addWidget(soft_2);

        soft_3 = new QCheckBox(SetUp);
        soft_3->setObjectName(QStringLiteral("soft_3"));

        verticalLayout->addWidget(soft_3);

        soft_4 = new QCheckBox(SetUp);
        soft_4->setObjectName(QStringLiteral("soft_4"));

        verticalLayout->addWidget(soft_4);

        soft_5 = new QCheckBox(SetUp);
        soft_5->setObjectName(QStringLiteral("soft_5"));

        verticalLayout->addWidget(soft_5);

        soft_6 = new QCheckBox(SetUp);
        soft_6->setObjectName(QStringLiteral("soft_6"));

        verticalLayout->addWidget(soft_6);

        soft_7 = new QCheckBox(SetUp);
        soft_7->setObjectName(QStringLiteral("soft_7"));

        verticalLayout->addWidget(soft_7);

        soft_8 = new QCheckBox(SetUp);
        soft_8->setObjectName(QStringLiteral("soft_8"));

        verticalLayout->addWidget(soft_8);

        soft_9 = new QCheckBox(SetUp);
        soft_9->setObjectName(QStringLiteral("soft_9"));

        verticalLayout->addWidget(soft_9);

        soft_10 = new QCheckBox(SetUp);
        soft_10->setObjectName(QStringLiteral("soft_10"));

        verticalLayout->addWidget(soft_10);

        soft_11 = new QCheckBox(SetUp);
        soft_11->setObjectName(QStringLiteral("soft_11"));

        verticalLayout->addWidget(soft_11);

        soft_12 = new QCheckBox(SetUp);
        soft_12->setObjectName(QStringLiteral("soft_12"));

        verticalLayout->addWidget(soft_12);

        soft_13 = new QCheckBox(SetUp);
        soft_13->setObjectName(QStringLiteral("soft_13"));

        verticalLayout->addWidget(soft_13);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ok_btn = new QPushButton(SetUp);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout->addWidget(ok_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(SetUp);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(SetUp);

        QMetaObject::connectSlotsByName(SetUp);
    } // setupUi

    void retranslateUi(QDialog *SetUp)
    {
        SetUp->setWindowTitle(QApplication::translate("SetUp", "SetUp", nullptr));
        text->setText(QApplication::translate("SetUp", "\344\277\256\346\224\271\347\233\221\346\216\247\350\275\257\344\273\266", nullptr));
        soft_1->setText(QApplication::translate("SetUp", "\347\210\261\345\245\207\350\211\272", nullptr));
        soft_2->setText(QApplication::translate("SetUp", "QQ", nullptr));
        soft_3->setText(QApplication::translate("SetUp", "VS", nullptr));
        soft_4->setText(QApplication::translate("SetUp", "Android Studio", nullptr));
        soft_5->setText(QApplication::translate("SetUp", "Wamp", nullptr));
        soft_6->setText(QApplication::translate("SetUp", "sublime_text", nullptr));
        soft_7->setText(QApplication::translate("SetUp", "Dev-C++", nullptr));
        soft_8->setText(QApplication::translate("SetUp", "eclipse", nullptr));
        soft_9->setText(QApplication::translate("SetUp", "IntelliJ IDEA", nullptr));
        soft_10->setText(QApplication::translate("SetUp", "PyCharm", nullptr));
        soft_11->setText(QApplication::translate("SetUp", "myeclipse", nullptr));
        soft_12->setText(QApplication::translate("SetUp", "\345\276\256\344\277\241web\345\274\200\345\217\221\350\200\205\345\267\245\345\205\267", nullptr));
        soft_13->setText(QApplication::translate("SetUp", "Adobe Photoshop CS6", nullptr));
        ok_btn->setText(QApplication::translate("SetUp", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QApplication::translate("SetUp", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetUp: public Ui_SetUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
