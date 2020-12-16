#include "myrandom.h"
#include <QDateTime>

MyRandom::MyRandom(int seed)
{
    if (seed != -1)
        qsrand(seed);
    else
        qsrand(QTime::currentTime().msec());
}

int MyRandom::get(int max)
{
    return qrand()%max;
}

double MyRandom::getFloat()
{
    return (qrand()%1001)/1000.0;
}
