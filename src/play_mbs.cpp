#include "battleship.h"
#include "mobile.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void game1()
{
	Mobile mbs;
	Ship temp(5, make_pair(0,0), 'v');
        mbs.fleet1.push_back(temp);
        Ship temp1(4, make_pair(1, 1), 'h');
        mbs.fleet1.push_back(temp1);
        Ship temp2(3, make_pair(2, 2), 'v');
        mbs.fleet1.push_back(temp2);
        Ship temp3(3, make_pair(5, 5), 'v');
        mbs.fleet1.push_back(temp3);
        Ship temp4(2, make_pair(7, 3), 'h');
        mbs.fleet1.push_back(temp4);

        Ship temp5(5, make_pair(0,0), 'v');
        mbs.fleet2.push_back(temp5);
        Ship temp6(4, make_pair(1, 1), 'h');
        mbs.fleet2.push_back(temp6);
        Ship temp7(3, make_pair(2, 2), 'v');
        mbs.fleet2.push_back(temp7);
        Ship temp8(3, make_pair(5, 5), 'v');
        mbs.fleet2.push_back(temp8);
        Ship temp9(2, make_pair(7, 3), 'h');
        mbs.fleet2.push_back(temp9);

	GameResult result = mbs.attack_square(make_pair(13, -11));
        assert(result == RESULT_INVALID); //p1 turn
        result = mbs.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(0, 0));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	bool moveGood = mbs.move(make_pair(0, 0), 3, 'd');
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(0, 0), 3, 'd');
        assert(moveGood == true); //p2 turn
	result = mbs.attack_square(make_pair(0, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(0, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(0, 5));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(0, 5));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(0, 6));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(0, 6));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	moveGood = mbs.move(make_pair(0, 3), 5, 'u'); //bad move
        assert(moveGood == false); //p1 turn
	moveGood = mbs.move(make_pair(0, 3), 9, 'd'); // bad move
        assert(moveGood == false); //p1 turn
	moveGood = mbs.move(make_pair(0, 3), 2, 'u');
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(0, 3), 2, 'u');
        assert(moveGood == true); //p2 turn
	result = mbs.attack_square(make_pair(0, 5));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 aircraft carrier sunk
	result = mbs.attack_square(make_pair(0, 5));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 aircraft carrier sunk
	moveGood = mbs.move(make_pair(5, 5), 3, 'u');
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(5, 5), 3, 'u');
        assert(moveGood == true); //p2 turn
	moveGood = mbs.move(make_pair(2, 2), 2, 'u');
        assert(moveGood == false); //p1 turn; bad move because this moves one ship into another one
	result = mbs.attack_square(make_pair(8, 8));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; MISS
	result = mbs.attack_square(make_pair(9, 9));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; MISS
	moveGood = mbs.move(make_pair(7, 3), 1, 'r'); // right move works
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(7, 3), 1, 'r');
        assert(moveGood == true); //p2 turn
	moveGood = mbs.move(make_pair(8, 3), 2, 'l'); //left move works
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(8, 3), 2, 'l');
        assert(moveGood == true); //p2 turn
	moveGood = mbs.move(make_pair(6, 3), 3, 'r'); //off the board, so does not work
        assert(moveGood == false); //p1 turn


	//I want to cry right about now. I also have a midterm to study for tomorrow, but instead I am doing this dammit



	result = mbs.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(1, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(2, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(2, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(3, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(3, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	moveGood = mbs.move(make_pair(1, 1), 2, 'l'); //this is off the board, so it should not work
        assert(moveGood == false); //p1 turn
	result = mbs.attack_square(make_pair(4, 1));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 battleship sunk
	result = mbs.attack_square(make_pair(4, 1));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 battleship sunk

	// tears. many tears

	moveGood = mbs.move(make_pair(2, 2), 2, 'd');
        assert(moveGood == true); //p1 turn
	moveGood = mbs.move(make_pair(2, 2), 2, 'd');
        assert(moveGood == true); //p2 turn
	result = mbs.attack_square(make_pair(2, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(2, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(2, 5));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn
	result = mbs.attack_square(make_pair(2, 5));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn
	result = mbs.attack_square(make_pair(2, 6));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 cruiser sunk
	result = mbs.attack_square(make_pair(2, 6));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 cruiser sunk

	//fuck

	result = mbs.attack_square(make_pair(0, 9));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; miss
	result = mbs.attack_square(make_pair(1, 9));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; miss
	moveGood = mbs.move(make_pair(6, 3), 2, 'l'); //does not work because conflicting spots for ships
        assert(moveGood == false); //p1 turn
	moveGood = mbs.move(make_pair(6, 3), 3, 'l');
        assert(moveGood == false); //p1 turn
	result = mbs.attack_square(make_pair(5, 2));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn;
	result = mbs.attack_square(make_pair(5, 2));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn;
	result = mbs.attack_square(make_pair(5, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn;
	result = mbs.attack_square(make_pair(5, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn;
	result = mbs.attack_square(make_pair(5, 4));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn; player 2 submarine sunk
	result = mbs.attack_square(make_pair(5, 4));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn; player 1 submarine sunk

	//fuck part 2
	result = mbs.attack_square(make_pair(6, 3));
        assert(result == RESULT_KEEP_PLAYING); //p1 turn;
	result = mbs.attack_square(make_pair(6, 3));
        assert(result == RESULT_KEEP_PLAYING); //p2 turn;
	result = mbs.attack_square(make_pair(7, 3));
        assert(result == RESULT_PLAYER1_WINS); //p1 turn; he fucking won. he did it

}


int main() {
	game1();
	cout << "game 1 works" << endl;

}
