#include "point.h"
#include "../shared/qstd.h"
using namespace qstd;

Point::Point(int x, int y):
    m_x(x),m_y(y)
{
    cout<<"Constructeurs Point(int, int) appele"<<endl;

}

Point::Point(Point &p):
    m_x(p.m_x),m_y(p.m_y)
{
    cout<<"Constructeurs Point(Point&) appele"<<endl;
}

Point::~Point()
{
    cout<<"Destructeur appele"<<endl;
}

bool Point::coincide(Point &p)
{
    if (m_x==p.m_x && m_y==p.m_y)
        return true;
    else
        return false;
}
