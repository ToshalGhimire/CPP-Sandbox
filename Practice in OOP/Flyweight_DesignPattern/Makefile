CXX = g++
CXXFLAGS	= -std=c++11 -ggdb -Wall

all: Maze

clean:
	rm maze Board.o stdafx.o 

maze: Board.o stdafx.o
	$(CXX) $(CXXFLAGS) main.cc Board.o -o maze

Board.o: Board.cpp
	$(CXX) $(CXXFLAGS) -c board.cpp

stdafx.o: stdafx.cpp
	$(CXX) $(CXXFLAGS) -c stdafx.cpp
