#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <random>
#include <ctime>        // std::time
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int myrandom(int i) { return rand() % i; }
void mainLoop();

int random(int min, int max) //range : [min, max)
{
   static bool first = true;
   if ( first )
   {
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min);
}

class Card {
private:
	char suit;
	char value;
	int pointVal; //used to help determine melds
public:
	Card(char, char, int);
	Card();
	char getValue(); //used for initializing and dealing out cards
	char getSuit();
	void showCard();
	int getPoints();
};

Card::Card() {

}

Card::Card(char s, char v, int p) {
		suit = s;
		value = v;
		pointVal = p;
}

void Card::showCard() {
	cout << value << suit << " ";
}

char Card::getValue() {
	return value;
}

int Card::getPoints() {
	return pointVal;
}

char Card::getSuit() {
	return suit;
}

class Deck {
private:
	vector<Card> deck;
	vector<Card> set;
public:
	Deck();
	void shuffle();
	void addCard(Card);
	Card removeTopCard();
	void populateDeck();
	void deleteDeck(); // called only once
	void printDeck();
	Card removeCardAt(int num);
	void scanMelds();
	void showTopCard();
	int calculateDeadwood();
	vector<Card> sort(vector<Card>);
	vector<Card> sortByValue(vector<Card>);
	void sortDeck();
	void scanSets();
	void scanRuns();
	bool hasSets();
	char getSetType();
	char getTopCardValue();
	int getSetSize();
};

Deck::Deck() {

}

int Deck::getSetSize() {
	return set.size();
}

char Deck::getTopCardValue() {
	return deck[deck.size() - 1].getValue();
}

bool Deck::hasSets() {
	return set.size() > 0;
}

char Deck::getSetType() {
	return set[0].getValue();
}

void Deck::printDeck() {
	if (set.size() > 0) {
		cout << "{ ";
		for (unsigned int i = 0; i < set.size(); i++) {
			set[i].showCard();
		}
		cout << "}";
	}

	for (unsigned int i = 0; i < deck.size(); i++) {
		deck[i].showCard();
	}
}

void Deck::deleteDeck()
{
	for (int i = 0; i < 10; i++)
	{
		deck.erase(deck.begin(), deck.begin() + 1);
	}
}

void Deck::shuffle()
{
	srand(time(0));
	random_shuffle(deck.begin(), deck.end(), myrandom);
}

void Deck::addCard(Card c) {
	deck.push_back(c);
}

Card Deck::removeCardAt(int num) {
	if (set.size() > num) {
		Card card = set[num];
		set.erase(set.begin() + num);
		return card;
	} else {
		num = num - set.size();
	 	Card card = deck[num];
	 	deck.erase(deck.begin() + num);
	 	return card;
	}
 }

Card Deck::removeTopCard() {
	Card card = deck[deck.size() - 1];
	deck.erase(deck.begin() + deck.size()); //removes card from deck. For instance, an object mainDeck of type Deck in main function
	return card;
}

void Deck::showTopCard() {
	Card card = deck[deck.size() - 1];
	card.showCard();
}

void Deck::sortDeck() {
	deck = sort(deck);
}

vector<Card> Deck::sort(vector<Card> vec) {
	vector<Card> newVector;

	while (vec.size() > 0) {
		Card card = vec[0];
		vector<Card> temp;
		for (int j = 1; j < vec.size(); j++) {
			if (vec[j].getSuit() == card.getSuit()) {
				temp.push_back(vec[j]);
				vec.erase(vec.begin() + j);
				j--;
			}
			if (j == vec.size() - 1) {
				temp.push_back(card);
				vec.erase(vec.begin());
				temp = sortByValue(temp);
				for (int i = 0; i < temp.size(); i++) {
					newVector.push_back(temp[i]);
				}
			}
		}
	}
	return newVector;
}

vector<Card> Deck::sortByValue(vector<Card> vec) {
	vector<Card> newVector;

	for (int i = 0; i < vec.size(); ++i) {
		for (int j = 0; j < vec.size() - i - 1; ++j) {
			if (vec[j].getPoints() > vec[j + 1].getPoints()) {
				Card card = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = card;
			}
		}
	}

	return vec;
}

