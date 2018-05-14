#ifndef _DECK_H_
#define _DECK_H_

#include <string>
#include <vector>
#include <random>

enum class Suit { Hearts, Clubs, Diamonds, Spades };

std::string SuitStringify(Suit sq);

struct Card {
	Suit suit;
	// let 1 be an ace and 11 be a Jack etc.
	int value;
};

std::string CardStringify(Card c);
std::string CardStringify(std::vector<Card> cards);
std::string CardStringifyWithNums(std::vector<Card> cards);

class Deck {
public:
	Deck();  // constructor

	void Shuffle();

	std::vector<Card> Draw(const int num, std::vector<Card> &cards);
	std::vector<Card> Draw(const int num);
	Card Draw();
	void Discard(Card c);
	Card DrawFromDiscard();

	Card * GetTopDiscardExample();
	std::string GetTopDiscard();

	int GetCardsLeft();

	std::string RevealOrder();

private:
	std::vector<Card> cards_;
	std::vector<Card> discard_;

	std::default_random_engine random_gen_;

};



#endif  // _DECK_H_