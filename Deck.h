#ifndef Deck_H
#define Deck_H
#include <vector>

class Deck{
private:
	vector<Card> deck;
	Card c;//used as an intermediary
public:
	void shuffle();
	//void addCard(Card card);
	void removeTopCard();
	void populateDeck();
	void dealHands(Deck&,Deck&); //initializes both the computers and players decks with 10 cards each
	void deleteDeck(); // called only once
	void printHand(); //used to verify stuff
	void printDeck();
};

#endif
