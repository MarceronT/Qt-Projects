#include "mainwindow.h"
#include "qstd.h"
using namespace qstd;
#include <QApplication>
#include "deevolutionaryprocess.h"
#include "deindividual.h"

void testIndividu() {
    cout<<"Test Individus :"<<endl;
    DeIndividual *di1 = new DeIndividual();
    di1->evaluate();
    cout<<di1->toString()<<endl;
    DeIndividual *di2 = new DeIndividual(di1);
    di2->evaluate();
    cout<<di2->toString()<<endl;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testIndividu();
//    DeEvolutionaryProcess evo;
//    evo.run();
//    MainWindow w;
//    w.show();
//    return a.exec();
}
