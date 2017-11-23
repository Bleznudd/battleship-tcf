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

public:

	Player(string );
	~Player();

	Grid getGrid();
	string getName();
	static bool getWinning;
	void Attack(Point);

};

#endif
