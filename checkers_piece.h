#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H

#include "piece.h"
#include "game.h"
#include <map>

using namespace std;

class CPiece: public Piece {
public:
	CPiece(Coord c) {
		piece[c] = 0; //0 if not king
	}

	int checkKing(Coord c, int counter, bool turn) {
		if (turn == false) {
			if (c.first == 7) {
				counter++;
			}
		}

		if (turn == true) {
			if (c.first == 0) {
				counter++;
			}
		}
		return counter;
	}

	bool makeKing(int counter) { // if true then change map to 1
		if (counter > 0) {
			return true;
		} else {
			return false;
		}
	}
private:
	map<Coord, int> piece;
};
#endif
