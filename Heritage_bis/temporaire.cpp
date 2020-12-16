#include "temporaire.h"
#include<QTextStream>

Temporaire::Temporaire(QString p, QString n, Sexe s, double tx, double nb):
    Humain(p,n,s),m_tx_hor(tx),m_nb_heure(nb)
{

}

double Temporaire::salaire()
{
    return m_tx_hor * m_nb_heure;
}

QString Temporaire::getClassName()
{
    return "Temporaire";
}

QString Temporaire::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<Humain::toString()<<" ("<<getClassName()<<") :"<<salaire();
    return res;
}
