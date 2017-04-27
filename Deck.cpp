#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>
#include "Card.h"
#include "Deck.h"

using namespace std;

//---------------4/26/2017--------------//

int myrandom(int i) { return rand() % i; }

Deck::Deck() {
	
}

void Deck::dealHands(Deck& other1, Deck& other2)
{
	for (unsigned int i = 0; i < 10; i++)
	{
		other1.c.addCard(other2.deck[i].getSuit(), other2.deck[i].getValue());

		other1.deck.push_back(other1.c);

		other2.deck.erase(other2.deck.begin(), other2.deck.begin() + 1);
	}
}

void Deck::printHand()
{
	cout << "-------Hand---------" << endl;

	int count = 0;
	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].getSuit() << "\t" << deck[i].getValue() << endl;
		cout << endl;
	}
}

void Deck::printDeck()
{
	int count = 0; //test
	cout << "-------Deck---------" << endl;


	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].getSuit() << "\t" << deck[i].getValue() << endl;
		cout << endl;
		count++;
	}
	cout << endl;
	cout << "The deck now has (testing) " << count << endl;
	cout << endl;
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

void Deck::addCard(Card card) {
	deck.push_back(card);
}

Card Deck::removeCardAt(int num) {
 	Card card = deck[num];
 	vec.erase(vec.begin() + num);
 	return card;
 }

Card Deck::removeTopCard() {
	Card card = deck.back();
	deck.erase(deck.begin(), deck.begin() + 1); //removes card from deck. For instance, an object mainDeck of type Deck in main function
	return card;
}

void Deck::populateDeck()
{

	char suit[4] = { 'H', 'D', 'C', 'S' };
	char value[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			c.addCard(suit[i], value[i]);


			deck.push_back(c);
		}
	}
}

void Deck:Deck scanMelds() {
		
}
