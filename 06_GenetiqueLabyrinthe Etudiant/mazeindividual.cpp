#include "mazeindividual.h"
#include <QTextStream>
#include "parameters.h"

static QString txt;

double MazeIndividual::getFitness() const
{
    return fitness;
}

void MazeIndividual::mutate()
{
    // déclenche-t-on une suppression ?
    if(Parameters::randomGenerator->getFloat()<Parameters::mutationDeleteRate) {
        int geneIndex=Parameters::randomGenerator->get(genome.size());
        genome.removeAt(geneIndex);
    }
    // déclenche-t-on un ajout ?
    if(Parameters::randomGenerator->getFloat()<Parameters::mutationAddRate) {
        MazeGene *gadd=new MazeGene();
        genome.append(gadd);
    }
    // mutation aléatoire gène par gène
    for(int i=0;i<genome.size();i++) {
        if(Parameters::randomGenerator->getFloat()<Parameters::mutationRate) {
            MazeGene *g=genome.at(i);
            g->mutate();
        }
    }
}

double MazeIndividual::evaluate()
{
    fitness=Maze::evaluate(this);
    return fitness;
}

QList<MazeGene *> MazeIndividual::getGenome() const
{
    return genome;
}

QString MazeIndividual::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<fitness<<" : [";
    foreach (MazeGene *g, genome) {
        buf<<g->toString()<<", ";
    }
    buf<<"]";
    return res;
}

bool MazeIndividual::lessFitnessThan(MazeIndividual *m1, MazeIndividual *m2)
{
    return m1->getFitness() < m2->getFitness();
}

MazeIndividual::MazeIndividual()
{
    for(int i=0;i<Parameters::initialGenesNb;i++)
        genome.append(new MazeGene());
}

MazeIndividual::MazeIndividual(MazeIndividual *father)
{
    for(int i=0;i<father->getGenome().size();i++) {
        genome.append(new MazeGene(father->getGenome().at(i)));
    }
    mutate();
}

MazeIndividual::MazeIndividual(MazeIndividual *father, MazeIndividual *mother)
{
    int cuttingPoint=Parameters::randomGenerator->get(father->getGenome().size());
    // avant cuttingPoint, on prend les gènes du père
    for(int i=0;i<cuttingPoint;i++) {
        genome.append(new MazeGene(father->getGenome().at(i)));
    }
    // après, les gènes de la mère
    for(int i=cuttingPoint;i<mother->getGenome().size();i++) {
        genome.append(new MazeGene(mother->getGenome().at(i)));
    }
    mutate();
}
