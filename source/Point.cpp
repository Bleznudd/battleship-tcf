#include "../header/Point.h"
#include <iostream>

using namespace std;

Point::Point(int x_, int y_){
    x = x_;
    y = y_;
    hit = false;
    shippart = false;
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
istream& operator>>(istream& istream, Point &p1){
    int xx;
    int yy;
    char c;
    istream >> xx >> c >> yy;

    p1.setX(xx);
    p1.setY(yy);
    return istream;
}
Point operator-(Point &p1, Point &p2){
    Point d((p1.getX()-p2.getX()),(p1.getY()-p2.getY()));
    return d;
}
Point operator+(Point &p1, Point &p2){
    Point sum((p1.getX()+p2.getX()),(p1.getY()+p2.getY()));
    return sum;
}