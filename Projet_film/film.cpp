#include "film.h"
#include <QTextStream>

QList<Role *> Film::getRoles() const
{
    return m_roles;
}

Film::Film(QString titre, int annee)
{
    m_titre = titre;
    m_annee = annee;
}

void Film::ajouteRole(Role *r)
{
    m_roles.append(r);
}

QString Film::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<" "<<m_titre<<" ("<<m_annee<<")";
    return res;
}
