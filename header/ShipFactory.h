//factory delle navi

#ifndef SHIPFACT_H
#define SHIPFACT_H

#include <iostream>
#include "Destroyer.h"
#include "Cruiser.h"
#include "Carrier.h"
#include "Battleship.h"
#include "Ship.h"
#include "Player.h"

using namespace std;

class ShipFactory{

private:

    static int destroyerCounter;
    static int cruiserCounter;
    static int battleshipCounter;
    static int carrierCounter;

public:

    ShipFactory();
    ~ShipFactory();
    static bool create(Point, Point, Player*);
    static void restartCounters();
    static void deleteShip(Ship*);

};

#endif
