#ifndef SHIPS_H
#define SHIPS_H
#include <iostream>
#include <map>
#include "game.h"
#include "piece.h"
using namespace std;

class Ship: public Piece {
public:
	Ship(int num, Coord c, char direction) {

		direction = toupper(direction);
		length = num;
		if ((c.first > 9) || (c.first<0) || (c.second > 9) || (c.second<0)) {
			cout << "Off the board!" << endl;
		} else if (direction == 'H') {
			if (num+c.second < 10) {
				lgbtq = direction;
				for (int i=0;i<num;i++) {
					Coord temp = make_pair(c.first, c.second+i);
					location[temp] = 0;
				}
			} else {
				cout << "Off the board!" << endl;
			}
		} else if (direction == 'V') {
			if (num+c.first < 10) {
				lgbtq = direction;
				for (int i=0;i<num;i++) {
					Coord temp = make_pair(c.first+i, c.second);
					location[temp] = 0;
				}
			} else {
				cout << "Off the board!" << endl;
			}
		}
	}
	int is_sunk() {
		typedef map<Coord, int>::iterator iterator;
		int counter1=0;
		int counter2=0;
		for (iterator it = location.begin(); it != location.end(); it++) {
			counter1++;
			if (it->second == 1) {
				counter2++;
			}
		}
		if (counter1==counter2) {
			return 1; //is sunk
		}
		return 0;
	}

	int has_coord(Coord c) {
		int counter = 0;
		typedef map<Coord, int>::iterator iterator;
		for (iterator it = location.begin(); it != location.end(); it++) {
			if(it->first == c){
				return counter;
			}
			counter++;
		}
		return -1;

	}

	void hit(int h){
		typedef map<Coord, int>::iterator iterator;
		int counter = 0;
		for (iterator it = location.begin(); it != location.end(); it++){
			if(counter == h){
				location[it->first]++;
			}
			counter++;
		}
	}

	bool shift(int num, char dir){
		typedef map<Coord, int>::iterator iterator;
		typedef map<Coord, int>::reverse_iterator r_iterator;
		if (dir=='R'){
			if (lgbtq == 'V'){
				return false;
			}
			if (location.rbegin()->first.second + num >9){
				return false;
			}
			for (r_iterator rit = location.rbegin(); rit!= location.rend(); rit++){
				rit->first.second += num;
			}
			return true;
		}
		if (dir=='L'){
			if (lgbtq == 'V'){
				return false;
			}
			if (location.begin()->first.second - num <0){
				return false;
			}
			for (iterator it = location.begin(); it!= location.end(); it++){
				it->first.second -= num;
			}
			return true;
		}
		if (dir=='U'){
			if (lgbtq == 'H'){
				return false;
			}
			if (location.rbegin()->first.first + num >9){
				return false;
			}
			for (r_iterator rit = location.rbegin(); rit!=location.rend(); rit++){
				rit->first.first += num;
			}
			return true;
		}
		if (dir=='D'){
			if (lgbtq == 'H'){
				return false;
			}
			if (location.begin()->first.first - num <0){
				return false;
			}
			for (iterator it = location.begin(); it!=location.end(); it++){
				it->first.first -= num;
			}
			return true;
		}
	}

	char get_dir(){
		return lgbtq;
	}

	void set_name(String s){
		name = s;
	}

	String get_name(){
		return name;
	}

private:
	map<Coord, int> location;
	string name;
	char lgbtq; //orientation of ship on board (vertical (V) or horizontal (H)
	int length;
};

#endif
