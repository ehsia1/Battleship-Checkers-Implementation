#include "game.h"
#include "checkers_piece.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "checkers.h"
using namespace std;

	CheckersGame::CheckersGame(): Game(), p1pieces(), p2pieces() {} //constructor for checkers game

	int CheckersGame::check_coord(Coord c, int whosePiece) { //check to see if piece is there
		int counter = 0;
		typedef vector<CPiece>::iterator iterator;
		if (whosePiece == 0) {	//whosepiece tell fxn whose pieces to check
			for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
				if (it->has_coord(c)) {
					return counter; //index of piece in vector is returned
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
		return -1; //if no piece has coordinate, -1 is returned
	}

	int CheckersGame::can_move(Coord c, string direction, int index) { //checks if move from a coordinate in a direction is valid
		char vert = direction.at(0);
		if (vert != 'B' && vert != 'T'){ //if direction input is bad
			return 0;
		}
		char lat = direction.at(1);
		if (lat != 'R' && lat != 'L'){
			return 0;
		}
		if (turn == true) { //player 2 turn cases
			if (vert == 'B') {
				if (lat == 'L') {
					Coord d = make_pair(c.first-1, c.second+1); //occupancy state of coordinate is checked
					if (d.first < 0 || d.second > 7){ //move is off the board
						return -1000;
					}
					if (check_coord(d,1)>-1){ //player two has a piece there
						return -1000;
					}
					if (check_coord(d,0)>-1){ //player one has a piece there (leaves possibility of jumping available)
						return -30;
					}
					return 30;
				} else if (lat == 'R') {
					Coord d = make_pair(c.first+1, c.second+1);
					if (d.first > 7 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -1000;
					}
					if (check_coord(d,0)>-1){
						return -40;
					}
					return 40;
				}
			} else if (p2pieces[index].checkKing()) { //checks directions if piece is king
				if (vert == 'T') {
					if (lat == 'L') {
						Coord d = make_pair(c.first-1, c.second-1);
						if (d.first < 0 || d.second < 0){
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -1000;
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
							return -1000;
						}
						if (check_coord(d,0) > -1){
							return -20;
						}
						return 20;
					}
				}
			}
		} else if (turn == false) { //player 1 cases
			if (vert == 'T') {
                                if (lat == 'L') {
                                        Coord d = make_pair(c.first-1, c.second-1);
					if (d.first < 0 || d.second < 0){
						return -1000;
					}
					if (check_coord(d,0) > -1){
						return -1000;
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
						return -1000;
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
                                                	return -1000;
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
							return -1000;
						}
						if (check_coord(d,1) > -1){
							return -4;
						}
                                                return 4;
                                        }
                                }
                        }
		}
		return -1000; //something invalid (ex. making a move only a king can make)
	}
	//can jump
	int CheckersGame::can_jump(Coord d, string direction, int index) { //checks to see if piece can jump in that direction
		int dir = can_move(d, direction, index); //checks for occupant of square one increment away
		int temp;
		if (turn == false) { //player 1 cases
			if (dir == -1) { //player 2 piece occupies space in immediate direction so jump possibility should be checked - direction: TL
				Coord e = make_pair(d.first-1, d.second-1); //coordinate is updated so move function can be called to check for jump location
				temp = can_move(e, direction, index);
				if (temp == -1000){ //jump location is invalid
					return 0;
				}
				if (temp == 1) { //jump location is available
					return 1;
				}
				return 0;
			} else if (dir == -2) { //direction: TR
				Coord e = make_pair(d.first+1, d.second-1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 2) {
					return 2;
				}
				return 0;
			} else if (dir == -3) { //direction: BL
				Coord e = make_pair(d.first-1, d.second+1);
				temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
				if (temp == 3) {
					return 3;
				}
				return 0;
			} else if (dir == -4) { //BR
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
			if (dir == -10) { //TL
                                Coord e = make_pair(d.first-1, d.second-1);
                                temp = can_move(e, direction, index);
				if (temp==-1000){
					return 0;
				}
                                if (temp == 10) {
                                        return -1;
                                }
                                return 0;
                        } else if (dir == -20) { //TR
                                Coord e = make_pair(d.first+1, d.second-1);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
                                if (temp == 20) {
                                        return -2;
                                }
                                return 0;
                        } else if (dir == -30) { //BL
                                Coord e = make_pair(d.first-1, d.second+1);
                                temp = can_move(e, direction, index);
				if (temp == -1000){
					return 0;
				}
                                if (temp == 30) {
                                        return -3;
                                }
                                return 0;
                        } else if (dir == -40) { //BR
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

	bool CheckersGame::is_jump(){ //checks if jump is available for player
		typedef vector<CPiece>::iterator iterator;
		if (turn == false){
			int count = 0;
			for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++){ //goes through vector of pieces
				Coord tcd = it->get_coord();
				if (can_jump(tcd,"TR",count)>0 || can_jump(tcd,"TL",count)>0 || can_jump(tcd,"BL",count)>0 || can_jump(tcd,"BR",count)>0){
					return true; //jump possibility exists
				}
				count++;
			}
		}
		else if (turn == true){
			int count = 0;
			for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++){
				Coord tcd = it->get_coord();
				if (can_jump(tcd,"TR",count)<0 || can_jump(tcd,"TL",count)<0 || can_jump(tcd,"BL",count)<0 || can_jump(tcd,"BR",count)<0){
					return true;
				}
				count++;
			}
		}
		return false; //no jumps available
	}

	//attack square (move piece in a direction and check for jump)
	GameResult CheckersGame::attack_square(Coord d, string direction) {
		if (turn == false) { //p1piece
			int index = check_coord(d, 0);
			if (index >= 0) { //makes sure there exists a piece with coordinate
				if (is_jump()){ //forces user to enter jump if jump is available
					if (can_jump(d, direction, index) == 0){
						return RESULT_INVALID;
					}
				}
				int mv = can_move(d, direction, index);
				if (mv == -1000 || mv == 0){ //if move in that direction is invalid
					return RESULT_INVALID;//invalid move;
				}
				int jump = can_jump(d, direction, index);
				if (mv > 0) { //move it
					if (p1pieces[index].move(mv,1)==1){ //if player is eligible for crowning
						p1pieces[index].makeKing();
						cout<<"CROWNED"<<endl;
					}
				}
				else if (jump > 0) { //jump it
					int oindex = -1; //used later for knowing which opponents piece to be jumped
					bool crowned = false; //used for JUMPED message suppresion later
					if (p1pieces[index].move(jump,2)==1){ //piece that is jumping has it coordinates updated in piece.move function
						p1pieces[index].makeKing();
						if (!check_win()){ //suppresses crowned message if game is won
							cout<<"CROWNED"<<endl;
						}
						crowned = true;
					}

					if (jump == 1) { //direction: TL
						oindex = check_coord(make_pair(d.first-1,d.second-1),1); //if jump is possible, get vector index of opponents piece to be jumped
					} else if (jump == 2) { //TR
						oindex = check_coord(make_pair(d.first+1,d.second-1),1);
					} else if (jump == 3) { //BL
						oindex = check_coord(make_pair(d.first-1,d.second+1),1);
					} else if (jump == 4) { //BR
						oindex = check_coord(make_pair(d.first+1,d.second+1),1);
					}
					if (oindex > -1) {
						p2pieces[oindex].jumped(); //update coordinate of jumped piece
						if (!crowned){ //only print JUMPED if piece was not just crowned
							cout<<"JUMPED"<<endl;
						}
					}
					//check for additional jumps
					int cnt = 0; //tracks number of available jumps
					Coord p1temp = p1pieces[index].get_coord();
					if (can_jump(p1temp, "TL", index)){
						cnt++;
					}
					if (can_jump(p1temp, "TR", index)){
						cnt++;
					}
					if (p1pieces[index].checkKing()){
						if (can_jump(p1temp, "BL", index)){
							cnt++;
						}
						if (can_jump(p1temp, "BR", index)){
							cnt++;
						}
					}
					if (cnt>=1){
						return RESULT_KEEP_PLAYING; //if more jumps available, main will repromt user because turn was not changed by toggle()
					}
				}
				if (check_win()) {
					cout << "PLAYER 1 WINS" << endl;
					return RESULT_PLAYER1_WINS;
				} else {
					toggle(); //change turn
				}
			}else{
				return RESULT_INVALID;
			}
		} else while (turn == true) { //p2piece
			int index = check_coord(d, 1);
			if (index >= 0) {
				if (is_jump()){
                                        if (can_jump(d, direction, index) == 0){
                                                return RESULT_INVALID;
                                        }
                                }
				int mv = can_move(d, direction, index);
				if (mv == -1000 || mv == 0){
					return RESULT_INVALID; //invalid move;
				}
				int jump = can_jump(d, direction, index);
			        if (mv > 0) { //move it
					if (p2pieces[index].move(mv/10,1)==2){
						p2pieces[index].makeKing();
						cout<<"CROWNED"<<endl;
					}
                                }
				else if(jump < 0) { //jump it
                                        int oindex = -1;
					bool crowned = false;
					if (p2pieces[index].move(jump*-1,2)==2){
						p2pieces[index].makeKing();
						if (!check_win()){
							cout<<"CROWNED"<<endl;
						}
						crowned = true;
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
						if (!crowned){
							cout<<"JUMPED"<<endl;
						}
					}
					//check for additional jumps
					int cnt = 0;
					Coord p2temp = p2pieces[index].get_coord();
					if (can_jump(p2temp, "BL", index)){
						cnt++;
					}
					if (can_jump(p2temp, "BR", index)){
						cnt++;
					}
					if (p2pieces[index].checkKing()){
						if (can_jump(p2temp, "TL", index)){
							cnt++;
						}
						if (can_jump(p2temp, "TR", index)){
							cnt++;
						}
					}
					if (cnt>=1){
						return RESULT_KEEP_PLAYING;
					}
                                }
				if (check_win()) {
					cout << "PLAYER 2 WINS" << endl;
					return RESULT_PLAYER2_WINS;
				} else {
					toggle();
				}
			}else{
				return RESULT_INVALID;
			}
		}
		return RESULT_KEEP_PLAYING;
	}
	//check win
	bool CheckersGame::check_win() {
		typedef vector<CPiece>::iterator iterator;
		int counter = 0; //keeps track of number of opponets pieces that were removed from board
		if (turn == false) { //pplayer 1 checks player 2 pieces
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
		if (counter == 12) { //if all pieces are off board (were jumped)
			return true;
		} else {
			return false;
		}
	}

	void CheckersGame::printp() { //this function is commented out - it prints location and pieces state (-1 for off board)
		typedef vector<CPiece>::iterator iterator;
		cout<<"p1 pieces"<<endl;
		for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++) {
			it->print();
		}
		cout<<"p2 pieces"<<endl;
		for (iterator it = p2pieces.begin(); it != p2pieces.end(); it++){
			it->print();
		}
	}

        CheckersBoard::CheckersBoard() { //board
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                                ckarray[i][j] = '-';
                        }
                }
        }
