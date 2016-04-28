https://ehsia1@bitbucket.org/erwcs120/hw6.git

TEAM (team name: "Back_row 4.0"): 

Rohan Tilva - rtilva1
Evan Hsia - ehsia1
Willie Franceschi - wfrance2

DESIGN:
	game.h --> contains the enum information (GameResult), typedef for the Coord used in battleship and mobile battleship
	piece.h --> includes functions from game.h; has virtual functions (shift, has_coord) that are overriden in later classes 
	ships.h --> IS-A-PIECE relationship; used to create Ship objects (each ship was made an object because each ship had unique properties, such as unique location on the 
		board and length. Also contained overarching functions that could be applied to all Ships (functions like  


REQUIRED LANGUAGE FEATURES:

- to overload the "<<" operator, we used it to print the coordinates of each of the ships in the fleet. This function is in the driver (main). It (and all calls to it in the
driver) are commented out right now because it was used for testing our boards and making sure our games actually worked.

- STL container classes: used containers such as maps, vector, pair. Map was used as instance variable for each Ship object (since this map keeps track of where on the board 
the ships are, as well as if the location on the ship has been hit or not). Also, inside this map were Coords (pairs) which served to keep track of where the ships were on the 
board.Vectors used in battleshipGame/mobile class (vector = fleet of ships), and in checkers class (vector = all of player1/player2's checkers pieces). Pair also used to link 
coordinates of checkers pieces with corresponding int that marks whether that piece is a king or not. 

- Virtual functions (ie. shift) defined in piece.h overriden in subsequent classes (for mobilebs, checkers). 

-Inheritance: checkers is-a-game relationship, mobilebs is-a-game, battleship is-a-game relationship (game is a parent class of these derived classes). The "is-a-game" relationship
 is used primarily to initialize the turn for the specific game (initialized as player 1's turn) and for the general toggle function which switches the turns. checkers_piece 
is-a-piece relationship, and ship class is-a-piece relationship. Piece has virtual functions (shift, has_coord) that are inherited by subclasses and overriden in the subclasses.   

- Polymorphism: implemented for functions defined in piece.h (shift and has_coord are both overriden in the subclasses; for example ships.h redefines shift and has_coord, and 
checkers_piece.h redefines has_coord). Also, the check_win and attack_square functions are defined differently for different classes. For example, the battlshipGame class defines
the check_win function for both battleship and mobile battleship, while checkers.h defines the check_win function specifically for checkers objects. This same concept also applies
to attack_square: battleship.h defines attack_square for both battleship and mobile battleship classes, and checkers.h defines attack_square defines attack_square differently for
the checkers objects. 

COMPLETENESS:

- complete; not aware of any missing functionality

SPECIAL INSTRUCTIONS:

- run driver just as the google doc specifies. 
