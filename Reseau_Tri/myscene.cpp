#include "myscene.h"
#include "mainwindow.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    QPen black;
    black.setColor(Qt::black);
    black.setWidth(3);

    //Première ligne
    addLine(-200, 0, -50, 0,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

    addLine(-200, 100, 50, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

    addLine(-200, 200, -50, 200, ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

    addLine(-200, 300, 50, 300, ChangeColor(MainWindow::listeNombreNonTrie.value(3)));


    if(MainWindow::listeNombreNonTrie.value(0) > MainWindow::listeNombreNonTrie.value(2))

    {

        addLine(-50, 0, -50, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

        addLine(-50, 200, 200, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

        addLine(-53, 0, -53, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        addLine(-50, 0, 200, 0,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        MainWindow::listeNombreNonTrie.swap(0,2);

    }


    else

    {

        addLine(-50, 0, -50, 200,black);

        addLine(-50, 0, 200, 0,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

        addLine(-50, 200, 200, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

    }


    if(MainWindow::listeNombreNonTrie.value(1) > MainWindow::listeNombreNonTrie.value(3))

    {

        addLine(50, 100, 50, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(50, 300, 200, 300, ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(53, 100, 53, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        addLine(50, 100, 200, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        MainWindow::listeNombreNonTrie.swap(1,3);

    }


    else

    {

        addLine(50, 100, 50, 300,black);

        addLine(50, 300, 200, 300, ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        addLine(50, 100, 200, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

    }


    if(MainWindow::listeNombreNonTrie.value(0) > MainWindow::listeNombreNonTrie.value(1))

    {

        addLine(200, 0, 200, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

        addLine(200, 100, 300, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

        addLine(197, 0, 197, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(200, 0, 350, 0,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        MainWindow::listeNombreNonTrie.swap(0,1);

    }


    else

    {

        addLine(200, 0, 200, 100,black);

        addLine(200, 100, 300, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(200, 0, 350, 0,ChangeColor(MainWindow::listeNombreNonTrie.value(0)));

    }


    if(MainWindow::listeNombreNonTrie.value(2) > MainWindow::listeNombreNonTrie.value(3))

    {

        addLine(200, 200, 200, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        addLine(200, 300, 350, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        addLine(197, 200, 197, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        addLine(200, 200, 300, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        MainWindow::listeNombreNonTrie.swap(2,3);

    }

    else

    {

        addLine(200, 200, 200, 300,black);

        addLine(200, 300, 350, 300,ChangeColor(MainWindow::listeNombreNonTrie.value(3)));

        addLine(200, 200, 300, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

    }


    if(MainWindow::listeNombreNonTrie.value(1) > MainWindow::listeNombreNonTrie.value(2))

    {

        addLine(300, 100, 300, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(300, 200, 350, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

        addLine(297, 100, 297, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        addLine(300, 100, 350, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        MainWindow::listeNombreNonTrie.swap(1,2);

    }


    else

    {

        addLine(300, 100, 300, 200,black);

        addLine(300, 200, 350, 200,ChangeColor(MainWindow::listeNombreNonTrie.value(2)));

        addLine(300, 100, 350, 100,ChangeColor(MainWindow::listeNombreNonTrie.value(1)));

    }


    addRect(-56,-6,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(-56,194,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(46,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(46,296,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));


    addRect(194,-4,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,196,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,296,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(294,196,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(294,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));
}

QPen MyScene::ChangeColor(int value)
{
    QPen pen;
    pen.setWidth(3);

    if (value == 1)
        pen.setColor(Qt::red);

    if (value == 2)
        pen.setColor(Qt::green);

    if (value == 3)
        pen.setColor(Qt::blue);

    if (value == 4)
        pen.setColor(Qt::yellow);

    return pen;
}
