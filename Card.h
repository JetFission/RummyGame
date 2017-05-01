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
	int actualPoint;
public:
	char getValue(); //used for initializing and dealing out cards
	char getSuit();
	int getPoint();
	int getActualPoint();

	void addCard(char, char, int, int);

	void showCard();
};

#endif
