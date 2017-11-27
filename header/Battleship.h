//nave da 4

#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Battleship:private Ship{

private:

public:
    ~Battleship();
    Battleship(Point, Point);
    

};

#endif
