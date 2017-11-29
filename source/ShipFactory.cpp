#include "../header/ShipFactory.h"

ShipFactory::ShipFactory(){

}
ShipFactory::~ShipFactory(){
    
}
static bool create(Point pstart, Point pend, Player* currentp){

    bool creation=false;
    int len=0;

    if(abs(pstart.getX()-pend.getX())==0){
        len=abs(pstart.getY()-pend.getY())+1;
    }
    if(abs(pstart.getY()-pend.getY())==0){
        len=abs(pstart.getX()-pend.getX())+1;
    }

    Ship *ship;
    
    switch(len){
        case 2:
            ship = new Destroyer(pstart,pend);
            creation=true;
        break;
        case 3:
            ship = new Cruiser(pstart,pend);
            creation=true;
        break;
        case 4:
            ship = new Battleship(pstart,pend);
            creation=true;
        break;
        case 5:
            ship = new Carrier(pstart,pend);
            creation=true;
        break;
        default:

        break;
    }
    if(creation==true){ 
        currentp->fleet.push_back(ship);
        vector<Point*>::iterator iter;
        for(iter=ship->OccupiedPoints.begin() ; iter!=ship->OccupiedPoints.end(); iter++){
            (*iter)->setShippoint(true); //non va bene perchè i punti non fanno parte della griglia
        }
    }
    return creation;
}