#include "../header/Player.h"
#include "../header/ShipFactory.h"
#include "../header/Graphic.h"

using namespace std;
using graphic::up;

int Player::counter=0;
bool Player::somewinner=false;

Player::Player(string name_){
    name = name_;
}
Player::Player(){
    size = 9;
    shipnum=1;
    counter++;
    for(int i=0;i<=size;i++){
        vector<Point> vect;
        for(int j=0;j<=size;j++){
            vect.push_back(Point(i,j));
        }
        // char ch[] = {' ','1','2','3','4','5','6','7','8','9','X'};
        // char pos[3]={' ',ch[i],' '};
        // vect[0].setMark(pos);
        // map[0][i].setMark(pos);
        // 
        // per evitare gli errori con l'attack() su 0,0 suppongo sia meglio inserire una legenda nella 
        // Draw(), vedi sotto
        map.push_back(vect);
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
    int n=1;
    while(shipnum > 0){
        n=n+3;
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
    cin.ignore();
    cin.ignore();
    graphic::up(n+1);
}
void Player::Draw(){
    vector<vector<Point> >::iterator i;
    cout << "                       0  1  2  3  4  5  6  7  8  9 " << endl;
    int riga=0;
    for(i=map.begin(); i!=map.end(); i++){
        cout << "                    " <<riga << " ";
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            cout << j->getMark()[0];  
            cout << j->getMark()[1];   
            cout << j->getMark()[2];    
        };
        cout << endl;
        riga++;
    }
    cout << endl;
}
void Player::Attack(Player &player){
    cout << "Turno del giocatore " << player.getName() << ": " <<endl;    
    Point attackpoint;
    cout << "Inserisci il punto che desideri attaccare: ";
    cin >> attackpoint;
    for(vector<vector<Point> >::iterator i=map.begin(); i!=map.end(); i++){
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            if(*j==attackpoint && j->getHit()==false){
                j->setHit(true);
                if(j->getShippoint()==true){
                    j->setMark("[#]");
                    cout << "Colpito!";
                    cin.ignore();
                    cin.ignore();

                    for(vector<Ship*>::iterator s=fleet.begin(); s!=fleet.end(); s++){
                        (*s)->setHit(attackpoint);
                        if((*s)->checkSunk()==true){
                            fleet.erase(s);
                        }
                    }
                }
                else{
                    j->setMark("[-]");
                    cout << "Mancato!";
                    cin.ignore();
                    cin.ignore();
                }
                cout << endl;
            }
            else if(*j==attackpoint && j->getHit()==true){
                cout << "Punto già inserito, provane un altro." << endl;
                cin.ignore();
                cin.ignore();
                graphic::up(4);
                Attack(player);
            } 
        }
    }
    if(fleet.empty()==true){
        Player::somewinner=true;
    }
    graphic::up(16);
}