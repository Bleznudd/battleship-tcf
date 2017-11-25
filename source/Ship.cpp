#include "../header/Ship.h"

using namespace std;

Ship::Ship(){

}
Ship::~Ship(){

}
Ship::Ship(Point start_, Point end_){
    if(abs(start_.getX()-end_.getX())==lenght){
        for(unsigned int i=0; i<lenght; i++){
          blocks.push_back(Point(start_.getX() + i, start_.getY()));  
        };
    }
    else if(abs(start_.getY()-end_.getY())==lenght){
        for(unsigned int i=0; i<lenght; i++){
          blocks.push_back(Point(start_.getX(), start_.getY() + i));  
        };
    }
    else{
        cout << "La nave non è posizionabile tra i punti inseriti" << endl;
    }
}

Ship::~Ship(){
    cout << "Affondata!" << endl; //quando una nave è distrutta comunica al giocatore l'avvenuto affondamento
}

vector<Point> Ship::getBlocks(){
    return blocks;
}
