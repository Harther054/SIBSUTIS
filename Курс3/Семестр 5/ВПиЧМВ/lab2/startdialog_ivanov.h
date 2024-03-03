#ifndef STARTDIALOG_IVANOV_H
#define STARTDIALOG_IVANOV_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_ivanov.h"

class StartDialog_Ivanov : public QPushButton
{
    Q_OBJECT

public:
    StartDialog_Ivanov(QWidget* pwgt = nullptr) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()), SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
        InputDialog_Ivanov* pInputDialog = new InputDialog_Ivanov;
        if(pInputDialog->exec() == QDialog::Accepted)
        {
            QMessageBox::information(0, "Ваше Информация: ", "Имя: " + pInputDialog->firstName()+
                                     "\nФамилия: " + pInputDialog->lastName());
        }
        delete pInputDialog;
    }
};

#endif // STARTDIALOG_IVANOV_H
