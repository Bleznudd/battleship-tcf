//nave da 3

#ifndef CRUISER_H
#define CRUISER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Ship.h"
using namespace std;

class Cruiser:private Ship{

public:

    Cruiser(Point, Point);
    friend class ShipFactory;

};

#endif
