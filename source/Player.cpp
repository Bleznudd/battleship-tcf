#include "../header/Player.h"

using namespace std;

Player::Player(string name_){
    name = name_;
}

Player::~Player(){

}

Grid* Player::getGrid(){
    return &myGrid;
}

string Player::getName(){
    return name;
}

void Player::Attacked(){   //ridondanza con Grid::Check()

    Point attackpoint;
    cout << "Inserisci posizione da colpire ((x,y) due interi separati da una virgola): ";
    cin >> attackpoint;
    if(myGrid.Check(attackpoint)==true){
        cout << "Colpito!" << endl;
    }
    else{
        cout << "Mancato" << endl;
    }
}