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
using graphic::color;

int main(){

    //PRESENTAZIONE DEL GIOCO
    graphic::clear();
    graphic::gohome();
    cout << color('b',"        -------------------------------------------------------- ") << endl;
    cout << color('b',"       |                   ") 
         << color('g',"BATTAGLIA NAVALE") 
         << color('b',"                 |") << endl;
    cout << color('b',"        -------------------------------------------------------- ") << endl;
    cout << endl;
    cout << "     ********************************************************** " << endl;
    cout << " Benvenuti a battaglia navale, per cominciare inserite i nomi dei giocatori " << endl;
    cout << endl;

    //CREAZIONE DEI GIOCATORI
    Player *p1 = new Player();
    Player *p2 = new Player();
    graphic::up(5);

    //CREAZIONE DELLE FLOTTE
    p1->Deploy();
    p2->Deploy();

    //TURNI DI GIOCO
    bool thisturn = false;
    while(Player::getSomewinner() == false){
        if(thisturn == true){
            p1->Draw();
            p1->Attack(*p2);
            thisturn = false;
        }
        else{
            p2->Draw();
            p2->Attack(*p1);
            thisturn = true;
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