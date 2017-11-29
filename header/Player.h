//giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Point.h"
#include "ShipFactory.h"
#include <string>

class Player{

private:

	static int counter;
	int shipnum;
	int size;
	string name;
	vector<vector<Point>> map;
	static bool somewinner;
	vector<*Ship> fleet;

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
