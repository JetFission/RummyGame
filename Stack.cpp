#include <iostream>

using namespace std;

class Stack {
private:
  Card *deck;
  int size;
  int top;
public:
  Stack(int s);
  void push(Card d);
  Card pop();
  void expandSize();
};

Stack::Stack(int s) {
  size = s;
  deck = new Card[size];
  top = -1;
}

void Stack::push(Card d) {
  if(size == top) {
    expandSize();
  }

  deck[top + 1] = d;
  top++;
}

Card Stack::pop() {
  top--;
  return deck[top + 1];
}

void Stack::expandSize() {
  Card *temp = new Card[size * 2];

  for (int i = 0; i < size; i++) {
    temp[i] = deck[i];
  }

  deck = temp;
}
