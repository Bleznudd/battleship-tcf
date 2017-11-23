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
    Point();
    ~Point();
    Point(int=0, int=0);
    Point(string);

};

#endif