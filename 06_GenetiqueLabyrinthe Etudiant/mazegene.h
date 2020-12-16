#ifndef MAZEGENE_H
#define MAZEGENE_H

#include "maze.h"
#include <QString>

class MazeGene
{
public:
    Maze::Direction direction;
    MazeGene();
    MazeGene(MazeGene *mg);
    void mutate();
    QString toString();
};

#endif // MAZEGENE_H
