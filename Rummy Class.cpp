#include <iostream>
using namespace std;

class Card {
	private:

	public:
	string suit;	   				 	     //Card Suit
	char value; 							 //Card Value
	Card();
};

Card::Card(){}; 							//Place Holder Code


int main(){
//Possible Values and Suits for each Card.

//string ClassSuits[4] =  { "\u2661", "\u2662", "\u2663", "\u2660" }; //Heart, Diamond, Club, Spade *Not outputting Ascii in Command Prompt, Double check linux Output
string ClassSuits[4] =  { "_Hrt", "_Dia", "_Clb", "_Spd" }; //Heart, Diamond, Club, Spade
char NumValues[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}; //Accepted Values

int CardID=0; 								//Card Number 0 through 51
Card MainDeck[52];							//Creates a Deck of Blank Cards
for(int i = 0; i < 4; ++i){					//Suit Assignment Loop
for(int j = 0; j < 13; ++j){				//Value Assignment Loop

	MainDeck[CardID].suit = ClassSuits[i]; //Sets The Card's Suit
	MainDeck[CardID].value = NumValues[j]; //Sets The Card's Value

//cout << MainDeck[CardID].value << MainDeck[CardID].suit << endl; //Debug Code: Displays all cards

++CardID; 									//Moves to the next Blank Card
};
};

/* 
//Debug Code; Lets user check individual card id's
cin >> CardID;
cout << MainDeck[CardID].value << MainDeck[CardID].suit << endl;
*/

  return 0;
}

