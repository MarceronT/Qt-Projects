#ifndef CASE_H
#define CASE_H

#include <QString>

class Case
{
public:
    int i, j; // création des variables pour des coordonnées
    Case(int _i=0, int _j=0); // constructeur prenant en paramètre les coordonnées
    Case(const Case &c);
    Case(const Case *c);
    static bool egale(const Case *c1, const Case *c2);
    QString toString();
};

#endif // CASE_H
