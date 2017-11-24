#include "../header/Grid.h"

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

void Grid::Check(Point attackpoint){    //ridondanza con Player::Attacked()
    vector<Ship*>::iterator shipiter;
    vector<Point>::iterator pointiter;
    bool hit = false;
    for(shipiter=fleet.begin(); shipiter!=fleet.end(); shipiter++){
        for(pointiter=(*shipiter)->getBlocks().begin(); pointiter!=(*shipiter)->getBlocks().end(); pointiter++){
            if(attackpoint == (*pointiter)){ //come confronto Point e iterator<Point> ?
                //Questa è la soluzione, gli iteratori vengono considerati al pari dei puntatori, quindi per
                //confrotare Point e il suo iteratore devo deferenziare l'iteratore con *, analogamente, per 
                //assegnare all'iteratore di Point il puntatore al primo punto di un iteratore di navi
                //(ricordiamo che l'iteratore di navi è un puntatore a un puntatore a un vettore di puntatori)
                //devo deferenziare due volte, ovvero usare * oppure *->
                map[attackpoint.getX()][attackpoint.getY()] = "[#]";
                hit = true;
            }
        }
    };
    if(hit == false){ 
        map[attackpoint.getX()][attackpoint.getY()] = "[-]";
    }
}

void Grid::Deploy(Ship s){
    fleet.push_back(&s);
}