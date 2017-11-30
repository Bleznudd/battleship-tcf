//main

#include <iostream>
#include "./header/Point.h"
#include "./header/Player.h"
#include "./header/Ship.h"
#include "./header/Graphic.h"
using namespace std;
using graphic::up;
using graphic::clear;
using graphic::gohome;

int main(){

    //PRESENTAZIONE DEL GIOCO
    graphic::clear();
    graphic::gohome();
    cout << "--- Benvenuti ---" << endl;

    //CREAZIONE DEI GIOCATORI
    Player *p1 = new Player();
    Player *p2 = new Player();
    graphic::up(2);

    //CREAZIONE DELLE FLOTTE
    p1->Deploy();
    p2->Deploy();

    //TURNI DI GIOCO
    bool thisturn = false;
    while(Player::getSomewinner() == false){
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