#include "mainwindow.h"

#include <qapplication>

int main(int argc, char *argv[])
{
    qapplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}
