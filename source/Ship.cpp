#include "Ship.h"

using namespace std;

Ship::Ship(){

}
Ship::~Ship(){

}
Ship::Ship(Point start_, Point end_){
    if(start_.getX()-end.getX()==lenght || start_.getY()-end.getY()==lenght){
        start = start_;
        end = end_;
    }
    else{
        cout << "La nave non è posizionabile tra i punti inseriti" << endl;
    }
}