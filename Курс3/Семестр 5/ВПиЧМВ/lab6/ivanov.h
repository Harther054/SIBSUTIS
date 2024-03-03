#ifndef IVANOV_H
#define IVANOV_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class Ivanov;
}

class Ivanov : public QWidget
{
    Q_OBJECT

public slots:
    void recieveData(QString str);

public:
    explicit Ivanov(QWidget *parent = 0);
    ~Ivanov();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Ivanov *ui;
};

#endif // IVANOV_H
