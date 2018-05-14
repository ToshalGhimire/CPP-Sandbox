#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include "Deck.h"


class Player {
public:
	Player(const std::string name);

	std::string get_name() {return name_;};

	void GiveCards(std::vector<Card> cards);
	void GiveCard(Card card);

	Card DiscardCard(const int card_index);

	std::vector<Card> GetCards();


private:
	std::string name_;
	std::vector<Card> hand_;
};


#endif  // _PLAYER_H_