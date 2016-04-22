#include <utility>
#include "battleship.h"

using namespace std;

void placement() {
	string dif_ships[] = {"AICRAFT CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
	int lengths[] = {5, 4, 3, 3, 2};

	string userInput;
	for (int i=0; i<5;i++) {
		bool okay = true;
		while (okay) {
			cout << "PLAYER 1 PLACE " << dif_ships[i] << ":";
			cin >> userInput;
			cout << endl;
			int first = userInput.at(0) - '0';
			int second = userInput.at(1) - '0';
			char direction = userInput.at(2);

			for (int j=0; j < i; j++) {
				if (


			}


		}

	}

}


int main() {

	//cout << "CHOOSE A GAME:";
	char choice = 'k';
	//cin >> choice;

	while (choice != 'q' && choice != 'Q' && choice != '1' && choice != '2' && choice != '3') {
		cout << "CHOOSE A GAME:"
		cin >> choice;
		cout << endl;
	}

	switch(choice) {
		case 'q':
		case 'Q':
			return 1;
			break;
		case '1':
			BattleshipGame bsgame;
			
			break;
		case '2':
			//
			break;
		case '3':
			//
			break;
		default:
	}
return 0;
}
