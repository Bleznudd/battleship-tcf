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
    graphic::title("BATTAGLIA NAVALE");
    cout << "     ********************************************************** " << endl;
    cout << " Benvenuti a battaglia navale, per cominciare inserite i nomi dei giocatori " << endl;
    cout << endl;

    //CREAZIONE DEI GIOCATORI
    Player *p1 = new Player();
    Player *p2 = new Player();
    graphic::up(5);

    //ISTRUZIONI
    cout << "     ************************* ISTRUZIONI ************************* " << endl;
    cout << "Generali" << endl;
    cout << "     Il gioco si svoglie in una griglia 10x10 caselle numerate 0-9." << endl;
    cout << "     Una posizione va indicata con 2 numeri separati da virgola (y,x)." << endl;
    cout << "Legenda" << endl;
    cout << "     cacciatorpediniere = nave da 2 caselle" << endl;
    cout << "        incrociatore    = nave da 3 caselle" << endl;
    cout << "      nave da battaglia = nave da 4 caselle" << endl;
    cout << "         portaerei      = nave da 5 caselle" << endl;
    cout << "            [ ]         = casella base" << endl;
    cout << "            [-]         = casella mancata" << endl;
    cout << "            [#]         = casella colpita" << endl;
    cout << "            [0]         = casella occupata da una nave" << endl;
    cout << "Fase 1: Schieramento" << endl;
    cout << "     Ogni giocatore deve posizionare 4 cacciatorpedinieri, 3 incrociatori" << endl;
    cout << "     2 navi da battaglia e 1 portaerei. Una volta posizionate tutte le navi" << endl;
    cout << "     tocca all'altro giocatore." << endl;
    cout << "Fase 2: Gioco" << endl;
    cout << "     A turno i giocatori idicano una posizione in cui sparare ricevendo" << endl;
    cout << "     come risposta un messaggio (colpito o mancato ed eventualmente affondato)." << endl;
    cout << "     Quando un giocatore affonda tutte le navi avversarie è dichiarato vincitore" << endl;
    cout << endl;
    graphic::waitUser();
    graphic::up(24);
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