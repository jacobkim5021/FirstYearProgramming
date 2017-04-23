#include <iostream>
using namespace std;

int main(){
	int input;
	unsigned long long factorial = 1;
	
	cout << "Enter a number: ";
	cin >> input;
	
	if (input <= 20 & input > 0){
		
		for(int i=input; i>0; i--){
			factorial *= i;
		}
			
		cout << "Its factorial is " << factorial;

		return 0;
	}
	else if (input == 0) {
		factorial = 1;
		cout << "Its factorial is " << factorial;
	}
	else {
		cerr << "Error: Invalid input. Program terminated.";
		return -1;
	}
}