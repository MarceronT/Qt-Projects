#ifndef HUMAIN_H
#define HUMAIN_H
#include <QString>
#include "sexe.h"

class Humain
{
private:
    QString m_prenom;
    QString m_nom;
    Sexe m_sexe;
public:
    Humain(QString prenom,QString nom,Sexe sexe);
    QString toString();
};

#endif // HUMAIN_H
