/********************************************************************************
** Form generated from reading UI file 'Question.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTION_H
#define UI_QUESTION_H

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

class Ui_Question
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *question_label;
    QLineEdit *question_input;
    QHBoxLayout *horizontalLayout;
    QPushButton *question_ok;
    QSpacerItem *horizontalSpacer;
    QPushButton *question_cancel;

    void setupUi(QDialog *Question)
    {
        if (Question->objectName().isEmpty())
            Question->setObjectName(QStringLiteral("Question"));
        Question->resize(400, 132);
        verticalLayout_2 = new QVBoxLayout(Question);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        question_label = new QLabel(Question);
        question_label->setObjectName(QStringLiteral("question_label"));
        QFont font;
        font.setFamily(QStringLiteral("AcadEref"));
        font.setPointSize(22);
        question_label->setFont(font);

        verticalLayout->addWidget(question_label);

        question_input = new QLineEdit(Question);
        question_input->setObjectName(QStringLiteral("question_input"));

        verticalLayout->addWidget(question_input);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        question_ok = new QPushButton(Question);
        question_ok->setObjectName(QStringLiteral("question_ok"));

        horizontalLayout->addWidget(question_ok);

        horizontalSpacer = new QSpacerItem(98, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        question_cancel = new QPushButton(Question);
        question_cancel->setObjectName(QStringLiteral("question_cancel"));

        horizontalLayout->addWidget(question_cancel);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(Question);

        QMetaObject::connectSlotsByName(Question);
    } // setupUi

    void retranslateUi(QDialog *Question)
    {
        Question->setWindowTitle(QApplication::translate("Question", "Question", nullptr));
        question_label->setText(QApplication::translate("Question", "\345\215\201\345\205\255\350\277\233\345\210\266\346\225\26012H\347\232\204\344\272\214\350\277\233\345\210\266\347\232\204\350\241\250\347\244\272\344\270\272?", nullptr));
        question_ok->setText(QApplication::translate("Question", "\347\241\256\350\256\244", nullptr));
        question_cancel->setText(QApplication::translate("Question", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Question: public Ui_Question {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTION_H
