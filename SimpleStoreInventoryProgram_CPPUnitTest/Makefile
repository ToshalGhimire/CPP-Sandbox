CXX = g++
CXXFLAGS	= -std=c++11 -ggdb -Wall

all: HW3

clean:
	rm HW3 Store.o TextUI.o Item.o Cart.o test test.gcno test.gcda

HW3: Store.o TextUI.o Item.o Cart.o
	$(CXX) $(CXXFLAGS) main.cc Store.o TextUI.o Item.o Cart.o -o HW3

# Store.o: Store.cc
# 	$(CXX) $(CXXFLAGS) -c Store.cc

# TextUI.o: TextUI.cc
# 	$(CXX) $(CXXFLAGS) -c TextUI.cc

# Item.o: Item.cc
# 	$(CXX) $(CXXFLAGS) -c Item.cc

# Cart.o: Cart.cc
# 	$(CXX) $(CXXFLAGS) -c Cart.cc


all: test
 
test: Store.o TextUI.o Item.o Cart.o test.cc
	$(CXX) $(CXXFLAGS) $(CXXTESTFLAGS) test.cc Store.o TextUI.o Item.o Cart.o -o test

Store.o: Store.cc
	$(CXX) $(CXXFLAGS) -c Store.cc

TextUI.o: TextUI.cc
	$(CXX) $(CXXFLAGS) -c TextUI.cc

Item.o: Item.cc
	$(CXX) $(CXXFLAGS) -c Item.cc

Cart.o: Cart.cc
	$(CXX) $(CXXFLAGS) -c Cart.cc