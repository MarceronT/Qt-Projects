#include "complexe.h"
#include <QTextStream>
#include "cmath"

complexe::complexe(double r, double i)
{
    m_reel = r;
    m_imaginaire = i;
}

complexe complexe::carre() const
{
    double r =m_reel*m_reel - m_imaginaire*m_imaginaire;
    double i = 2*m_reel*m_imaginaire;
    return complexe(r,i);
}

QString complexe::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<m_reel<<" + i * "<<m_imaginaire;
    return res;
}

complexe complexe::ajoute(const complexe &z) const
{
    double r =m_reel + z.m_reel;
    double i =m_imaginaire + z.m_imaginaire;
    return complexe(r, i);
}

double complexe::module() const
{
    return sqrt(m_reel*m_reel + m_imaginaire*m_imaginaire);
}

bool complexe::diverge() const
{
    if(module()>2)
        return true;
    else
        return false;
}



