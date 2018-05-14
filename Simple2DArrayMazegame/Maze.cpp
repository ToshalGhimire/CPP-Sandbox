/**
Toshal Ghimire
Homework 1

This is where the implementation of the Maze and Board class is
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>


#include "Maze.h"
#include "Player.h"

int level = 1;
/**

    translates Enum Squaretype to string to be used for the board
    @param Squaretype sq
    @return Char
*/
std::string SquareTypeStringify(SquareType sq) {
switch(sq){
    case SquareType::Wall: return "W";
    case SquareType::Exit: return "E";
    case SquareType::Empty: return ".";
    case SquareType::Human: return "H";
    case SquareType::Treasure: return "$";
    case SquareType::Mystery1: return "?";
    case SquareType::Mystery2: return "?";
    default: return "";
    }
};

/**

    Board constructor; randomly fills board with treasure and walls

    @param row and columns
    @return nothing
*/
Board::Board(const int rows, const int columns){
    std::srand(std::time(0));
    rows_ = rows;
    cols_ = columns;

    std::vector<std::vector<SquareType>> array_2d(rows, std::vector<SquareType>(columns, SquareType::Empty));
    //arr_ = array_2d;

    for(int i = 0 ; i < rows; i++){
        for(int j = 0; j < columns; j++){

            //the following if statements sets up the board using rand() for each enum
            if(i == 0 && j == 0){
                array_2d[i][j] = SquareType::Human;
            }else if (i == rows-1 && j == columns-1){
                array_2d[i][j] = SquareType::Exit;
            }else if(rand() <= RAND_MAX * 0.2){
                array_2d[i][j] = SquareType::Wall;
            }else if(rand() >= RAND_MAX * 0.9){
                array_2d[i][j] = SquareType::Treasure;
            }else if(rand() >= RAND_MAX * 0.95){
                array_2d[i][j] = SquareType::Mystery1;
            }else if(rand() >= RAND_MAX * 0.95){
                array_2d[i][j] = SquareType::Mystery2;
            }

        }
    }
    arr_ = array_2d;
}

/**
   Returns the square type of a certain index

    @param rows and columns
    @return SquareType enum
*/
SquareType Board::GetValue(int row, int col){
    return this->arr_[row][col];
};

/**
    sets the value of a certain index into a SquareType enum

    @param row & column index and SquareType enum
    @return
*/
void Board::SetValue(int row, int col, SquareType value){
    this->arr_[row][col] = value;
};

/**
    returns a vector of a Position struct, that are legal moves of Player * p
    checks if in edge of board or in front of wall

    @param a pointer to a player class
    @return vector of Position struct
*/
std::vector<Position> Board::GetMoves(Player *p){
    std::vector<Position> moves;
    Position current = p->get_position();

    // Right check
    if(current.col != this->get_cols()-1 && this->GetValue(current.row,current.col+1) != SquareType::Wall ){
        moves.push_back({current.row,current.col+1});
    }
    // Left check
    if(current.col != 0 && this->GetValue(current.row,current.col-1) != SquareType::Wall){
        moves.push_back({current.row,current.col-1});
    }
    // down check
    if(current.row != this->get_rows()-1 && this->GetValue(current.row+1,current.col) != SquareType::Wall){
        moves.push_back({current.row+1,current.col});
    }
    // up check
    if(current.row != 0 && this->GetValue(current.row-1,current.col) != SquareType::Wall ){
        moves.push_back({current.row-1,current.col});
    }
    //the condition before the "&&" are to sort circuit if its in the edge of the board

    return moves;
};

/**
    moves the player to a position and returns true if its a valid position, other wise returns false

    @param Player pointer, row and columns index
    @return boolean
*/
bool Board::MovePlayer(Player *p, int r, int c){
    std::vector<Position> allowed = this->GetMoves(p);


    for(auto t : allowed){
        if(t.row == r && t.col == c){
            p->SetPosition({r,c});
            return true;
        }
    }
    return false;

};
/**
    calls GetValue at the ending index, returns SquareType::Exit;

    @param
    @return true if player found exit, false otherwise
*/
SquareType Board::GetExitOccupant(){
    return this->GetValue(get_rows()-1,get_cols()-1);
};

/**
    prints the board

    @param none
    @return Displays the board in terminal
*/
void Board::displayBoard(){
    for(int j = 0 ; j < this->get_rows(); j++){
        std::cout<<"\t ";
        for(int i = 0; i < this->get_cols(); i++){
            std::cout<<SquareTypeStringify(this->get_arr()[j][i])<<" ";
        }
        std::cout<<"\n";
    }
};

/* -------------------------------------Maze class------------------------------*/


/**
    maze constructor creates a player and a board object and calls Maze::NewGame()

    @param size of the board that you want
    @return
*/
Maze::Maze(const int size){

    board_ = new Board(size,size);
    turn_count_ = 0;

}; // constructor

