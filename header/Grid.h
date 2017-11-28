//scacchiera

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Point.h"
#include "Ship.h"
using namespace std;

class Grid{

private:
    int size=10;

public:

    Grid(int=10);
    ~Grid();

};

#endif