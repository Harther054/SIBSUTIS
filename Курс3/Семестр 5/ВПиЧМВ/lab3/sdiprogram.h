#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QWidget>
#include <QStatusBar>
#include "docwindow.h"
#include "sdiprogram.h"


namespace Ui {
class SDIProgram;
}

class SDIProgram : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram(QWidget *pwgt = 0) : QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu ("&File");
        QMenu* pmnuHelp = new QMenu ("&Help");
        DocWindow* pdoc = new DocWindow;

        pmnuFile->addAction("&Open...", pdoc, SLOT(slotLoad()), QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save", pdoc, SLOT(slotSave()), QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save", pdoc, SLOT(slotSaveAs()), QKeySequence("CTRL+SHIFT+S"));
        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()));
        pmnuFile->addSeparator();
        pmnuFile->addAction("&Quit", qApp, SLOT(quit()), QKeySequence("CTRL+Q"));
        pmnuHelp->addAction("&About", this, SLOT(slotAbout()), Qt::Key_F1);


        menuBar()->addMenu((pmnuFile));
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)), SLOT(slotChangeWindowTitle(const QString&)));

        statusBar()->showMessage("Ready", 2000);
    }
    ~SDIProgram();
public slots:
     void slotAbout()
     {
        QMessageBox::about(this, "Автор", "IP-114 | Иванов");
     }
     void slotChangeWindowTitle(const QString& str)
     {
        setWindowTitle(str);
     }
private:
    Ui::SDIProgram *ui;
};

#endif // SDIPROGRAM_H
