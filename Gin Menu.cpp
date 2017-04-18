#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

int Rules(){
	cout << "Here are the rules:\n";
		//open rules.exe
		//This will save space on the final code
		system ("start rules.exe");
};

int main(){
	string answer = "null";
	cout << "Welcome to Gin Rummy, please select an option:\n\n";
	cout << "Play:\n-Start the game\n\n";
	cout << "Rules:\n-How to play the game\n\n";
	cin >> answer;
	cout << endl;
	ofstream GinRules;
	if((answer == "Play") || (answer == "play") || (answer == "P") || (answer == "p")){
		cout << "Let's play\n";
		//can call function to start game
	}
	
	if((answer == "Rules") || (answer == "rules") || (answer == "R") || (answer == "r")){
		Rules(); //seperate function to open rules.exe
	   	}
	
	else{
		cout << "Please select a valid option";
	}
	return 0;
}
