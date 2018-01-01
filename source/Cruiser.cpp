//implementazione di Cruiser.h

#include "../header/Cruiser.h"
#include <vector>

Cruiser::Cruiser(Point start_, Point end_){
    lenght=3;
    if(abs(start_.getX()-end_.getX())==lenght-1){
        for(int i=0; i<lenght; i++){
            OccupiedPoints.push_back(new Point(start_.getX() + i, start_.getY()));  
        };
    }
    else if(abs(start_.getY()-end_.getY())==lenght-1){
        for(int i=0; i<lenght; i++){
            OccupiedPoints.push_back(new Point(start_.getX(), start_.getY() + i));  
        };
    }
}
