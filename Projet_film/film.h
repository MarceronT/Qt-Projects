#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QList>

class Role;
class Film
{
private:
    QString m_titre;
    int m_annee;
    QList<Role *> m_roles ;

public:
    Film(QString titre,int annee);
    void ajouteRole(Role *r);
    QString toString();
    QList<Role *> getRoles() const;
};

#endif // FILM_H
