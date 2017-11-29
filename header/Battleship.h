//nave da 4

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Ship.h"
using namespace std;

class Battleship:public Ship{

public:

    Battleship(Point, Point);
    friend class ShipFactory;
    
};

#endif
