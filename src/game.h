/*
Rohan Tilva,Evan Hsia, William Franceschi
wfrance2@jhu.edu
HW5
*/
#ifndef GAME_H
#define GAME_H

/*
 * Use this file as a *starting point*.  You may add more classes and other
 * definitions here.
 *
 * We have suggested a couple ideas (Board and Game) for base classes you can
 * use in your design.
 *
 * Implement derived types for the games in "battleship.h" and "tictactoe.h"
 *
 * You must use "enum GameResult" and "Coord" as defined here, and you must
 * implement derived types called BattleshipGame and TicTacToeGame, each with
 * a public attack_square member function, as you can see from reading
 * play_bs.cpp and play_ttt.cpp.
 */

#include <utility>

enum GameResult {
	RESULT_KEEP_PLAYING, // turn was valid and game is not over yet
	RESULT_INVALID,      // turn was invalid; e.g. attacked square
	                     // was attacked previously
	RESULT_STALEMATE,    // game over, neither player wins
	RESULT_PLAYER1_WINS, // game over, player 1 wins
	RESULT_PLAYER2_WINS  // game over, player 2 wins
};

typedef std::pair<int, int> Coord;

class Board {
public:
	Board() {}
}; //end Board

class Game {
public:
	Game(): turn(false) {
	}

	void toggle() { //changes the turn
		turn = !turn;
	}

	bool turn;
}; //end Game

#endif
