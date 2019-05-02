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
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_VerificationDlg
{
public:
    QPushButton *ver_qr;
    QPushButton *ver_face;

    void setupUi(QDialog *VerificationDlg)
    {
        if (VerificationDlg->objectName().isEmpty())
            VerificationDlg->setObjectName(QStringLiteral("VerificationDlg"));
        VerificationDlg->resize(400, 177);
        ver_qr = new QPushButton(VerificationDlg);
        ver_qr->setObjectName(QStringLiteral("ver_qr"));
        ver_qr->setGeometry(QRect(130, 100, 91, 31));
        ver_face = new QPushButton(VerificationDlg);
        ver_face->setObjectName(QStringLiteral("ver_face"));
        ver_face->setGeometry(QRect(130, 30, 91, 31));

        retranslateUi(VerificationDlg);

        QMetaObject::connectSlotsByName(VerificationDlg);
    } // setupUi

    void retranslateUi(QDialog *VerificationDlg)
    {
        VerificationDlg->setWindowTitle(QApplication::translate("VerificationDlg", "VerificationDlg", nullptr));
        ver_qr->setText(QApplication::translate("VerificationDlg", "\346\211\253\347\240\201\350\256\244\350\257\201", nullptr));
        ver_face->setText(QApplication::translate("VerificationDlg", "\344\272\272\350\204\270\350\257\206\345\210\253\350\256\244\350\257\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerificationDlg: public Ui_VerificationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFICATIONDLG_H
