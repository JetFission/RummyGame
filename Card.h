#ifndef Card_H
#define Card_H
#include <iostream>

using namespace std;

class Card {
private:
  string suit;
  string value;
public:
  Card(string, string);
  void showCard();
};

#endif
