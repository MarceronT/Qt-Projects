#include "deindividual.h"
#include "parameters.h"
#include <QTextStream>
#include <QDebug>

int DeIndividual::getFitness() const
{
    return m_fitness;
}

void DeIndividual::setFitness(int fitness)
{
    m_fitness = fitness;
}

DeIndividual::DeIndividual()
{
    for(int i=0;i<Parameters::nbDes;i++){
        int v=Parameters::randomGenerator->get(6)+1;
        m_genome.append(new DeGene(v));
    }
}

DeIndividual::DeIndividual(DeIndividual *father)
{
    foreach (DeGene *dg, father->m_genome) {
        m_genome.append(dg);
    }
    mutate();
}

void DeIndividual::mutate()
{
    int nbGenesModifier = Parameters::randomGenerator->get(Parameters::nbDes);
    for (int i=0;i<nbGenesModifier;i++){
        if(Parameters::randomGenerator->getFloat()<Parameters::mutationRate){
          int indice = Parameters::randomGenerator->get(m_genome.size());
          int v = Parameters::randomGenerator->get(6)+1;
          qDebug()<<"On change l'indice "<<indice<< " a "<<v;
          m_genome.at(indice)->setValeur(v);
        }
    }
}

QString DeIndividual::toString()
{
    QString res;
    QTextStream buf(&res);
    buf<<m_fitness<<" : [";
    foreach (DeGene *dg, m_genome){
        buf<<dg->getValeur()<<" ";
    }
    buf<<"] ";
    return res;
}

int DeIndividual::evaluate()
{
    m_fitness =0;
    foreach (DeGene *dg, m_genome){
        m_fitness += dg->getValeur();
    }
    return m_fitness;
}

bool DeIndividual::lessFitnessThan(DeIndividual *di1, DeIndividual *di2)
{
    return di1->getFitness()<di2->getFitness();
}


