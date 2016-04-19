#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <array>

using namespace std;
//typedef array<Coord, int> ship;
class BattleshipGame: public Game {
public:
	BattleshipGame(array<Coord, 5> p1ship, array<Coord, 5> p2ship): Game(), board() {
		if (check_size(p1ship, p2ship) && check_same(p1ship, p2ship) && check_bounds(p1ship, p2ship)) {
			for (int i=0; i<10; i++){
				for (int j=0; j<10; j++){
					for (int k=0; k<5; k++){
						if(i==p1ship[k].first && j==p1ship[k].second){
							board.bsarray1[i][j] = 'S';
						}
						if(i==p2ship[k].first && j==p2ship[k].second){
							board.bsarray2[i][j] = 'S';
						}
					}
				}
			}
		}
	}
	bool check_size(array<Coord, 5> p1ship, array<Coord, 5> p2ship) {
		int size1 = sizeof(p1ship)/8;
                int size2 = sizeof(p2ship)/8;
                if (size1 != 5 || size2 != 5) {
                        cout << "Not the right number of ships present." << endl;
			return false;
                }
		return true;
	}

	bool check_same(array<Coord, 5> p1ship, array<Coord, 5> p2ship) {
		for (int i = 0; i < 5; i++) {
                        for (int j = i+1; j < 5; j++) {
                                if (p1ship[i] == p1ship[j] || p2ship[i] == p2ship[j]) {
                                        cout << "Invalid: at least two ships on same spot." << endl;
                                        return false;
                                }
                        }
                }
		return true;
	}

	bool check_bounds(array<Coord, 5> p1ship, array<Coord, 5> p2ship) {
		int count = 0;
                for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 5; j++) {
                                if (p1ship[j].first == i) {
                                        count++;
                                }
                                if (p1ship[j].second == i) {
                                        count++;
                                }
                                if (p2ship[j].first == i) {
                                        count++;
                                }
                                if (p2ship[j].second == i) {
                                        count++;
                                }
                        }
                }
                if (count != 20) {
                        cout << "At least one ship out of bounds." << endl;
                        return false;
                }
		return true;
	}

	GameResult attack_square(Coord d) {
		if (turn==false) {
			if (board.bsarray2[d.first][d.second] == '-') {
				board.bsarray2[d.first][d.second] = 'O';
				if (check_win()) {
					return RESULT_PLAYER1_WINS;
				}
				toggle();
				return RESULT_KEEP_PLAYING;
			} else if (board.bsarray2[d.first][d.second] == 'S') {
				board.bsarray2[d.first][d.second] = 'X';
				if (check_win()) {
                                        return RESULT_PLAYER1_WINS;
                                }
				toggle();
				return RESULT_KEEP_PLAYING;
			} else if (board.bsarray2[d.first][d.second] == 'X' || board.bsarray2[d.first][d.second] == 'O') {
				return RESULT_INVALID;
			}
		} else {
			if (board.bsarray1[d.first][d.second] == '-') {
                                board.bsarray1[d.first][d.second] = 'O';
                                if (check_win()) {
                                        return RESULT_PLAYER2_WINS;
                                }
                                toggle();
                                return RESULT_KEEP_PLAYING;
                        } else if (board.bsarray1[d.first][d.second] == 'S') {
                                board.bsarray1[d.first][d.second] = 'X';
                                if (check_win()) {
                                        return RESULT_PLAYER2_WINS;
                                }
                                toggle();
                                return RESULT_KEEP_PLAYING;
                        } else if (board.bsarray1[d.first][d.second] == 'X' || board.bsarray1[d.first][d.second] == 'O') {
                                return RESULT_INVALID;
                        }
			//return RESULT_INVALID;
		}
		return RESULT_INVALID;
	}
	bool check_win() {
		if (turn == false) {
			for (int i=0; i<10; i++){
                        	for (int j=0; j<10; j++){
					if (board.bsarray2[i][j]=='S') {
						return false;
					}
				}
			}
		} else {
                        for (int i=0; i<10; i++){
                                for (int j=0; j<10; j++){
                                        if (board.bsarray1[i][j]=='S') {
                                                return false;
                                        }
                                }
                        }
                }
		return true;
	}

private:
	Board board;
};

#endif