/**
    starts a new game, runs a do-while loop until the player hits the exit index, calls take turn inside the loop

    @param a player pointer and enemies
    @return
*/
void Maze::NewGame(Player *human, const int enemies){
    players_.push_back(human);
    std::cout<<"Welcome to Toshal's maze game!\n\n";

    do{
        system("cls");

        std::cout<<"\n\tLEVEL "<<level<<"\n\t--------\n\n";

        this->board_->displayBoard();
        std::cout<<"\n\n";
        this->TakeTurn(human);
        this->turn_count_++;

    }while(!this->IsGameOver());

    level++;

    system("cls");
    human->ChangePoints(1);
    std::cout<<"\n\n";
    std::cout<<"Congrats! You finished the game!\n";
    std::cout<<"YOUR TOTAL POINTS = "<<human->get_points()<<"."<<std::endl;
    std::cout<<"YOU HAVE "<<human->get_lives()<<" LIVES LEFT."<<std::endl;
};

/**
    displays possible moves and asks for user input. the input it put through an if-else case to move the player appropriately

    @param Player pointer
    @return
*/
void Maze::TakeTurn(Player *p){
    std::string player_input = "";
    std::vector<Position> allowed_moves = this->board_->GetMoves(p);


    std::cout<<p->get_points()<<" Points\n"<<std::endl;
    std::cout<<p->get_name()<<" can go: ";
    for(auto aa : allowed_moves){
        std::cout<<p->ToRelativePosition(aa)<<" ";
    }

    std::cout<<"\nPlease enter your choice: ";
    std::cin>> player_input;

    std::transform(player_input.begin(),player_input.end(),player_input.begin(), ::tolower);
    //this checks user inputs and then
    if(player_input == "d" || player_input == "right"){
        if(board_->MovePlayer(p,p->get_position().row,p->get_position().col+1)){

            //Ternary operator to for hitting treasures/mystery
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Treasure)? p->ChangePoints(100) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery1)? p->ChangePoints(200) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery2)? p->ChangePoints(-100) : p->ChangePoints(0);

            //changes empty spot to human
            board_->SetValue(p->get_position().row,p->get_position().col,SquareType::Human);

            //changes human spot to empty
            board_->SetValue(p->get_position().row,p->get_position().col-1,SquareType::Empty);
        }

    }else if(player_input == "a" || player_input == "left"){
        if(board_->MovePlayer(p,p->get_position().row,p->get_position().col-1)){

            //Ternary operator to for hitting treasures/mystery
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Treasure)? p->ChangePoints(100) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery1)? p->ChangePoints(200) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery2)? p->ChangePoints(-100) : p->ChangePoints(0);

            //change empty to human
            board_->SetValue(p->get_position().row,p->get_position().col,SquareType::Human);

            //change human to empty
            board_->SetValue(p->get_position().row,p->get_position().col+1,SquareType::Empty);

        }

    }else if(player_input == "w" || player_input == "up"){
        if(board_->MovePlayer(p,p->get_position().row-1,p->get_position().col)){

            //Ternary operator to for hitting treasures/mystery
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Treasure)? p->ChangePoints(100) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery1)? p->ChangePoints(200) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery2)? p->ChangePoints(-100) : p->ChangePoints(0);

            //changes empty to human
            board_->SetValue(p->get_position().row,p->get_position().col,SquareType::Human);

            //changes human to empty
            board_->SetValue(p->get_position().row+1,p->get_position().col,SquareType::Empty);
        }
    }else if(player_input == "s" || player_input == "down" ){
        if(board_->MovePlayer(p,p->get_position().row+1,p->get_position().col)){

            //Ternary operator to for hitting treasures/mystery
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Treasure)? p->ChangePoints(100) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery1)? p->ChangePoints(200) : p->ChangePoints(0);
            (board_->GetValue(p->get_position().row,p->get_position().col) == SquareType::Mystery2)? p->ChangePoints(-100) : p->ChangePoints(0);

            //changes empty to human
            board_->SetValue(p->get_position().row,p->get_position().col,SquareType::Human);

            //changes human to empty
            board_->SetValue(p->get_position().row-1,p->get_position().col,SquareType::Empty);
        }
    }

};


/**
    Returns and removes the last player in the player_ vector

    @param
    @return Returns Player *
*/
Player * Maze::GetNextPlayer(){
    Player * temp = this->players_.at(this->players_.size()-1);
    this->players_.pop_back();

    return temp;


};

/**
    checks if the SquareType::Human has reached the exit enum

    @param
    @return true if player found exit, false otherwise
*/
bool Maze::IsGameOver(){
    if(this->board_->GetValue(board_->get_rows()-1,board_->get_cols()-1)== SquareType::Human)
        return true;
    else
        return false;
};

void Maze::ChangeSize(int a){
    this->board_ = new Board(a,a);
};

//NOT NEEDED
//std::string GenerateReport();
//std::string Stringify();


