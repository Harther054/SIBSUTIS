/********************************************************************************
** Form generated from reading UI file 'ivanov.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IVANOV_H
#define UI_IVANOV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ivanov
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QWidget *Ivanov)
    {
        if (Ivanov->objectName().isEmpty())
            Ivanov->setObjectName(QStringLiteral("Ivanov"));
        Ivanov->resize(514, 350);
        label = new QLabel(Ivanov);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 241, 221));
        label->setLayoutDirection(Qt::LeftToRight);
        label->setFrameShape(QFrame::Panel);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);
        textEdit = new QTextEdit(Ivanov);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(270, 10, 221, 251));
        buttonBox = new QDialogButtonBox(Ivanov);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(70, 300, 351, 23));
        buttonBox->setLayoutDirection(Qt::LeftToRight);
        buttonBox->setStyleSheet(QStringLiteral("background-color: rgb(255, 248, 187) "));
        buttonBox->setStandardButtons(QDialogButtonBox::Open|QDialogButtonBox::Reset|QDialogButtonBox::Save);
        buttonBox->setCenterButtons(true);

        retranslateUi(Ivanov);

        QMetaObject::connectSlotsByName(Ivanov);
    } // setupUi

    void retranslateUi(QWidget *Ivanov)
    {
        Ivanov->setWindowTitle(QApplication::translate("Ivanov", "Form", nullptr));
        label->setText(QApplication::translate("Ivanov", "\320\244\320\276\321\202\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ivanov: public Ui_Ivanov {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IVANOV_H
