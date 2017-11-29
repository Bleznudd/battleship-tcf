//giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Point.h"
#include "Ship.h"
#include <string>

class Player{

public:

	static int counter;
	int shipnum;
	int size;
	string name;
	vector<vector<Point> > map;
	static bool somewinner;
	vector<Ship*> fleet;

public:

	Player(string);
	Player();
	~Player();
	string getName();
	static bool getSomewinner();
	void SubstractShipnum();
	void Deploy();
	void Draw();
	void Attack(Player&);
	friend class ShipFactory;

};

#endif
