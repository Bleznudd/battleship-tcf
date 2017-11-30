//main

#include <iostream>
#include "./header/Point.h"
#include "./header/Player.h"
#include "./header/Ship.h"
using namespace std;

void up(){
    // for(int i=0; i <10; i++){        //probabilmente è necessario un size+ qualcosa per cancellare tutto 
    //     cout << "\x1b[A";            //quest'istruzione posiziona il cursore una riga in su
    // };
    //visto che non so ancora quanto in su devo spostare, per i test utilizzo un clear
    //cout << "\x1b[2J" ;                 //quest'istruzione fa un clear del teminale  
}


int main(){

    //PRESENTAZIONE DEL GIOCO
    cout << "\x1b[2J" ;                 //quest'istruzione fa un clear del teminale
    cout << "\x1b[;H";                  //quest'istruzione posiziona il cursore in alto a sinistra
    cout << "--- Benvenuti ---" << endl;

    //CREAZIONE DEI GIOCATORI
    Player *p1 = new Player();
    Player *p2 = new Player();

    //CREAZIONE DELLE FLOTTE
    p1->Deploy();
    p2->Deploy();

    //TURNI DI GIOCO
    bool thisturn = false;
    while(Player::getSomewinner() == false){
        up();
        if(thisturn == false){
            p1->Draw();
            p1->Attack(*p2);
            thisturn = true;
        }
        else{
            p2->Draw();
            p2->Attack(*p1);
            thisturn = false;
        }
    };

    //DECRETAMENTO DEL VINCITORE
    if(thisturn == false){
        cout << "Complimenti " << p2->getName() << ", hai vinto!" << endl;
    }
    else{
        cout << "Complimenti " << p1->getName() << ", hai vinto!" << endl;
    }
    
    delete p1;
    delete p2;

    return 0;
}