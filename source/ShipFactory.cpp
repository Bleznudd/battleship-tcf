#include "../header/ShipFactory.h"
#include "../header/Graphic.h"
#include <algorithm>       //per std::swap in ShipFactory::create()

using graphic::up;

ShipFactory::ShipFactory(){

}
ShipFactory::~ShipFactory(){
    
}
bool ShipFactory::create(Point pstart, Point pend, Player* currentp){

    bool creation=false;
    int len=0;
    Point tmp;

    if(pstart.getX()-pend.getX()==0){
        len=abs(pstart.getY()-pend.getY())+1;
        if((pstart.getY()-pend.getY())>0){
            swap(pstart, pend);
        }
    }
    if(pstart.getY()-pend.getY()==0){
        len=abs(pstart.getX()-pend.getX())+1;
        if((pstart.getX()-pend.getX())>0){
            swap(pstart, pend);
        }
    }

    Ship *ship;
    
    switch(len){
        case 2:
            if(currentp->shipnum[1]>0){
                currentp->shipnum[1]--;
                ship = new Destroyer(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
        break;
        case 3:
            if(currentp->shipnum[2]>0){
                currentp->shipnum[2]--;
                ship = new Cruiser(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
        break;
        case 4:
            if(currentp->shipnum[3]>0){
                currentp->shipnum[3]--;
                ship = new Battleship(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
        break;
        case 5:
            if(currentp->shipnum[4]>0){
                currentp->shipnum[4]--;
                ship = new Carrier(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
        break;
    }
    if(creation==true){ 
        vector<Point*>::iterator iter;
        for(iter=ship->OccupiedPoints.begin() ; iter!=ship->OccupiedPoints.end(); iter++){
            for(int i=0;i<=currentp->size;i++){
                for(int j=0;j<=currentp->size;j++){
                    if(**iter==currentp->map[i][j]){
                        if(currentp->map[i][j].getShippoint()==true){
                            creation=false;
                            graphic::up(2);
                        }
                        else{
                        currentp->map[i][j].setShippoint(true);
                        }
                    }
                    else{

                    } 
                }
            }
        }
        currentp->fleet.push_back(ship);
    }
    return creation;
}