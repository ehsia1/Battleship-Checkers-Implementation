#ifndef SHIPS_H
#define SHIPS_H
#include <iostream>
#include <map>
#include "game.h"
#include "piece.h"
using namespace std;

class Ship: public Piece {
public:

	Ship(int num, Coord c, char direction); //constructor

	int is_sunk(); //checks if the ship is sunk

	int has_coord(Coord c); //see if ship has a given coordinate

	void hit(int h); //checks if hit or not

	bool shift(int num, char dir); //shifts the ship based on given direction and length of shifting

	char get_dir(); //returns instance variable (direction)

	void set_name(string s); //sets the name of the ship

	string get_name(); //return the name (because it is private)

	int get_length(); //returns length of ship (because it is private)

	void sink(); //makes ship go off board if it is sunk

	map<Coord, int> location;

private:
	void get_rid(); //erases/deletes old spots of ship post shifting

	void update(map<Coord, int> temploc); //places ship in new spot on board

	string name;
	char lgbtq; //orientation of ship on board (vertical (V) or horizontal (H)
	int length;
};

#endif
