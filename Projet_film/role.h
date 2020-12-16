#ifndef ROLE_H
#define ROLE_H
#include <QString>

class Acteur;
class Film;
class Role
{
private:
    Acteur* pActeur;
    Film* pFilm;
    QString m_role;

public:
    Role(Acteur* acteur,Film* film,QString role);
    QString toString();
};

#endif // ROLE_H
