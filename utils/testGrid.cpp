#include <iostream>
#include "../header/Grid.h"
#include "../header/Point.h"
#include "../header/Ship.h"
using namespace std;

int main(){

    Grid g(10);

    cout << "\x1b[2J";
    cout << "\x1b[;H";
    for(int i=0; i<10; i++){
        cout << endl;
    }
    g.Draw();
    g.Deploy(Ship(Point(1,1), Point(2,2)));

    return 0;
}