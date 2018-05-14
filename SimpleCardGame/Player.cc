#include "Player.h"

/**
    Creates a new Player with a certain name.

    @param name the string name of the player
*/
Player::Player(const std::string name) {
	name_ = name;
	std::vector<Card> tmp;
	hand_ = tmp;
}


/**
    Gives the player new cards.

    @param cards a vector of cards for the player to add to their hand
*/
void Player::GiveCards(std::vector<Card> cards) {
	for (Card c : cards) {
		hand_.push_back(c);
	}
}

/**
    Gives the player one new card.

    @param card a single card for the player to add to their hand
*/
void Player::GiveCard(Card card) {
	hand_.push_back(card);	
}

/**
	Gets the cards that are currently in the player's hand

	@return a vector of cards currently in the player's hand
*/
std::vector<Card> Player::GetCards() {
	return hand_;
}

/**
	Discards a card based on its location in a player's hand

	@return the card that has been discarded
*/
Card Player::DiscardCard(const int card_index) {
	Card to_discard = hand_[card_index];
	hand_.erase(hand_.begin() + card_index);
	return to_discard;
}