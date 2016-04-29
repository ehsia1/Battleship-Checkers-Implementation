#include "game.h"
#include "checkers_piece.h"
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include "checkers.h"
using namespace std;


	CheckersGame::CheckersGame(): Game(), p1pieces(), p2pieces() {}

	int CheckersGame::check_coord(Coord c, int whosePiece) { //check to see if piece is there
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

	int CheckersGame::can_move(Coord c, string direction, int index) { //checks if move is valid
		char vert = direction.at(0);
		if (vert != 'B' && vert != 'T'){
			return 0;
		}
		char lat = direction.at(1);
		if (lat != 'R' && lat != 'L'){
			return 0;
		}
		if (turn == true) {
			if (vert == 'B') {
				if (lat == 'L') {
					Coord d = make_pair(c.first-1, c.second+1);
					if (d.first < 0 || d.second > 7){
						return -1000;
					}
					if (check_coord(d,1)>-1){
						return -1000;
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
						return -1000;
					}
					if (check_coord(d,0)>-1){
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
		} else if (turn == false) {
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
		return -1000;
	}
	//can jump
	int CheckersGame::can_jump(Coord d, string direction, int index) {
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

	bool CheckersGame::is_jump(){
		typedef vector<CPiece>::iterator iterator;
		if (turn == false){
			int count = 0;
			for (iterator it = p1pieces.begin(); it != p1pieces.end(); it++){
				Coord tcd = it->get_coord();
				if (can_jump(tcd,"TR",count)>0 || can_jump(tcd,"TL",count)>0 || can_jump(tcd,"BL",count)>0 || can_jump(tcd,"BR",count)>0){
					return true;
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
		return false;
	}

	//attack square (move)
	GameResult CheckersGame::attack_square(Coord d, string direction) {
		if (turn == false) { //p1piece
			int index = check_coord(d, 0);
			if (index >= 0) {
				if (is_jump()){
					if (can_jump(d, direction, index) == 0){
						return RESULT_INVALID;
					}
				}
				int mv = can_move(d, direction, index);
				if (mv == -1000 || mv == 0){
					return RESULT_INVALID;//invalid move;
				}
				int jump = can_jump(d, direction, index);
				bool crowned = true;
				if (mv > 0) { //move it
					if (p1pieces[index].move(mv,1)==1){
						p1pieces[index].makeKing();
					}
				}
				else while (jump > 0 && crowned) { //jump it
					int oindex = -1;
					if (p1pieces[index].move(jump,2)==1){
						p1pieces[index].makeKing();
						crowned = false;
					}

					if (jump == 1) { //tl
						oindex = check_coord(make_pair(d.first-1,d.second-1),1);
						d.first-=2;
						d.second-=2;
					} else if (jump == 2) { //tr
						oindex = check_coord(make_pair(d.first+1,d.second-1),1);
						d.first+=2;
						d.second-=2;
					} else if (jump == 3) { //bl
						oindex = check_coord(make_pair(d.first-1,d.second+1),1);
						d.first-=2;
						d.second+=2;
					} else if (jump == 4) { //br
						oindex = check_coord(make_pair(d.first+1,d.second+1),1);
						d.first+=2;
						d.second+=2;
					}
					if (oindex > -1) {
						p2pieces[oindex].jumped();
					}
					//check for additional jumps
					int cnt = 0;
					vector<string> dir;
					Coord p1temp = p1pieces[index].get_coord();
					if (can_jump(p1temp, "TL", index)){
						cnt++;
						dir.push_back("TL");
					}
					if (can_jump(p1temp, "TR", index)){
						cnt++;
						dir.push_back("TR");
					}
					if (p1pieces[index].checkKing()){
						if (can_jump(p1temp, "BL", index)){
							cnt++;
							dir.push_back("BL");
						}
						if (can_jump(p1temp, "BR", index)){
							cnt++;
							dir.push_back("BR");
						}
					}
					string ndir = "GJ";
					if (cnt>=1){
						dir[0] = ndir;
						cout<<"PLAYER1:";
						string in;
						cin>>in;
						cout<<endl;
						Coord t = make_pair(in.at(0)-'0',in.at(1)-'0');
						if (t != p1temp){
							return RESULT_INVALID;
						}
						char third = toupper(in.at(2));
						char fourth = toupper(in.at(3));
						string ndir = {third, fourth};
						bool check = false;
						for (vector<string>::iterator it = dir.begin(); it != dir.end(); it++){
							if (ndir.compare((*it)) == 0){
								check = true;
							}
						}
						if (check != true){
							return RESULT_INVALID;
						}
					}
					jump = can_jump(p1temp,ndir,index);
				}
				if (check_win()) {
					cout << "PLAYER 1 WINS" << endl;
					return RESULT_PLAYER1_WINS;
				} else {
					toggle();
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
				bool crowned = true;
			        if (mv > 0) { //move it
					if (p2pieces[index].move(mv/10,1)==2){
						p2pieces[index].makeKing();
						crowned = false;
					}
                                }
				else while (jump < 0 && crowned) { //jump it
                                        int oindex = -1;
					if (p2pieces[index].move(jump*-1,2)==2){
						p2pieces[index].makeKing();
						crowned = false;
					}

                                        if (jump == -1) { //tl
                                                oindex = check_coord(make_pair(d.first-1,d.second-1),0);
						d.first-=2;
						d.second-=2;
                                        } else if (jump == -2) { //tr
                                                oindex = check_coord(make_pair(d.first+1,d.second-1),0);
						d.first+=2;
						d.second-=2;
                                        } else if (jump == -3) { //bl
                                                oindex = check_coord(make_pair(d.first-1,d.second+1),0);
						d.first-=2;
						d.second+=2;
                                        } else if (jump == -4) { //br
                                                oindex = check_coord(make_pair(d.first+1,d.second+1),0);
						d.first+=2;
						d.second+=2;
                                        }
					if (oindex > -1) {
						p1pieces[oindex].jumped();
					}
					//check for additional jumps
					int cnt = 0;
					vector<string> dir;
					Coord p2temp = p2pieces[index].get_coord();
					if (can_jump(p2temp, "BL", index)){
						cnt++;
						dir.push_back("BL");
					}
					if (can_jump(p2temp, "BR", index)){
						cnt++;
						dir.push_back("BR");
					}
					if (p2pieces[index].checkKing()){
						if (can_jump(p2temp, "TL", index)){
							cnt++;
							dir.push_back("TL");
						}
						if (can_jump(p2temp, "TR", index)){
							cnt++;
							dir.push_back("TR");
						}
					}
					string ndir = "GJ";
					if (cnt>=1){
						dir[0] = ndir;
						cout<<"PLAYER2:";
						string in;
						cin>>in;
						cout<<endl;
						Coord t = make_pair(in.at(0)-'0',in.at(1)-'0');
						if (t != p2temp){
							return RESULT_INVALID;
						}
						char third = toupper(in.at(2));
						char fourth = toupper(in.at(3));
						string ndir = {third, fourth};
						bool check = false;
						for (vector<string>::iterator it = dir.begin(); it != dir.end(); it++){
							if (ndir.compare((*it)) == 0){
								check = true;
							}
						}
						if (check != true){
							return RESULT_INVALID;
						}
					}
					jump = can_jump(p2temp,ndir,index);
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

	void CheckersGame::printp() {
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

        CheckersBoard::CheckersBoard() {
                for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++) {
                                ckarray[i][j] = '-';
                        }
                }
        }