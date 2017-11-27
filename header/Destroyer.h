//nave da 2

#ifndef DESTROYER_H
#define DESTROYER_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Destroyer:private Ship{

private:

public:
    ~Destroyer();
    Destroyer(Point, Point);
    

};

#endif


