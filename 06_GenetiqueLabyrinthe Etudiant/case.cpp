#include "case.h"

Case::Case(int _i, int _j)
{
    i = _i;
    j = _j;
}

Case::Case(const Case &c)
{
    i = c.i;
    j = c.j;
}

Case::Case(const Case *c)
{
    i = c->i;
    j = c->j;
}

bool Case::egale(const Case *c1, const Case *c2)
{
    if (c1->i == c2->i && c1->j == c2->j){
        return true;
    }
    else{
        return false;
    }
}

QString Case::toString()
{
    QString res;
    res.sprintf("[%d, %d]", i, j);
    return res;
}
