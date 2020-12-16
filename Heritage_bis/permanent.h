#ifndef PERMANENT_H
#define PERMANENT_H
#include "humain.h"

class Permanent : public Humain
{
private:
    double m_salaire_fixe;
public:
    Permanent(QString p,QString n, Sexe s, double f);
    double salaire();
    QString toString();
    QString getClassName();
};

#endif // PERMANENT_H
