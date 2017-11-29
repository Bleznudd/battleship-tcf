//nave da 2

#ifndef DESTROYER_H
#define DESTROYER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Ship.h"
using namespace std;

class Destroyer:private Ship{

public:

    Destroyer(Point, Point);
    friend class ShipFactory;

};

#endif
