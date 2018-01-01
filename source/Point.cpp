//implementazione di Punto.h

#include "../header/Point.h"

using namespace std;

Point::Point(int x_, int y_){
    x = x_;
    y = y_;
    hit = false;
    shippoint = false;
    mark[0] = '[';
    mark[1] = ' ';
    mark[2] = ']';
}
Point::~Point(){

}
void Point::setX(int x_){
    x=x_;
}
void Point::setY(int y_){
    y=y_;
}
int Point::getX(){
    return x;
}
int Point::getY(){
    return y;
}
char* Point::getMark(){
    return mark;
}
void Point::setMark(const char mark_[3]){
    mark[0] = mark_[0];
    mark[1] = mark_[1];
    mark[2] = mark_[2];
}
bool Point::getHit(){
    return hit;
}
void Point::setHit(bool tf){
    hit = tf;
}
bool Point::getShippoint(){
    return shippoint;
}
void Point::setShippoint(bool sp){
    shippoint = sp;
}
bool operator==(Point &p1, Point &p2){
    if(p1.getX() == p2.getX() && p1.getY() == p2.getY()){
        return true;
    }
    else{
        return false;
    }
}
ostream& operator<<(ostream& ostream, Point &p1){
    ostream << p1.getX() << "," << p1.getY();
    return ostream;
}
istream& operator>>(istream& ist, Point &p1){
    int xx;
    int yy;
    char c;
    ist >> xx >> c >> yy;
    if(xx>=0 && xx<=9 && yy>=0 && yy<=9){
        p1.setX(xx);
        p1.setY(yy);
        ist.ignore(999,'\n');
    }
    else{
        ist.setstate(std::ios_base::failbit);
    }
    return ist;
}
