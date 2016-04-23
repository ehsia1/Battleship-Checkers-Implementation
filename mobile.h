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
#include "ships.h"
#include "battleship.h"

class Mobile: public BattleshipGame {
public:
	Mobile(): BattleshipGame() {}
	bool move(Coord c, int num, char dir){
		if (num>3 || num<-3){
			return false;
		}
		if (turn==false){
			int str = check_coord(c,0);
			if (str<0){
				return false;
			}
			if (fleet1[str].shift(num, dir)){
				return true;
			}
			return false;
		}
		else if (turn==true){
			int str = check_coord(c, 1);
			if (str<0){
				return false;
			}
			if (fleet2[str].shift(num, dir)){
				return true;
			}
			return false;
		}
		return false;
	}
};

#endif

