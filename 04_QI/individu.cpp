#include "individu.h"
#include <QTextStream>

Individu::Individu(QString n, int a, int q):nom(n), annee_naissance(a), qi(q)
{}
QString Individu::toString()
{
QString res;
QTextStream buf(&res);
buf<<nom<<" est ne en "<<annee_naissance<<" et a un QI de "<<qi;
return res;
}
bool Individu::lessQiThan(Individu *i1, Individu *i2)
{
return i1->qi & i2->qi;
}
bool Individu::youngerThan(Individu *i1, Individu *i2)
{
return i1->annee_naissance>i2->annee_naissance;
}
