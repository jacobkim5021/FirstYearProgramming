#include <iostream>
#include <climits>
using namespace std;

int main(){
	int a, b;
	cout << INT_MAX << " " << INT_MIN << endl;
	cout << "Enter two integers to add: " << endl;
	cin >> a >> b;
	
	if (cin.good()){
		char next = cin.get();
		bool endOfInt = (next == ' ') || (next == '\n') || (next == '\t');
		if (endOfInt)
			if (INT_MIN < a+b && INT_MAX > a+b)
				cout << "Sum of two numbers is: " << a + b;
			else
				cerr<< "Error: Summed value out of the signed int range.";
		else {
			cerr << "Error: Invalid input. Non-integer detected.";
			return -1;
		}
	}
	else {
		cerr << "Error. Invalid input. Not a number.";	
		return -1;
	}


	return 0;
}