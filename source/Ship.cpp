#include "../header/Ship.h"

using namespace std;

Ship::Ship(){

}
Ship::~Ship(){
    cout << "Affondata!" << endl;
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
        cout << " E affondato !";
        return true;
    }
    return false;
}