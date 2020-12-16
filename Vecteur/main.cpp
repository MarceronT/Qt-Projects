#include "../shared/qstd.h"
using namespace qstd;
#include "vecteur3d.h"

int main()
{
    cout<<"Projet Vecteurs 3D"<<endl;
    Vecteur3D v1(5,4,3);
    cout<<"v1 = "<<v1.toString()<<endl;
    Vecteur3D v2(15,-4,5);
    cout<<"v2 = "<<v2.toString()<<endl;
    Vecteur3D v3=v1.ajoute(v2);
    cout<<"v3 = v1 + v2 = "<<v3.toString()<<endl;
    double ps=v1.produitScalaire(v2);
    cout<<"(produit scalaire): v1.v2 = "<<ps<<endl;
    Vecteur3D v4=v1.produitVectoriel(v2);
    cout<<"(produit vectoriel): v1*v2 = "<<v4.toString()<<endl;
}
