https://ehsia1@bitbucket.org/erwcs120/hw6.git

TEAM (team name: "Back_row 4.0"): 

Rohan Tilva - rtilva1
Evan Hsia - ehsia1
Willie Franceschi - wfrance2

DESIGN:
	Overall:
        Battleships Game, Mobile BS, and Checkers are all games and inherit virtual functions
        from game.h. Mobile BS is a Battleship Game, but with additional moving functionality.

        For Battleship Game, there are 2 fleets (vector of Ships), one per player. Each fleet has 5 Ship objects,
        which are created during the placement phase. Each player makes one move for their turn.
        Invalid placements prompt the user to repeat the placement. The user proceeds to play
        battleships, sinking ships and taking names until a player wins. Invalid coordinates
        prompt the user to repeat an attack. The game tells notifies the user when a ship is sunk
        or hit.
        The check_coord function checks to see if a ships of a player's fleet contains a coordinate.

        Most of the functionality is in attack_square, which makes calls to check_coord when
        dictating hits and misses.

        For Mobile Game, the user plays just like battleship, but instead of a shot, the user has
        the option to move their ship. A move function in the Mobile game class checks to make
        sure the move is valid (does not go off board, does not collide with a possibly more expensive
        ship like an air craft carrier). The move function calls upon the shift function for the ship,
        which updates the coordinates of the ship that shift was called upon.

        For Checkers Game, the user plays checkers until a winner is established.
        Thec check_coord function is used again to see if a player has a piece with the coordinate.
        The can_move function uses the the check_coord function to determine the state of a spot on
        the board (empty, player1 or player2 piece occupies) and returns different values corresponding
        to not only the state of the spot, but also the direction that was tested.
        The can_jump function is uses the can_move function to test the state of a spot, the return value
        is indicative of whether jump can be performed in the user specified direction.
        RECURSION is used in attack_square for the multiple jump functionality.

	game.h --> contains the enum information (GameResult), typedef for the Coord used in battleship and mobile battleship
	piece.h --> includes functions from game.h; has virtual functions (shift, has_coord) that are overriden in later classes 
	ships.h --> IS-A-PIECE relationship; used to create Ship objects (each ship was made an object because each ship had unique properties, such as unique location on the 
		board and length. Also contained overarching functions that could be applied to all Ships
	checkers_piece.h --> IS-A-PIECE relationship; used to create CPiece objects (checkers pieces); each checkers piece can become a king or be jumped
	battleship.h --> IS-A-GAME relationship, HAS-A-Ship; uesd to create BattleshipsGame objects; has functions and class definition for BattleshipGame
	mobile.h --> IS-A-BattleshipsGame relationship, HAS-A-Ship; inherits all the functions for a battleship game but Mobile game also has extra moving functionality for moving ships
	checkers.h --> IS-A-Game relationship, HAS-A-Cpiece; used to create CheckersGame object; has a lot of functions

	.cpp files corresponding to .h files hold the function definitions and functionality

	driver1.cpp --> allows the user to select which game, and then makes appropriate calls so user can play that game; executable - make driver1; ./driver1

	play_bs.cpp --> tester file for battleship game; executable - make play_bs; ./play_bs
	play_mbs.cpp --> tester file for mobile battleship game; executable - make play_mbs; ./play_mbs
	play_checkers.cpp --> tester file for checkers game; executable - make play_checkers; ./play_checkers 


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
