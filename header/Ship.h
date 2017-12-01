//classe astratta ship

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Ship{

friend class ShipFactory;

protected:

    int lenght;
    bool sunk=false;
    vector<Point*> OccupiedPoints;

public:
    
    Ship();
    ~Ship();
    void setHit(Point&);
    bool checkSunk();

};

#endif