#pragma once
#include <vector>
#include <iostream>


enum class SquareType { Wall, Empty, Exit, Human, Treasure }; //enum class to identify the tile
std::string SquareTypeStringify(std::string a);


/**
	tile class that has flags and a enum data field to determine what type of tile it is, will be used insided of board class

*/
class Tile
{
public:
	Tile(std::string type);
	std::string get_str() { return str_; }
	SquareType get_type() { return tile_squareType_; }


private:
	SquareType tile_squareType_;

	bool IsEmpty_ = false;
	bool IsWall_ = false;
	bool IsExit_ = false;
	bool IsTreasure_ = false;
	bool IsHuman_ = false;

	std::string str_;


};


/**
	Board class that uses flyweight design pattern for each type of tile
	has overloaded<< inorder to output board
	board is in a 2d vector datatype

*/
class Board
{
public:
	Board(int r, int c);
	void displayBoard();
	
	int get_rows() { return rows_; }
	int get_cols() { return cols_; }
	std::vector<std::vector<Tile*>> get_board() { return board_; }

	friend std::ostream& operator<<(std::ostream& os, Board * data);
	friend std::ostream& operator<<(std::ostream& os, Board& data);


	//~Board();
private: 
	//flyweight of tile classes
	Tile * wall = new Tile("wall");
	Tile * empty = new Tile("empty");
	Tile * exit = new Tile("exit");
	Tile * human = new Tile("human");
	Tile * treasure = new Tile("treasure");

	std::vector<std::vector<Tile*>> board_;
	int rows_, cols_;
};