void Deck::scanSets() {
	int j = 0;
	int countSet = 0;//keeps track of how many sets are accumulated
	vector<Card> temp;

	for (unsigned int i = 0; i < deck.size(); i++) //takes just one card
	{
		for (j = i + 1; j < deck.size(); j++) //compares each cards point value with the rest
		{
			if (deck[i].getValue() == deck[j].getValue())
			{
				countSet++;

				temp.push_back(deck[j]);
			}
		}

		if (countSet == 2 || countSet == 3)
		{

			set.push_back(deck[i]);

			deck.erase(deck.begin() + i);


			for (unsigned int k = 0; k < temp.size(); k++)
			{
				set.push_back(temp[k]);
			}
			temp.clear();


			for (unsigned int i = 0; i < set.size(); i++)
			{
				for (unsigned int j = i + 1; j < deck.size(); j++)
				{
					if (set[i].getValue() == deck[j].getValue())
						deck.erase(deck.begin() + j);
				}
			}
		}

		else //meant to delete cards added if a set was not formed
		{
			temp.clear();
		}
		countSet = 0;
	}
}

void Deck::scanMelds() {

}

int Deck::calculateDeadwood() {
	int points = 0;
	for (int i = 0; i < deck.size(); i++) {
		points += deck[i].getPoints();
	}

	return points;
}

void Deck::populateDeck()
{

	char suit[4] = { 'H', 'D', 'C', 'S' };
	char value[13] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			int points = 0;

			if (value[j] == 'A')
				points = 1;
			if (value[j] == 'J' || value[j] == 'Q' || value[j] == 'K')
				points = 10;
			if (value[j] == 'T')
				points = 10;
			if (value[j] == '2' || value[j] == '3' || value[j] == '4' || value[j] == '5' || value[j] == '6' || value[j] == '7' || value[j] == '8' || value[j] == '9')
				points = j + 2;

			Card card(suit[i], value[j], points);
			deck.push_back(card);
		}
	}
}

int main() {
	//start main menu
	string answer; //variable to check options with
	cout << "Welcome to Gin Rummy, please select an option:\n\n";
	cout << "Play:\n-Start the game\n\n";
	cout << "Rules:\n-How to play the game\n\n";
	cout << "Exit:\n-Closes the Game\n\n";
	cin >> answer;
	cout << endl;
	bool menuloop = true;

	while (menuloop){

		//multiple ways to input 'play'
		if((answer == "Play") || (answer == "play") || (answer == "P") || (answer == "p")) {
			menuloop = 0;
			cout << "Let's play\n";
			//can call function to start game
			mainLoop();
		}

		//multiple ways to input 'rules'
		else if((answer == "Rules") || (answer == "rules") || (answer == "R") || (answer == "r")){
			menuloop = 1;
			//Rules(); //seperate function to open rules.exe
			cout << "----------------------------------------------\n\n";
			cout << "Welcome to Gin Rummy, please select an option:\n\n";
			cout << "Play:\n-Start the game\n\n";
			cout << "Rules:\n-How to play the game\n\n";
			cout << "Exit:\n-Closes the Game\n\n";
			cin >> answer;
			cout << endl;
		}
		//adds exit option
		else if((answer == "Exit") || (answer == "exit") || (answer == "E") || (answer == "e")) {
			menuloop = 0;
			cout << "===Program Terminated===" << endl; //seperate function to open rules.exe
		} else {
			cout << "Please select a valid option\n" << endl;
			menuloop = false;
		}
	}

	return 0;
}

