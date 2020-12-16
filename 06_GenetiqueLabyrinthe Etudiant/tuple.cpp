#include "tuple.h"
#include <QTextStream>

Tuple::Tuple(Case *_c1, Case *_c2):c1(_c1), c2(_c2)
{}

Tuple::Direction Tuple::direction(Tuple &tuple)
{
    if(tuple.c1->j == tuple.c2->j)
        return Direction::Verticale;
    else if(tuple.c1->i == tuple.c2->i)
        return Direction::Horizontale;
    else
        return Direction::AAARG;
}

QString Tuple::toString()
{
    QString res;
    res.sprintf("[%d, %d] -> [%d, %d]", c1->i, c1->j, c2->i, c2->j);
    return res;
}
