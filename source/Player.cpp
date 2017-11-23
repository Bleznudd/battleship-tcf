#include "../header/Player.h"

using namespace std;

Player::Player(string name_){
    name = name_;
}

Player::~Player(){

}

Grid Player::getGrid(){
    return myGrid;
}

string Player::getName(){
    return name;
}

void Player::Attacked(Point attackpoint){   //ridondanza con Grid::Check()

}