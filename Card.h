#ifndef Card_H
#define Card_H
#include <iostream>

using namespace std;

class Card {
private:
  string suit;
  string value;
  int cardPoint;
public:
  Card(string, string);
  void showCard();
};

#endif
