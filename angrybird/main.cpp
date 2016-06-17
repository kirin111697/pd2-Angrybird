#include "mainwindow.h"
#include "checkpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    checkPage c;
    c.show();

    return a.exec();
}
