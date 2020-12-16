#include "temps.h"
#include <QTextStream>

int Temps::getH() const
{
    return h;
}

void Temps::setH(int value)
{
    h = value;
}

int Temps::getM() const
{
    return m;
}

void Temps::setM(int value)
{
    m = value;
}

int Temps::getS() const
{
    return s;
}

void Temps::setS(int value)
{
    s = value;
}

QString Temps::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<h<<":"<<m<<":"<<s<<" ("<<totalSecondes()<<" s.)";
    return res;
}

Temps::Temps(int nh, int nm, int ns):h(nh),m(nm),s(ns)
{

}

int Temps::totalSecondes()
{
    return 3600*h+60*m+s;
}

void Temps::ajouteSecondes(int ns)
{
    s+=ns;
    if(s>=60) {
        int nm=s/60;
        s=s%60;
        m+=nm;
        if(m>=60) {
            int nh=m/60;
            m=m%60;
            h+=nh;
        }
    }
}
