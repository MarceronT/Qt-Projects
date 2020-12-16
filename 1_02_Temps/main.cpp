#include "../shared/qstd.h"
using namespace qstd;
#include "temps.h"

int main()
{
    cout<<"Projet Temps :"<<endl;
    Temps t(23,50,10);
    cout<<t.toString()<<endl;
    cout<<"On ajoute 900 secondes..."<<endl;
    t.ajouteSecondes(900);
    cout<<t.toString()<<endl;
}
