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
    shipnum=2;
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
    while(shipnum > 0){
        this->fleetVisible(true);
        this->Draw();
        int surpluslines=11;
        Point pi, pf;
        cout << "Inserisci il punto iniziale della tua nave: ";
        while(!(cin >> pi)) {
            cin.clear();
            cin.ignore(999,'\n');
            cout<<"Il punto inserito non è valido, reinserirlo" << endl;
            cout << "Inserisci il punto iniziale della tua nave: ";
            surpluslines+=2;
        }
        cout << "Inserisci il punto finale della tua nave: ";
        while(!(cin >> pf)) {
            cin.clear();
            cin.ignore(999,'\n');
            cout<<"Il punto inserito non è valido, reinserirlo" << endl;
            cout << "Inserisci il punto finale della tua nave: ";
            surpluslines+=2;
        }
        if(ShipFactory::create(pi, pf, this) == true){
            SubstractShipnum();
        }
        else{
            cout << "L' intervallo di punti non corrisponde a nessun tipo di nave, riprovare" << endl;
        }
        graphic::waitUser();
        graphic::up(surpluslines+6);
    }
    this->fleetVisible(false);
    ShipFactory::restartCounters();
    graphic::up(2);
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
    int surpluslines = 0;
    while(!(cin >> attackpoint)) {
        cin.clear();
        cin.ignore(999,'\n');
        cout<<"Il punto inserito non è valido, reinserirlo" << endl;
        cout << "Inserisci il punto che desideri attaccare: ";
        surpluslines+=2;
    }
    for(vector<vector<Point> >::iterator i=map.begin(); i!=map.end(); i++){
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            if(*j==attackpoint && j->getHit()==false){
                j->setHit(true);
                if(j->getShippoint()==true){
                    j->setMark("[#]");
                    cout << "Colpito!";
                    for(vector<Ship*>::iterator s=fleet.begin(); s!=fleet.end() && fleet.empty()==false; s++){
                        (*s)->setHit(attackpoint);
                        if((*s)->checkSunk()==true){
                            fleet.erase(s);
                        }
                    }
                }
                else{
                    j->setMark("[-]");
                    cout << "Mancato!";
                }
                cout << endl;
            }
            else if(*j==attackpoint && j->getHit()==true){
                cout << "Punto già inserito, provane un altro." << endl;
                graphic::up(4);
                Attack(player);
            } 
        }
    }
    if(fleet.empty()==true){
        Player::somewinner=true;
    }
    graphic::waitUser();
    graphic::up(16+surpluslines+1);
}

void Player::fleetVisible(bool visible){
    if(visible==true){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(map[i][j].getShippoint()==true){
                    map[i][j].setMark("[0]");
                }
            }
        }
    }
    else if(visible==false){
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                map[i][j].setMark("[ ]");
            }
        }
    }
}