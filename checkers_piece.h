#ifndef CHECKERS_PIECE_H
#define CHECKERS_PIECE_H

#include "piece.h"
#include "game.h"
#include <map>
#include <iostream>

using namespace std;

class CPiece: public Piece {
public:
	CPiece(Coord c); //constructor

	int checkKing(); //check if a piece is a king

	void makeKing(); //change the int

	int has_coord(Coord c); //check if spot has coord given

	int check_jumped(); //see if piece was jumped

	Coord get_coord(); //return coordinate

	void jumped(); //place off the board

	int move(int dir, int num); //move the piece

	void print();
private:
	pair<Coord, int> loc;

};
#endif
