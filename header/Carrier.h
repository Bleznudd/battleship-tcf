//nave da 5

#ifndef CARRIER_H
#define CARRIER_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Ship.h"
using namespace std;

class Carrier:public Ship{

public:

    Carrier(Point, Point);
    friend class ShipFactory;

};

#endif
