#include <iostream>
using namespace std;

int main(){
	int numbers[5];
	int swapped = 1;
	int swapCount = 0;
	int tempValue;
	
	cout << "Enter 5 ID: ";
	
	for(int h=0; h<5; h++){
		cin >> numbers[h];
	}
	
	for(int i=0; i<5; i++){
		if(cin.fail() || numbers[i] > 99999999 || numbers[i] < 10000000){
			cerr << "Error: Invalid input.";
		}
	}
	
	while(swapped == 1){
		swapped = 0;
		for(int j=0; j<4; j++){
			if(numbers[j] < numbers[j+1]){
				tempValue = numbers[j];
				numbers[j] = numbers[j+1];
				numbers[j+1] = tempValue;
				swapped = 1;
				swapCount += 1;
			}
		}
		
	}
	
	cout << "Sorted ID: ";
	
	for(int k=0;k<5;k++){
		cout << numbers[k] << " ";
	}

	cout << endl << "Swap count: " << swapCount << endl << "Enter another input: ";
	
	int newInput;
	int newInputPosition;
	cin >> newInput;
	
	if(cin.fail() || newInput < 10000000 || newInput > 99999999)
		cerr << "Error: Invalid input.";
	if(newInput < numbers[4]){
		newInputPosition = 5;
	}
	else{
		for(int l=4; l>=0; l--){
			if(newInput>numbers[l])
				newInputPosition = l;
			else if(newInput == numbers[l])
				cerr << "Error: This ID exists.";	
		}
	}
	
	cout << "The value " << newInput << " is in position " << newInputPosition;

	
	
	

	return 0;
}