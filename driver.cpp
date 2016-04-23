#include <utility>
#include "battleship.h"

using namespace std;

void placement(BattleshipGame bsgame) {
	string dif_ships[] = {"AICRAFT CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
	int lengths[] = {5, 4, 3, 3, 2};

	Coord bs = make_pair(1, 1);
	string userInput;
	Ship temp2(5, bs, 'V');
	for (int i=0; i<5;i++) {
		bool okay = true;
		while (okay) {
			cout << "PLAYER 1 PLACE " << dif_ships[i] << ":";
			cin >> userInput;
			cout << endl;
			int first = userInput.at(0) - '0';
			int second = userInput.at(1) - '0';
			char direction = toupper(userInput.at(2));
			Coord tempCoord = make_pair(first, second);
			Ship temp(lengths[i], tempCoord, direction); 
			temp2 = temp;
			for (vector<Ship>::iterator it = bsgame.fleet1.begin() ; it != bsgame.fleet1.end(); it++) {
				for (int j=0; j<lengths[i]; j++){
					if (direction == 'H'){
						tempCoord.second++;
					}else if (direction == 'V'){
						tempCoord.first++;
					}
					if (!(*it).has_coord(tempCoord))
						okay = false;
					}

			}
		}
		bsgame.fleet1[i] = temp2;
	}

	for (int i=0; i<5;i++) {
                bool okay = true;
                while (okay) {
                        cout << "PLAYER 2 PLACE " << dif_ships[i] << ":";
                        cin >> userInput;
                        cout << endl;
                        int first = userInput.at(0) - '0';
                        int second = userInput.at(1) - '0';
                        char direction = toupper(userInput.at(2));
                        Coord tempCoord = make_pair(first, second);
                        Ship temp(lengths[i], tempCoord, direction); 

                        for (vector<Ship>::iterator it = bsgame.fleet2.begin() ; it != bsgame.fleet2.end(); it++) {
                                for (int j=0; j<lengths[i]; j++){
                                        if (direction == 'H'){
                                                tempCoord.second++;
                                        }else if (direction == 'V'){
                                                tempCoord.first++;
                                        }
                                        if (!(*it).has_coord(tempCoord))
                                                okay = false;
                                        }

                        }
                }
                bsgame.fleet2[i] = temp2;
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
			//
			break;
		case '3':
			//
			break;
	}
return 0;
}
