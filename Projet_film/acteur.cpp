#include "acteur.h"
#include <QTextStream>


QList<Role *> Acteur::getRoles() const
{
    return m_roles;
}

Acteur::Acteur(QString prenom, QString nom, int anneeNaissance, Genre sexe)
{
    m_prenom = prenom;
    m_nom = nom;
    m_anneeNaissance = anneeNaissance;
    m_sexe = sexe;
}

void Acteur::ajouteRole(Role *r)
{
    m_roles.append(r);
}

QString Acteur::toString()
{
    QString res;
    QTextStream buf(&res);
    QString titre=(m_sexe==Masculin)?"M.":"Mme";
    buf<<titre<<" "<<m_prenom<<" "<<m_nom<<" ("<<m_anneeNaissance<<")";
    return res;
}
