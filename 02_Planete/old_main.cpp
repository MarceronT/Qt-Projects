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
    // affichage
    for (int i=0;i<8;i++)
        cout<<systemeSolaire[i].toString()<<endl;
// cherche la planète la plus éloignée
   /* Planete *laPlusLoin=systemeSolaire; // on stocke dans laPlusLoin le num du tableau c.a.d le pointeur du 1er element
    for(int i=1;i<8;i++){
    //si la distance de la planete i est supérieure
        if(systemeSolaire[i].getDistance() > laPlusLoin->getDistance())
    // on modifie le pointeur laPlusLoin
        laPlusLoin=systemeSolaire+i; // ou laPlusLoin = &système[i]
    }
cout<<"La plus éloignee est "<<laPlusLoin->toString()<<endl;*/
// cherche la planète la plus éloignée V2
    Planete &laPlusLoin = systemeSolaire[0];
    for(int i =1;i<8;i++){
        if(systemeSolaire[i].getDistance() > laPlusLoin.getDistance())
            laPlusLoin= systemeSolaire[i];
    }
cout<<"La plus éloignee est "<<laPlusLoin.toString()<<endl;
}
