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
bool Player::getSomewinner(){
    return somewinner;
}
void Player::SubstractShipnum(){
    shipnum--;
}
void Player::Deploy(){
    while(shipnum > 0){
        Point pi, pf;
        cout << "Inserisci il punto iniziale della tua nave: ";
        cin >> pi;
        cout << "Inserisci il punto finale della tua nave: ";
        cin >> pf;
        if(ShipFactory::create(pi, pf) == true){
            SubstractShipnum();
        }
        else{
            cout << "L' intervallo di punti non corrisponde a nessun tipo di nave, riprovare" << endl;
        }
    }
}
void Player::Draw(){
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            cout << map[i][j];   
        };
        cout << endl;
    }
}
void Player::Attack(Player &player){
    Point attackpoint;
    cout << "Inserisci il punto che desideri attaccare: ";
    cin >> attackpoint;
    for(vector<vector<Point>>::iterator i=map.begin(); i!=map.end(); i++){
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            if(*j==attackpoint && j->getShippoint()==true){
                j->setHit(true);
                j->setMark("[#]");
            } 
        };
    }
}