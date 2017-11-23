#include "Grid.h"

#define up cout << "\x1b[A"; //quest'istruzione posiziona il cursore una riga in su

using namespace std;

Grid::Grid(int size_){
    size = size_;
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            map[i][j]="[ ]";
        };
    };
}

Grid::~Grid(){

}

int Grid::getShipNum(){
    return shipNum;
}

void Grid::subtractShipNum(){
    shipNum =- 1;
}

void Grid::Draw(){
    for(int i=0; i <size; i++){     //probabilmente è necessario un size+ qualcosa per cancellare tutto 
        up;
    };
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            cout << map[i][j];
        };
        cout << endl;
    };
}

void Grid::DrawShips(){

}

void Grid::Check(Point attackpoint){

}

void Grid::Deploy(Ship s){
    fleet.push_back(&s);
}