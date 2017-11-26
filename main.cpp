//main

#include <iostream>
#include "./header/Point.h"
#include "./header/Grid.h"
#include "./header/Player.h"
#include "./header/Ship.h"
#include "./header/ShipFactory.h"

using namespace std;

void up(){
    for(int i=0; i <10+3+4; i++){     //probabilmente è necessario un size+ qualcosa per cancellare tutto 
        cout << "\x1b[A"; //quest'istruzione posiziona il cursore una riga in su
    };
}

void deploy(Player *player){
    Point startp;
    Point endp;
    cout << "Schieramento della flotta del giocatore " << player->getName() << endl;
    while(player->getGrid()->getShipNum()>0){
        //player->getGrid()->DrawShips();
        cout << "Inserisci posizione inziale della nave ((x,y) due interi separati da una virgola): ";
        cin >> startp;
        cout << "Inserisci posizione finale della nave ((x,y) due interi separati da una virgola): ";
        cin >> endp;
        //per il momento trasformo la classe astratta ship in una reale e faccio a meno della factory
        //per verificare il funzionamento delle altre componenti
        //player->getGrid().Deploy(ShipFactory::create(Point(startp), Point(endp));
        player->getGrid()->Deploy(new Ship(startp,endp));
        player->getGrid()->subtractShipNum();
        // cout << player->getGrid()->getShipNum() << endl;
        player->getGrid()->DrawShips();
        cout << endl;
    }
}

int main(){

    //bool Player::winning = false;
    bool test = false;

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
    cout << endl << endl;
    cout << endl << endl;
    cout << endl << endl;


    /*
     *Gioco
    */
    bool thisround = false;
<<<<<<< HEAD
=======
    Point thispoint;
>>>>>>> fc67e1a89d7a4d231e83ab687ee7ce557fd1f9a9
    for(int i =0; i<10; i++){
        cout << endl;
    }
    //while(Player::getWinning()==false){
    while(test==false){
        if(thisround == false){
            up();
            cout << "Turno del giocatore " <<  p1->getName() << endl;
            p2->getGrid()->Draw();
<<<<<<< HEAD
            p2->Attacked();
=======
            cout << "Inserisci posizione da colpire ((x,y) due interi separati da una virgola): ";
            cin >> thispoint;
            p2->Attacked(thispoint);
>>>>>>> fc67e1a89d7a4d231e83ab687ee7ce557fd1f9a9
            thisround = true;
        }
        else{
            up();
            cout << "Turno del giocatore " <<  p2->getName() << endl;
            p1->getGrid()->Draw();
<<<<<<< HEAD
            p1->Attacked();
=======
            cout << "Inserisci posizione da colpire ((x,y) due interi separati da una virgola): ";
            cin >> thispoint;
            p1->Attacked(thispoint);
>>>>>>> fc67e1a89d7a4d231e83ab687ee7ce557fd1f9a9
            thisround = false;
        }
    }

    if(thisround == false){
        cout << endl << "Complimenti " << p1->getName()  << " ! Hai vinto " << endl;
    }
    else{
        cout << endl << "Complimenti " << p2->getName()  << " ! Hai vinto " << endl;
    }

    delete p1;
    delete p2;

    return 0;
}