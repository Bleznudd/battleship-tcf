//main

#include <iostream>
#include "Point.h"
#include "Grid.h"
#include "Player.h"
#include "Ship.h"

using namespace std;

void deploy(Player *player){
    string startp;
    string endp;
    cout << "Schieramento della flotta del giocatore " << player->getName() << endl;
    while(player->getGrid().getShipNum()>0){
        player->getGrid().DrawShips();
        cout << "Inserisci posizione inziale della nave ((x,y) due interi separati da una virgola): ";
        cin >> startp;
        cout << "Inserisci posizione finale della nave ((x,y) due interi separati da una virgola): ";
        cin >> endp;
        player->getGrid().Deploy(Ship(Point(startp),Point(endp)));
        player->getGrid.subtractShipNum();
    }
}

int main(){

    bool Player::winning = false;

    /*
     *Presentazione del gioco
    */
    cout << "\x1b[2J"; //quest'istruzione fa un clear del terminale
    cout << "\x1b[;H"; //quest'istruzione posiziona il cursore in alto a sinistra
    cout << "##############" << endl;

    /*
     *Caricamento giocatori
    */
    cout << "Nome giocatore 1: ";
    string s;   //nomi giocatori
    cin >> s;
    Player *p1 = new Player(s);
    cout << "Nome giocatore 2: ";
    cin >> s;
    Player *p2 = new Player(s);

    /*
     *Schieramento flotte
    */
    deploy(p1);
    deploy(p2);


    /*
     *Gioco
    */
    bool thisround = false;
    string thispoint;
    while(Player::getWinning()==false){
        if(thisround == false){
            cout << "Turno del giocatore " <<  p1->getName() << endl;
            p2->getGrid.Draw();
            cout << "Inserisci posizione da colpire ((x,y) due interi separati da una virgola): ";
            cin >> thispoint;
            p1->Attack(Point(thispoint));
            thisround = true;
        }
        else{
            cout << "Turno del giocatore " <<  p2->getName() << endl;
            p1->getGrid.Draw();
            cout << "Inserisci posizione da colpire ((x,y) due interi separati da una virgola): ";
            cin >> thispoint;
            p2->Attack(Point(thispoint));
            thisround = false;
        }
    }

    if(thisround = false){
        cout << endl << "Complimenti " << p1->getName()  << " ! Hai vinto " << endl;
    }
    else{
        cout << endl << "Complimenti " << p2->getName()  << " ! Hai vinto " << endl;
    }

    return 0;
}