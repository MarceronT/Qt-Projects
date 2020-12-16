#ifndef INDIVIDU_H
#define INDIVIDU_H
#include <QString>
class Individu
{
private:
QString nom;
int annee_naissance;
int qi;
public:
Individu(QString n, int a, int q);
QString toString();
static bool lessQiThan(Individu *i1, Individu *i2);
static bool youngerThan(Individu *i1, Individu *i2);
};
#endif // INDIVIDU_H
