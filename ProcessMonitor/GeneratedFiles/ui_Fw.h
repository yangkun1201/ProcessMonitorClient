/********************************************************************************
** Form generated from reading UI file 'Fw.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FW_H
#define UI_FW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fw
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_name;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_time;

    void setupUi(QWidget *Fw)
    {
        if (Fw->objectName().isEmpty())
            Fw->setObjectName(QStringLiteral("Fw"));
        Fw->resize(183, 72);
        Fw->setMinimumSize(QSize(60, 60));
        layoutWidget = new QWidget(Fw);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 116, 16));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        label_name = new QLabel(layoutWidget);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        layoutWidget1 = new QWidget(Fw);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 40, 116, 16));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_time = new QLabel(layoutWidget1);
        label_time->setObjectName(QStringLiteral("label_time"));

        horizontalLayout_2->addWidget(label_time);


        retranslateUi(Fw);

        QMetaObject::connectSlotsByName(Fw);
    } // setupUi

    void retranslateUi(QWidget *Fw)
    {
        Fw->setWindowTitle(QApplication::translate("Fw", "Fw", nullptr));
        label->setText(QApplication::translate("Fw", "\346\255\243\345\234\250\350\277\220\350\241\214:", nullptr));
        label_name->setText(QString());
        label_2->setText(QApplication::translate("Fw", "\345\275\223\345\211\215\347\224\250\346\227\266:", nullptr));
        label_time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Fw: public Ui_Fw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FW_H
