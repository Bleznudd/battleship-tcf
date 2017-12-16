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
    cout << "      ********************************************************** " << endl;
    cout << " Benvenuti a battaglia navale, per cominciare inserite i nomi dei giocatori " << endl;
    cout << endl;

    //CREAZIONE DEI GIOCATORI
    Player *p1 = new Player();
    Player *p2 = new Player();
    graphic::up(5);

    //ISTRUZIONI
    cout << "     ************************* ISTRUZIONI ************************* " << endl
         << "Generali" << endl
         << "     Il gioco si svoglie in una griglia 10x10 caselle numerate 0-9." << endl
         << "     Una posizione va indicata con 2 numeri separati da virgola (y,x)." << endl
         << "Legenda" << endl
         << "     cacciatorpediniere = nave da 2 caselle" << endl
         << "        incrociatore    = nave da 3 caselle" << endl
         << "      nave da battaglia = nave da 4 caselle" << endl
         << "         portaerei      = nave da 5 caselle" << endl
         << "            [ ]         = casella base" << endl
         << "            [-]         = casella mancata" << endl
         << "            [#]         = casella colpita" << endl
         << "            [0]         = casella occupata da una nave" << endl
         << "Fase 1: Schieramento" << endl
         << "     Ogni giocatore deve posiionare 4 cacciatorpedinieri, 3 incrociatori" << endl
         << "     2 navi da battaglia e 1 portaerei. Una volta posizionate tutte le navi" << endl
         << "     tocca all'altro giocatore." << endl
         << "Fase 2: Gioco" << endl
         << "     A turno i giocatori idicano una posizione in cui sparare ricevendo" << endl
         << "     come risposta un messaggio (colpito o mancato ed eventualmente affondato)." << endl
         << "     Quando un giocatore affonda tutte le navi avversarie è dichiarato vincitore" << endl
         << endl;
    graphic::waitUser();
    graphic::up(24);
    //CREAZIONE DELLE FLOTTE
    p1->Deploy();
    p2->Deploy();

    //TURNI DI GIOCO
    bool thisturn = false;
    while(Player::getSomewinner() == false){
        if(thisturn == false){
            p2->Draw();
            p1->Attack(*p2);
            thisturn = true;
        }
        else{
            p1->Draw();
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