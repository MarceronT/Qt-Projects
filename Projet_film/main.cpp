#include "../shared/qstd.h"
using namespace qstd;
#include "acteur.h"
#include "film.h"
#include "role.h"


int main()
{
    QList<Acteur *> acteurs;

        acteurs.append(new Acteur("Jodie","Foster",1962,Feminin));

        acteurs.append(new Acteur("Bruce","Willis",1955,Masculin));

        acteurs.append(new Acteur("Milla","Jovovich",1975,Feminin));



        QList<Film *> films;

        films.append(new Film("Contact",1997));

        films.append(new Film("Le cinquieme element",1997));

        films.append(new Film("L'armee des 12 singes",1995));



        QList<Role *> role;

        role.append(new Role(acteurs.at(0),films.at(0),"Arroway"));

        role.append(new Role(acteurs.at(1),films.at(1),"Karben Dallas"));

        role.append(new Role(acteurs.at(1),films.at(2),"James Cole"));

        role.append(new Role(acteurs.at(2),films.at(0),"Clown"));

        foreach(Role *r, role){

            cout<<r->toString()<<endl;

        }
}
