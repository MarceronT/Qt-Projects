#include "signal.h"
#include <monlcdslider.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    signal w;
    w.show();
    return a.exec();
}
