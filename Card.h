#ifndef Card_H
#define Card_H

#include <iostream>
#include <string> 

using namespace std;

class Card {
private:
	char suit;
	char value;
	int pointVal; //used to help determine melds 
public:
	Card(char, char);

	char getValue(); //used for initializing and dealing out cards
	char getSuit();

	void addCard(char, char);

	void showCard();
};

#endif
