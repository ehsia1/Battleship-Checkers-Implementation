#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <array>
#include <map>
#include "ships.h"
#include "battleship.h"
using namespace std;

	BattleshipGame::BattleshipGame(): Game(), fleet1(), fleet2() {} //constructor which initializes some sh*t
	int BattleshipGame::check_coord(Coord c, int whoseShips) { //check if coord present in fleet of ships
		if (whoseShips == 0) { //if player 2's turn
			int counter = 0;
			typedef vector<Ship>:: iterator iterator;
			for (iterator it=fleet1.begin(); it!=fleet1.end(); it++) {
				int index = (*it).has_coord(c);
				if (index >= 0){
					return counter; //return counter if found
				}
				counter++;
			}
			return -1;

		}
		if (whoseShips == 1) { //
                        int counter = 0; //if player 1's turn
                        typedef vector<Ship>:: iterator iterator;
                        for (iterator it=fleet2.begin(); it!=fleet2.end(); it++) {
                                int index = (*it).has_coord(c);
                                if (index >= 0){
                                        return counter; //if found
                                }
                                counter++;
                        }
                        return -1;

                }
		return -1;
	}

	GameResult BattleshipGame::attack_square(Coord d) { //attack the square with the given input
		if (turn==false) { //player 1 turn
			if (d.first < 0 || d.first > 9 || d.second < 0 || d.second > 9) { //if off the board
				cout << "INVALID MOVE" << endl;
                                return RESULT_INVALID;
                        }
			int is_hit = check_coord(d, 1);
			if (is_hit >= 0) {
                                int st = fleet2[is_hit].has_coord(d);
                                fleet2[is_hit].hit(st);
				if (fleet2[is_hit].is_sunk()) { //checks if all spots in ship were sunk
                                        cout << "SUNK " << fleet2[is_hit].get_name() << endl;
                                        toggle();
                                        fleet2[is_hit].sink();
					if (check_win()) {
						cout << "PLAYER 1 WON" << endl; //all the ships are sunk
						return RESULT_PLAYER1_WINS;
					}
                                        return RESULT_KEEP_PLAYING; //if not won, but still sunk
                                }else{
					cout << "Hit!" << endl; //if not sunk but hit
				}
/*				if (check_win()) { // should probably switch this order (hit then sunk then win)
                                cout << "PLAYER 1 WON" << endl;
                                return RESULT_PLAYER1_WINS;
                        	}
*/				//
				toggle(); //change turn
				return RESULT_KEEP_PLAYING;
			}
			cout << "MISS" << endl;
			toggle();
			return RESULT_KEEP_PLAYING;
		} else { //this is the same but for player 2; see the above comments
			if (d.first < 0 || d.first > 9 || d.second < 0 || d.second > 9) {
                                cout << "INVALID MOVE" << endl;
                                return RESULT_INVALID;
                        }
                        int is_hit = check_coord(d, 0);
                        if (is_hit >= 0) {
                                int st = fleet1[is_hit].has_coord(d);
                                fleet1[is_hit].hit(st);
				if (fleet1[is_hit].is_sunk()) {
                                        cout << "SUNK " << fleet1[is_hit].get_name() << endl;
                                        toggle();
                                        fleet1[is_hit].sink();
					if (check_win()) {
						cout << "PLAYER 2 WON" << endl;
						return RESULT_PLAYER2_WINS;
					}
                                        return RESULT_KEEP_PLAYING;
                                }
				else {
					cout << "Hit!" << endl;
				}
/*                                if (check_win()) {
                                cout << "PLAYER 2 WON" << endl;
                                return RESULT_PLAYER2_WINS;
                                }
*/                                //
                                toggle();
                                return RESULT_KEEP_PLAYING;
                        }
                        cout << "MISS" << endl;
                        toggle();
                        return RESULT_KEEP_PLAYING;
		}
	}
	bool BattleshipGame::check_win() { //check to see if all the ships are sunk
		typedef vector<Ship>::iterator iterator;
		int counter = 0;
		if (turn == true) {
			for (iterator it = fleet2.begin(); it != fleet2.end(); it++ ) {
				if (it->is_sunk()==1) { //if the specific ship is sunk then increment counter
					counter++;
				}
			}
			if (counter == 5) { //if all the ships are sunk
				return true;
			}
		} else { //same as above
			for (iterator it = fleet1.begin(); it != fleet1.end(); it++ ) {
                                if (it->is_sunk()==1) {
                                        counter++;
                                }
                        }
                        if (counter == 5) {
                                return true;
                        }
                }
		return false;
	}

	BattleshipBoard::BattleshipBoard() { //the board
		for (int i=0;i<10;i++) {
			for (int l=0;l<10;l++) {
				bsarray[i][l] = '-';
			}
		}
	}
