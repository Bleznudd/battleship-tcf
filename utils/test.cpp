/*
 *
 *  VERIFICA LA SOVRASCRITTURA CHE ANDRÀ
 *  IMPLEMENTATA NELLA Grid::Draw()
 *
 */

#include <iostream>
#include <vector>

#define clear cout << "\x1b[A"; //quest'istruzione posiziona il cursore una riga in su

using namespace std;

void Draw(vector<vector<string>> map, int size){
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            cout << map[i][j];
        };
        cout << endl;
    };
};

int main(){

    int size = 10;
    vector<vector<string>> map(size, vector<string>(size));
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            map[i][j] = "[ ]";
        };
    };
    map[4][8] = "[#]";
    map[4][9] = "[-]";
    Draw(map, size);
    for(int i=0; i <size; i++){
        clear;
    };
    map[1][3] = "[#]";
    map[2][7] = "[-]";
    map[4][8] = "[ ]";
    map[4][9] = "[ ]";
    Draw(map, size);




    return 0;
}