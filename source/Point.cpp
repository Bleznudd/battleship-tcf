#include "../header/Point.h"

using namespace std;

Point::Point(int x_, int y_){
    x = x_;
    y = y_;
}
Point::~Point(){

}
Point::Point(string s){
    bool flag = false;
    string tmpx = "";
    string tmpy = "";
    if(s != ""){
        for(unsigned int i=0; i < s.length(); i++){
            if(s.at(i)!=',' && flag==false){
                tmpx = tmpx+s.at(i);
            }
            else if(s.at(i)!=',' && flag==true){
                tmpy = tmpy+s.at(i);
            }
            else if(s.at(i)==',' && flag==false){
                flag = true;
            }
        }
    x = stoi(tmpx);
    y = stoi(tmpy);
    }
}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

bool operator==(Point &p1, Point &p2){
    if(p1.getX() == p2.getX() && p1.getY() == p2.getY()){
        return true;
    }
    else{
        return false;
    }

}