#include "Card.h"
#include "Deck.h"
#include <string>;
#include <iostream>;
using namespace std;

int Rules();
void mainLoop();

int main() {
	string answer; //variable to check options with
	cout << "Welcome to Gin Rummy, please select an option:\n\n";
	cout << "Play:\n-Start the game\n\n";
	cout << "Rules:\n-How to play the game\n\n";
	cout << "Exit:\n-Closes the Game\n\n";
	cin >> answer;
	cout << endl;
	bool menuloop = true;
	
	while (menuloop == true){
	
	//multiple ways to input 'play'
	if((answer == "Play") || (answer == "play") || (answer == "P") || (answer == "p")){
		menuloop = 0;
		cout << "Let's play\n";
		//can call function to start game
		mainLoop();
	}
	//multiple ways to input 'rules'
	else if((answer == "Rules") || (answer == "rules") || (answer == "R") || (answer == "r")){
		menuloop = 1;
		Rules(); //seperate function to open rules.exe
		cout << "----------------------------------------------\n\n";
		cout << "Welcome to Gin Rummy, please select an option:\n\n";
		cout << "Play:\n-Start the game\n\n";
		cout << "Rules:\n-How to play the game\n\n";
		cout << "Exit:\n-Closes the Game\n\n";
		cin >> answer;
		cout << endl;
	   	}
	//adds exit option
	else if((answer == "Exit") || (answer == "exit") || (answer == "E") || (answer == "e")){
		menuloop = 0;
		cout << "===Program Terminated===" << endl; //seperate function to open rules.exe
	   	}
	
	else{cout << "Please select a valid option\n" << endl; menuloop = false;}
}
	
	return 0;

}

void mainLoop() {
  
	//initalize decks, may have to remove the () on these
	Deck stockPile();
	Deck discardPile();
	Deck playerHand();
	Deck AIHand();
	
	//prepare stock pile
	stockPile.populateDeck();
	stockPile.shuffle();
	
	//deal cards to players and ai
	for (int i = 0; i < 9; i++) {
		playerHand.addCard(stockPile.removeTopCard);
		AIHand.addCard(stockPile.removeTopCard);
	}
	
	//initalize discard pile
	discardPile.addCard(stockPile.removeTopCard);
	
	//persistent variables here
	boolean finished = false;
	int playerScore = 0;
	int AIScore = 0;
	int turn = 1; //1 is the players turn, 2 is the AI's turn
	
	while (!finished) {
		
		//game logic goes here
		
		//player turn
		if (turn == 1) {
			//show game UI
			int csize = 10;	
			int psize = 10;	
			char dummychar;

			cout << "****************************************************************" << endl;
			cout << "* Player Score:" << "000" << "\tStock Size:" << "00" << "\t\tTop Card:" << "XX" << "    *" << endl;
			cout << "* Computer Score:" << "000" << "\tDiscard Size:" << "00" << "\t\tBottom Card:" << "XX" << " *" <<endl;
			cout << "****************************************************************" << endl;

			cout << "\t\t\t::Computers Hand::\n\t\t";
			for (int i = 0; i < csize; ++i) {
				cout << "XX" << "  ";
			}

			cout << "\n\n";

			cout << "\t\t\t::Players Hand::\n\t\t";
			for (int i = 0; i < csize; ++i) {
				cout << "XX" << "  ";
			}

			cout << endl;
			cout << "****************************************************************" << endl;
			cout << "\t\t\t   ::Player Actions::" << endl;
			cout <<"\t\tA)Play\tB)Draw\tC)Move\tD)View\tE)Exit" << endl;
			cout <<"\t\tPlease Select Action::";
			cin >> dummychar;
			cout << endl;
			
			if (dummychar == 'c') {		//example
				//do something
			}
		}
		
		if (turn == 2) {
			//ai turn
		}
		
	}
}

int Rules(){cout << "Here are the rules:\n"; system ("start rules.exe");}
//open rules.exe
//This will save space on the final code
		
