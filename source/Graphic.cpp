#include <iostream>
#include "../header/Graphic.h"
using namespace std;

namespace graphic{

    #ifdef ANSI

        void up(int n){
            for(int i=0; i <n; i++){
                cout << "\x1b[A";
                r();
            };
        }
        void r(){
            cout << "\x1b[2K";
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
        void waitUser(){
            cout << "(Premi ENTER per continuare)" << endl;
            cin.ignore();
        }
        void title(string s){
            cout << color('b',"       +--------------------------------------------------------+ ") << endl
                 << color('b',"       |                   ") 
                 << color('g',s)
                 << color('b',"                 |") << endl
                 << color('b',"       +--------------------------------------------------------+ ") << endl
                 << endl;
        }

    #endif

    #ifdef NOTANSI

        void up(int n){
            clear();
        }
        void r(){

        }
        void clear(){
            for(unsigned i=0; i<10; i++){
                cout << endl << endl << endl << endl << endl;
            }
        }
        void gohome(){
        
        }
        string color(char color,string s){
            string new_s;
            new_s = s;
            return new_s;
        }
        void waitUser(){
            cout << "(Premi ENTER per continuare)" << endl;
            cin.ignore();
            cin.ignore();
        }
        void title(string s){
            cout << "        -------------------------------------------------------- " << endl
                 << "       |                   "
                 << s
                 << "                 |" << endl
                 << "        -------------------------------------------------------- " << endl
                 << endl;
        }

    #endif

}