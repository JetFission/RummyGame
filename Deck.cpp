#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>
#include "Card.h"

using namepsace std;

int myrandom(int i) { return rand() % i; }

class Deck{
private:
  vector<Card> deck;
  static vector<Card> theDeck; //each player gets a copy of the revised deck
public:
  void shuffle();
  void addCard(Card card);
  void removeTopCard();
  void populateDeck();
  void dealHands(); //initializes both the computers and players decks with 10 cards each
  void printStuff() //used to verify stuff
};

void Deck::printStuff()
{
	

void Deck::dealHands()
{
  for(int i = 0; i < 10; i++) //load players hand and delete the cards taken from the deck
    {
        inter.card = deck[i].card;
        inter.suit = deck[i].suit;

        computer.push_back(inter);

        theDeck.erase(theDeck.begin(), theDeck.begin()+1);

}
}

void Deck::shuffle() {
  random_shuffle(theDeck.begin(), theDeck.end() , myrandom);
}

void Deck::addCard(Card card) {
  deck.push_back(card);
}

void Deck::emoveTopCard() {
  deck.erase(deck.begin(), deck.begin()+1); //removes card from deck. For instance, an object mainDeck of type Deck in main function
}

void Deck::populateDeck()
{
  Card d; //used to load cards into the vector

	char suit[4] = { 'h', 'd', 'c', 's' };
	char card[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			d.suit = suit[i];
			d.card = card[j];

			theDeck.push_back(d);
		}
	}

}
