#include "../header/ShipFactory.h"
#include "../header/Graphic.h"
#include <algorithm>       //per std::swap in ShipFactory::create()


using graphic::up;

ShipFactory::ShipFactory(){

}
ShipFactory::~ShipFactory(){
    
}
void ShipFactory::create(Point pstart, Point pend, Player* currentp){

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
    else if(pstart.getX()-pend.getX()!=0 && pstart.getY()-pend.getY()!=0){
        throw "I 2 punti non sono allineati, riprovare\n";
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
            else{
                throw "Hai già esaurito le navi di questo tipo, riprovare\n";
            }
        break;
        case 3:
            if(currentp->shipnum[2]>0){
                currentp->shipnum[2]--;
                ship = new Cruiser(pstart,pend);
                cout << "Creato incrociatore" << endl;
                creation=true;
            }
            else{
                throw "Hai già esaurito le navi di questo tipo, riprovare\n";
            }
        break;
        case 4:
            if(currentp->shipnum[3]>0){
                currentp->shipnum[3]--;
                ship = new Battleship(pstart,pend);
                cout << "Creata nave da battaglia" << endl;
                creation=true;
            }
            else{
                throw "Hai già esaurito le navi di questo tipo, riprovare\n";
            }
        break;
        case 5:
            if(currentp->shipnum[4]>0){
                currentp->shipnum[4]--;
                ship = new Carrier(pstart,pend);
                cout << "Creata portaerei" << endl;
                creation=true;
            }
            else{
                throw "Hai già esaurito le navi di questo tipo, riprovare\n";
            }
        break;
        case 0: 
        break;
        default:
            throw "Non esiste una nave con questa lunghezza, riprovare\n";
        break;
    }
    if(creation==true){ 
        vector<Point*>::iterator iter;
        for(iter=ship->OccupiedPoints.begin() ; iter!=ship->OccupiedPoints.end(); iter++){
            for(int i=0;i<=currentp->size;i++){
                for(int j=0;j<=currentp->size;j++){
                    if(**iter==currentp->map[i][j]){
                        if(currentp->map[i][j].getShippoint()==true){
                            deleteship(ship,currentp);
                            cout << endl;
                            graphic::up(2);
                            throw "posizione già occupata, riprovare\n";
                        }
                        else{
                        currentp->map[i][j].setShippoint(true);
                        currentp->fleet.push_back(ship);
                        }
                    }
                    else{

                    } 
                }
            }
        }
    }
}

void ShipFactory::deleteship(Ship* ship, Player* player){
    player->shipnum[(ship->lenght-1)]++;
    delete ship;
}