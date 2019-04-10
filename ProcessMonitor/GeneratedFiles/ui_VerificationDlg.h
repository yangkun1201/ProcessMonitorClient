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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_VerificationDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *verificationCode_Edit;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_btn;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;

    void setupUi(QDialog *VerificationDlg)
    {
        if (VerificationDlg->objectName().isEmpty())
            VerificationDlg->setObjectName(QStringLiteral("VerificationDlg"));
        VerificationDlg->resize(400, 89);
        verticalLayout = new QVBoxLayout(VerificationDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(VerificationDlg);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        verificationCode_Edit = new QLineEdit(VerificationDlg);
        verificationCode_Edit->setObjectName(QStringLiteral("verificationCode_Edit"));

        horizontalLayout_2->addWidget(verificationCode_Edit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ok_btn = new QPushButton(VerificationDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout->addWidget(ok_btn);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(VerificationDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout->addWidget(cancel_btn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(VerificationDlg);

        QMetaObject::connectSlotsByName(VerificationDlg);
    } // setupUi

    void retranslateUi(QDialog *VerificationDlg)
    {
        VerificationDlg->setWindowTitle(QApplication::translate("VerificationDlg", "VerificationDlg", nullptr));
        label->setText(QApplication::translate("VerificationDlg", "\350\257\267\350\276\223\345\205\245\351\252\214\350\257\201\347\240\201:", nullptr));
        ok_btn->setText(QApplication::translate("VerificationDlg", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QApplication::translate("VerificationDlg", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VerificationDlg: public Ui_VerificationDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFICATIONDLG_H
