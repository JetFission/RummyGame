#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>

using namepsace std;

int myrandom(int i) { return rand() % i; }

class Deck{
private:
  vector<Card> deck;
public:
  void shuffle();
  void addCard(Card card);
  void removeTopCard();
  void populateDeck();
};

void Deck::shuffle() {
  random_shuffle(deck.begin(), deck.end() , myrandom);
}

void Deck::addCard(Card card) {
  deck.push_back(card);
}

void removeTopCard() {
  deck.erase(deck.begin(), deck.begin()+1); //removes card from deck. For instance, an object mainDeck of type Deck in main function
}

void populateDeck()
{
  
}
