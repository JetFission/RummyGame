#include "Card.h"
#include <iostream>

using namespace std;

void Card::showCard() {
	cout << value << "\t" << suit;
}

char Card::getValue()
{
	return value;
}

char Card::getSuit()
{
	return suit;
}

int Card::getPoint()
{
	return pointVal;
}

int Card::getActualPoint()
{
	return actualPoint;
}

void Card::addCard(char s, char v, int p, int actualP)
{
	suit = s;
	value = v;
	pointVal = p;
	actualPoint = actualP;
}
