#include "../header/ShipFactory.h"
#include "../header/Graphic.h"

using graphic::up;

// int ShipFactory::destroyerCounter=0;
// int ShipFactory::cruiserCounter=0;
// int ShipFactory::battleshipCounter=0;
// int ShipFactory::carrierCounter=0;

ShipFactory::ShipFactory(){

}
ShipFactory::~ShipFactory(){
    
}
bool ShipFactory::create(Point pstart, Point pend, Player* currentp){

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
            if(currentp->shipnum[1]>0){
                currentp->shipnum[1]--;
                ship = new Destroyer(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            // ShipFactory::destroyerCounter++;
            // if(ShipFactory::destroyerCounter<=1){
            //     ship = new Destroyer(pstart,pend);
            //     cout << "Creato cacciatorpediniere" << endl;
            //     creation=true;
            // }
            // else{
            //     ShipFactory::destroyerCounter--;
            // }
        break;
        case 3:
            if(currentp->shipnum[2]>0){
                currentp->shipnum[2]--;
                ship = new Destroyer(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            // ShipFactory::cruiserCounter++;
            // if(ShipFactory::cruiserCounter<=1){
            //     ship = new Cruiser(pstart,pend);
            //     cout << "Creato incrociatore" << endl;
            //     creation=true;
            // }
            // else{
            //     ShipFactory::cruiserCounter--;
            // }
        break;
        case 4:
            if(currentp->shipnum[3]>0){
                currentp->shipnum[3]--;
                ship = new Destroyer(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            // ShipFactory::battleshipCounter++;
            // if(ShipFactory::battleshipCounter<=1){
            //     ship = new Battleship(pstart,pend);
            //     cout << "Creata nave da battaglia" << endl;
            //     creation=true;
            // }
            // else{
            //     ShipFactory::battleshipCounter--;
            // }
        break;
        case 5:
            if(currentp->shipnum[4]>0){
                currentp->shipnum[4]--;
                ship = new Destroyer(pstart,pend);
                cout << "Creato cacciatorpediniere" << endl;
                creation=true;
            }
            // ShipFactory::carrierCounter++;
            // if(ShipFactory::carrierCounter<=1){
            //     ship = new Carrier(pstart,pend);
            //     cout << "Creata portaerei" << endl;
            //     creation=true;
            // }
            // else{
            //     ShipFactory::carrierCounter--;
            // }
        break;
    }
    if(creation==true){ 
        vector<Point*>::iterator iter;
        for(iter=ship->OccupiedPoints.begin() ; iter!=ship->OccupiedPoints.end(); iter++){
            //(*iter)->setShippoint(true); //non va bene perchè i punti non fanno parte della griglia
            for(int i=0;i<=currentp->size;i++){
                for(int j=0;j<=currentp->size;j++){
                    if(**iter==currentp->map[i][j]){
                        if(currentp->map[i][j].getShippoint()==true){
                            creation=false;
                            //deleteShip(ship);
                            graphic::up(2);
                            return creation;
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
// void ShipFactory::restartCounters(){
//     ShipFactory::destroyerCounter=0;
//     ShipFactory::cruiserCounter=0;
//     ShipFactory::battleshipCounter=0;
//     ShipFactory::carrierCounter=0;
// }
// void ShipFactory::deleteShip(Ship* ship){
//     switch(ship->getLenght()){
//         case 2:
//             ShipFactory::destroyerCounter--;
//         break;
//         case 3:
//             ShipFactory::cruiserCounter--;
//         break;
//         case 4:
//             ShipFactory::battleshipCounter--;
//         break;
//         case 5:
//             ShipFactory::carrierCounter--;
//         break;
//         default:

//         break;
//     }
//     delete ship;
// }