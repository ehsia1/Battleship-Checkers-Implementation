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
		typedef vector<CPiece>::iterator iterator;
		char vert = direction.at(0);
		char lat = direction.at(1);
		if (turn == true) {
			if (vert == 'B') {
				if (lat == 'L') {
					Coord d = make_pair(c.first--, c.second++);
					if (d.first < 0 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -110;
					}
					if (check_coord(d,0)>-1){
						return -10;
					}
					return 10;
				} else if (lat == 'R') {
					Coord d = make_pair(c.first++, c.second++);
					if (d.first > 7 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -220;
					}
					if (check_coord(d,2)>-1){
						return -20;
					}
					return 20;
				}
			} else if (p2pieces[index].check_king()) {
				if (vert == 'T') {
					if (lat == 'L') {
						Coord d = make_pair(c.first--, c.second--);
						if (d.first < 0 || d.second < 0){
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -330;
						}
						if (check_coord(d,0) > -1){
							return -30;
						}
						return 30;
					} else if (lat == 'R') {
						Coord d = make_pair(c.first++, c.second--);
						if (d.first > 7 || d.second < 0){
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -440;
						}
						if (check_coord(d,0) > -1){
							return -40;
						}
						return 40;
					}
				}
			}
		} else if (turn == false) {
			if (vert == 'T') {
                                if (lat == 'L') {
                                        Coord d = make_pair(c.first--, c.second--);
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
                                        Coord d = make_pair(c.first++, c.second--);
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
                        } else if (p1pieces[index].check_king()) {
                                if (vert == 'B') {
                                        if (lat == 'L') {
                                                Coord d = make_pair(c.first--, c.second++);
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
                                                Coord d = make_pair(c.first++, c.second++) {
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
		typedef vector<CPiece>::iterator iterator;
		if (turn == false) {
			if (dir == -1) { //tl
				Coord e = make_pair(d.first--, d.second--);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
				if (temp == 1) {
					return 1;
				}
				return 0;
			} else if (dir == -2) { //tr
				Coord e = make_pair(d.first++, d.second--);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
				if (temp == 2) {
					return 2;
				}
				return 0;
			} else if (dir == -3) { //bl
				Coord e = make_pair(d.first--, d.second++);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
				if (temp == 3) {
					return 3;
				}
				return 0;
			} else if (dir == -4) { //br
				Coord e = make_pair(d.first++, d.second++);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
				if (temp == 4) {
					return 4;
				}
				return 0;
			}
		} else if (turn == true) { //player 2
			if (dir == -10) { //bl
                                Coord e = make_pair(d.first--, d.second++);
                                temp = can_move(e, direction, index);
				if (temp==-1000){
					return //0?;
				}
                                if (temp == 10) {
                                        return -1;
                                }
                                return 0;
                        } else if (dir == -20) { //br
                                Coord e = make_pair(d.first++, d.second++);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
                                if (temp == 20) {
                                        return -2;
                                }
                                return 0;
                        } else if (dir == -30) { //tl
                                Coord e = make_pair(d.first--, d.second--);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
				}
                                if (temp == 30) {
                                        return -3;
                                }
                                return 0;
                        } else if (dir == -40) { //tr
                                Coord e = make_pair(d.first++, d.second--);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return //0?;
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
		direction = transform(direction.begin(), direction.end(), direction.begin(), toupper);
		if (turn == false) { //p1piece
			int index = check_coord(d, 0);
			if (index >= 0) {
				int mv = can_move(d, direction, index);
				if (mv == -1000){
					return //invalid move;
				}
				int jump = can_jump(d, direction, index);
				if (mv > 0) { //move it
					if (p1pieces[index].move(mv,1)==1){
						p1pieces[index].makeKing();
					}
					/*
					if (mv == 1) { // tl
						p1pieces[index].first.first--;
						p1pieces[index].first.second--;
					} else  if (mv == 2) { // tr
						p1pieces[index].first.first++;
						p1pieces[index].first.second--;
					} else if (mv == 3) { // bl
						p1pieces[index].first.first--;
						p1pieces[index].first.second++;
					} else if (mv == 4) { // br
						p1pieces[index].first.first++;
						p1pieces[index].first.second++;
					}*/
				}
				else if (jump != 0) { //jump it
					int oindex;
					if (p1pieces[index].move(jump,2)==1){
						p1pieces[index].makeKing();
					}
					p2pieces[oindex].jumped();
					/*
					if (jump == 1) { //tl
						p1pieces[index].first.first -=2;
						p1pieces[index].first.second -=2;
						oindex = check_coord(make_pair(d.first--,d.second--),1);
						jump(p2pieces[oindex]);
					} else if (jump == 2) { //tr
						p1pieces[index].first.first += 2;
						p1pieces[index].first.second -= 2;
						oindex = check_coord(make_pair(d.first++,d.second--),1);
						jump(p2pieces[oindex]);
					} else if (jump == 3) { //bl
						p1pieces[index].first.first -=2;
						p1pieces[index].first.second +=2;
						oindex = check_coord(make_pair(d.first--,d.second++),1);
						jump(p2pieces[oindex]);
					} else if (jump == 4) { //br
						p1pieces[index].first.first +=2;
						p1pieces[index].first.second -=2;
						oindex = check_coord(make_pair(d.first++,d.second--),1);
						jump(p2pieces[oindex]);
					}*/
				}
			}
		} else if (turn == true) { //p2piece
			int index = check_coord(d, 1);
			if (index >= 0) {
				int mv = can_move(d, direction, index);
				if (mv == -1000){
					return //invalid move;
				}
				int jump = can_jump(d, direction, index);
			        if (mv > 0) { //move it
					if (p2pieces[index].move(mv/10,1)==2){
						p2pieces[index].makeKing();
					}
					/*
                                        if (mv == 10) { // bl
                                                p2pieces[index].first.first--;
                                                p2pieces[index].first.second++;
                                        } else if (mv == 20) { // br
                                                p2pieces[index].first.first++;
                                                p2pieces[index].first.second++;
                                        } else if (mv == 30) { // tl
                                                p2pieces[index].first.first--;
                                                p2pieces[index].first.second--;
                                        } else if (mv == 40) { // tr
                                                p2pieces[index].first.first++;
                                                p2pieces[index].first.second--;
                                        }*/
                                }
				else if (jump != 0) { //jump it
                                        int oindex;
					if (p2pieces[index].move(jump*-1,2)==2){
						p2pieces[index].makeKing();
					}
					p1pieces[oindex].jumped();
					/*
                                        if (jump == -1) { //bl
                                                p2pieces[index].first.first -= 2;
                                                p2pieces[index].first.second +=2;
                                                oindex = check_coord(make_pair(d.first--,d.second++),0);
                                                jump(p1pieces[oindex]);
                                        } else if (jump == -2) { //br
                                                p2pieces[index].first.first += 2;
                                                p2pieces[index].first.second += 2;
                                                oindex = check_coord(make_pair(d.first++,d.second++),0);
                                                jump(p1pieces[oindex]);
                                        } else if (jump == -3) { //tl
                                                p2pieces[index].first.first -=2;
                                                p2pieces[index].first.second -=2;
                                                oindex = check_coord(make_pair(d.first--,d.second--),0);
                                                jump(p1pieces[oindex]);
                                        } else if (jump == -4) { //tr
                                                p2pieces[index].first.first +=2;
                                                p2pieces[index].first.second -=2;
                                                oindex = check_coord(make_pair(d.first++,d.second--),0);
						jump(p1pieces[oindex]);
                                        }
					*/
                                }

			}
		}
	//check win




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
