#include <iostream>
#include <string>
#include <fstream> 
using namespace std;

int Rules(){
	cout << "Here are the rules:\n";
		//open GinRules.txt
		//This will save space on the final code
		ifstream infile1;
   		infile1.open("GinRulesV1.txt");
    	//Fail check
    	if(infile1.fail()){ cout << "File failed to open.\n"; exit(1); }
	    //Prints file to screen and closes the file
   		cout << infile1.rdbuf();
    	infile1.close();
	

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
		Rules();
	   	}
	
	else{
		cout << "Please select a valid option";
	}
	return 0;
}
