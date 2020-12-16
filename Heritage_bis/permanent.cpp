#include "permanent.h"
#include<QTextStream>

Permanent::Permanent(QString p, QString n, Sexe s, double f):
    Humain(p,n,s),m_salaire_fixe(f)
{

}

double Permanent::salaire()
{
    return m_salaire_fixe;
}

QString Permanent::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<Humain::toString()<<" ("<<getClassName()<<") :"<<salaire();
    return res;
}

QString Permanent::getClassName()
{
    return "Permanent";
}
