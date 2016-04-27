#include "battleship.h"
#include "mobile.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void game1()
{
	BattleshipGame bsg;
	Ship temp(5, make_pair(0,0), 'h');
	bsg.fleet1.push_back(temp);
	Ship temp1(4, make_pair(1, 1), 'h');
	bsg.fleet1.push_back(temp1);
	Ship temp2(3, make_pair(2, 2), 'h');
	bsg.fleet1.push_back(temp2);
	Ship temp3(3, make_pair(3, 3), 'h');
        bsg.fleet1.push_back(temp3);
	Ship temp4(2, make_pair(4, 4), 'h');
        bsg.fleet1.push_back(temp4);

        Ship temp5(5, make_pair(0,0), 'h');
        bsg.fleet2.push_back(temp5);
        Ship temp6(4, make_pair(1, 1), 'h');
        bsg.fleet2.push_back(temp6);
        Ship temp7(3, make_pair(2, 2), 'h');
        bsg.fleet2.push_back(temp7);
        Ship temp8(3, make_pair(3, 3), 'h');
        bsg.fleet2.push_back(temp8);
        Ship temp9(2, make_pair(4, 4), 'h');
        bsg.fleet2.push_back(temp9);

	GameResult result = bsg.attack_square(make_pair(10, 11));
	assert(result == RESULT_INVALID);
	result = bsg.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(1, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(-3, -5));
        assert(result == RESULT_INVALID); //p2 turn
	result = bsg.attack_square(make_pair(1, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(2, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(2, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(3, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(3, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(4, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 aircraft carrier sunk
	result = bsg.attack_square(make_pair(4, 0));
        assert(result == RESULT_KEEP_PLAYING);//p2 turn; player 1 aircraft carrier sunk
	result = bsg.attack_square(make_pair(9, 9));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; miss
	result = bsg.attack_square(make_pair(9, 9));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; miss
	result = bsg.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(9, 8));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; miss
	result = bsg.attack_square(make_pair(9, 8));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; miss
	result = bsg.attack_square(make_pair(2, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(2, 1));
        assert(result == RESULT_KEEP_PLAYING);//p2 turn
	result = bsg.attack_square(make_pair(-5, 11));
        assert(result == RESULT_INVALID); //p1 fucked up his coordinates lol 
	result = bsg.attack_square(make_pair(3, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(3, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(4, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 battleship sunk
	result = bsg.attack_square(make_pair(4, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 battleship sunk
	result = bsg.attack_square(make_pair(2, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(2, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(3, 2));
        assert(result == RESULT_KEEP_PLAYING);//p1 turn
	result = bsg.attack_square(make_pair(3, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(4, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn //playter 2 cruiser sunk
	result = bsg.attack_square(make_pair(4, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 cruiser sunk
	result = bsg.attack_square(make_pair(19, 10));
        assert(result == RESULT_INVALID); //p1 really having trouble with his coordinates lol. do we need to go back to elementary school?
	result = bsg.attack_square(make_pair(3, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; try again bud. you can do it
	result = bsg.attack_square(make_pair(3, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(4, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(4, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(5, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; p2 submarine sunk
	result = bsg.attack_square(make_pair(5, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; p2 submarine sunk
	result = bsg.attack_square(make_pair(4, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(4, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(5, 4));
        assert(result == RESULT_PLAYER1_WINS); //p1 WINS CUZ HE's FUCKING AWesOme LoL I'm losing my mind
}

void game2() {

	BattleshipGame bsg;
        Ship temp(5, make_pair(0,0), 'v');
        bsg.fleet1.push_back(temp);
        Ship temp1(4, make_pair(1, 1), 'v');
        bsg.fleet1.push_back(temp1);
        Ship temp2(3, make_pair(2, 2), 'v');
        bsg.fleet1.push_back(temp2);
        Ship temp3(3, make_pair(3, 3), 'v');
        bsg.fleet1.push_back(temp3);
        Ship temp4(2, make_pair(4, 4), 'v');
        bsg.fleet1.push_back(temp4);

        Ship temp5(5, make_pair(0,0), 'v');
        bsg.fleet2.push_back(temp5);
        Ship temp6(4, make_pair(1, 1), 'v');
        bsg.fleet2.push_back(temp6);
        Ship temp7(3, make_pair(2, 2), 'v');
        bsg.fleet2.push_back(temp7);
        Ship temp8(3, make_pair(3, 3), 'v');
        bsg.fleet2.push_back(temp8);
        Ship temp9(2, make_pair(4, 4), 'v');
        bsg.fleet2.push_back(temp9);

	GameResult result = bsg.attack_square(make_pair(99, 66));
        assert(result == RESULT_INVALID); //p1 turn
        result = bsg.attack_square(make_pair(8, 8));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; he missed lol
        result = bsg.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
        result = bsg.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
        result = bsg.attack_square(make_pair(-8, -9));
        assert(result == RESULT_INVALID); //p2 turn
        result = bsg.attack_square(make_pair(0, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
        result = bsg.attack_square(make_pair(0, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
        result = bsg.attack_square(make_pair(0, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
        result = bsg.attack_square(make_pair(0, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
        result = bsg.attack_square(make_pair(0, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
        result = bsg.attack_square(make_pair(0, 3));
	assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(8, 5));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(9, 6));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(0, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 aircraft carrier sunk
        result = bsg.attack_square(make_pair(0, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 aircraft carrier sunk
	result = bsg.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(7, 7));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; miss
	result = bsg.attack_square(make_pair(8, 7));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; miss
	result = bsg.attack_square(make_pair(1, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(1, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(1, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(1, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(1, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 battleship sunk
	result = bsg.attack_square(make_pair(1, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 battleship sunk


	//UPDATE: getting very tired. eyelid's drooping. coffee is needed. also about 10% of extra credit maybe

	result = bsg.attack_square(make_pair(2, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(2, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(2, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(2, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(2, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 cruiser sunk
	result = bsg.attack_square(make_pair(2, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 cruiser sunk

	//just had coffee, feeling lit AF right now.

	result = bsg.attack_square(make_pair(3, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(3, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(-9, -11));
        assert(result == RESULT_INVALID); //p2 turn
	result = bsg.attack_square(make_pair(3, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(3, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(3, 5));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 submarine sunk
	result = bsg.attack_square(make_pair(3, 5));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 submarine sunk
	result = bsg.attack_square(make_pair(4, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = bsg.attack_square(make_pair(4, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = bsg.attack_square(make_pair(4, 5));
        assert(result == RESULT_PLAYER2_WINS); //p2 turn; PLAYER 2 WINS THE GAME
}

int main() {
	game1(); //yay!!!!!!
	cout << "Hahaha yoooo game1 works" <<endl;
	game2();
	cout << "game2 works too. Can we get 100% yet?" << endl;
}
