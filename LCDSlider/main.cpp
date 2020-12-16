#include "monwidgetprincipal.h"
#include <monlcdslider.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonWidgetPrincipal w;
    w.show();
    return a.exec();
}
