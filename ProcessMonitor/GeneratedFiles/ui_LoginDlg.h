/********************************************************************************
** Form generated from reading UI file 'LoginDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDLG_H
#define UI_LOGINDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginDlg
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *account_input;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password_input;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *ok_btn;
    QPushButton *cancel_btn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn_regist;

    void setupUi(QDialog *LoginDlg)
    {
        if (LoginDlg->objectName().isEmpty())
            LoginDlg->setObjectName(QStringLiteral("LoginDlg"));
        LoginDlg->resize(397, 224);
        verticalLayout = new QVBoxLayout(LoginDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(LoginDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 0));

        horizontalLayout->addWidget(label);

        account_input = new QLineEdit(LoginDlg);
        account_input->setObjectName(QStringLiteral("account_input"));

        horizontalLayout->addWidget(account_input);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(LoginDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(60, 0));

        horizontalLayout_2->addWidget(label_2);

        password_input = new QLineEdit(LoginDlg);
        password_input->setObjectName(QStringLiteral("password_input"));
        password_input->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(password_input);


        verticalLayout->addLayout(horizontalLayout_2);

        line = new QFrame(LoginDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        ok_btn = new QPushButton(LoginDlg);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));

        horizontalLayout_3->addWidget(ok_btn);

        cancel_btn = new QPushButton(LoginDlg);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));

        horizontalLayout_3->addWidget(cancel_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btn_regist = new QPushButton(LoginDlg);
        btn_regist->setObjectName(QStringLiteral("btn_regist"));

        horizontalLayout_3->addWidget(btn_regist);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(LoginDlg);

        QMetaObject::connectSlotsByName(LoginDlg);
    } // setupUi

    void retranslateUi(QDialog *LoginDlg)
    {
        LoginDlg->setWindowTitle(QApplication::translate("LoginDlg", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("LoginDlg", "\350\264\246\345\217\267", nullptr));
        label_2->setText(QApplication::translate("LoginDlg", "\345\257\206\347\240\201", nullptr));
        ok_btn->setText(QApplication::translate("LoginDlg", "\347\241\256\350\256\244", nullptr));
        cancel_btn->setText(QApplication::translate("LoginDlg", "\345\217\226\346\266\210", nullptr));
        btn_regist->setText(QApplication::translate("LoginDlg", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDlg: public Ui_LoginDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDLG_H
