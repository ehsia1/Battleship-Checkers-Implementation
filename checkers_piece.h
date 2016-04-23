#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H

#include <utility>
#include "piece.h"
#include "game.h"

using namespace std;

class CPiece: public Piece {
public:
	CPiece() {
		isKing = false;
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

	bool makeKing(int counter) {
		if (counter > 0) {
			return true;
		} else {
			return false;
		}
	}
private:
	bool isKing;
};
#endif
