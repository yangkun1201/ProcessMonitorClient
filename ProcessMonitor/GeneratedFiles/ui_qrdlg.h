/********************************************************************************
** Form generated from reading UI file 'qrdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QRDLG_H
#define UI_QRDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QrDlg
{
public:
    QLabel *qrImg;

    void setupUi(QWidget *QrDlg)
    {
        if (QrDlg->objectName().isEmpty())
            QrDlg->setObjectName(QStringLiteral("QrDlg"));
        QrDlg->resize(400, 300);
        qrImg = new QLabel(QrDlg);
        qrImg->setObjectName(QStringLiteral("qrImg"));
        qrImg->setGeometry(QRect(110, 60, 171, 171));

        retranslateUi(QrDlg);

        QMetaObject::connectSlotsByName(QrDlg);
    } // setupUi

    void retranslateUi(QWidget *QrDlg)
    {
        QrDlg->setWindowTitle(QApplication::translate("QrDlg", "Form", nullptr));
        qrImg->setText(QApplication::translate("QrDlg", "\345\233\276\347\211\207\345\212\240\350\275\275\344\270\255...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QrDlg: public Ui_QrDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QRDLG_H
