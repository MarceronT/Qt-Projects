#include "systeme.h"
#include<QTextStream>

Systeme::Systeme(QString nom) : m_nom(nom)
{

}

void Systeme::ajoutePlanete(Planete *p)
{
    m_liste_Planetes.append(p);
}

int Systeme::taille()
{
    return m_liste_Planetes.size();
}

Planete *Systeme::getPlanete(int i)
{
    if(i<taille()) {
        return m_liste_Planetes.at(i);
    }
    else {
        return nullptr;
    }
}

QString Systeme::toString()
{
    QString res;
    QTextStream buf(&res);
    buf << "Systeme" <<m_nom<<" ("<<taille()<<" planetes) :";
    foreach (Planete *p, m_liste_Planetes) {
        buf<<endl<<p->toString();
    }
    return res;
}
