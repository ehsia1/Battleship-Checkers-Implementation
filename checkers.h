#ifndef CHECKERS_H
#define CHECKERS_H

#include "game.h"
#include "checkers_piece.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class CheckersGame: public Game {
public:
	CheckersGame();

	//insert functions
	int check_coord(Coord c, int whosePiece); //check to see if piece is there

	int can_move(Coord c, string direction, int index); //checks if move is valid

	//can jump
	int can_jump(Coord d, string direction, int index); //checks to see if jump is valid

	bool is_jump();

	//attack square (move)
	GameResult attack_square(Coord d, string direction);

	//check win
	bool check_win();

	void printp();

	vector<CPiece> p1pieces;
	vector<CPiece> p2pieces;

};

class CheckersBoard: public Board {
public:
        CheckersBoard();

private:
        char ckarray[8][8];
};

#endif
