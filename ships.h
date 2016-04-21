#ifndef SHIPS_H
#define SHIPS_H
#include <iostream>
#include <map>
#include "game.h"
using namespace std;

class Ship {
public:
	Ship(int num, Coord c, char direction) {

		if ((c.first > 9) || (c.first<0) || (c.second > 9) || (c.second<0)) {
			cout << "Off the board!" << endl;
		} else if (direction == 'h') {
			if (num+c.second < 10) {
				for (int i=0;i<num;i++) {
					Coord temp = make_pair(c.first, c.second+i);
					location[temp] = 0;
				}
			} else {
				cout << "Off the board!" << endl;
			}
		} else if (direction == 'v') {
			if (num+c.first < 10) {
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
private:
	map<Coord, int> location;
};

#endif
