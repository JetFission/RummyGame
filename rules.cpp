#include <iostream>
#include <cstring>
using namespace std;

bool rules = true;

int main()  {
	string answer = "null";
	//display rules
	while(rules == true){
	cout <<"\tBasic Rules:\n\n"
		 <<"************************************************************************\n"
		 <<"-Your hand will have ten cards\n"
		 <<"-When drawing, you can select the top card from the deck or discard pile\n"
		 <<"-Once a card is drawn, one card from your hand must be discarded.\n"
		 <<"   -Note: it may be the drawn card\n-Aces are low, worth one point\n"
		 <<"-Face cards are worth ten points\n-The game is composed of rounds\n"
		 <<"-You are trying to get to 50 points before the other player\n"
		 <<"-The starting player will alternate each round\n"
		 <<"************************************************************************\n\n"
		 <<"Press Enter to continue:";
	if (cin.get() == '\n')
    //cout << string( 30, '\n' );
    cout <<"\n\tCommon Terms:\n\n"
		 << "************************************************************************\n"
    	 <<"-Meld: a run or set.\n"
    	 <<"-Run: comprised of at least three cards in numerical order of the same suit.\n"
    	 <<"-Set: comprised of three or four cards of the same value.\n"
    	 <<"-Deadwood: cards that are not in a meld. Your deadwood score is the face value \n"
    	 <<"           of the cards in your deadwood. Aces are 1 point, faces cards are 10\n"
    	 <<"-Knocking: going out when your deadwood is worth 10 or fewer points\n"
    	 <<"-Going Gin: knocking when your deadwood is worth zero points.\n"
		 <<"            When all of your cards are in melds\n"
    	 <<"************************************************************************\n\n"
    	 <<"Press Enter to continue:";
	if (cin.get() == '\n')
	cout <<"\n\tObjective:\n\n"
		 <<"************************************************************************\n\n"
		 <<"-Get to 50 points before the other player.\n"
		 <<"-Get your cards into runs and/or sets and then knocking or declaring Gin.\n"
		 <<"-You may knock when your deadwood is worth ten or fewer points.\n"
		 <<"-The other player, known as the defending player, may \"lay off\" their deadwood.\n"
		 <<"-Laying Off: defender may add to the knocker's melds.\n"
		 <<"	-I.E. continue a run or add to a set\n"
		 <<"-The defender cannot lay off cards if the other player has declared Gin\n"
		 <<"************************************************************************\n\n"
		 <<"Press Enter to continue:";
	if (cin.get() == '\n')
    cout <<"\n\tPoints:\n\n"
		 <<"************************************************************************\n\n"
		 <<"-Points are based on the difference of Deadwood.\n"
		 <<"-The Deadwood value of the knocking player is subtracted from the \n defender's Deadwood\n"
		 <<"-The difference is then the points for that round\n-Going Gin: gives a bonus of 25 points\n"
		 <<"-Undercutting: when the defender's Deadwood is less or equal to the knocking player's\n"
		 <<"	-Note: this can occour after laying off\n"
		 <<"-This is worth 25 points + the difference in Deadwood after laying off\n"
		 <<"************************************************************************\n\n"
		 <<"Press Enter to continue:";
    if (cin.get() == '\n')
    cout <<"\n\nDo you want to see the rules again?\n         Yes      No\n";
    cin >> answer;
    if ((answer == "Yes") || (answer == "yes") || (answer == "Y") || (answer == "y")){
    //leave blank	
	}
	if ((answer == "No") || (answer == "no") || (answer == "N") || (answer == "n")){
   	rules = false;
	}
	
	}
    
  return 0;
  }
