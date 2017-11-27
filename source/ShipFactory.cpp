#include "../header/ShipFactory.h"

ShipFactory::ShipFactory(){



}

ShipFactory::~ShipFactory(){
    
    }

static Ship create(Point pstart, Point pend){

    bool lok=false;
    int lenght;

    while(lok==false){
        if(abs(pstart.getX()-pend.getX())==0){
            lenght=abs(pstart.getY()-pend.getY())+1;
            lok=true;
        }
        else if(abs(pstart.getY()-pend.getY())==0){
            lenght=abs(pstart.getX()-pend.getX())+1;
            lok=true;
        }
        else{
            cout << "La nave non è posizionabile tra i punti inseriti" << endl;
            cout << "Inserisci il punto iniziale: ";
            cin >> pstart;
            cout << "Inserisci il punto finale: ";
            cin >> pend;
        }
    }
    
    bool creation=false;
    Ship *ship;

    while(creation==false){
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
        else{
            cout << "Lunghezza della nave non valida!" << endl;
            cout << "Inserisci il punto iniziale: ";
            cin >> pstart;
            cout << "Inserisci il punto finale: ";
            cin >> pend;
        }
    }

    return *ship;
}