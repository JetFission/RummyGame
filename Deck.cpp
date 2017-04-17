#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>

using namepsace std;

int myrandom(int i) { return rand() % i; }

class Deck{
private:
  vector<Card> deck;
public:
  void shuffle();
  void addCard(Card card);
  void removeTopCard();
  void populateDeck();
  void dealHands(); //initializes both the computers and players decks with 10 cards each
};

void Deck::dealHands()
{
  
}

void Deck::shuffle() {
  random_shuffle(deck.begin(), deck.end() , myrandom);
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

			deck.push_back(d);
		}
	}

}
