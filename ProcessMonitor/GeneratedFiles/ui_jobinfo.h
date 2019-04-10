/********************************************************************************
** Form generated from reading UI file 'jobinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOBINFO_H
#define UI_JOBINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JobInfo
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_4;
    QLabel *label_10;
    QLabel *label_5;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_7;
    QLabel *label_13;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_8;

    void setupUi(QWidget *JobInfo)
    {
        if (JobInfo->objectName().isEmpty())
            JobInfo->setObjectName(QStringLiteral("JobInfo"));
        JobInfo->resize(241, 300);
        label = new QLabel(JobInfo);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(14);
        label->setFont(font);
        label_3 = new QLabel(JobInfo);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 100, 36, 16));
        label_9 = new QLabel(JobInfo);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(61, 100, 115, 16));
        label_4 = new QLabel(JobInfo);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 140, 60, 16));
        label_10 = new QLabel(JobInfo);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(85, 140, 81, 16));
        label_5 = new QLabel(JobInfo);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 180, 36, 16));
        label_11 = new QLabel(JobInfo);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(61, 180, 181, 16));
        label_12 = new QLabel(JobInfo);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(61, 220, 51, 16));
        label_7 = new QLabel(JobInfo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 220, 36, 16));
        label_13 = new QLabel(JobInfo);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(82, 260, 71, 16));
        label_6 = new QLabel(JobInfo);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 260, 57, 16));
        label_2 = new QLabel(JobInfo);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 60, 36, 16));
        label_8 = new QLabel(JobInfo);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(61, 60, 91, 16));

        retranslateUi(JobInfo);

        QMetaObject::connectSlotsByName(JobInfo);
    } // setupUi

    void retranslateUi(QWidget *JobInfo)
    {
        JobInfo->setWindowTitle(QApplication::translate("JobInfo", "Form", nullptr));
        label->setText(QApplication::translate("JobInfo", "\346\213\233\350\201\230\344\277\241\346\201\257", nullptr));
        label_3->setText(QApplication::translate("JobInfo", "\350\241\214\344\270\232\357\274\232", nullptr));
        label_9->setText(QApplication::translate("JobInfo", "IT\346\234\215\345\212\241\357\274\210\347\263\273\347\273\237/\346\225\260\346\215\256...", nullptr));
        label_4->setText(QApplication::translate("JobInfo", "\345\267\245\344\275\234\345\234\260\347\202\271\357\274\232", nullptr));
        label_10->setText(QApplication::translate("JobInfo", "\346\235\255\345\267\236-\344\275\231\346\235\255\345\214\272", nullptr));
        label_5->setText(QApplication::translate("JobInfo", "\345\205\254\345\217\270\357\274\232", nullptr));
        label_11->setText(QApplication::translate("JobInfo", "\344\270\255\345\233\275\350\201\224\351\200\232\342\200\224\344\270\255\345\233\275\350\201\224\351\200\232\346\265\231\346\261\237\347\234\201\345\210\206\345\205\254\345\217\270", nullptr));
        label_12->setText(QApplication::translate("JobInfo", "8000/\346\234\210", nullptr));
        label_7->setText(QApplication::translate("JobInfo", "\345\267\245\350\265\204\357\274\232", nullptr));
        label_13->setText(QApplication::translate("JobInfo", "2018-03-29", nullptr));
        label_6->setText(QApplication::translate("JobInfo", "\345\217\221\345\270\203\346\227\266\351\227\264\357\274\232", nullptr));
        label_2->setText(QApplication::translate("JobInfo", "\350\201\214\344\275\215\357\274\232", nullptr));
        label_8->setText(QApplication::translate("JobInfo", "Java\345\274\200\345\217\221\345\267\245\347\250\213\345\270\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JobInfo: public Ui_JobInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOBINFO_H
