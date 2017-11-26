#include <iostream>
#include "../header/Grid.h"
#include "../header/Ship.h"
#include "../header/Point.h"
#include "../header/Player.h"


using namespace std;

int main(){

    cout << "Instanzio un nuovo giocatore staticamente: A" << endl;
    Player a("A");
    cout << "Inserisco due punti per creare una nave" << endl;
    string pi, pf;
    cout << "Punto di inizio: ";
    cin >> pi;
    cout << "Punto di fine: ";
    cin >> pf;
    cout << "Facciamo il deploy della nave" << endl;
    a.getGrid()->Deploy(new Ship(Point(pi), Point(pf)));
    cout << "Stampiamo i punti della nave" << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[0].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[0].getY() << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[1].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[1].getY() << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[2].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[2].getY() << endl;
    cout << "Proviamo a stampare i punti successivi" << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[3].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[3].getY() << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[4].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[4].getY() << endl;
    cout << "Inserisco due punti per creare una nuova nave" << endl;
    cout << "Punto di inizio: ";
    cin >> pi;
    cout << "Punto di fine: ";
    cin >> pf;
    cout << "Facciamo il deploy della nave" << endl;
    a.getGrid()->Deploy(new Ship(Point(pi), Point(pf)));
    cout << "Stampiamo i punti della nave" << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[0].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[0].getY() << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[1].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[1].getY() << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[2].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[2].getY() << endl;
    cout << "Proviamo a stampare i punti successivi" << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[3].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[3].getY() << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[4].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[4].getY() << endl;
    // cout << "Stampiamo i punti di un'altra nave che non dovrebbe esistere" << endl;
    // cout << a.getGrid()->fleet[2]->getBlocks()[0].getX() << ", " << a.getGrid()->fleet[2]->getBlocks()[0].getY() << endl;
    // cout << a.getGrid()->fleet[2]->getBlocks()[1].getX() << ", " << a.getGrid()->fleet[2]->getBlocks()[1].getY() << endl;
    // cout << a.getGrid()->fleet[2]->getBlocks()[2].getX() << ", " << a.getGrid()->fleet[2]->getBlocks()[2].getY() << endl;
    // cout << a.getGrid()->fleet[2]->getBlocks()[3].getX() << ", " << a.getGrid()->fleet[2]->getBlocks()[3].getY() << endl;
    // cout << a.getGrid()->fleet[2]->getBlocks()[4].getX() << ", " << a.getGrid()->fleet[2]->getBlocks()[4].getY() << endl;
    // com'è logico ci restituisce seg fault
    cout << "Proviamo adesso a fare stampare gli stessi punti con due for annidati che ciclano su fleet" << endl;
    vector<Ship*>::iterator shipiter;
    vector<Point>::iterator pointiter;
    int i=1;
    for(shipiter=a.getGrid()->fleet.begin(); shipiter!=a.getGrid()->fleet.end(); shipiter++){
        cout << "nave " << i << endl;
        i++;
        for(pointiter=(*shipiter)->getBlocks().begin(); pointiter!=(*shipiter)->getBlocks().end(); pointiter++){
                 cout << pointiter->getX() << ", " << pointiter->getY() << endl;
        }
    };
    cout << "Verifichiamo che nulla abbia modificato i valori ristampando come nel modo precedente" << endl;
    cout << "Stampiamo i punti della nave 1" << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[0].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[0].getY() << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[1].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[1].getY() << endl;
    cout << a.getGrid()->fleet[0]->getBlocks()[2].getX() << ", " << a.getGrid()->fleet[0]->getBlocks()[2].getY() << endl;    
    cout << "Stampiamo i punti della nave 2" << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[0].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[0].getY() << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[1].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[1].getY() << endl;
    cout << a.getGrid()->fleet[1]->getBlocks()[2].getX() << ", " << a.getGrid()->fleet[1]->getBlocks()[2].getY() << endl;
   


    return 0;
}