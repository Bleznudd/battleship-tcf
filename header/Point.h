//classe punto

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point{

private:
    int x;
    int y;

public:

    Point(int=0, int=0);
    ~Point();
    Point(string);
    int getX();
    int getY();
    friend bool operator==(Point &p1, Point &p2);

};

#endif