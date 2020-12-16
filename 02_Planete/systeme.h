#ifndef SYSTEME_H
#define SYSTEME_H
#include "planete.h"
#include <QString>
#include <QList>

class Systeme
{
private:
    QString m_nom;
    QList<Planete*> m_liste_Planetes;
public:
    Systeme(QString nom);
    void ajoutePlanete(Planete *p);
    int taille();
    Planete *getPlanete(int i);
    QString toString();
};

#endif // SYSTEME_H
