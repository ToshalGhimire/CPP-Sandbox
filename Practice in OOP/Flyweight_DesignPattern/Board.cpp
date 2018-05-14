#include "stdafx.h"
#include "Board.h"
#include <algorithm>
#include <ctime>
#include <string>
#include <iostream>




/**
	ctor for Board, takes in rows and columns and then creates a board with certian probalities for each occurance of tile using its tile object

	@param int row, int col
	@return 

*/
Board::Board(int r, int c)
{

	std::srand(std::time(0));


	rows_ = r;
	cols_ = c;

	std::vector<std::vector<Tile*>> array_2d(rows_, std::vector<Tile*>(cols_,empty));


	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < cols_; j++) {

			//the following if statements sets up the board using rand() for each enum
			if (i == 0 && j == 0) {
				array_2d[i][j] = human;
			}
			else if (i == rows_ - 1 && j == cols_ - 1) {
				array_2d[i][j] = exit;
			}
			else if (rand() <= RAND_MAX * 0.2) {
				array_2d[i][j] = wall;
			}
			else if (rand() >= RAND_MAX * 0.9) {
				array_2d[i][j] = treasure;
			}
			else{}

		}
	}
	board_ = array_2d;
}

/**
	display board method used to display board, not used in main since << was overloaded 

@param int row, int col
@return

*/
void Board::displayBoard() {
	for (int j = 0; j < this->get_rows(); j++) {
		std::cout << "\t ";
		for (int i = 0; i < this->get_cols(); i++) {
			//std::string temp = 
			std::cout << SquareTypeStringify(this->get_board()[i][j]->get_str()) << " ";
		}
		std::cout << "\n";
	}
};

/**
	Operator overloading with <<, takes in the Board and returns output stream

	@param Board object
	@return ostream

*/
std::ostream& operator<<(std::ostream& os, Board& data)
{
	os << std::endl;
	for (int j = 0; j < data.get_rows(); j++) {
		os << "\t ";
		for (int i = 0; i < data.get_cols(); i++) {
			//std::string temp = 
			os << SquareTypeStringify((data.get_board()[i][j]->get_str())) << " ";
		}
		os << std::endl;
	}

	os << std::endl;

	return os;
}
/**
	Operator overloading with <<, takes in the Board and returns output stream
	overloading for pointers

	@param Board object
	@return ostream

*/
std::ostream& operator<<(std::ostream& os, Board * data)
{
	os << std::endl;
	for (int j = 0; j < data->get_rows(); j++) {
		os << "\t ";
		for (int i = 0; i < data->get_cols(); i++) {
			//std::string temp = 
			os << SquareTypeStringify((data->get_board()[i][j]->get_str())) << " ";
		}
		os << std::endl;
	}

	os << std::endl;

	return os;
}

/**
stringify the board inorder to print it properly

@param std::string a
@return std::string b

*/
std::string SquareTypeStringify(std::string a) {
	if (a == "wall" || a == "w")
	{

		return "W";

	}
	else if (a == "empty" || a == "e")
	{

		return ".";
	}
	else if (a == "end" || a == "exit")
	{

		return "E";
	}
	else if (a == "treasure" || a == "t")
	{

		return "$";
	}
	else if (a == "human" || a == "h")
	{

		return "H";
	}
	else {
		return "";
	}
	

};


//Tile class  

/**
ctor for tile, takes in string of tile type and then sets it flag to true then sets it Squaretype field to approiate enum value

@param string
@return

*/
Tile::Tile(std::string type)
{

	str_ = type;
	if (type == "wall" || type == "w")
	{

		IsWall_ = true;
		tile_squareType_ = SquareType::Wall;
	}
	else if (type == "empty" || type == "e")
	{

		IsEmpty_ = true;
		tile_squareType_ = SquareType::Empty;

	}
	else if (type == "end" || type == "exit")
	{

		IsExit_ = true;
		tile_squareType_ = SquareType::Exit;

	}
	else if (type == "treasure" || type == "t")
	{

		IsTreasure_ = true;
		tile_squareType_ = SquareType::Treasure;

	}
	else if (type == "human" || type == "h")
	{

		IsHuman_ = true;
		tile_squareType_ = SquareType::Human;

	}
	else {
		std::cout << "Error: tile type not found!" << std::endl;
		delete this;
	}
}

