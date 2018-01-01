//nave da 3

#ifndef CRUISER_H
#define CRUISER_H

#include "Point.h"
#include "Ship.h"
using namespace std;

class Cruiser:public Ship{

public:

    Cruiser(Point, Point);
    friend class ShipFactory;

};

#endif