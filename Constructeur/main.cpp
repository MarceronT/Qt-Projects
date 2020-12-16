#include "../shared/qstd.h"
using namespace qstd;
#include "point.h"

int main()
{
    cout<<"Projet Constructeurs"<<endl;
    Point p1(10,10);
    Point p2;
    Point p3(10,10);
    cout<<"Entre p1 et p2 : "<<p1.coincide(p2)<<endl;
    cout<<"Entre p1 et p3 : "<<p1.coincide(p3)<<endl;
}
