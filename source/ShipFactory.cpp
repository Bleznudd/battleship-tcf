#include "../header/ShipFactory.h"
#include "../header/Graphic.h"
#include <algorithm>//--------------------> per std::swap in ShipFactory::create()

using namespace std;
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
    else if(pstart.getY()-pend.getY()==0){
        len=abs(pstart.getX()-pend.getX())+1;
        if((pstart.getX()-pend.getX())>0){
            swap(pstart, pend);
        }
    }
    else{
        return false;
    }

    Ship *ship;

    switch(len){
        case 2:
            if(currentp->shipnum[1]>0){
                ship = new Destroyer(pstart,pend);
                //cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            else{
                return false;
            }
        break;
        case 3:
            if(currentp->shipnum[2]>0){
                ship = new Cruiser(pstart,pend);
                //cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            else{
                return false;
            }
        break;
        case 4:
            if(currentp->shipnum[3]>0){
                ship = new Battleship(pstart,pend);
                //cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            else{
                return false;
            }
        break;
        case 5:
            if(currentp->shipnum[4]>0){
                ship = new Carrier(pstart,pend);
                //cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            else{
                return false;
            }
        break;
        default:
            return false;
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
                        }
                        else if(creation == true){
                        currentp->map[i][j].setShippoint(true);
                        }
                    }
                }
            }
        }
    }
    if(creation == true){
        currentp->shipnum[(len-1)]--;
        currentp->fleet.push_back(ship);
    }
    else{
        delete ship;
    }
    return creation;
}