#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;

int deadPoints1 = 0; //holds deadwood points for each of the players
int deadPoints2 = 0;

void calculateScore(int); //get the final score

//----------------4/30/2017-------------//

int main()
{
	Deck player;
	Deck computer;
	Deck mainDeck;
	Deck gateKeeper; //just used to call functions 
	Deck pile; //holds the vector for the discard pile

	
	int spot = 0; //used to hold the position of the card to be discarded

	int turn = 0; 

	char choice = ' '; //holds choice that the user makes

	bool knock = false;
	bool AI = false; //used to help A.I. make a decision 

	std::cout << "-----------------GIN RUMMY------------" << endl;
	std::cout << endl;
	std::cout << endl;
	

	mainDeck.populateDeck();
	mainDeck.shuffle();

	pile.addCard(mainDeck);
	mainDeck.deleteCard();

	gateKeeper.dealHands(player, mainDeck);
	mainDeck.deleteDeck();

	gateKeeper.dealHands(computer, mainDeck);
	mainDeck.deleteDeck();

	player.scanSet();
	player.scanRun();
	computer.scanSet();
	computer.scanRun();

	deadPoints1 = player.calculateDeadwood();
	deadPoints2 = computer.calculateDeadwood();

	

	while (mainDeck.getSizeOfStock() > 0 && knock == false)
	{

		std::cout << "****************************************************************" << endl;
		std::cout << endl;
		std::cout << "* Player Score:" << deadPoints1 << endl;
		std::cout << "* Computer Score:" << deadPoints2 << endl;
		std::cout << "Top card of the discard pile shown below " << endl;
		pile.printCard();
		std::cout << endl;
		std::cout << endl;

		std::cout << "Player's hand: " << endl;
		std::cout << endl;

		std::cout << "------------------------------------------------------------------" << endl;
		player.printHand();
		std::cout << "------------------------------------------------------------------" << endl;
		std::cout << endl;


		std::cout << "Player's melds are " << endl;
		std::cout << "------------------------------------------------------------------" << endl;
		player.printSet();
		std::cout << "------------------------------------------------------------------" << endl;
		std::cout << endl;
		player.printRun();

		std::cout << "****************************************************************" << endl;


		

		if (turn == 0)
		{
			std::cout << "Type d to draw from the discard pile " << endl;
			std::cout << "s to draw from the stock, or k to knock (must have 10 points or less of deadwood)." << endl;

			cin >> choice;

			if (choice == 'd')
			{
				player.addCard(pile);
				pile.deleteCard();
			}

			else if (choice == 's')
			{
				player.addCard(mainDeck);
				mainDeck.deleteCard();
			}

			else if (choice == 'k' && deadPoints1 <= 10)
			{
				knock == true;
				calculateScore(turn);
			}

			std::cout << endl;
			std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
			std::cout << "Please pick a card to go to the discard pile (must be one different from one drawn)." << endl;
			std::cout << "The way this works is you enter a number 0-n. With n being the last position of your card." << endl;
			std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
			std::cout << endl;

			cin >> spot;

			pile.addCardFromSpot(player, spot);
			player.deleteCardFromSpot(spot);

			player.scanSet();
			player.scanRun();


			deadPoints1 = player.calculateDeadwood();
			turn = 1; //A.I. turn
		}

		else if (turn == 1)
		{

			if (deadPoints2 <= 10)
			{
				knock == true;
				calculateScore(turn);
			}

			else if (deadPoints2 > 10)
			{
				AI = pile.checkAI(computer);

				if (AI == true) //AI draws from the discard pile
				{
					if (choice == 'd')
					{
						computer.addCard(pile);
						pile.deleteCard();
					}
				}

				else if (AI == false) //AI draws from the stock
				{
					computer.addCard(mainDeck);
					mainDeck.deleteCard();
				}

				pile.addCardFromSpot(computer, 0);
				computer.deleteCardFromSpot(0);

				computer.scanSet();

				deadPoints2 = computer.calculateDeadwood();
			}
			turn = 0; //back to the player's turn
		}
		
	}

	if (knock = false)
	{
		cout << "--------------------------------------------------------" << endl;
		cout << "It is a tie because there are no more cards in the deck. " << endl;
		cout << "--------------------------------------------------------" << endl;
	}
	
	std::system("pause");
	return 0;
}

void calculateScore(int theTurn)
{
	int finalScore = 0;
	if (theTurn == 0)
	{
		finalScore = deadPoints2 - deadPoints1;

		cout << ":::::::::::::::: END OF GAME ::::::::::::::::::::" << endl;
		cout << "Player wins! with a score of " << finalScore << endl;
		cout << ":::::::::::::::: END OF GAME ::::::::::::::::::::" << endl;
	}

	else if (theTurn == 1)
	{
		finalScore = deadPoints1 - deadPoints2;

		cout << ":::::::::::::::: END OF GAME ::::::::::::::::::::" << endl;
		cout << "Computer wins! with a score of " << finalScore << endl;
		cout << ":::::::::::::::: END OF GAME ::::::::::::::::::::" << endl;
	}

}
