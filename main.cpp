//main

#include <iostream>
#include "./header/Point.h"
#include "./header/Grid.h"
#include "./header/Player.h"
#include "./header/Ship.h"
using namespace std;

void up(){
    for(int i=0; i <10+3+4+1; i++){     //probabilmente è necessario un size+ qualcosa per cancellare tutto 
        cout << "\x1b[A"; //quest'istruzione posiziona il cursore una riga in su
    };
}

int main(){

    return 0;
}