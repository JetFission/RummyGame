#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>

using namespace std;

//---------------4/17/2017--------------//

struct Card
{
	char suit;
	char card;
};

int myrandom(int i) { return rand() % i; }

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


void Deck::dealHands(Deck& other1, Deck& other2)
{
	for (unsigned int i = 0; i < 10; i++)
	{
		other1.c.card = other2.deck[i].card;
		other1.c.suit = other2.deck[i].suit;

		other1.deck.push_back(other1.c);

		cout << "each card " << other2.deck[i].card << "\t" << other2.deck[i].suit << endl;//test

		other2.deck.erase(other2.deck.begin(), other2.deck.begin() + 1);
	}
}

void Deck::printHand()
{
	cout << "-------Hand---------" << endl;

	int count = 0;
	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].suit << "\t" << deck[i].card << endl;
		cout << endl;
		count++;
	}
	cout << count << endl;
}

void Deck::printDeck()
{
	cout << "-------Deck---------" << endl;
	

	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].suit << "\t" << deck[i].card << endl;
		cout << endl;
		
	}
}

void Deck::deleteDeck()
{
	for (int i = 0; i < 10; i++) 
	{
		deck.erase(deck.begin(), deck.begin() + 1);
	}
}


void Deck::shuffle() 
{
	srand(time(0));


	random_shuffle(deck.begin(), deck.end(), myrandom);
}

/*void Deck::addCard(Card card) {
	deck.push_back(card);
}*/

void Deck::removeTopCard() {
	deck.erase(deck.begin(), deck.begin() + 1); //removes card from deck. For instance, an object mainDeck of type Deck in main function
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
