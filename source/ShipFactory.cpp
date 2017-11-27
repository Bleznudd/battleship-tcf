#include ShipFactory.h

ShipFactory::ShipFactory{



}

ShipFactory::~ShipFactory{
    
    }

static Ship create(Point pstart, Point pend){

    while(abs(start_.getX()-end_.getX())!=lenght-1 && (abs(start_.getY()-end_.getY())!=lenght-1)){
        cout << "La nave non è posizionabile tra i punti inseriti" << endl;
        cout << "Inserisci il punto iniziale: ";
        cin >> pstart;
        cout << "Inserisci il punto finale: ";
        cin >> pend;
    };
    if(abs(pstart->getX()-pend->getX())==0){
        int lenght=abs(pstart->getY()-pend->getY())+1;
    }
    else if(abs(pstart->getY()-pend->getY())==0){
        int lenght=abs(pstart->getX()-pend->getX())+1;
    }
    
    bool creation=false;

    while(creation=false){
        if(lenght==2){
            Ship *ship = new Destroyer(pstart,pend);
            creation=true;
        }
        if(lenght==3){
            Ship *ship = new Cruiser(pstart,pend);
            creation=true;
        }
        if(lenght==4){
            Ship *ship = new Battleship(pstart,pend);
            creation=true;
        }
        if(lenght==5){
            Ship *ship = new Carrier(pstart,pend);
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

    return ship;
}