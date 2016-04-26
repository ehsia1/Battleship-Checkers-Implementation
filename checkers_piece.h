#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H

#include "piece.h"
#include "game.h"
#include <map>

using namespace std;

class CPiece: public Piece {
public:
	CPiece(Coord c) {
		piece.fisrt = c;
		piece.second = 0; //0 if not king
	}

	int checkKing() {
		return piece.second;
	}

	void makeKing() {
		piece.second = 1;
	}

	int has_coord(Coord c) {
		if (piece.first == c) {
			return 1;
		}
		return 0;
	}

	pair<Coord, int> piece;

};
#endif
