#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ivanov.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void sendData(QString str);

private slots:
    void onButtonSend();
    void on_pushButton_clicked();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Ivanov *MyForm;

};

#endif // MAINWINDOW_H
