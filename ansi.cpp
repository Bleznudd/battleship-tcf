#include <iostream>
using namespace std;

int main(){

    int servosolopermettereinpausa;

    /*
        *Scrivo una pseudo matrice di "Test"
    */
    for(int i=0; i <4; i++){
        cout << "Test - Test - Test - Test - Test - Test" << endl;
    };

    /*
        *Metto in pausa
    */
    cout << "Inseisci un intero a caso e sovrascrivi: ";
    cin >> servosolopermettereinpausa;

    /*
        *Sposto il cursore in su di 5 caselle
    */
    for(int i=0; i <5; i++){
        cout << "\x1b[A" ; //per il significado vedasi: https://en.wikipedia.org/wiki/ANSI_escape_code
    };

    /*
        *Sovrascrivo una pseudo matrice di "Prov"
    */
    for(int i=0; i <4; i++){
        cout << "Prov - Prov - Prov - Prov - Prov - Prov" << endl;
    };
    cout << "Hai premuto invio e hai sovrascritto                                           " << endl;

    return 0;
}