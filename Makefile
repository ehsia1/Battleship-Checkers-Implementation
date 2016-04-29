CXX = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CXXFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

.PHONY: all
all: play_mbs play_checkers play_bs driver1

#driver
driver: driver1.o battleship.o mobile.o checkers.o ships.o checkers_piece.o
	$(CXX) -o driver driver.o battleship.o mobile.o checkers.o ships.o checkers_piece.o

driver1.o: driver1.cpp battleship.h mobile.h checkers.h
	$(CXX) $(CXXFLAGS) -c driver1.cpp

#tests
play_bs: play_bs.o battleship.o ships.o
	$(CXX) -o play_bs play_bs.o battleship.o ships.o

play_bs.o: play_bs.cpp battleship.h mobile.h
	$(CXX) $(CXXFLAGS) -c play_bs.cpp

play_mbs: play_mbs.o mobile.o battleship.o ships.o
	$(CXX) -o play_mbs play_mbs.o battleship.o mobile.o ships.o

play_mbs.o: play_mbs.cpp mobile.h battleship.h
	$(CXX) $(CXXFLAGS) -c play_mbs.cpp

play_checkers: play_checkers.o checkers.o checkers_piece.o
	$(CXX) -o play_checkers play_checkers.o checkers.o checkers_piece.o

play_checkers.o: play_checkers.cpp checkers.h checkers_piece.h
	$(CXX) $(CXXFLAGS) -c play_checkers.cpp

#non-executable .cpp files
battleship.o: battleship.cpp
	$(CXX) $(CXXFLAGS) -c battleship.cpp

mobile.o: mobile.cpp game.h ships.h battleship.h mobile.h
	$(CXX) $(CXXFLAGS) -c mobile.cpp

checkers.o: checkers.cpp game.h checkers_piece.h checkers.h
	$(CXX) $(CXXFLAGS) -c checkers.cpp

ships.o: ships.cpp game.h piece.h ships.h
	$(CXX) $(CXXFLAGS) -c ships.cpp

checkers_piece.o: checkers_piece.cpp piece.h game.h checkers_piece.h
	$(CXX) $(CXXFLAGS) -c checkers_piece.cpp
#make clean
clean:
	rm -f *.o driver play_checkers play_mbs play_bs *.gcov
