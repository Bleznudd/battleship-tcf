#include <iostream>
#include "../header/Graphic.h"
using namespace std;

namespace graphic{

    void up(int n){
        for(int i=0; i <n; i++){        //probabilmente è necessario un size+ qualcosa per cancellare tutto 
            cout << "\x1b[A";           //quest'istruzione posiziona il cursore una riga in su
            cout << "\x1b[2K";
        };
   
    }
    void clear(){
        cout << "\x1b[2J" ;
    }
    void gohome(){
        cout << "\x1b[;H";
    }
    string color(char color,string s){
        string new_s;
        switch(color){
            case('r'):
                new_s = "\033[1;31m " + s + " \033[0m";
            break;
            case('g'):
                new_s = "\033[1;32m " + s + " \033[0m";
            break;
            case('y'):
                new_s = "\033[1;33m " + s + " \033[0m";
            break;
            case('b'):
                new_s = "\033[1;34m " + s + " \033[0m";
            break;
        }
        return new_s;
    }

}