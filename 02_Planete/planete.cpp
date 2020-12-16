#include "planete.h"
#include <QTextStream>
#include <cmath>

double Planete::getDistance() const
{
    return m_distance;
}

Planete::Planete(QString nom, int diametre, double distance):
    m_nom(nom), m_diametre(diametre),m_distance(distance)
{

}

QString Planete::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<"Planete "<<m_nom<<" ; diam="<<m_diametre<<" ; distance="<<m_distance<<" km ; ";
    buf<<"Distance au soleil="<<m_distance<<" millions de km";
    return res;
}

double Planete::distanceEntre(const Planete &p) const
{
    return fabs(p.m_distance - m_distance);
}
