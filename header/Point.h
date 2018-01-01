//classe punto

#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;

class Point{

private:
    
    int x;
    int y;
    bool hit;
    bool shippoint;
    char mark[3];

public:

    Point(int=0, int=0);
    ~Point();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    char* getMark();
    void setMark(const char[3]);
    bool getHit();
    void setHit(bool);
    bool getShippoint();
    void setShippoint(bool);
    friend bool operator==(Point &p1, Point &p2);
    friend ostream& operator<<(ostream& ostream, Point &p1);
    friend istream& operator>>(istream& istream, Point &p1);

};

#endif
