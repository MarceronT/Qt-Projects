#include "../shared/qstd.h"
using namespace qstd;
#include "complexe.h"

int main()
{
cout<<"Projet Nombres Complexes"<<endl;
complexe Z1(0.5,0.7);
cout<<"Z1 = "<<Z1.toString()<<endl;
complexe Z2(-0.2,0.1);
cout<<"Z2 = "<<Z2.toString()<<endl;
complexe Z3=Z1.carre();
cout<<"Z3 = Z1^2 = "<<Z3.toString()<<endl;
complexe Z4=Z3.ajoute(Z2);
cout<<"Z4 = Z3 + Z2 = "<<Z4.toString()<<endl;
double m=Z4.module();
cout<<"Module de Z4 = "<<m<<" -> diverge ? "<<(Z4.diverge()?"Oui":"Non")<<endl;
}
