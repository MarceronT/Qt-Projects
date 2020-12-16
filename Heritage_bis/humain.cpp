#include "humain.h"
#include "sexe.h"
#include<QTextStream>

Humain::Humain(QString prenom, QString nom, Sexe sexe):m_prenom(prenom),m_nom(nom),m_sexe(sexe)
{

}

QString Humain::toString()
{
    QString res;
    QTextStream buf(&res);
    QString titre=(m_sexe==Masculin)?"M.":"Mme";
    buf<<titre<<" "<<m_prenom<<" "<<m_nom;
    return res;
}
