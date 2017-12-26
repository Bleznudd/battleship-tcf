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
    shipnum[1]=3;      //numero navi da 2
    shipnum[2]=0;      //numero navi da 3
    shipnum[3]=0;      //numero navi da 4
    shipnum[4]=0;      //numero navi da 5
    shipnum[0]=shipnum[1]+shipnum[2]+shipnum[3]+shipnum[4];      //numero totale di navi
    counter++;
    for(int i=0;i<=size;i++){
        vector<Point> vect;
        for(int j=0;j<=size;j++){
            vect.push_back(Point(i,j));
        }
        map.push_back(vect);
    }
    cout << "Nome giocatore " << counter << ": ";
    getline(cin,name);
}
Player::~Player(){

}
string Player::getName(){
    return name;
}
vector<Ship*> &Player::getFleet(){
    return fleet;
}
vector<vector<Point> > &Player::getMap(){
    return map;
}
bool Player::getSomewinner(){
    return somewinner;
}
void Player::UpdateShipnum(){
    shipnum[0]=shipnum[1]+shipnum[2]+shipnum[3]+shipnum[4];
}
void Player::Deploy(){
    Draw();
    cout << "Schieramento della flotta del giocatore " << name << ": ";
    while(shipnum[0] > 0){
        int surpluslines=0;
        Point pi, pf;
        cout << endl << "Inserisci il punto iniziale della tua nave: ";
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
            UpdateShipnum();
            graphic::up(surpluslines+16);
            fleetVisible(true);
            Draw();
        }
        else{
            graphic::up(3);
            cout << "L' intervallo di punti non corrisponde a nessun tipo di nave disponibile, riprovare";
        }
    }
    fleetVisible(false);
    graphic::waitUser();
    graphic::up(14);
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
    cout << "Turno del giocatore " << getName() << endl;    
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
    for(vector<vector<Point> >::iterator i=player.getMap().begin(); i!=player.getMap().end(); i++){
        for(vector<Point>::iterator j=i->begin(); j!=i->end(); j++){
            if(*j==attackpoint && j->getHit()==false){
                j->setHit(true);
                if(j->getShippoint()==true){
                    j->setMark("[#]");
                    cout << "Colpito!";

                    int count = 0;
                    vector<Ship*>::iterator s=player.getFleet().begin();
                    while(s!=player.getFleet().end() && player.getFleet().empty()==false){
                        (*s)->setHit(attackpoint);
                        if((*s)->checkSunk()==true){
                            delete *(player.getFleet().begin()+count);
                            player.getFleet().erase(player.getFleet().begin()+count);
                        }
                        else{
                            s++;
                        }
                        count++;
                    }
                }
                else{
                    j->setMark("[-]");
                    cout << "Mancato!";
                }
                cout << endl;
                graphic::waitUser();
                graphic::up(17+surpluslines);
            }
            else if(*j==attackpoint && j->getHit()==true){
                graphic::up(2);
                cout << "Punto già inserito, provane un altro. ";
                Attack(player);
            } 
        }
    }
    if(player.getFleet().empty()==true){
        Player::somewinner=true;
    }
}

void Player::fleetVisible(bool visible){
    if(visible==true){
        for(int i=0;i<=size;i++){
            for(int j=0;j<=size;j++){
                if(map[i][j].getShippoint()==true){
                    map[i][j].setMark("[0]");
                }
            }
        }
    }
    else if(visible==false){
        for(int i=0;i<=size;i++){
            for(int j=0;j<=size;j++){
                map[i][j].setMark("[ ]");
            }
        }
    }
}