#include "../header/Grid.h"

using namespace std;

Grid::Grid(int size_){
    size = size_;
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            map[i][j]="[ ]";
        };
    };
    shipNum=1;
}

Grid::~Grid(){

}

int Grid::getShipNum(){
    return shipNum;
}

void Grid::subtractShipNum(){
    shipNum = shipNum - 1;
}

void Grid::Draw(){
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            cout << map[i][j];
        };
        cout << endl;
    };
}

void Grid::DrawShips(){
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
         if(Check(Point(i,j))==true){
            map[iterpoint.getX()][iterpoint.getY()] = "[0]";
            };
    };
    Draw();
    for(unsigned int i=0; i<size; i++){
        for(unsigned int j=0; j<size; j++){
            map[i][j]="[ ]";
        };
    };
}

bool Grid::Check(Point attackpoint){    //ridondanza con Player::Attacked()
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
    return hit;
    //per ora la funzione è implementata come bool, ovvero restituisce solo "Colpito" oppure "Mancato"
    //non è ancora pronta per restituire "Affondato", ma è un problema che affronterò più avanti
}

void Grid::Deploy(Ship* s){
    fleet.push_back(s);
}