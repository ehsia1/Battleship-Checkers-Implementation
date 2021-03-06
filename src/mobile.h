/*
william Franceschi
Rohan Tilva
Evan Hsia
final project*/

#ifndef MOBILE_H
#define MOBILE_H

#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <array>
#include <map>
#include <cctype>
#include "ships.h"
#include "battleship.h"

class Mobile: public BattleshipGame {
public:
	Mobile(); //constructor 

	bool move(Coord c, int num, char dir); //moves ship
};

#endif

