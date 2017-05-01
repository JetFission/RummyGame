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

struct myclass {
	bool operator() (Card i, Card j) { return (i.getPoint() < j.getPoint()); }
} myobject;

//---------------4/30/2017--------------//

int myrandom(int i) { return rand() % i; }

void Deck::dealHands(Deck& other1, Deck& other2)
{
	for (unsigned int i = 0; i < 10; i++)
	{
		other1.c.addCard(other2.deck[i].getSuit(), other2.deck[i].getValue(), other2.deck[i].getPoint());

		other1.deck.push_back(other1.c);

		other2.deck.erase(other2.deck.begin(), other2.deck.begin() + 1);
	}
}

void Deck::printHand()
{
	cout << "-------Hand---------" << endl;

	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << "Position: " << i << ")   " << deck[i].getSuit() << "\t" << deck[i].getValue() <<  endl;
		cout << endl;
	}
}

int Deck::getSizeOfStock()
{
	return deck.size();
}

void Deck::printSet() //testing purposes
{
	cout << "-------Set---------" << endl;

	cout << "The size of set is " << set.size() << endl; //test

	for (unsigned int i = 0; i < set.size(); i++)
	{

		cout << set[i].getSuit() << "\t" << set[i].getValue() << endl;
		cout << endl;
	}
}

void Deck::printRun() //testing purposes
{
	cout << "-------Run---------" << endl;

	for (unsigned int i = 0; i < run.size(); i++)
	{

		cout << run[i].getSuit() << "\t" << run[i].getValue() << endl;
		cout << endl;
	}
}

void Deck::printDeck()
{
	cout << "-------Deck---------" << endl;

	for (unsigned int i = 0; i < deck.size(); i++)
	{
		cout << deck[i].getSuit() << "\t" << deck[i].getValue() <<  endl;
		cout << endl;
	}
}

void Deck::deleteDeck() //deletes one card from deck, depending on which object calls it
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

void Deck::addCard(Deck& card) 
{
	deck.push_back(card.deck[0]);
}

void Deck::printCard()
{
	cout << deck[0].getSuit() << "\t" << deck[0].getValue() << endl;
}

void Deck::addCardFromSpot(Deck& card, int place)
{
	deck.push_back(card.deck[place]);
}

void Deck::deleteCardFromSpot(int place)
{
	deck.erase(deck.begin() + place);
}

void Deck::populateDeck()
{

	char suit[4] = { 'H', 'D', 'C', 'S' };
	char value[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	int point[13] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1 };

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			c.addCard(suit[i], value[j], point[j]);


			deck.push_back(c);
		}
	}
}

void Deck::scanSet()
{
	
	int j = 0;
	int countSet = 0;//keeps track of how many sets are accumulated 

	for (unsigned int i = 0; i < deck.size(); i++) //takes just one card
	{
		for (j = i + 1; j < deck.size(); j++) //compares each cards point value with the rest
		{
			if (deck[i].getValue() == deck[j].getValue())
			{
				countSet++;

				//c.addCard(deck[j].getSuit(), deck[j].getValue(), deck[j].getPoint());

				temp.push_back(deck[j]);
			}
		}

		if (countSet == 3)
		{
			cout << endl; //testing 
			cout << "Load card " << endl;
			cout << endl;

			//c.addCard(deck[i].getSuit(), deck[i].getValue(), deck[i].getPoint());

			set.push_back(deck[i]);

			deck.erase(deck.begin() + i);


			for (unsigned int k = 0; k < temp.size(); k++)
			{
				set.push_back(temp[k]);
			}
			temp.clear();
			

			for (unsigned int i = 0; i < set.size(); i++)
			{
				for (unsigned int j = i + 1; j < deck.size(); j++)
				{
					if (set[i].getValue() == deck[j].getValue())
						deck.erase(deck.begin() + j);
				}
			}
		}

		else //meant to delete cards added if a set was not formed
		{
			
			temp.clear();
		}
		countSet = 0;
	}
}

void Deck::scanRun()
{
	std::sort(deck.begin(), deck.end(), myobject); //sorts the deck with the smallest point value going to the front

	int j = 0;
	int countRun = 0;//keeps track of how many sets are accumulated 
	int count = 0;

	for (unsigned int i = 0; i < deck.size(); i++) //takes just one card
	{
		for (j = i + 1; j < deck.size(); j++) //compares each cards point value with the rest
		{
			if (deck[i].getSuit() == deck[j].getSuit())
			{
				count++;
				if (deck[i].getPoint() + count == deck[j].getPoint())
				{
					countRun++;

					temp.push_back(deck[j]);
				}
			}
		}

		if (countRun >= 2)
		{
			run.push_back(deck[i]);

			deck.erase(deck.begin() + i);


			for (unsigned int k = 0; k < temp.size(); k++)
			{
				run.push_back(temp[k]);
			}
			temp.clear();


			for (unsigned int i = 0; i < set.size(); i++)
			{
				for (unsigned int j = i + 1; j < deck.size(); j++)
				{
					if ((run[i].getValue() == deck[j].getValue()) && (run[i].getSuit() == deck[j].getSuit()))
						deck.erase(deck.begin() + j);
				}
			}
		}

		else //meant to delete cards added if a set was not formed
		{

			temp.clear();
		}
		countRun = 0;
		count = 0;
	}
}

void Deck::deleteCard() //get rid of only one card 
{
	deck.erase(deck.begin()); 
}

int Deck::calculateDeadwood() 
{
	deadPoints = 0;
	for (int i = 0; i < deck.size(); i++) 
	{
		deadPoints += deck[i].getPoint();
	}

	return deadPoints;
}

bool Deck::checkAI(Deck& card)
{
	bool found = false;
	for (unsigned int i = 0; i < card.deck.size(); i++)
	{
		if (deck[0].getValue() == card.deck[i].getValue())
		{
			found == true;
		}
	}
	return found;
}


