#include "../shared/qstd.h"
using namespace qstd;
#include "systeme.h"

int main()
{
    Planete systemeSolaire[8]=
    {
        Planete ("Mercure",4878,57.9),
        Planete ("Venus",12104,108.2),
        Planete ("Terre",12756,149.6),
        Planete ("Mars",6787,227.9),
        Planete ("Jupiter",142754,778.3),
        Planete ("Saturne",120057,1427),
        Planete ("Uranus",51177,2869.6),
        Planete ("Neptune",49520,4496.6)
    };
    Systeme sol("Solaire");
    for(int i=0;i<8;i++)
        sol.ajoutePlanete(&systemeSolaire[i]);
    cout<<sol.toString()<<endl;

    // récupération d'une planète :
    cout<<"Entrer un indice : "<<endl;
    int indice;
    cin>>indice;
    Planete *p=sol.getPlanete(indice);
    if(p!=nullptr){
        cout<<p->toString()<<endl;
    }
    else {
       cerr<<"La planete "<<indice<<" n'existe pas !"<<endl;
    }
}
