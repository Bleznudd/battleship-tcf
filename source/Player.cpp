#include "../header/Player.h"
#include "../header/ShipFactory.h"

using namespace std;

int Player::counter=0;
bool Player::somewinner=false;

Player::Player(string name_){
    name = name_;
}
Player::Player(){
    size = 10;
    shipnum=1;
    counter++;
    for(int i=0;i<=size;i++){
        for(int j=0;j<=size;j++){
            vector<Point> vect;
            vect.push_back(Point(i,j));
            map.push_back(vect);
        }
    }
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
    cout << "Schieramento della flotta del giocatore " << name << ": " <<endl;
    while(shipnum > 0){
        Point pi, pf;
        cout << "Inserisci il punto iniziale della tua nave: ";
        cin >> pi;
        cout << "Inserisci il punto finale della tua nave: ";
        cin >> pf;
        if(ShipFactory::create(pi, pf, this) == true){
            SubstractShipnum();
        }
        else{
            cout << "L' intervallo di punti non corrisponde a nessun tipo di nave, riprovare" << endl;
        }
    }
}
void Player::Draw(){
    //cout << "Draw" << endl;
    vector<vector<Point> >::iterator i;
    for(i=map.begin(); i!=map.end(); i++){
        //cout << "riga";
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            cout << j->getMark()[0];  
            cout << j->getMark()[1];   
            cout << j->getMark()[2];    
        };
        cout << endl;
    }
}
void Player::Attack(Player &player){
    cout << "Turno del giocatore " << name << ": " <<endl;    
    Point attackpoint;
    cout << "Inserisci il punto che desideri attaccare: ";
    cin >> attackpoint;
    for(vector<vector<Point> >::iterator i=map.begin(); i!=map.end(); i++){
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            if(*j==attackpoint && j->getHit()==false){
                if(j->getShippoint()==true){
                    j->setMark("[#]");
                    cout << "Colpito!" << endl;
                }
                else{
                    j->setMark("[-]");
                    cout << "Mancato!" << endl;
                }
                j->setHit(true);
            }
            else if(*j==attackpoint && j->getHit()==true){
                cout << "Punto già inserito, provane un altro." << endl;
                Attack(player);
            } 
        }
    }
}