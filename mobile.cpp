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
#include "mobile.h"

using namespace std;

	Mobile::Mobile(): BattleshipGame() {} //constructor creates instance of battleshipgame

	bool Mobile::move(Coord c, int num, char dir){ //move that shieeeet
		if (num>3 || num<-3){ //cant move this much lol
			return false;
		}
		dir = toupper(dir);

		if (turn==false){
			int str = check_coord(c,0);
			if (str<0){ //not allowed
				return false;
			}
			for (int i=1; i<=num; i++){
				if (dir == 'D'){ //if down
					if (check_coord(make_pair(fleet1[str].location.rbegin()->first.first, fleet1[str].location.rbegin()->first.second+i),0) != -1 ){
						return false; //not allowed, aka ship blocking or something
					}
				}
				else if (dir == 'U'){
					if (check_coord(make_pair(fleet1[str].location.begin()->first.first, fleet1[str].location.begin()->first.second-i),0) !=-1){
						return false; //not allowed, aka ship blocking or something
					}
				}
				else if (dir == 'R'){
					if (check_coord(make_pair(fleet1[str].location.rbegin()->first.first+i, fleet1[str].location.rbegin()->first.second),0) != -1){
						return false;//not allowed, aka ship blocking or something
					}
				}
				else if (dir == 'L'){
					if (check_coord(make_pair(fleet1[str].location.begin()->first.first-i, fleet1[str].location.begin()->first.second),0) !=-1){
						return false;//not allowed, aka ship blocking or something
					}
				}
			}
			if(fleet1[str].shift(num, dir)){ //actually shifts the ship
				toggle(); //toggle turn
				return true;
			}
			return false; //never reached
		}
		else if (turn==true){ //the same thing as above, so I'm not gonna waste my time commenting it lol
			int str = check_coord(c, 1);
			if (str<0){
				return false;
			}
			for (int i=1; i<=num; i++){
                                if (dir == 'D'){
                                        if (check_coord(make_pair(fleet2[str].location.rbegin()->first.first, fleet2[str].location.rbegin()->first.second+i),1) != -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'U'){
                                        if (check_coord(make_pair(fleet2[str].location.begin()->first.first, fleet2[str].location.begin()->first.second-i),1) != -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'R'){
                                        if (check_coord(make_pair(fleet2[str].location.rbegin()->first.first+i, fleet2[str].location.rbegin()->first.second),1) != -1){
                                                return false;
                                        }
                                }
                                else if (dir == 'L'){
                                        if (check_coord(make_pair(fleet2[str].location.begin()->first.first-i, fleet2[str].location.begin()->first.second),1) != -1){
                                                return false;
                                        }
                                }
                        }

			if(fleet2[str].shift(num, dir)){
				toggle();
				return true;
			}
			return false;
		}
		return false;
	}


