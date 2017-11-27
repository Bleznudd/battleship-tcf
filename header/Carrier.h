//nave da 5

#ifndef CARRIER_H
#define CARRIER_H

#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

class Carrier:private Ship{

private:

public:
    ~Carrier();
    Carrier(Point, Point);
    

};

#endif
