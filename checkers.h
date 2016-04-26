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

	bool can_move(Coord c, string direction, int index) { //checks if move is valid
		typedef vector<CPiece>::iterator iterator;
		char vert = direction.at(0);
		char lat = direction.at(1);
		if (turn == false) {
			if (vert == 't') {
				if (lat == 'l') {
					Coord d = make_pair(c.first++, c.second--);
					for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
						if (it->has_coord(d)) {
							return false;
						}
					}
					return true;
				} else if (lat == 'r') {
					Coord d = make_pair(c.first++, c.second++);
					for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
						if (it->has_coord(d)) {
							return false;
						}
					}
					return true;
				}
			} else if (p1pieces[index].piece[c] == 1) {
				if (vert == 'b') {
					if (lat == 'l') {
						Coord d = make_pair(c.first--, c.second--);
						for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++) {
							if (it->has_coord(d)) {
								return false;
							}
						}
						return true;
					} else if (lat == 'r') {
						Coord d = make_pair(c.first--, c.second++) {
						for (iterator it = p2pieces.being(); it != p2pieces.end(); it++) {
							if (it->has_coord(d)) {
								return false;
							}
						}
						return true;
					}
				}
			}
		} else if (turn == true) {
			if (vert == 't') {
                                if (lat == 'l') {
                                        Coord d = make_pair(c.first--, c.second++);
                                        for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                if (it->has_coord(d)) {
                                                        return false;
                                                }
                                        }
                                        return true;
                                } else if (lat == 'r') {
                                        Coord d = make_pair(c.first--, c.second--);
                                        for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                if (it->has_coord(d)) {
                                                        return false;
                                                }
                                        }
                                        return true;
                                }
                        } else if (p2pieces[index].piece[c] == 1) {
                                if (vert == 'b') {
                                        if (lat == 'l') {
                                                Coord d = make_pair(c.first++, c.second++);
                                                for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
                                                        if (it->has_coord(d)) {
                                                                return false;
                                                        }
                                                }
                                                return true;
					} else if (lat == 'r') {
                                                Coord d = make_pair(c.first++, c.second--) {
                                                for (iterator it = p1pieces.being(); it != p1pieces.end(); it++) {
                                                        if (it->has_coord(d)) {
                                                                return false;
                                                        }
                                                }
                                                return true;
                                        }
                                }
                        }
		}
		return false;
	}
	//can jump
	//attack square (move)
	GameResult attack_square(Coord d, string direction) {
		direction = toupper(direction);
		
	//check win




	vector<CPiece> p1pieces;
	vector<CPiece> p2pieces;

};

#endif
