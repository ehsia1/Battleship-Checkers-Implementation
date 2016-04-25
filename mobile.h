/*
william Franceschi
Rohan Tilva
Evan Hsia
final project*/

#ifndef MOBILE_H
#define MOBILE_H

#include "game.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <array>
#include <map>
#include <cctype>
#include "ships.h"
#include "battleship.h"
using namespace std;

class Mobile: public BattleshipGame {
public:
	Mobile(): BattleshipGame() {}

	bool move(Coord c, int num, char dir){
		if (num>3 || num<-3){
			return false;
		}
		dir = toupper(dir);

		if (turn==false){
			int str = check_coord(c,0);
			if (str<0){
				cout << "swag";
				return false;
			}
			for (int i=1; i<=num; i++){
				if (dir == 'U'){
					if (check_coord(make_pair(fleet1[str].location.rend()->first.first, fleet1[str].location.rend()->first.second+i),0) == -1 ){
						return false;
					}
				}
				else if (dir == 'D'){
					if (check_coord(make_pair(fleet1[str].location.begin()->first.first, fleet1[str].location.begin()->first.second-i),0) !=-1){
						return false;
					}
				}
				else if (dir == 'R'){
					if (check_coord(make_pair(fleet1[str].location.rend()->first.first+i, fleet1[str].location.rend()->first.second),0) != -1){
						return false;
					}
				}
				else if (dir == 'L'){
					if (check_coord(make_pair(fleet1[str].location.begin()->first.first-i, fleet1[str].location.begin()->first.second),0) !=-1){
						return false;
					}
				}
			}
			fleet1[str].shift(num, dir);
			toggle();
			return true;
			//return false;
		}
		else if (turn==true){
			int str = check_coord(c, 1);
			if (str<0){
				return false;
			}
			for (int i=1; i<=num; i++){
                                if (dir == 'U'){
                                        if (check_coord(make_pair(fleet2[str].location.rend()->first.first, fleet2[str].location.rend()->first.second+i),1) == -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'D'){
                                        if (check_coord(make_pair(fleet2[str].location.begin()->first.first, fleet2[str].location.begin()->first.second-i),1) != -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'R'){
                                        if (check_coord(make_pair(fleet2[str].location.rend()->first.first+i, fleet2[str].location.rend()->first.second),1) != -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'L'){
                                        if (check_coord(make_pair(fleet2[str].location.begin()->first.first-i, fleet2[str].location.begin()->first.second),1) != -1){
                                                return false;
                                        }
                                }
                        }

			fleet2[str].shift(num, dir);
			toggle();
			return true;
			//return false;
		}
		return false;
	}
};

#endif

