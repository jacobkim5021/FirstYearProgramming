#include <iostream>
using namespace std;

int main(){
	char input[100];
	int startingIndex;
	int endingIndex;
	char extractedWord[100];
	int j = 0;
	
	cout << "Please input a word: ";
	cin >> input;
	cout << "Please input the starting index: ";
	cin >> startingIndex;
	cout << "Please input the ending index: ";
	cin >> endingIndex;
	
	if (startingIndex < 0 || endingIndex < 0){
		cerr << "Error: Index number cannot be negative.";
		return -1;
	}
		
	
	
	for (int i=startingIndex; i<=endingIndex; i++){
		extractedWord[j] = input[i];
		j++;

	}
	
	cout << "The extracted word is: " << extractedWord;
	
	
	return 0;
}