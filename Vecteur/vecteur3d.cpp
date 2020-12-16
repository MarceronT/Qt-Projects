#include "vecteur3d.h"
#include <QTextStream>

Vecteur3D::Vecteur3D(double x, double y, double z)
{
    m_v[0] = x;
    m_v[1] = y;
    m_v[2] = z;
}

Vecteur3D::Vecteur3D(double v[])
{
    m_v[0]= v[0];
    m_v[1]= v[1];
    m_v[2]= v[2];
}

Vecteur3D Vecteur3D::ajoute(const Vecteur3D &v) const
{
    double t_local[3];
    int i;
    for (i=0;i<3;i++){
        t_local[i]=m_v[i]+v.m_v[i];
    }
    return Vecteur3D(t_local[0],t_local[1],t_local[2]);
}

Vecteur3D Vecteur3D::produitVectoriel(Vecteur3D &v) const
{
    double t_local[3];
    t_local[0]=m_v[1]*v.m_v[2] - m_v[2]*v.m_v[1];
    t_local[1]=m_v[2]*v.m_v[0] - m_v[0]*v.m_v[2];
    t_local[2]=m_v[0]*v.m_v[1] - m_v[1]*v.m_v[0];
    return Vecteur3D(t_local[0],t_local[1],t_local[2]);
}

double Vecteur3D::produitScalaire(Vecteur3D &v) const
{
    double scalaire=0;
    int i;
    for (i=0;i<3;i++){
        scalaire = scalaire+m_v[i]*v.m_v[i];
    }
    return scalaire;
}

QString Vecteur3D::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"["<<m_v[0]<<", "<<m_v[1]<<", "<<m_v[2]<<"]"<<endl;
    return res;
}