void mainLoop() {
	//persistent game variables here
	bool roundFinished = false;
	bool gameFinished = false;
	int playerScore = 0;
	int AIScore = 0;
	int turn = 1; //1 is the players turn, 2 is the AI's turn
	string message = "";
	int roundNum = 1;

	while (!gameFinished) {
		//initalize decks, may have to remove the () on these
		Deck stockPile;
		Deck discardPile;
		Deck playerHand;
		Deck AIHand;

		//prepare stock pile
		stockPile.populateDeck();
		stockPile.shuffle();

		//deal cards to players and ai
		for (int i = 0; i < 10; i++) {
			playerHand.addCard(stockPile.removeTopCard());
			AIHand.addCard(stockPile.removeTopCard());
		}

		//initalize discard pile
		discardPile.addCard(stockPile.removeTopCard());

		while (!roundFinished) {

			//player turn
			if (turn == 1) {
				//show game UI, drawing
				int csize = 10;
				int psize = 10;
				char choice;

				if (system("CLS")) system("clear");
				cout << message;
				message = "";

				cout << endl;
				cout << "****************************************************************" << endl;
				cout << "* Player Score:" << playerScore << "\tDeadwood: " << playerHand.calculateDeadwood() << endl;
				cout << "* Computer Score:" << AIScore << "\tRound " << roundNum << "\t\tDiscard Pile Top Card: ";
				discardPile.showTopCard();
				cout << endl;
				cout << "****************************************************************" << endl;

				cout << "\t\t\t::Computers Hand (debug)::\n\t\t";
				AIHand.printDeck();

				cout << "\n\n";

				cout << "\t\t\t::Players Hand::\n\t\t";
				//-------------Scan player melds-----------
				playerHand.scanSets();
				//playerHand.sortDeck();
				playerHand.printDeck();

				cout << endl;
				cout << "****************************************************************" << endl;
				cout << "\t\t\t   ::Draw::" << endl;
				cout <<"\t\td)from discard pile\ts)from stock pile" << endl;
				cout <<"\t\tPlease Select Action: ";
				cin >> choice;
				cout << endl;

				if (choice == 'd') { 		//drawing from discard pile
					playerHand.addCard(discardPile.removeTopCard());
				}
				if (choice == 's') {	//drawing from stock pile
					playerHand.addCard(stockPile.removeTopCard());
				}

				//-----------scan player melds-------------
				playerHand.scanSets();

				bool loop = false;
				do {
					if (system("CLS")) system("clear");
					cout << message << endl;
					message = "";

					cout << "****************************************************************" << endl;
					cout << "* Player Score:" << playerScore << "\tDeadwood: " << playerHand.calculateDeadwood() << endl;
					cout << "* Computer Score:" << AIScore << "\tRound " << roundNum << "\t\tDiscard Pile Top Card: ";
					discardPile.showTopCard();
					cout << endl;
					cout << "****************************************************************" << endl;

					cout << "\t\t\t::Computers Hand (debug)::\n\t\t";
					AIHand.printDeck();

					cout << "\n\n";

					cout << "\t\t\t::Players Hand::\n\t\t";
					//playerHand.sortDeck();
					playerHand.printDeck();

					cout << endl;
					cout << "****************************************************************" << endl;
					cout << "\t\t\t   ::Discard::" << endl;
					cout <<"\t\td)discard\tk)knock" << endl;
					cout <<"\t\tPlease Select Action: ";
					cin >> choice;
					cout << endl;

					if (choice == 'd') {		//discard
						int cardNum = 0;
						cout << "Enter card number to discard: ";
						cin >> cardNum;
						discardPile.addCard(playerHand.removeCardAt(cardNum));
						loop = false;
					}
					if (choice == 'k') {	//knock, if possible
						if (playerHand.calculateDeadwood() <= 10) {
							roundNum++;
							if (playerHand.calculateDeadwood() > AIHand.calculateDeadwood()) {
								int score = 25 + (playerHand.calculateDeadwood() - AIHand.calculateDeadwood());
								AIScore += score;
								message = "Undercut! Computer gets ";
								message += score;
								message += " points.";
							} else {
								int score = AIHand.calculateDeadwood() - playerHand.calculateDeadwood();
								playerScore +=score;
								message = "Player knocks, earns ";
								message += score;
								message += " points!";
							}
							roundFinished = true;
						}
						if (playerHand.calculateDeadwood() > 10) {
							if (system("CLS")) system("clear");
							message = "Can't knock yet!";
							loop = true;
						}
					}
				} while (loop);
			}

			//ai turn
			if (turn == 2) {
				//-----------scan ai melds-------------
				AIHand.scanSets();

				if (!AIHand.hasSets()) {
					AIHand.addCard(stockPile.removeTopCard());

					int discardCard = random(0, 10);
					discardPile.addCard(AIHand.removeCardAt(discardCard));
				}
				if (AIHand.hasSets()) {
					char setType = AIHand.getSetType();
					char discardValue = discardPile.getTopCardValue();

					if (setType == discardValue)
						AIHand.addCard(discardPile.removeTopCard());
					else
						AIHand.addCard(stockPile.removeTopCard());

					if (AIHand.calculateDeadwood() <= 10) {
						roundNum++;
						if (AIHand.calculateDeadwood() > playerHand.calculateDeadwood()) {
							int score = 25 + (AIHand.calculateDeadwood() - playerHand.calculateDeadwood());
							playerScore += score;
							message = "Undercut! Player gets ";
							message += score;
							message += " points.";
						} else {
							int score = playerHand.calculateDeadwood() - AIHand.calculateDeadwood();
							AIScore +=score;
							message = "Computer knocks, earns ";
							message += score;
							message += " points!";
						}
						roundFinished = true;
					}

					int discardCard = random(AIHand.getSetSize(), 10);
					discardPile.addCard(AIHand.removeCardAt(discardCard));
				}
			}

			//swtich turns
			if (turn == 2) {
				turn = 1;
			} else {
				turn = 2;
			}
		}
	}
}
