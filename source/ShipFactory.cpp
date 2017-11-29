#include "../header/ShipFactory.h"

ShipFactory::ShipFactory(){



}

ShipFactory::~ShipFactory(){
    
    }

static bool create(Point pstart, Point pend){

    bool creation=false;
    int lenght=0;

    if(abs(pstart.getX()-pend.getX())==0){
        lenght=abs(pstart.getY()-pend.getY())+1;
    }
    if(abs(pstart.getY()-pend.getY())==0){
        lenght=abs(pstart.getX()-pend.getX())+1;
    }

    Ship *ship;
    
    if(lenght==2){
        *ship = new Destroyer(pstart,pend);
        creation=true;
    }
    if(lenght==3){
        *ship = new Cruiser(pstart,pend);
        creation=true;
    }
    if(lenght==4){
        *ship = new Battleship(pstart,pend);
        creation=true;
    }
    if(lenght==5){
        *ship = new Carrier(pstart,pend);
        creation=true;
    }

    if(creation==true){
        fleet.Push_Back(*ship);
        vector<Point*>::iterator iter;
        for(iter=(*ship)->OccupiedPoints.begin ; iter!=(*ship)->OccupiedPoints.end; iter++){
            iter.setShippoint(true);
        }
    }

    return creation;

}