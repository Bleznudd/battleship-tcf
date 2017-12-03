//giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Point.h"
#include "Ship.h"
#include <string>

class Player{

friend class ShipFactory;

private:

	static int counter;
	int shipnum[5];		//vettore del numero di ogni tipo di nave, [0] è il numero totale
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
	void fleetVisible(bool visible);

};

#endif