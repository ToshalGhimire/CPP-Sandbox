#ifndef _MAZE_H_
#define _MAZE_H_

#include <vector>
#include "Player.h"

 // you may change this enum as you need
 enum class SquareType { Wall, Exit, Empty, Human, Treasure, Mystery1,Mystery2 };
 // TODO: implement
 std::string SquareTypeStringify(SquareType sq);

 class Board {
 public:
 	// TODO: implement
 	Board(const int rows, const int columns);

 	// already implemented in line
 	int get_rows() const {return rows_; }
 	int get_cols() const {return cols_; }
 	std::vector<std::vector<SquareType>> get_arr() {return arr_;}

 	// TODO: you MUST implement the following functions
 	SquareType GetValue(int row, int col);
 	void SetValue(int row, int col, SquareType value);
 	std::vector<Position> GetMoves(Player *p);
 	bool MovePlayer(Player *p, int r, int c);
 	SquareType GetExitOccupant();

 	// You may implement this function, as needed
 	void displayBoard();
 	std::string Stringify();

 private:
 	//std::vector<SquareType> arr_;
 	std::vector<std::vector<SquareType>> arr_;

 	int rows_;
 	int cols_;

 	// you may add more data, as needed
 };

 class Maze {
 public:
 	// TODO: implement these functions
 	Maze(const int size); // constructor
 	void NewGame(Player *human, const int enemies);
 	void TakeTurn(Player *p);
 	Player * GetNextPlayer();
 	bool IsGameOver();

 	void ChangeSize(int a);

 	// You may implement these functions, as needed
 	std::string GenerateReport();
 	std::string Stringify();


 private:
 	Board *board_;
 	std::vector<Player *> players_;\
 	int turn_count_;

 	// you may add more data, as needed

 };  // class Maze

#endif  // _MAZE_H_
