#include "../header/Ship.h"

using namespace std;

Ship::Ship(){

}

Ship::Ship(Point *start_, Point *end_){
    while(abs(start_->getX()-end_->getX())!=lenght-1 && (abs(start_->getY()-end_->getY())!=lenght-1)){
        cout << "La nave non è posizionabile tra i punti inseriti" << endl;
        cout << "Inserisci il punto iniziale: ";
        cin >> *start_;
        cout << "Inserisci il punto finale: ";
        cin >> *end_;
    };
    if(abs(start_->getX()-end_->getX())==lenght-1){
        for(unsigned int i=0; i<lenght; i++){
        blocks.push_back(new Point(start_->getX() + i, start_->getY()));  
        };
    }
    else if(abs(start_->getY()-end_->getY())==lenght-1){
        for(unsigned int i=0; i<lenght; i++){
        blocks.push_back(new Point(start_->getX(), start_->getY() + i));  
        };
    }
}

Ship::~Ship(){
    cout << "Affondata!" << endl; //quando una nave è distrutta comunica al giocatore l'avvenuto affondamento
}

vector<Point*> Ship::getBlocks(){
    return blocks;
}
