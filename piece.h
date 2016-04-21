#ifndef PIECE_H
#define PIECE_H

#include <utility>
#include "game.h"

class Piece {
public:

	Piece() {}

	virtual void move(int num, char direction) {
		num = num;
		direction = direction;
	}

	virtual int has_coord(Coord c) {
		int first = c.first;
		int second = c.second;
		int third = first + second;
		third = 1;
		return third;
	}

	virtual void hit(int h) {
		h = h;
	}

	virtual int is_sunk() {
		return 1;
	}

};

#endif
