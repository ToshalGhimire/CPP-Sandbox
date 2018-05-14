#include <iostream>

#include "CardGame.h"
#include "Player.h"

int main() {
	Player * a = new Player("Lovelace");
	Player * b = new Player("Babbage");
	std::vector<Player *> players = {a, b};
	
	CardGame *cg = new CardGame(players);
	cg->PlayGame(2);
	
	// uncomment this line once you have CardGame implemented and the game fully working
	// cg->PlayGame(2);

	return 0;
}