//classe giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Point.h"
#include "Ship.h"

class Player{

friend class ShipFactory;

private:

	static int counter;
	static bool somewinner;
	int shipnum[5];		//vettore del numero di ogni tipo di nave, [0] è il numero totale
	int size;			//dimensione della griglia
	string name;
	vector<vector<Point> > map;
	vector<Ship*> fleet;

public:

	Player();
	~Player();
	string getName();
	vector<Ship*> &getFleet();
	vector<vector<Point> > &getMap();
	void UpdateShipnum();
	void Deploy();
	void Draw();
	void Attack(Player&);
	void setFleetVisible(bool visible);
	static bool getSomewinner();

};

#endif