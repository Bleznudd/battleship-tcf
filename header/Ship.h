//classe astratta ship

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Ship{

protected:
    int lenght=3;
    vector<Point*> blocks;

public:
    Ship();
    ~Ship();
    Ship(Point, Point);
    vector<Point*> getBlocks();
    

};

#endif

