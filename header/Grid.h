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
    int shipNum;
    vector<Ship*> fleet;
    vector<vector<string>> map = vector<vector<string>>(size, vector<string>(size));

public:
    Grid(int=10);
    ~Grid();
    int getShipNum();
    void subtractShipNum();
    void Draw();
    void DrawShips();
    void Check(Point);
    void Deploy(Ship);

};

#endif