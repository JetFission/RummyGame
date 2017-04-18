#include <iostream>
#include "Deck.h"

using namespace std;

//----------------4/17/2017-------------//

int main()
{
	Deck player;
	Deck computer;
	Deck mainDeck;
	Deck gateKeeper;

	mainDeck.populateDeck();
	mainDeck.shuffle();

	mainDeck.printDeck();

	gateKeeper.dealHands(player,mainDeck);

	gateKeeper.dealHands(computer,mainDeck);

	player.printDeck();

	computer.printHand();

	mainDeck.printDeck();


	system("pause");
	return 0;
}
