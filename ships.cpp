#include <iostream>
#include <map>
#include "game.h"
#include "piece.h"
#include "ships.h"
using namespace std;

	Ship::Ship(int num, Coord c, char direction) { //constructor

		direction = toupper(direction); //generalize the cases
		length = num;
		if ((c.first > 9) || (c.first<0) || (c.second > 9) || (c.second<0)) { //if off the board say off the board
			cout << "Off the board!" << endl;
		} else if (direction == 'V') { //vertical placement
			if (num+c.second < 10) { //checks if length of ship will cause ship to go off board
				lgbtq = direction;
				for (int i=0;i<num;i++) {
					Coord temp = make_pair(c.first, c.second+i);
					location[temp] = 0; //puts coordinates in map with hit value of 0
				}
			} else {
				cout << "Off the board!" << endl; //if off the board
			}
		} else if (direction == 'H') { //horizontal placement
			if (num+c.first < 10) { //see 'V'
				lgbtq = direction;
				for (int i=0;i<num;i++) {
					Coord temp = make_pair(c.first+i, c.second);
					location[temp] = 0; //put in map
				}
			} else {
				cout << "Off the board!" << endl;
			}
		}
	}
	int Ship::is_sunk() { //checks if ship is sunk
		typedef map<Coord, int>::iterator iterator;
		int counter1=0;
		int counter2=0;
		for (iterator it = location.begin(); it != location.end(); it++) { // iterate through map
			counter1++;
			if (it->second >= 1) { //if the number is greater than 0 (if its been hit)
				counter2++;
			}
		}
		if (counter1==counter2) { //means all spots in map are >0
			return 1; //is sunk
		}
		return 0;
	}

	int Ship::has_coord(Coord c) { //check if a ship has a coordinate
		int counter = 0;
		typedef map<Coord, int>::iterator iterator;
		for (iterator it = location.begin(); it != location.end(); it++) { //go thru map
			if(it->first == c){
				return counter; //return counter which is the spot of the foudn coordinate
			}
			counter++;
		}
		return -1; //not found

	}

	void Ship::hit(int h){ //if hit
		typedef map<Coord, int>::iterator iterator;
		int counter = 0;
		for (iterator it = location.begin(); it != location.end(); it++){
			if(counter == h){
				location[it->first]++; //increment spot in map if coord was hit
			}
			counter++;
		}
	}

	bool Ship::shift(int num, char dir){ //shift the ship
		map<Coord, int> temploc;
		typedef map<Coord, int>::iterator iterator;
		typedef map<Coord, int>::reverse_iterator r_iterator;
		if (num <= 0){
			return false;
		}
		if (dir=='D'){
			if (lgbtq == 'H'){ //not allowed under rules
				return false;
			}
			if (location.rbegin()->first.second + num >9){ //if off the board
				return false;
			}
			for (r_iterator rit = location.rbegin(); rit!= location.rend(); rit++){
				Coord temp = rit->first; //store info in temp
				temp.second += num;
				temploc[temp] = rit->second; //put new information in new map temploc
			}
			get_rid();
			update(temploc); //put new map in by update function
			return true;
		}
		if (dir=='U'){ //see above comments
			if (lgbtq == 'H'){ //not allowed
				return false;
			}
			if (location.begin()->first.second - num <0){
				return false;
			}
			for (iterator it = location.begin(); it!= location.end(); it++){
				Coord temp = it->first;
				temp.second -= num;
				temploc[temp] = it->second;
			}
			get_rid();
			update(temploc);
			return true;
		}
		if (dir=='R'){ //see above comments
			if (lgbtq == 'V'){ //not allowed
				return false;
			}
			if (location.rbegin()->first.first + num >9){
				return false;
			}
			for (r_iterator rit = location.rbegin(); rit!=location.rend(); rit++){
				Coord temp = rit->first;
				temp.first += num;
				temploc[temp] = rit->second;
			}
			get_rid();
			update(temploc);
			return true;
		}
		if (dir=='L'){ //see above comments
			if (lgbtq == 'V'){ //not allowed
				return false;
			}
			if (location.begin()->first.first - num <0){
				return false;
			}
			for (iterator it = location.begin(); it!=location.end(); it++){
				Coord temp = it->first;
				temp.first -= num;
				temploc[temp] = it->second;
			}
			get_rid();
			update(temploc);
			return true;
		}
		return false;
	}

	char Ship::get_dir(){ //return direction since private
		return lgbtq;
	}

	void Ship::set_name(string s){ //set name of ship
		name = s;
	}

	string Ship::get_name(){ //return name since private
		return name;
	}

	int Ship::get_length(){ //return length since private
		return length;
	}

	void Ship::sink(){ //if ship is sunk put it off the board so no conflicts with other ships arise
		typedef map<Coord, int>::iterator iterator;
		for (iterator it = location.begin(); it != location.end(); it++){
			Coord temp = it->first;
                        temp.first = -1; //make the coordinates -1 so its off the board;
			temp.second = -1;
                        location[temp] = it->second;
                        location.erase(it->first); //erase previous spots
		}
	}

	void Ship::get_rid(){ //get rid of old map spots
		typedef map<Coord, int>::iterator iterator;
		for (iterator it = location.begin(); it != location.end(); it++){
			location.erase(it->first);
		}
	}

	void Ship::update(map<Coord, int> temploc){ //update with new map
		typedef map<Coord, int>::iterator iterator;
		for (iterator it = temploc.begin(); it != temploc.end(); it++){
			location[it->first] = it->second;
		}
	}
