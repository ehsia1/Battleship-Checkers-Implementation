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

	void makeKing(int counter) {
		typedef map<Coord, int>::iterator iterator;
		if (counter > 0) {
			for (iterator it = piece.begin(); it != piece.end(); it++) {
				it->second = 1;
			}
		} else {
			return;
		}
	}

private:
	map<Coord, int> piece;
};
#endif
