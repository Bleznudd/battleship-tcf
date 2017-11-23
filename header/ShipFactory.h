//factory delle navi

#ifndef SHIPFACT_H
#define SHIPFACT_H

#include <iostream>
#include "Ship.h"

using namespace std;

class ShipFactory{

private:
    
public:

    ShipFactory();
    ~ShipFactory();
    static Ship create(Point, Point);

};

#endif