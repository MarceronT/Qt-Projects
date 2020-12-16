#include "../shared/qstd.h"
using namespace qstd;
#include <QList>
#include "individu.h"
QList<Individu *> liste;
void init() {
liste.append(new Individu("Einstein", 1879, 150));
liste.append(new Individu("Everett", 1930, 147));
liste.append(new Individu("Pauli", 1900, 145));
liste.append(new Individu("Bohr", 1885, 140));
}
void affiche() {
foreach (Individu *i, liste) {
cout<<i->toString()<<endl;
}
}
int main()
{
cout<<"Initialisation"<<endl;
init();
cout<<endl<<"Affichage :"<<endl;
affiche();
cout<<endl<<"Tri par QI croissant :"<<endl;
std::sort(liste.begin(), liste.end(), Individu::lessQiThan);
affiche();
cout<<endl<<"Tri par age croissant :"<<endl;
std::sort(liste.begin(), liste.end(), Individu::youngerThan);
affiche();
}
