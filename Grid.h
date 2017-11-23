//scacchiera

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Ship.h"
using namespace std;

class Grid{

private:
    int size;
    int shipNum;
    vector<Ship*> fleet;
    Point *map = new Point[size][size];

public:
    Grid(int=10);
    ~Grid();
    int getShipNum();
    //MOD +
    void subtractShipNum();
    //
    void Draw();
    void DrawShips();
    void Check(Point);
    void Deploy(Ship);





};

#endif GRID_H