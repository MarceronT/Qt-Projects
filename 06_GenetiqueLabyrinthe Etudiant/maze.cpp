#include "maze.h"
#include "parameters.h"
#include <cmath>
#include <QRegExp>
#include <QStringList>
#include <QDebug>
#include "mazeindividual.h"

QList<Tuple *> Maze::paths;
int Maze::nbcol=0;
int Maze::nblig=0;
Case *Maze::entrance, *Maze::exit;

QString Maze::Maze1=
        "*--*--*--*--*\n" \
        "E           |\n" \
        "*  *  *--*--*\n" \
        "|  |  |     |\n" \
        "*  *--*  *  *\n" \
        "|        |  |\n" \
        "*  *--*--*  *\n" \
        "|        |  S\n" \
        "*--*--*--*--*";
QString Maze::Maze2=
        "*--*--*--*--*--*--*\n" \
        "E        |  |     |\n" \
        "*--*--*  *  *  *--*\n" \
        "|     |     |     |\n" \
        "*  *  *  *  *  *  *\n" \
        "|  |  |  |     |  |\n" \
        "*--*  *  *--*--*  *\n" \
        "|     |  |     |  |\n" \
        "*  *--*--*  *  *  *\n" \
        "|  |        |  |  |\n" \
        "*  *  *  *--*  *  *\n" \
        "|     |     |     S\n" \
        "*--*--*--*--*--*--*";

bool Maze::isPossible(Case *pos1, Case *pos2)
{
    foreach (Tuple *t, paths) {
        if((Case::egale(pos1,t->c1) && Case::egale(pos2,t->c2)) ||
                (Case::egale(pos2,t->c1) && Case::egale(pos1,t->c2)))
            return true;
    }
    return false;
}

bool Maze::isJunction(Case *pos)
{
    int nbRoads=0;
    foreach (Tuple *t, paths) {
        if(Case::egale(t->c1,pos) || Case::egale(t->c2,pos))
            nbRoads++;
    }
    return nbRoads>2;
}

void Maze::tailleLabyrinthe()
{
    foreach (Tuple *t, Maze::paths) {
        //Parameters::print(t->toString(), 0);
        int col=int(fmax(t->c1->j, t->c2->j));
        int lig=int(fmax(t->c1->i, t->c2->i));
        if(col>=nbcol)  nbcol = col;
        if(lig>nblig)   nblig = lig;
    }
    nbcol++;
    nblig++;
}

void Maze::init(QString s)
{
    QRegExp tagExp("\n");
    QStringList lines=s.split(tagExp);
    int nbLines=0;
    foreach (QString line, lines) {
        if(nbLines%2) {
            // ligne impaire -> contenu couloir
            int index = line.indexOf("E");
            if(index!=-1) {
                if(index==line.count()-1)
                    index--;
                entrance=new Case(nbLines/2, index/3);
            }
            index = line.indexOf("S");
            if(index!=-1) {
                if(index==line.count()-1)
                    index--;
                exit=new Case(nbLines/2, index/3);
            }
            for(int column=0; column<line.count()/3; column++) {
                QString caseStr = line.mid(column*3, 3);
                if(!caseStr.contains("|") && !caseStr.contains("E") && !caseStr.contains("S")) {
                    paths.append(new Tuple(new Case(nbLines/2, column-1), new Case(nbLines/2, column)));
                }
            }
        }
        else {
            // ligne paire -> murs
            QRegExp tagLigne=QRegExp("\\*");
            QStringList cases = line.split(tagLigne);
            int column=0;
            foreach (QString mur, cases) {
                if(mur.length()==0)
                    continue;
                if(mur=="  ")
                    paths.append(new Tuple(new Case(nbLines/2-1, column), new Case(nbLines/2, column)));
                column++;
            }
        }
        nbLines++;
    }
    //Vérification de l'initialisation
    /*qDebug() <<"Entree : "<<entrance->toString()<<" ; Sortie : "<<exit->toString();
    qDebug() <<paths.size()<<QObject::tr(" tuples enregistrés :");
    foreach (Tuple *t, paths) {
        qDebug() <<"Peut aller de "<<t->toString();
    }*/
    tailleLabyrinthe();
    for(int l=0;l<nblig;l++) {
        for(int c=0;c<nbcol;c++) {
            Case *caseLC=new Case(l, c);
            /*if(isJunction(caseLC))
                qDebug() <<caseLC->toString()<<" est un carrefour";
            if(isPossible(caseLC, new Case(l-1,c)))
                qDebug() <<"Depuis "<<caseLC->toString()<<", on peut aller en haut.";
            if(isPossible(caseLC, new Case(l+1,c)))
                qDebug() <<"Depuis "<<caseLC->toString()<<", on peut aller en bas.";
            if(isPossible(caseLC, new Case(l,c-1)))
                qDebug() <<"Depuis "<<caseLC->toString()<<QObject::tr(", on peut aller à gauche.");
            if(isPossible(caseLC, new Case(l,c+1)))
                qDebug() <<"Depuis "<<caseLC->toString()<<QObject::tr(", on peut aller à droite.");
                */
        }
    }
}

double Maze::evaluate(MazeIndividual *individual)
{
    Case *currentPosition=new Case(entrance);
    bool end=false;
    for(int i=0;i<individual->getGenome().size();i++) {
        MazeGene g=individual->getGenome().at(i);
        switch (g.direction) {
        case Bottom:
            while(isPossible(currentPosition, new Case(currentPosition->i+1, currentPosition->j)) && !end) {
                currentPosition->i++;
                end=isJunction(currentPosition) || Case::egale(currentPosition, exit);
            }
            end=false;
            break;
        case Top:
            while(isPossible(currentPosition, new Case(currentPosition->i-1, currentPosition->j)) && !end) {
                currentPosition->i--;
                end=isJunction(currentPosition) || Case::egale(currentPosition, exit);
            }
            end=false;
            break;
        case Right:
            while(isPossible(currentPosition, new Case(currentPosition->i, currentPosition->j+1)) && !end) {
                currentPosition->j++;
                end=isJunction(currentPosition) || Case::egale(currentPosition, exit);
            }
            end=false;
            break;
        case Left:
            while(isPossible(currentPosition, new Case(currentPosition->i, currentPosition->j-1)) && !end) {
                currentPosition->j--;
                end=isJunction(currentPosition) || Case::egale(currentPosition, exit);
            }
            end=false;
            break;
        }
        if(Case::egale(currentPosition, exit))
            return 0;
    }
    int distance=abs(exit->i-currentPosition->i) + abs(exit->j-currentPosition->j);
    return distance;
}
