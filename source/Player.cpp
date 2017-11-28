#include "../header/Player.h"

using namespace std;

int Player::counter=0;

Player::Player(string name_){
    name = name_;
}
Player::Player(){
    counter++;
    cout << "Nome giocatore " << counter << ": ";
    cin >> name;
}
Player::~Player(){
}
string Player::getName(){
    return name;
}