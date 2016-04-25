#include <utility>
#include "battleship.h"
#include "mobile.h"
using namespace std;

void print(vector<Ship> fleet){
	for (vector<Ship>::iterator it = fleet.begin(); it!=fleet.end(); it++){
		it->display();
	}
}

void placement(BattleshipGame& bsgame) {
	string dif_ships[] = {"AIRCRAFT CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
	int lengths[] = {5, 4, 3, 3, 2};

	Coord bs = make_pair(1, 1);
	string userInput;
	Ship temp2(5, bs, 'V');
	bool share = true;
	for (int i=0; i<5;i++) {
		bool okay = true;
		while (okay) {
			cout << "PLAYER 1 PLACE " << dif_ships[i] << ":";
			cin >> userInput;
			cout << endl;
			if (userInput.at(0) == 'q' || userInput.at(0) == 'Q'){
				exit(1);
			}
			share = true;
			int first = userInput.at(0) - '0';
			int second = userInput.at(1) - '0';
			char direction = toupper(userInput.at(2));
			Coord tempCoord = make_pair(first, second);
			Ship temp(lengths[i], tempCoord, direction);
			if (temp.location.empty()==false){
				temp2 = temp;
				if (bsgame.fleet1.empty() == false) {
					for (vector<Ship>::iterator it = bsgame.fleet1.begin() ; it != bsgame.fleet1.end(); it++) {
						int index = lengths[i];
						tempCoord.first = first;
						tempCoord.second = second;
						for (int j=0; j<index; j++){
							if (it->has_coord(tempCoord) > -1) {
								//cout << "bad placement"<<endl;
								share = false;
							}
							if (direction == 'H'){
								tempCoord.second++;
							}else if (direction == 'V'){
								tempCoord.first++;
							}
						}

					}
					if (share){
						okay = false;
					}
				}
				else{
					okay = false;
				}
			}
			else {
				temp2 = temp;
			}
		}
		if(share){
			//cout<<"added"<<endl;
			temp2.set_name(dif_ships[i]);
			bsgame.fleet1.push_back(temp2);
		}
		//print(bsgame.fleet1);
	}

	for (int i=0; i<5;i++) {
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
                                                        }
        	        	                        if (direction == 'H'){
        	                	                        tempCoord.second++;
        	                        	        }else if (direction == 'V'){
        	                                	        tempCoord.first++;
        	                              		}
						}
 		                       	}
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

int main() {

	//cout << "CHOOSE A GAME:";
	char choice = 'k';
	//cin >> choice;

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
			print(bsgame.fleet1);
			print(bsgame.fleet2);
			if (bsgame.fleet1.empty() == true) {
				cout << "word" << endl;
			}
			if (bsgame.fleet2.empty() == true) {
				cout << "yo" << endl;
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
					if (input.at(0) == 'p') {
						print(bsgame.fleet1);
					} else {
					int first = input.at(0) - '0';
					int second = input.at(1) - '0';
					Coord d = make_pair(first, second);
					if (bsgame.attack_square(d) == RESULT_PLAYER1_WINS) {
						count1++;
					}
					}
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
				}
			}
			break;
		}
		case '2':
			{
			Mobile mobilegame;
                        placement(mobilegame);
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
					} else if (inputLength == 4) {
						int first = input.at(0) - '0';
						int second = input.at(1) - '0';
						char third = input.at(2);
						int fourth = input.at(3) - '0';
						Coord c = make_pair(first, second);
						mobilegame.move(c, fourth, third);
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
                                        } else if (inputLength == 4) {
                                                int first = input.at(0) - '0';
                                                int second = input.at(1) - '0';
                                                char third = input.at(2);
                                                int fourth = input.at(3) - '0';
                                                Coord c = make_pair(first, second);
                                                mobilegame.move(c, fourth, third);
                                        }
				}
			}
			break;
		}
		case '3':
			//
			break;
	}
return 0;
}
