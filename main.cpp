#include "plateau.h"

#include <QApplication>
#include <QtGui>
#include <ctime>
#include <cstdlib>


int main(int argc, char *argv[])
{
    srand(time(0));
    QApplication a(argc, argv);
    //app.setWindowIcon(QIcon(":/status/mine"));
    Plateau fenetre;
    fenetre.show();

    return a.exec();
}
