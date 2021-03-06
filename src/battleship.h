#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <array>
#include <map>
#include "ships.h"

//typedef array<Coord, int> ship;

class BattleshipGame: public Game {
public:
//	BattleshipGame(): board1(), board2(), fleet1(), fleet2() {}
	BattleshipGame();
//	BattleshipGame(): Game(), fleet1(), fleet2() {};
	int check_coord(Coord c, int whoseShips); //check if coord is present

	GameResult attack_square(Coord d); //attack a certain coord

	bool check_win(); //check if game was won

	std::vector<Ship> fleet1; //vector of player 1's ships
	std::vector<Ship> fleet2;// ^^^ for player2
};

class  BattleshipBoard: public Board {
public:
	BattleshipBoard();

private:
	char bsarray[10][10];
};

#endif
