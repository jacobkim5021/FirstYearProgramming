#include <iostream>
using namespace std;

int main(){

	int number;
	cout << "Enter an integer: ";
	cin >> number;
	
	if (cin.good()){
		char next = cin.get();
		bool endOfInt = (next == ' ') || (next == '\n') || (next == '\t');
		if (endOfInt)
			cout << "The integer that you have entered is " << number; 
		else {
			cerr << "Error: Invalid input. Not an integer.";
			return -1;
		}
	}
	else {
		cerr << "Error. Invalid input. Not a number.";	
		return -1;
	}
	






	return 0;
}