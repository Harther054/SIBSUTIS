#include "mainwindow.h"
#include "startdialog_ivanov.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Ivanov startDialog;
    startDialog.show();

    return a.exec();
}
