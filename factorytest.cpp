#include "./header/ShipFactory.h"
#include "./header/Point.h"

int main(){

    ShipFactory *shipyard = new ShipFactory();

    shipyard->create(Point(0,0),Point(1,0));

    delete shipyard;

    return 0;

}