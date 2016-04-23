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

using namespace std;
//typedef array<Coord, int> ship;

class BattleshipGame: public Game {
public:
//	BattleshipGame(): board1(), board2(), fleet1(), fleet2() {}
	BattleshipGame(): Game(), fleet1(), fleet2() {}
	int check_coord(Coord c, int whoseShips) {
		if (whoseShips == 0) {
			int counter = 0;
			typedef vector<Ship>:: iterator iterator;
			for (iterator it=fleet1.begin(); it!=fleet1.end(); it++) {
				int index = (*it).has_coord(c);
				if (index >= 0){
					return counter;
				}
				counter++;
			}
			return -1;

		}
		if (whoseShips == 1) {
                        int counter = 0;
                        typedef vector<Ship>:: iterator iterator;
                        for (iterator it=fleet2.begin(); it!=fleet2.end(); it++) {
                                int index = (*it).has_coord(c);
                                if (index >= 0){
                                        return counter;
                                }
                                counter++;
                        }
                        return -1;

                }
		return -1;
	}

	GameResult attack_square(Coord d) {
		if (turn==false) { //player 1 turn
			if (d.first < 0 || d.first > 9 || d.second < 0 || d.second > 9) {
				cout << "INVALID MOVE" << endl;
                                return RESULT_INVALID;
                        }
			int is_hit = check_coord(d, 1);
			if (is_hit >= 0) {
				if (check_win()) {
                                cout << "PLAYER 1 WON" << endl;
                                return RESULT_PLAYER1_WINS;
                        	}
				if (fleet2[is_hit].is_sunk()) {
					cout << "SUNK" << fleet2[is_hit].get_name() << endl;
					toggle();
					fleet2[is_hit].sink();
					return RESULT_KEEP_PLAYING;

				}
				cout << "Hit!" << endl;
				int st = fleet2[is_hit].has_coord(d);
				fleet2[is_hit].hit(st);
				//
				toggle();
				return RESULT_KEEP_PLAYING;
			}
			cout << "MISS" << endl;
			toggle();
			return RESULT_KEEP_PLAYING;
		} else {
			if (d.first < 0 || d.first > 9 || d.second < 0 || d.second > 9) {
                                cout << "INVALID MOVE" << endl;
                                return RESULT_INVALID;
                        }
                        int is_hit = check_coord(d, 1);
                        if (is_hit >= 0) {
                                if (check_win()) {
                                cout << "PLAYER 2 WON" << endl;
                                return RESULT_PLAYER2_WINS;
                                }
                                if (fleet1[is_hit].is_sunk()) {
                                        cout << "SUNK" << fleet1[is_hit].get_name() << endl;
                                        toggle();
					fleet1[is_hit].sink();
                                        return RESULT_KEEP_PLAYING;

                                }
                                cout << "Hit!" << endl;
                                int st = fleet1[is_hit].has_coord(d);
                                fleet1[is_hit].hit(st);
                                //
                                toggle();
                                return RESULT_KEEP_PLAYING;
                        }
                        cout << "MISS" << endl;
                        toggle();
                        return RESULT_KEEP_PLAYING;
		}
	}
	bool check_win() {
		typedef vector<Ship>::iterator iterator;
		int counter = 0;
		if (turn == false) {
			for (iterator it = fleet2.begin(); it != fleet2.end(); it++ ) {
				if (it->is_sunk() == 1) {
					counter++;
				}
			}
			if (counter == 5) {
				return true;
			}
		} else {
			for (iterator it = fleet1.begin(); it != fleet1.end(); it++ ) {
                                if (it->is_sunk() == 1) {
                                        counter++;
                                }
                        }
                        if (counter == 5) {
                                return true;
                        }
                }
		return false;
	}

	vector<Ship> fleet1;
	vector<Ship> fleet2;
};

class  BattleshipBoard: public Board {
	BattleshipBoard() {
		for (int i=0;i<10;i++) {
			for (int l=0;l<10;l++) {
				bsarray[i][l] = '-';
			}
		}
	}
private:
	char bsarray[10][10];
};

#endif
