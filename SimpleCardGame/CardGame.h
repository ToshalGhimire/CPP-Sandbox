#ifndef _CARDGAME_H_
#define _CARDGAME_H_

#include <vector>
#include "Player.h"


class CardGame {
public:
	CardGame(std::vector<Player *> players)
	: players_(players)
	{}

	 //TODO: implement these in the CardGame.cc file
	 void PlayGame(const int hand_size);
     void TakeTurn(Player *p);

	 Player * GetWinner();
	 bool IsWinner(std::vector<Card> a);
	 int getdelt_count(){return delt_count_;};

private:
	std::vector<Player *> players_;
	Deck *deck_;
	int delt_count_;//was not needed after all
	bool won_ = false;
};

#endif // _CARDGAME_H_
