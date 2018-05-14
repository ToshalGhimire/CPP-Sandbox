/**
Toshal Ghimire
Homework 1

This is where the Maze class is called, it plays the game;

I did not define a 2d array the same way we learned in class, everything else is implemented

for my additional features, i choose #2 and #5
    #2 - i hadded a mystery treasure denoted by '?'. it has a 50% chance of giving 200 points or losing 100
    #5 - starts by 2X2 then keeps going, can be changed in main, points and lives are consistent through out

I did not attempt extra credit

*/

#include <iostream>
#include <string>
#include <vector>

#include "Maze.h"
#include "Player.h"

using namespace std;
int main(){

    int maze_size = 2;
    Maze* game = new Maze(maze_size);

    Player * player1 = new Player("Toshal");

    int level = 1;
    while(level < 6){
        game->ChangeSize(maze_size++);
        player1->SetPosition({0,0});
        game->NewGame(player1, 0);
        level++;
    }
}
