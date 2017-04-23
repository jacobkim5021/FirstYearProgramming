#include <iostream>
using namespace std;

int main(){
	int base;
	int initialInput;
	int spaceCounter = 0;
	
	cout << "Please enter the base/height (odd number) of the hour-glass:";
	cin >> base;
	
	initialInput = base;
	
	bool odd = base % 2;
	
	if (!odd){
		cerr << "Error: Enter an odd size.";
		return -1;
	}
	else if(base < 0){
		cerr << "Error: Enter a positive, odd integer.";
		return -1;
	}
	
	
	for(int k=base ; k > 0 ; k -= 2){
		for(int i=base ; i>0 ; i--){
			cout << "*";
		}
		cout << endl;
		if (base == 1){
			break;
		}
		
		base -= 2;
		
		spaceCounter += 1;
		for(int j = 0 ; j < spaceCounter ; j++){
			cout << " ";
		}
		
	}
	spaceCounter -= 1;
	
	for(int k=base ; k < initialInput ; k+=2){
		base += 2;
		for(int j = 0 ; j < spaceCounter ; j++){
			cout << " ";
		}
		for(int i=base ; i>0 ; i--){
			cout << "*";
		}
		cout << endl;
		spaceCounter -= 1;
	}
	
	
	
	
	
	return 0;
}