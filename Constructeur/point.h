#ifndef POINT_H
#define POINT_H


class Point
{
private:
    int m_x;
    int m_y;
public:
    Point(int x=0,int y=0);
    Point(Point& p);
    ~Point();
    bool coincide(Point& p);
};

#endif // POINT_H
