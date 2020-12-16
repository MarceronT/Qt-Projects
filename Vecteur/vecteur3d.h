#ifndef VECTEUR3D_H
#define VECTEUR3D_H
#include <QString>

class Vecteur3D
{
private:
    double m_v[3];
public:
    Vecteur3D(double x=0,double y=0,double z=0);
    Vecteur3D(double v[3]);
    Vecteur3D ajoute(const Vecteur3D& v) const;
    Vecteur3D produitVectoriel(Vecteur3D& v) const;
    double produitScalaire(Vecteur3D& v) const;
    QString toString();
};

#endif // VECTEUR3D_H
