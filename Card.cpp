#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(char s, char v) {
  if ((s == 'H') | (s == 'C') | (s == 'D') | (s == 'S')) {
    suit = s;
  } else {
    cout << "Invalid card suit error, check populateDeck()";
  }

  if ((v == 'A') | (v == '2') | (v == '3') | (v == '4') | (v == '5') | (v == '6') |
     (v == '7') | (v == '8') | (v == '9') | (v == 'T') | (v == 'J') | (v == 'Q') |
     (v == 'K')) {

    value = v;
  } else {
    cout << "Invalid card value error, check populateDeck()";
  }
}

void Card::showCard() {
	cout << value << suit;
}
