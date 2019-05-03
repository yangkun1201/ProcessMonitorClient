/********************************************************************************
** Form generated from reading UI file 'VerificationDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFICATIONDLG_H
#define UI_VERIFICATIONDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VerificationDlg
{
public:
    QPushButton *ver_qr;
    QPushButton *ver_face;
    QLabel *label;
    QLabel *message;

    void setupUi(QDialog *VerificationDlg)
    {
        if (VerificationDlg->objectName().isEmpty())
            VerificationDlg->setObjectName(QStringLiteral("VerificationDlg"));
        VerificationDlg->resize(400, 222);
        ver_qr = new QPushButton(VerificationDlg);
        ver_qr->setObjectName(QStringLiteral("ver_qr"));
        ver_qr->setGeometry(QRect(220, 50, 91, 31));
        ver_face = new QPushButton(VerificationDlg);
        ver_face->setObjectName(QStringLiteral("ver_face"));
        ver_face->setGeometry(QRect(60, 50, 91, 31));
        label = new QLabel(VerificationDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(63, 10, 251, 20));
        message = new QLabel(VerificationDlg);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(130, 90, 121, 61));

        retranslateUi(VerificationDlg);

        QMetaObject::connectSlotsByName(VerificationDlg);
    } // setupUi

    void retranslateUi(QDialog *VerificationDlg)
    {
        VerificationDlg->setWindowTitle(QApplication::translate("VerificationDlg", "VerificationDlg", nullptr));
        ver_qr->setText(QApplication::translate("VerificationDlg", "\346\211\253\347\240\201\350\256\244\350\257\201", nullptr));
        ver_face->setText(QApplication::translate("VerificationDlg", "\344\272\272\350\204\270\350\257\206\345\210\253\350\256\244\350\257\201", nullptr));
        label->setText(QApplication::translate("VerificationDlg", "\346\243\200\346\265\213\345\210\260\351\225\277\346\227\266\351\227\264\346\234\252\346\223\215\344\275\234\347\224\265\350\204\221\357\274\214\350\257\267\351\200\211\346\213\251\344\273\245\344\270\213\346\226\271\345\274\217\350\256\244\350\257\201", nullptr));
        message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class VerificationDlg: public Ui_VerificationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFICATIONDLG_H
