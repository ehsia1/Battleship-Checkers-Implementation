
/*Rohan Tilva
Willie Franceschi
Evan Hsia*/

#include <iostream>
#include <cassert>
#include <vector>
#include "checkers.h"
#include "checkers_piece.h"
#include "piece.h"

using namespace std;

void game1() {
	CheckersGame ckgame;
//	make_ckgame(ckgame);

	GameResult result = ckgame.attack_square(make_pair(2, 5), "TR");
	assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(9, 9), "TR");
        assert(result == RESULT_INVALID); //p2 turn; off the board
	result = ckgame.attack_square(make_pair(1, 2), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(3, 4), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(5, 2), "BR");
        assert(result == RESULT_INVALID); //p2 turn; gives invalid because have to jump another piece
	result = ckgame.attack_square(make_pair(0, 1), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; jumped a piece
	result = ckgame.attack_square(make_pair(6, 5), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(3, 2), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(5, 6), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(4, 1), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(3, 9), "BR");
        assert(result == RESULT_INVALID); //p1 turn invalid move because cant move that piece in that direction
	result = ckgame.attack_square(make_pair(4, 7), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(2, 3), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(0, 5), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; double jumps p2 pieces cause he's a boss
	result = ckgame.attack_square(make_pair(2, 3), "TR");
	assert(result == RESULT_KEEP_PLAYING); //p1 turn; double jump
	result = ckgame.attack_square(make_pair(5, 0), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(-4, 9), "BR");
        assert(result == RESULT_INVALID); //p1 turn; invalid off the board
	result = ckgame.attack_square(make_pair(6, 5), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(1, 0), "BL");
        assert(result == RESULT_INVALID); //p2 turn; invalid because you have to double jump the player1's piece
	result = ckgame.attack_square(make_pair(4, 3), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn first jump
	result = ckgame.attack_square(make_pair(6, 5), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn second jump
	result = ckgame.attack_square(make_pair(4, 7), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; third jump
	result = ckgame.attack_square(make_pair(1, 7), "BR");
        assert(result == RESULT_INVALID); //p1 turn; invalid there isnt a piece there lol
	result = ckgame.attack_square(make_pair(1, 6), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(3, 0), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(0, 7), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(5, 2), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(7, 4), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn this is first jump
	result = ckgame.attack_square(make_pair(5, 2), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn this is second jump
	result = ckgame.attack_square(make_pair(3, 0), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn this is third jump, after it has been crowned a king
	result = ckgame.attack_square(make_pair(6, 1), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(-4, -5), "BR");
        assert(result == RESULT_INVALID); //p1 turn invalid turn
	result = ckgame.attack_square(make_pair(3, 4), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(3, 2), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn this is the first jump
	result = ckgame.attack_square(make_pair(5, 4), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn this is the second jump
	result = ckgame.attack_square(make_pair(1, 6), "BL");
        assert(result == RESULT_INVALID); //p1 turn invalid; this tests that the player 1 pieces cannot move backwards unless they are a king
	result = ckgame.attack_square(make_pair(2, 7), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; jump
	result = ckgame.attack_square(make_pair(7, 2), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(7, 6), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(6, 3), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(4, 5), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn this is the first jump
	result = ckgame.attack_square(make_pair(6, 3), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn this is the second jump
	result = ckgame.attack_square(make_pair(1, 0), "BR");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(1, 2), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(7, 0), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(6, 5), "TL");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = ckgame.attack_square(make_pair(6, 1), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(4, 1), "TR");
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; got crowned
	result = ckgame.attack_square(make_pair(5, 2), "BL");
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = ckgame.attack_square(make_pair(5, 4), "TL");
        assert(result == RESULT_PLAYER1_WINS); //p1 turn
}
int main() {
	game1();
	cout << "It works god bless America" << endl;

}
