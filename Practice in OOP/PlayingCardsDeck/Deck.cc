#include <algorithm>  // for shuffling
#include <ctime>
#include <random>

#include "Deck.h"

std::string SuitStringify(Suit s) {
	switch (s) {
		case Suit::Hearts: return " of Hearts";
		case Suit::Clubs: return " of Clubs";
		case Suit::Spades: return " of Spades";
		case Suit::Diamonds: return " of Diamonds";
		default: return "";
	}
}

std::string CardStringify(Card c) {
	std::string s = "";
	//s.append(SuitStringify(c.suit));
	switch (c.value) {
		case 1: s.append("Ace"); break;
		case 11: s.append("Jack"); break;
		case 12: s.append("Queen"); break;
		case 13: s.append("King"); break;
		default: s.append(std::to_string(c.value)); break;
	}
	s.append(SuitStringify(c.suit));
	return s;
}

std::string CardStringifyWithNums(std::vector<Card> cards) {
	std::string s = "";
	for (int i = 0; i < cards.size(); i++) {
		Card c = cards[i];
		s.append("(" + std::to_string(i + 1) + ") ");
		s.append(CardStringify(c));
		s.append("\n");
	}
	return s;
}
//vector of cards
std::string CardStringify(std::vector<Card> cards) {
	std::string s = "";
	for (Card c : cards) {
		s.append(CardStringify(c));
		s.append("\n");
	}
	return s;
}

// standard deck constructor
Deck::Deck() {
	std::vector<Card> tmp;
	cards_ = tmp;
	std::vector<Card> tmp2;
	discard_ = tmp2;

	std::vector<Suit> suits = {Suit::Hearts, Suit::Diamonds, Suit::Spades, Suit::Clubs};

	for (Suit s : suits) {
		for (int i = 1; i <= 13; i++) {
			cards_.push_back({s, i});
		}
	}

	// so that we get different shuffling each time
	random_gen_ = std::default_random_engine {};
	random_gen_.seed(std::time(NULL));
}

void Deck::Shuffle() {
	// randomize the order of the cards in the deck
	// we don't want to just use this with no seed because the order
	// will be the same every time
	std::shuffle ( cards_.begin(), cards_.end(), random_gen_ );
}

Card Deck::Draw() {
	return this->Draw(1, cards_).front();
}

std::vector<Card> Deck::Draw(const int num) {
	return this->Draw(num, cards_);
}

// remove these cards from the deck and give them to the player
std::vector<Card> Deck::Draw(const int num, std::vector<Card> &cards) {
	std::vector<Card> drawn;
	if (num > cards.size()) {
		return drawn;
	}
	for (int i = 0; i < num; i++) {
		Card top = cards.front();
		drawn.push_back(top);
		// then we'll erase this card
		cards.erase(cards.begin());
	}
	return drawn;
}

Card Deck::DrawFromDiscard() {
	return this->Draw(1, discard_).front();
}

void Deck::Discard(Card c) {
	discard_.insert(discard_.begin(), c);
}

Card * Deck::GetTopDiscardExample() {
	if (discard_.size() == 0) {
		return NULL;
	}
	Card *top = &discard_.front();
	return top;
}

std::string Deck::GetTopDiscard() {
	if (discard_.size() == 0) {
		return "no discard";
	}
	return CardStringify(discard_.front());
}

int Deck::GetCardsLeft() {
	return cards_.size();
}

std::string Deck::RevealOrder() {
	return CardStringify(cards_);
}
