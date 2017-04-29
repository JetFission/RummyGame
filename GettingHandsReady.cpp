#include <iostream>       // std::cout
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

char p1;
string p2;
int p3, p4;

int myrandom(int i) { return rand() % i; }

struct Card
{
	string suit;
	char value;
	int deadwoodVal;
	int orderVal;
};




int main()
{
	
	
	srand(time(0)); //each shuffle will be different

	vector<Card> deck;
	Card d; //used to load cards into the vector

string suit[4] =  { "_Hrt", "_Dia", "_Clb", "_Spd" }; //Heart, Diamond, Club, Spade
char card[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'}; //Accepted Values

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 13; j++){
			d.suit = suit[i];
			d.value = card[j];
			
			
			//Assigns Deadwood Values and Order Weight to each Card
			if(card[j] == 'A'){
			d.deadwoodVal = 1;
			d.orderVal = 1;	
			}
			else if (card[j] == 'T'){
			d.deadwoodVal = 10;
			}
			else if((card[j] <= '9')&&(card[j] >= '2')){
			d.deadwoodVal = card[j] - '0';
			d.orderVal = card[j] - '0';
			};
			
			
			
		
			
			deck.push_back(d);
		}
	}

	random_shuffle(deck.begin(), deck.end() , myrandom); //shuffles the deck

	//---------------New Part 4/12/2017 9:00 am---------------//


    vector<Card> player; //players hand
    vector<Card> computer; //computers hand

    Card inter;


    for(int i = 0; i < 10; i++){ //load players hand and delete the cards taken from the deck
        inter.value = deck[i].value;
        inter.suit = deck[i].suit;
		inter.deadwoodVal = deck[i].deadwoodVal;
		
        player.push_back(inter);

        deck.erase(deck.begin(), deck.begin()+1);

    }

    for(int i = 0; i < 10; i++){ //load Computers hand and delete the cards taken from the deck
    
        inter.value = deck[i].value;
        inter.suit = deck[i].suit;
		inter.deadwoodVal = deck[i].deadwoodVal;
        computer.push_back(inter);

        deck.erase(deck.begin(), deck.begin()+1);

    }

    cout << "-------------Players hand------------------" << endl;
    cout << endl;

    for(unsigned int i = 0; i < player.size(); i++){
        //cout << player[i].suit << "\t" << player[i].value << endl;
        cout << player[i].value << player[i].suit << "  " << player[i].deadwoodVal << endl;
    }

    cout << endl;



    cout << "-------------Computers hand-----------------" << endl;
    cout << endl;

    for(unsigned int i = 0; i < computer.size(); i++){
        cout << computer[i].value << computer[i].suit << "  " << computer[i].deadwoodVal << endl;
    }



    cout << "----------Deck after drawing cards----------" << endl;
    cout << endl;
    int amount = 0;


    for(unsigned int i = 0; i < deck.size(); i++){
        cout << deck[i].value << deck[i].suit << " " << deck[i].deadwoodVal << endl;
        amount++;
    }

    cout << "Should have less than 52 cards, does it? " << amount << endl;




cout << "\nSORTING\n*******************************************************************" << endl;
//SORTING

//Sort by Suit
for(int x = 0; x < 52; ++x){
for(int handSlot = 0; handSlot < (player.size() - 1); ++handSlot){
if(player[handSlot].suit < player[handSlot + 1].suit){

p1 = player[handSlot].value;
p2 = player[handSlot].suit;
p3 = player[handSlot].deadwoodVal;
p4 = player[handSlot].orderVal;

player[handSlot].suit = player[handSlot + 1].suit;
player[handSlot].value = player[handSlot + 1].value;
player[handSlot].deadwoodVal =player[handSlot + 1].deadwoodVal;
player[handSlot].orderVal = player[handSlot + 1].orderVal;

player[handSlot +1].value = p1;
player[handSlot +1].suit = p2;
player[handSlot +1].deadwoodVal =p3;
player[handSlot +1].orderVal = p4;
}}};


//Sort Suits by Number
for(int x = 0; x < 52; ++x){

for(int handSlot = 0; handSlot < (player.size() - 1); ++handSlot){//====
if((player[handSlot].orderVal > player[handSlot + 1].orderVal)&&(player[handSlot].suit == player[handSlot + 1].suit)){
p1 = player[handSlot].value;
p2 = player[handSlot].suit;
p3 = player[handSlot].deadwoodVal;
p4 = player[handSlot].orderVal;

player[handSlot].suit = player[handSlot + 1].suit;
player[handSlot].value = player[handSlot + 1].value;
player[handSlot].deadwoodVal =player[handSlot + 1].deadwoodVal;
player[handSlot].orderVal = player[handSlot + 1].orderVal;

player[handSlot + 1].value = p1;
player[handSlot +1].suit = p2;
player[handSlot +1].deadwoodVal =p3;
player[handSlot].orderVal = p4;
}}};


//Print to Check Sort
for(int handSlot = 0; handSlot < (player.size()); ++ handSlot){
//cout << player[handSlot].value << player[handSlot].suit << "     " << player[handSlot].deadwoodVal << endl;
cout << player[handSlot].value << player[handSlot].suit << "  ";
}



	return 0;
}
