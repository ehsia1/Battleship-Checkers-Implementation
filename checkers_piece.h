#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H

#include "piece.h"
#include "game.h"
#include <map>

using namespace std;

class CPiece: public Piece {
public:
	CPiece(Coord c) {
		loc.fisrt = c;
		loc.second = 0; //0 if not king
	}

	int checkKing() {
		return loc.second;
	}

	void makeKing() {
		loc.second = 1;
	}

	int has_coord(Coord c) {
		if (loc.first == c) {
			return 1;
		}
		return 0;
	}

	int check_jumped(){
		return loc.second;
	}

	void jumped(){
		loc.first.first = -1;
		loc.first.second = -1;
		loc.second = -1;
	}

	void move(int dir, int num){
		if (dir == 1) { // tl
			loc.first.first-=num;
			loc.first.second-=num;
		} else  if (dir == 2) { // tr
			loc.first.first+=num;
			loc.first.second-=num;
		} else if (dir == 3) { // bl
			loc.first.first-=num;
			loc.first.second+=num;
		} else if (dir == 4) { // br
			loc.first.first+=num;
			loc.first.second+=num;
		}
	}

private:
	pair<Coord, int> loc;

};
#endif
