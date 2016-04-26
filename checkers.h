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
		return 0;
	}

	int can_move(Coord c, string direction, int index) { //checks if move is valid
		typedef vector<CPiece>::iterator iterator;
		char vert = direction.at(0);
		char lat = direction.at(1);
		if (turn == false) {
			if (vert == 'T') {
				if (lat == 'L') {
					Coord d = make_pair(c.first++, c.second--);
					for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
						if (it->has_coord(d)) {
							return -1;
						}
					}
					return 1;
				} else if (lat == 'R') {
					Coord d = make_pair(c.first++, c.second++);
					for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
						if (it->has_coord(d)) {
							return -2;
						}
					}
					return 2;
				}
			} else if (p1pieces[index].piece[c] == 1) {
				if (vert == 'B') {
					if (lat == 'L') {
						Coord d = make_pair(c.first--, c.second--);
						for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
							if (it->has_coord(d)) {
								return -3;
							}
						}
						return 3;
					} else if (lat == 'R') {
						Coord d = make_pair(c.first--, c.second++) {
						for (iterator it = p2pieces.being(); it != p2pieces.end(); it++) {
							if (it->has_coord(d)) {
								return -4;
							}
						}
						return 4;
					}
				}
			}
		} else if (turn == true) {
			if (vert == 'T') {
                                if (lat == 'L') {
                                        Coord d = make_pair(c.first--, c.second++);
                                        for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                if (it->has_coord(d)) {
                                                        return -10;
                                                }
                                        }
                                        return 10;
                                } else if (lat == 'R') {
                                        Coord d = make_pair(c.first--, c.second--);
                                        for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                if (it->has_coord(d)) {
                                                        return -20;
                                                }
                                        }
                                        return 20;
                                }
                        } else if (p2pieces[index].piece[c] == 1) {
                                if (vert == 'B') {
                                        if (lat == 'L') {
                                                Coord d = make_pair(c.first++, c.second++);
                                                for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                        if (it->has_coord(d)) {
                                                                return -30;
                                                        }
                                                }
                                                return 30;
					} else if (lat == 'R') {
                                                Coord d = make_pair(c.first++, c.second--) {
                                                for (iterator it = p1pieces.being(); it != p1pieces.end(); it++) {
                                                        if (it->has_coord(d)) {
                                                                return -40;
                                                        }
                                                }
                                                return 40;
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
				Coord e = make_pair(d.first++, d.second--);
				temp = can_move(e, direction, index);
				if (temp == 1) {
					return 1;
				}
				return 0;
			} else if (dir == -2) { //tr
				Coord e = make_pair(d.first++, d.second++);
				temp = can_move(e, direction, index);
				if (temp == 2) {
					return 2;
				}
				return 0;
			} else if (dir == -3) { //bl
				Coord e = make_pair(d.first--, d.second--);
				temp = can_move(e, direction, index);
				if (temp == 3) {
					return 3;
				}
				return 0;
			} else if (dir == -4) { //br
				Coord e = make_pair(d.first--, d.second++);
				temp = can_move(e, direction, index);
				if (temp == 4) {
					return 4;
				}
				return 0;
			}
		} else if (turn == true) { //player 2
			if (dir == -10) { //tl
                                Coord e = make_pair(d.first--, d.second++);
                                temp = can_move(e, direction, index);
                                if (temp == 10) {
                                        return -1;
                                }
                                return 0;
                        } else if (dir == -20) { //tr
                                Coord e = make_pair(d.first--, d.second--);
                                temp = can_move(e, direction, index);
                                if (temp == 20) {
                                        return -2;
                                }
                                return 0;
                        } else if (dir == -30) { //bl
                                Coord e = make_pair(d.first++, d.second--);
                                temp = can_move(e, direction, index);
                                if (temp == 30) {
                                        return -3;
                                }
                                return 0;
                        } else if (dir == -40) { //br
                                Coord e = make_pair(d.first++, d.second--);
                                temp = can_move(e, direction, index);
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
		direction = toupper(direction);
		if (turn == false) { //p1piece
			int index = check_coord(d, 0);
			int mv = can_move(d, direction, index);
			int jump = can_jump(d, direction, index);
			if (mv > 0 && jump == 0) { //move it
				if (mv == 1) { // tl
				} else if (mv == 2) { // tr
				} else if (mv == 3) { // bl
				} else if (mv == 4) { // br
			}
			if (jump != 0 && mv == 0) { //jump it
				if (jump == 1) { //tl
				} else if (jump == 2) { //tr
				} else if (jump == 3) { //bl
				} else if (jump == 4) { //br
				}
			}
		} else if (turn == true) { //p2piece
			int index = check_coord(d, 1);
		}
	//check win




	vector<CPiece> p1pieces;
	vector<CPiece> p2pieces;

};

#endif
