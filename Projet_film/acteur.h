#ifndef ACTEUR_H
#define ACTEUR_H
#include <QString>
#include "Genre.h"
#include <QList>

class Role;
class Acteur
{
private:
    QString m_prenom;
    QString m_nom;
    int m_anneeNaissance;
    Genre m_sexe;
    QList<Role *> m_roles ;

public:
    Acteur(QString prenom,QString nom,int anneeNaissance,Genre sexe);
    void ajouteRole(Role *r);
    QString toString();
    QList<Role *> getRoles() const;
};

#endif // ACTEUR_H
