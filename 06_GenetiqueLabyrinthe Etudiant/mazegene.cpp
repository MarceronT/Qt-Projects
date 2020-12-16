#include "mazegene.h"

#include "parameters.h"

MazeGene::MazeGene()
{
    direction = Maze::Direction(Parameters::randomGenerator->get(4));
}

MazeGene::MazeGene(MazeGene *mg)
{
    direction = mg->direction;
}

void MazeGene::mutate()
{
    direction = Maze::Direction(Parameters::randomGenerator->get(4));
}

QString MazeGene::toString()
{
    switch (direction) {
    case Maze::Bottom:
        return "B";
    case Maze::Left:
        return "L";
    case Maze::Top:
        return "T";
    default:
        return "R";
    }
}
