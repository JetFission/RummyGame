#ifndef Deck_H
#define Deck_H
#include <vector>
#include "Card.h"

class Deck{
private:
	vector<Card> deck;
	Card c;//used as an intermediary
	
	//---------------April 27---------------//
	vector<Card> melds
public:
	Deck();
	void shuffle();
	void addCard(Card card);
	Card removeTopCard();
	void populateDeck();
	void dealHands(Deck&, Deck&); //initializes both the computers and players decks with 10 cards each
	void deleteDeck(); // called only once
	void printHand(); //used to verify stuff
	void printDeck();
	Card removeCardAt(int num);
	void scanMelds();
};

#endif
