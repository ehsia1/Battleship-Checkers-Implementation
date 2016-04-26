#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include "game.h"

class Piece {
public:

	Piece() {}

	virtual bool shift(int num, char direction) {
		num = num;
		direction = direction;
		return true;
	}

	virtual int has_coord(Coord c) {
		int first = c.first;
		int second = c.second;
		int third = first + second;
		third = 1;
		return third;
	}

};

#endif
