//giocatore

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Grid.h"
#include "Point.h"
#include <string>

class Player{

private:

	string name;

public:

	Player(string);
	Player();
	~Player();
	string getName();

};

#endif
