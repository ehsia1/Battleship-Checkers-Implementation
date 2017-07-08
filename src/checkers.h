#ifndef CHECKERS_H
#define CHECKERS_H

#include "game.h"
#include "checkers_piece.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>

class CheckersGame: public Game {
public:
	CheckersGame();

	//insert functions
	int check_coord(Coord c, int whosePiece); //check to see if piece is there

	int can_move(Coord c, std::string direction, int index); //checks if move is valid

	//can jump
	int can_jump(Coord d, std::string direction, int index); //checks to see if jump is valid

	bool is_jump();

	//attack square (move)
	GameResult attack_square(Coord d, std::string direction);

	//check win
	bool check_win(); //all pieces removed for the player????

	void printp();

	std::vector<CPiece> p1pieces; //vector of all player 1's pieces
	std::vector<CPiece> p2pieces;// ^^ for player 2

};

class CheckersBoard: public Board {
public:
        CheckersBoard(); //constructor

private:
        char ckarray[8][8];
};

#endif
