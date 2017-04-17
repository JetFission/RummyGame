#include "Card.h"
#include <iostream>

using namespace std;

Card::Card(string s, string v) {
  if ((s == "Hearts") | (s == "Clubs") | (s == "Diamonds") | (s == "Spades")) {
    suit = s;
  } else {
    cout << "Invalid suit";
  }

  if ((v == "Ace") | (v == "2") | (v == "3") | (v == "4") | (v == "5") | (v == "6") |
     (v == "7") | (v == "8") | (v == "9") | (v == "10") | (v == "Jack") | (v == "Queen") |
     (v == "King")) {

    value = v;
  } else {
    cout << "Invalid value";
  }
}
