//implementazione di Ship.h

#include "../header/Ship.h"

#include <iostream>
using namespace std;

Ship::Ship(){

}
Ship::~Ship(){
    cout << " E Affondato!";
}
void Ship::setHit(Point &p){
    for(vector<Point*>::iterator iter=OccupiedPoints.begin(); iter!=OccupiedPoints.end(); iter++){
        if((**iter)==p){
            (*iter)->setHit(true);
        }
    }
}
bool Ship::checkSunk(){
    int nothit=0;
    for(vector<Point*>::iterator iter=OccupiedPoints.begin(); iter!=OccupiedPoints.end(); iter++){
        if((*iter)->getHit()==false){
            nothit++;
        }
    }
    if(nothit==0){
        sunk = true;
    }
    return sunk;
}

int Ship::getLenght(){
    return lenght;
}