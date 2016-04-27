#ifndef CHECKERS_H
#define CHECKERS_H

#include "game.h"
#include "checkers_piece.h"
#include <utility>
#include <vector>
using namespace std;


class CheckersGame: public Game {
public:
	CheckersGame(): Game(), p1pieces(), p2pieces() {}

	//insert functions
	int check_coord(Coord c, int whosePiece) { //check to see if piece is there
		int counter = 0;
		typedef vector<CPiece>::iterator iterator;
		if (whosePiece == 0) {
			for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
				if (it->has_coord(c)) {
					return counter;
				}
				counter++;
			}
		} else if (whosePiece == 1) {
			for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
				if (it->has_coord(c)) {
					return counter;
				}
				counter++;
			}
		}
		return -1;
	}

	int can_move(Coord c, string direction, int index) { //checks if move is valid
		char vert = direction.at(0);
		char lat = direction.at(1);
		if (turn == true) {
			if (vert == 'B') {
				if (lat == 'L') {
					Coord d = make_pair(c.first-1, c.second+1);
					if (d.first < 0 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -330;
					}
					if (check_coord(d,0)>-1){
						return -30;
					}
					return 30;
				} else if (lat == 'R') {
					Coord d = make_pair(c.first+1, c.second+1);
					if (d.first > 7 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -440;
					}
					if (check_coord(d,2)>-1){
						return -40;
					}
					return 40;
				}
			} else if (p2pieces[index].checkKing()) {
				if (vert == 'T') {
					if (lat == 'L') {
						Coord d = make_pair(c.first-1, c.second-1);
						if (d.first < 0 || d.second < 0){
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -110;
						}
						if (check_coord(d,0) > -1){
							return -10;
						}
						return 10;
					} else if (lat == 'R') {
						Coord d = make_pair(c.first+1, c.second-1);
						if (d.first > 7 || d.second < 0){
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -220;
						}
						if (check_coord(d,0) > -1){
							return -20;
						}
						return 20;
					}
				}
			}
		} else if (turn == false) {
			if (vert == 'T') {
                                if (lat == 'L') {
                                        Coord d = make_pair(c.first-1, c.second-1);
					if (d.first < 0 || d.second < 0){
						return -1000;
					}
					if (check_coord(d,0) > -1){
						return -11;
					}
					if (check_coord(d,1) > -1){
						return -1;
					}
                                        return 1;
                                } else if (lat == 'R') {
                                        Coord d = make_pair(c.first+1, c.second-1);
					if (d.first > 7 || d.second < 0){
						return -1000;
					}
					if (check_coord(d,0) > -1){
						return -22;
					}
					if (check_coord(d,1) > -1){
						return -2;
					}
                                        return 2;
                                }
                        } else if (p1pieces[index].checkKing()) {
                                if (vert == 'B') {
                                        if (lat == 'L') {
                                                Coord d = make_pair(c.first-1, c.second+1);
						if (d.first < 0 || d.second > 7){
							return -1000;
						}
						if (check_coord(d,0) > -1){
                                                	return -33;
						}
						if (check_coord(d,1) > -1){
							return -3;
						}
                                                return 3;
					} else if (lat == 'R') {
                                                Coord d = make_pair(c.first+1, c.second+1);
						if (d.first > 7 || d.second > 7){
							return -1000;
						}
						if (check_coord(d,0) > -1){
							return -44;
						}
						if (check_coord(d,1) > -1){
							return -4;
						}
                                                return 4;
                                        }
                                }
                        }
		}
		return 0;
	}
	//can jump
	int can_jump(Coord d, string direction, int index) {
		int dir = can_move(d, direction, index);
		int temp;
		if (turn == false) {
			if (dir == -1) { //tl
				Coord e = make_pair(d.first-1, d.second-1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 1) {
					return 1;
				}
				return 0;
			} else if (dir == -2) { //tr
				Coord e = make_pair(d.first+1, d.second-1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 2) {
					return 2;
				}
				return 0;
			} else if (dir == -3) { //bl
				Coord e = make_pair(d.first-1, d.second+1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 3) {
					return 3;
				}
				return 0;
			} else if (dir == -4) { //br
				Coord e = make_pair(d.first+1, d.second+1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 4) {
					return 4;
				}
				return 0;
			}
		} else if (turn == true) { //player 2
			if (dir == -10) { //tl
                                Coord e = make_pair(d.first-1, d.second-1);
                                temp = can_move(e, direction, index);
				if (temp==-1000){
					return 0;
				}
                                if (temp == 10) {
                                        return -1;
                                }
                                return 0;
                        } else if (dir == -20) { //tr
                                Coord e = make_pair(d.first+1, d.second-1);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
                                if (temp == 20) {
                                        return -2;
                                }
                                return 0;
                        } else if (dir == -30) { //bl
                                Coord e = make_pair(d.first-1, d.second+1);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
                                if (temp == 30) {
                                        return -3;
                                }
                                return 0;
                        } else if (dir == -40) { //br
                                Coord e = make_pair(d.first+1, d.second+1);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
                                if (temp == 40) {
                                        return -4;
                                }
                                return 0;
                        }
		}
		return 0;
	}

	//attack square (move)
	GameResult attack_square(Coord d, string direction) {
		if (turn == false) { //p1piece
			int index = check_coord(d, 0);
			if (index >= 0) {
				int mv = can_move(d, direction, index);
				if (mv == -1000){
					return RESULT_INVALID;//invalid move;
				}
				int jump = can_jump(d, direction, index);
				if (mv > 0) { //move it
					if (p1pieces[index].move(mv,1)==1){
						p1pieces[index].makeKing();
					}
					toggle();
				}
				else if (jump != 0) { //jump it
					int oindex = -1;
					if (p1pieces[index].move(jump,2)==1){
						p1pieces[index].makeKing();
					}

					if (jump == 1) { //tl
						oindex = check_coord(make_pair(d.first--,d.second--),1);
					} else if (jump == 2) { //tr
						oindex = check_coord(make_pair(d.first++,d.second--),1);
					} else if (jump == 3) { //bl
						oindex = check_coord(make_pair(d.first--,d.second++),1);
					} else if (jump == 4) { //br
						oindex = check_coord(make_pair(d.first++,d.second++),1);
					}
					if (oindex > -1) {
						p2pieces[oindex].jumped();
					}
				}
				if (check_win()) {
					return RESULT_PLAYER1_WINS;
				}
			}
		} else while (turn == true) { //p2piece
			int index = check_coord(d, 1);
			if (index >= 0) {
				int mv = can_move(d, direction, index);
				if (mv == -1000){
					return RESULT_INVALID; //invalid move;
				}
				int jump = can_jump(d, direction, index);
			        if (mv > 0) { //move it
					if (p2pieces[index].move(mv/10,1)==2){
						p2pieces[index].makeKing();
					}
					toggle();
                                }
				else if (jump != 0) { //jump it
                                        int oindex = -1;
					if (p2pieces[index].move(jump*-1,2)==2){
						p2pieces[index].makeKing();
					}

                                        if (jump == -1) { //tl
                                                oindex = check_coord(make_pair(d.first-1,d.second-1),0);
                                        } else if (jump == -2) { //tr
                                                oindex = check_coord(make_pair(d.first+1,d.second-1),0);
                                        } else if (jump == -3) { //bl
                                                oindex = check_coord(make_pair(d.first-1,d.second+1),0);
                                        } else if (jump == -4) { //br
                                                oindex = check_coord(make_pair(d.first+1,d.second+1),0);
                                        }
					if (oindex > -1) {
						p1pieces[oindex].jumped();
					}
					int cnt = 0;
					vector<String> dir;
					Coord p2temp = p2pieces[index].get_coord();
					if (can_jump(p2temp, "BL", index){
						cnt++;
						dir.push_back("BL");
					}
					if (can_jump(p2temp, "BR", index){
						cnt++;
						dir.push_back("BR");
					}
					if (p2pieces[index].checkKing()){
						if (can_jump(p2temp, "TL", index){
							cnt++;
							dir.push_back("TL");
						}
						if (can_jump(p2temp, "TR", index){
							cnt++;
							dir.push_back("TR");
						}
					}

					if (cnt>1){
						cout<<"Multiple Jumps Available, enter jump:(XYSS) "<<endl;
                                }
				if (check_win()) {
					return RESULT_PLAYER2_WINS;
				}
			}
		}
		return RESULT_KEEP_PLAYING;
	}
	//check win
	bool check_win() {
		typedef vector<CPiece>::iterator iterator;
		int counter = 0;
		if (turn == false) {
			for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
				if (it->check_jumped() == -1) {
					counter++;
				}
			}
		} else if (turn == true) {
			for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
				if (it->check_jumped() == -1) {
					counter++;
				}
			}
		}
		if (counter == 12) {
			return true;
		} else {
			return false;
		}
	}

	void printp() {
		typedef vector<CPiece>::iterator iterator;
		for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
			it->print();
		}
	}
	vector<CPiece> p1pieces;
	vector<CPiece> p2pieces;

};

class CheckersBoard: public Board {
public:
        CheckersBoard() {
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                                ckarray[i][j] = '-';
                        }
                }
        }
private:
        char ckarray[8][8];
};

#endif
