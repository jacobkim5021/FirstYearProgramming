#include <iostream>
using namespace std;

int main() {
	char input[2];
	char a1, a2, a3;
	int passcode;
	cout << "Enter three characters consecutively without space:";
	cin >> input; 
	a1 = input[0];
	a2 = input[1];
	a3 = input[2];
	passcode = 1000000 * a1 + 1000 * a2 + a3;
	cout << "The corresponding passcode is: ";
	cout << passcode << endl;
}