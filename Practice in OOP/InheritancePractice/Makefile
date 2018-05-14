CXX = g++
CXXFLAGS	= -std=c++11 -ggdb -Wall

all: Animal

clean:
	rm Animal.o Dog.o Cat.o Shark.o Bug.o Animal

Animal: Animal.o Dog.o Cat.o Shark.o Bug.o
	$(CXX) $(CXXFLAGS) main.cpp Animal.o Dog.o Cat.o Shark.o Bug.o -o Animal

Animal.o: Animal.cpp
	$(CXX) $(CXXFLAGS) -c Animal.cpp

Dog.o: Dog.cpp
	$(CXX) $(CXXFLAGS) -c Dog.cpp

Cat.o: Cat.cpp
	$(CXX) $(CXXFLAGS) -c Cat.cpp

Shark.o: Shark.cpp
	$(CXX) $(CXXFLAGS) -c Shark.cpp

Bug.o: Bug.cpp
	$(CXX) $(CXXFLAGS) -c Bug.cpp
