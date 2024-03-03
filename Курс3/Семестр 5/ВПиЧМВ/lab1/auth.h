#ifndef AUTH_H
#define AUTH_H

#include <QWidget>

namespace Ui {
class auth;
}

class auth : public QWidget
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = 0);
    ~auth();

private:
    Ui::auth *ui;
};

#endif // AUTH_H
