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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Fw
{
public:
    QLabel *label;
    QLabel *label_name;
    QLabel *label_2;
    QLabel *label_time;
    QLabel *label_3;
    QLabel *label_active;

    void setupUi(QWidget *Fw)
    {
        if (Fw->objectName().isEmpty())
            Fw->setObjectName(QStringLiteral("Fw"));
        Fw->resize(226, 79);
        Fw->setMinimumSize(QSize(60, 60));
        Fw->setStyleSheet(QStringLiteral(""));
        label = new QLabel(Fw);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 31, 16));
        label_name = new QLabel(Fw);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setGeometry(QRect(50, 10, 101, 16));
        label_2 = new QLabel(Fw);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 41, 16));
        label_time = new QLabel(Fw);
        label_time->setObjectName(QStringLiteral("label_time"));
        label_time->setGeometry(QRect(50, 30, 91, 16));
        label_3 = new QLabel(Fw);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 30, 31, 16));
        label_active = new QLabel(Fw);
        label_active->setObjectName(QStringLiteral("label_active"));
        label_active->setGeometry(QRect(60, 50, 91, 16));

        retranslateUi(Fw);

        QMetaObject::connectSlotsByName(Fw);
    } // setupUi

    void retranslateUi(QWidget *Fw)
    {
        Fw->setWindowTitle(QApplication::translate("Fw", "Fw", nullptr));
        label->setText(QApplication::translate("Fw", "\347\250\213\345\272\217:", nullptr));
        label_name->setText(QString());
        label_2->setText(QApplication::translate("Fw", "\346\264\273\345\212\250\345\200\274:", nullptr));
        label_time->setText(QString());
        label_3->setText(QApplication::translate("Fw", "\347\224\250\346\227\266:", nullptr));
        label_active->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Fw: public Ui_Fw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FW_H
