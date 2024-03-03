#ifndef INPUTDIALOG_IVANOV_H
#define INPUTDIALOG_IVANOV_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_Ivanov : public QDialog
{
    Q_OBJECT
private:
        QLineEdit * m_ptxtFirstName;
        QLineEdit * m_ptxtLastName;
public:
    InputDialog_Ivanov(QWidget *pwgt = nullptr);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_IVANOV_H
