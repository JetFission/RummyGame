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
	cout << "Exit:\n-Closes the Game\n\n";
	cin >> answer;
	cout << endl;
	ofstream GinRules;
	int menuloop = 1;
	
	while (menuloop == 1){
	menuloop = 0;
	
	if((answer == "Play") || (answer == "play") || (answer == "P") || (answer == "p")){
		menuloop = 0;
		cout << "Let's play\n";
		//can call function to start game
	}
	
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
	   	
	else if((answer == "Exit") || (answer == "exit") || (answer == "E") || (answer == "e")){
		menuloop = 0;
		cout << "===Program Terminated===" << endl; //seperate function to open rules.exe
	   	}
	
	else{
		cout << "Please select a valid option\n" << endl;
	}
}
	
	return 0;
}
