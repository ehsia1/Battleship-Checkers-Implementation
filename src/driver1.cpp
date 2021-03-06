#include <utility>
#include "battleship.h"
#include "mobile.h"
#include "checkers.h"

//runs the games
using namespace std;


void placement(BattleshipGame& bsgame) { //place ships on board
	string dif_ships[] = {"AIRCRAFT CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
	int lengths[] = {5, 4, 3, 3, 2}; //lengths of ships

	Coord bs = make_pair(1, 1);
	string userInput;
	Ship temp2(5, bs, 'V'); //temp needed (you'll see below)
	bool share = true;
	int same_pos = 0;
	int pos = 0;
	for (int i=0; i<5;i++) { //up until number of ships
		bool okay = true;
		while (okay) {
			cout << "PLAYER 1 PLACE " << dif_ships[i] << ":"; //place specific ship
			cin >> userInput;
			cout << endl;
			if (userInput.at(0) == 'q' || userInput.at(0) == 'Q'){ //quit program
				exit(1);
			}
			share = true;
			int first = userInput.at(0) - '0'; //first coord spot
			int second = userInput.at(1) - '0'; //second coord spot
			char direction = toupper(userInput.at(2));
			Coord tempCoord = make_pair(first, second);
			Ship temp(lengths[i], tempCoord, direction); //temp ship that we have to check the validity of
			if (temp.location.empty()==false){ //if false then no need to check the existing map cuz nothing in it
				temp2 = temp; //this is why temp2 is needed
				if (bsgame.fleet1.empty() == false) {
					for (vector<Ship>::iterator it = bsgame.fleet1.begin() ; it != bsgame.fleet1.end(); it++) { //iterate through fleet of ships
						int index = lengths[i];
						tempCoord.first = first;
						tempCoord.second = second;
						for (int j=0; j<index; j++){
							if (it->has_coord(tempCoord) > -1) { //if coord is present then dont add
								share = false;
								same_pos++;
							}
							if (direction == 'V'){
								tempCoord.second++; //increment to check all the spots on vertical axis
							}else if (direction == 'H'){
								tempCoord.first++;  //increment to check all the spots on vertical axis
							}
						}
						if (same_pos >= 1 || (same_pos == 1 && i != pos)) { //check if spot already taken
							cout << "Already a ship there" << endl;
						}
						same_pos = 0;
						pos++;
					}
					pos = 0;
					if (share){
						okay = false; //jump out of loop
					}
				}
				else{
					okay = false;
				}
			}
			else {
				temp2 = temp; //make the temp2 = temp so we can add
			}
		}
		if(share){
			temp2.set_name(dif_ships[i]); //temp2 has correct info so set its name to the ship
			bsgame.fleet1.push_back(temp2); //push temp2 into the fleet
		}
	}

	for (int i=0; i<5;i++) { //repeat this shit for player 2
                bool okay = true;
                while (okay) {
                        cout << "PLAYER 2 PLACE " << dif_ships[i] << ":";
                        cin >> userInput;
                        cout << endl;
			if (userInput.at(0) == 'Q' || userInput.at(0) == 'q') {
				exit(1);
			}
			share = true;
                        int first = userInput.at(0) - '0';
                        int second = userInput.at(1) - '0';
                        char direction = toupper(userInput.at(2));
                        Coord tempCoord = make_pair(first, second);
                        Ship temp(lengths[i], tempCoord, direction);
			if(temp.location.empty() == false){
				temp2=temp;
				if (bsgame.fleet2.empty() == false) {
		                        for (vector<Ship>::iterator it = bsgame.fleet2.begin() ; it != bsgame.fleet2.end(); it++) {
						int index = lengths[i];
						tempCoord.first = first;
						tempCoord.second = second;
        		                        for (int j=0; j<index; j++){
							if (it->has_coord(tempCoord) > -1) {
                                                                share = false;
								same_pos++;
                                                        }
        	        	                        if (direction == 'V'){
        	                	                        tempCoord.second++;
        	                        	        }else if (direction == 'H'){
        	                                	        tempCoord.first++;
        	                              		}
						}
						if (same_pos > 1 || (same_pos == 1 && i != pos)) {
							cout << "Already a ship there" << endl;
						}
						same_pos = 0;
						pos++;
 		                       	}
					pos = 0;
					if (share){
						okay = false;
					}
        		        } else {
					okay = false;
				}
			} else {
				temp2 = temp;
			}
		}
		if (share){
			temp2.set_name(dif_ships[i]);
			bsgame.fleet2.push_back(temp2);
		}

        }
}

/*void make_ckgame(CheckersGame & ckgame) { //sets the board for checkers
	Coord c = make_pair(1,0);
	for (int i = 0; i < 12; i++) {
		if (i == 4) {
			c = make_pair(0,1); //follows the rules for setting board for player 2 pieces
		} else if (i == 8) {
			c = make_pair(1,2);
		}
		CPiece temp(c);
		ckgame.p2pieces.push_back(temp);
		c = make_pair(c.first + 2, c.second);
	}

	Coord d = make_pair(0,5);
	for (int i = 0; i < 12; i++) {
		if (i == 4) {
			d = make_pair(1,6); //follows the rules for setting board for player 1 pieces
		} else if (i == 8) {
			d = make_pair(0,7);
		}
		CPiece temp(d);
		ckgame.p1pieces.push_back(temp);
		d = make_pair(d.first + 2, d.second);
	}
}*/

int main() {

	char choice = 'k';
	while (choice != 'q' && choice != 'Q' && choice != '1' && choice != '2' && choice != '3') {
		cout << "CHOOSE A GAME:";
		cin >> choice;
		cout << endl;
	}

	int count1=0;

	switch(choice) {
		case 'q':
		case 'Q':
			return 1;
			break;
		case '1':
		{
			BattleshipGame bsgame;
			placement(bsgame);
			//print(bsgame.fleet1);
			//print(bsgame.fleet2);
/*			cout << "PLAYER 1 SHIPS" << endl;
			cout << bsgame.fleet1;
			cout<< "PLAYER 2 SHIPS" << endl;
			cout << bsgame.fleet2;*/
			if (bsgame.fleet1.empty() == true) {
				//cout << "word" << endl;
			}
			if (bsgame.fleet2.empty() == true) {
				//cout << "yo" << endl;
			}
			string input;
			while (count1==0) {
				if (bsgame.turn == false) {
					cout << "PLAYER 1:";
					cin >> input;
					cout << endl;
					if (input.at(0) == 'q' || input.at(0) == 'Q') {
						exit(1);
					}
					int first = input.at(0) - '0';
					int second = input.at(1) - '0';
					Coord d = make_pair(first, second);
					if (bsgame.attack_square(d) == RESULT_PLAYER1_WINS) {
						count1++;
					}
					/*cout << "PLAYER 1 SHIPS" << endl;
		                        cout << bsgame.fleet1;
                		        cout<< "PLAYER 2 SHIPS" << endl;
                        		cout << bsgame.fleet2;*/

				} else {
					cout << "PLAYER 2:";
                                        cin >> input;
                                        cout << endl;
					if (input.at(0) == 'q' || input.at(0) == 'Q') {
                                                exit(1);
                                        }
                                        int first = input.at(0) - '0';
                                        int second = input.at(1) - '0';
                                        Coord d = make_pair(first, second);
					if (bsgame.attack_square(d) == RESULT_PLAYER2_WINS) {
                                                count1++;
                                        }
					/*cout << "PLAYER 1 SHIPS" << endl;
		                        cout << bsgame.fleet1;
                		        cout<< "PLAYER 2 SHIPS" << endl;
                        		cout << bsgame.fleet2;*/
				}
			}
			break;
		}
		case '2':
			{
			Mobile mobilegame;
                        placement(mobilegame);
			//print(mobilegame.fleet1);
			/*cout << "PLAYER 1 SHIPS" << endl;
                        cout << mobilegame.fleet1;
			cout << "PLAYER 2 SHIPS" << endl;
			cout << mobilegame.fleet2;*/
			string input;
			while (count1==0) {
				if (mobilegame.turn == false) {
					cout << "PLAYER 1:";
					cin >> input;
					if (input.at(0) == 'q' || input.at(0) == 'Q') {
                                                        exit(1);
                                        }
					int inputLength = input.length();
					if (inputLength == 2) {
						int first = input.at(0) - '0';
                                        	int second = input.at(1) - '0';
                                        	Coord d = make_pair(first, second);
                                        	if (mobilegame.attack_square(d) == RESULT_PLAYER1_WINS) {
                                                	count1++;
                                        	}
						//print(mobilegame.fleet1);
						/*cout << "PLAYER 1 SHIPS" << endl;
                       				cout << mobilegame.fleet1;
                        			cout << "PLAYER 2 SHIPS" << endl;
                        			cout << mobilegame.fleet2;*/
					} else if (inputLength == 4) {
						int first = input.at(0) - '0';
						int second = input.at(1) - '0';
						char third = input.at(2);
						int fourth = input.at(3) - '0';
						Coord c = make_pair(first, second);
						mobilegame.move(c, fourth, third);
						//print(mobilegame.fleet1);
						/*cout << "PLAYER 1 SHIPS" << endl;
                        			cout << mobilegame.fleet1;
                        			cout << "PLAYER 2 SHIPS" << endl;
                        			cout << mobilegame.fleet2;*/
//						mobilegame.toggle();
					}
				} else {
					cout << "PLAYER 2:";
                                        cin >> input;
                                        if (input.at(0) == 'q' || input.at(0) == 'Q') {
                                                        exit(1);
                                        }
                                        int inputLength = input.length();
                                        if (inputLength == 2) {
                                                int first = input.at(0) - '0';
                                                int second = input.at(1) - '0';
                                                Coord d = make_pair(first, second);
                                                if (mobilegame.attack_square(d) == RESULT_PLAYER2_WINS) {
                                                        count1++;
                                                }
						/*cout << "PLAYER 1 SHIPS" << endl;
                        			cout << mobilegame.fleet1;
                        			cout << "PLAYER 2 SHIPS" << endl;
                        			cout << mobilegame.fleet2;*/
                                        } else if (inputLength == 4) {
                                                int first = input.at(0) - '0';
                                                int second = input.at(1) - '0';
                                                char third = input.at(2);
                                                int fourth = input.at(3) - '0';
                                                Coord c = make_pair(first, second);
                                                mobilegame.move(c, fourth, third);
						/*cout << "PLAYER 1 SHIPS" << endl;
                        			cout << mobilegame.fleet1;
                        			cout << "PLAYER 2 SHIPS" << endl;
                        			cout << mobilegame.fleet2;*/
//						mobilegame.toggle();
                                        }
				}
			}
			break;
		}
		case '3':
		{
			CheckersGame ckgame;
//			make_ckgame(ckgame);
			string input;
			int count1 = 0;
			while (count1 == 0) {
				if (ckgame.turn == false) {
					cout << "PLAYER 1:";
					cin >> input;
					if (input.at(0) == 'q' || input.at(0) == 'Q') {
						exit(1);
					}
					int first = input.at(0) - '0';
					int second = input.at(1) - '0';
					char third = input.at(2);
					char fourth = input.at(3);
					third = toupper(third);
					fourth = toupper(fourth);
					string direction = {third, fourth};
					Coord d = make_pair(first, second);
					if (ckgame.attack_square(d, direction) == RESULT_PLAYER1_WINS) {
						count1++;
					}
					//ckgame.printp(); prints out player 1 pieces - used during testing and OVERRIDES << operater
				} else {
					cout << "PLAYER 2:";
					cin >> input;
					if (input.at(0) == 'q' || input.at(0) == 'Q') {
                                                exit(1);
                                        }
                                        int first = input.at(0) - '0';
                                        int second = input.at(1) - '0';
					char third = input.at(2);
                                        char fourth = input.at(3);
                                        third = toupper(third);
                                        fourth = toupper(fourth);
                                        string direction = {third, fourth};
                                        Coord d = make_pair(first, second);
                                        if (ckgame.attack_square(d, direction) == RESULT_PLAYER2_WINS) {
                                                count1++;
                                        }
					//ckgame.printp(); prints out player 2 pieces - used during testing and OVERRIDES << operator
				}
			}
			break;
		}
	}
	return 0;
}
