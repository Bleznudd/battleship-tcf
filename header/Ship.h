//classe astratta ship

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include "Point.h"
using namespace std;

class Ship{

private:
    int lenght;
    Point start;
    Point end;

public:
    Ship();
    ~Ship();
    Ship(Point, Point);
    

};

#endif

