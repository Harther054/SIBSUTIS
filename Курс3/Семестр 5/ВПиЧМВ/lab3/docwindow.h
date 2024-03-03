#ifndef DOCWINDOW_H
#define DOCWINDOW_H

#include <QTextEdit>
#include <QFileDialog>
#include <QTextStream>
#include <QColorDialog>
#include <QtWidgets>

class DocWindow: public QTextEdit
{
    Q_OBJECT
private:
    QString m_strFileName;

public:
    DocWindow(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotSave();
    void slotLoad();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_H
