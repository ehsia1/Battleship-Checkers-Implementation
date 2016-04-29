#include "piece.h"
#include "game.h"
#include <map>
#include <iostream>
#include "checkers_piece.h"
using namespace std;

	CPiece::CPiece(Coord c) { //initialize coord for piece
		loc.first = c;
		loc.second = 0; //0 if not king
	}

	int CPiece::checkKing() { //check if king by returning int
		return loc.second;
	}

	void CPiece::makeKing() { //1 for king, 0 for not king
		loc.second = 1;
	}

	int CPiece::has_coord(Coord c) { //check if coord = spot in loc
		if (loc.first == c) {
			return 1;
		}
		return 0;
	}

	int CPiece::check_jumped(){ //if >0 then jumped
		return loc.second;
	}

	Coord CPiece::get_coord(){ //return coordinate
		return loc.first;
	}

	void CPiece::jumped(){ //if jumped then put it off the board
		loc.first.first = -1;
		loc.first.second = -1;
		loc.second = -1;
	}

	int CPiece::move(int dir, int num){ //move this piece
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

		if (loc.first.second==0){ //end of board
			return 1;
		}
		if (loc.first.second==7){ //end of board
			return 2;
		}
		return 0;

	}

	void CPiece::print() {  //print the map
		cout << "(" << loc.first.first << ", " << loc.first.second << ") king:"<< loc.second << endl;
	}
