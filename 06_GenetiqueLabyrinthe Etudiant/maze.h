#ifndef MAZE_H
#define MAZE_H

#include <QList>
#include "tuple.h"
#include <QString>

class MazeIndividual;

class Maze
{
private:
    static bool isPossible(Case *pos1, Case *pos2);
    static bool isJunction(Case *pos);
public:
    static QList<Tuple *> paths;
    static int nbcol, nblig;
    static Case *entrance, *exit;
    static QString Maze1, Maze2;
    enum Direction {Top, Bottom, Left, Right};
    static void tailleLabyrinthe();
    static void init(QString s);
    static double evaluate(MazeIndividual *individual);
};

#endif // MAZE_H
