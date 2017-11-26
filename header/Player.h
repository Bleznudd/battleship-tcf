//giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Grid.h"
#include "Point.h"
#include <string>

class Player{

private:

	static bool winning;
	Grid myGrid;
	string name;
	static int counter;

public:

	Player(string);
	Player();
	~Player();
	Grid* getGrid();
	string getName();
	static bool getWinning;
	void Attacked();	//ridondanza con Grid::Check()

};

#endif
