#include "role.h"
#include <QTextStream>

#include "acteur.h"
#include "film.h"

Role::Role(Acteur *acteur, Film *film, QString role)
{
    pActeur = acteur;
    pFilm = film;
    m_role = role;
    pActeur->ajouteRole(this);
    pFilm->ajouteRole(this);
}

QString Role::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<pActeur->toString()<<" joue dans "<<pFilm->toString()<<" dans le role de "<<m_role<<endl;
    return res;
}
