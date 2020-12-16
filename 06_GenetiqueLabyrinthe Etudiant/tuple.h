#ifndef TUPLE_H
#define TUPLE_H

#include <QString>
#include "case.h"

class Tuple
{
public:
    Case *c1, *c2;
    Tuple(Case *_c1, Case *_c2);
    enum Direction {Horizontale, Verticale, AAARG};
    static Direction direction(Tuple &tuple);
    QString toString();
};

#endif // TUPLE_H
