//classe astratta ship

#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Ship{

private:

    int lenght;
    vector<Point*> OccupiedPoints;

public:
    
    Ship();
    ~Ship();
    friend class ShipFactory;

};

#endif

