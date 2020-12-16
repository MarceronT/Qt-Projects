#ifndef MAZEINDIVIDUAL_H
#define MAZEINDIVIDUAL_H

#include "mazegene.h"
#include <QList>
#include <QString>

class MazeIndividual
{
private:
    double fitness=-1;
    QList<MazeGene *> genome;
public:
    MazeIndividual();
    MazeIndividual(MazeIndividual *father);
    MazeIndividual(MazeIndividual *father, MazeIndividual *mother);
    double getFitness() const;
    void mutate();
    double evaluate();
    QList<MazeGene *> getGenome() const;
    QString toString();
    static bool lessFitnessThan(MazeIndividual *m1, MazeIndividual *m2);
};

#endif // MAZEINDIVIDUAL_H
