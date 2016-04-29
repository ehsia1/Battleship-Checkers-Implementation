#include "piece.h"
#include "game.h"
#include <map>
#include <iostream>
#include "checkers_piece.h"
using namespace std;

	CPiece::CPiece(Coord c) {
		loc.first = c;
		loc.second = 0; //0 if not king
	}

	int CPiece::checkKing() {
		return loc.second;
	}

	void CPiece::makeKing() {
		loc.second = 1;
	}

	int CPiece::has_coord(Coord c) {
		if (loc.first == c) {
			return 1;
		}
		return 0;
	}

	int CPiece::check_jumped(){
		return loc.second;
	}

	Coord CPiece::get_coord(){
		return loc.first;
	}

	void CPiece::jumped(){
		loc.first.first = -1;
		loc.first.second = -1;
		loc.second = -1;
	}

	int CPiece::move(int dir, int num){
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

		if (loc.first.second==0){
			return 1;
		}
		if (loc.first.second==7){
			return 2;
		}
		return 0;

	}

	void CPiece::print() {
		cout << "(" << loc.first.first << ", " << loc.first.second << ") king:"<< loc.second << endl;
	}
