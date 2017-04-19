#include <iostream>
using namespace std;

int main(){
int csize = 10;	
int psize = 10;	
char dummychar;

cout << "****************************************************************" << endl;
cout << "* Player Score:" << "000" << "\tStock Size:" << "00" << "\t\tTop Card:" << "XX" << "    *" << endl;
cout << "* Computer Score:" << "000" << "\tDiscard Size:" << "00" << "\t\tBottom Card:" << "XX" << " *" <<endl;
cout << "****************************************************************" << endl;

cout << "\t\t\t::Computers Hand::\n\t\t";
for(int i = 0; i < csize; ++i){
cout << "XX" << "  ";
}

cout << "\n\n";

cout << "\t\t\t::Players Hand::\n\t\t";
for(int i = 0; i < csize; ++i){
cout << "XX" << "  ";
}
cout << endl;
cout << "****************************************************************" << endl;
cout << "\t\t\t   ::Player Actions::" << endl;
cout <<"\t\tA)Play\tB)Draw\tC)Move\tD)View\tE)Exit" << endl;
cout <<"\t\tPlease Select Action::";
cin >> dummychar;
cout << endl;



  return 0;
}
