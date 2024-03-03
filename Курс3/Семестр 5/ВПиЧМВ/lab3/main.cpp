#include "sdiprogram.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTime>

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();
    for(int i = 0; i < 100;)
    {
        if(time.elapsed() > 40)
        {
            time.start();
            ++i;
        }
    psplash->showMessage("Loading modules: " +
                         QString::number(i)+"%",
                         Qt::AlignCenter|Qt::AlignCenter,
                         Qt::black);
    qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("bakcground.png"));
    splash.show();
    SDIProgram w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();
}
