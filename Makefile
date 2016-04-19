CXX = g++
CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CXXFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

.PHONY: all
all: play_ttt play_bs

play_ttt.o: play_ttt.cpp game.h tictactoe.h
	$(CXX) -c play_ttt.cpp $(CXXFLAGS)

play_bs.o: play_bs.cpp game.h battleship.h
	$(CXX) -c play_bs.cpp $(CXXFLAGS)

play_ttt: play_ttt.o
	$(CXX) -o play_ttt play_ttt.o $(CXXFLAGS)

play_bs: play_bs.o
	$(CXX) -o play_bs play_bs.o $(CXXFLAGS)

clean:
	rm -f *.o play_ttt play_bs
