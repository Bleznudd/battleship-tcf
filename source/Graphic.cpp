#include <iostream>
#include "../header/Graphic.h"
using namespace std;

namespace graphic{

    void up(int n){
        for(int i=0; i <n; i++){        //probabilmente è necessario un size+ qualcosa per cancellare tutto 
            cout << "\x1b[A";           //quest'istruzione posiziona il cursore una riga in su
        };  
    }
    void clear(){
        cout << "\x1b[2J" ;
    }
    void gohome(){
        cout << "\x1b[;H";
    }
    
}