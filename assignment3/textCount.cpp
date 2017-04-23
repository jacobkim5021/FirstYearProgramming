#include <iostream>
using namespace std;

int main(){
	char input[100];
	int counter = 0;
	cout << "Enter text without whitespace: ";
	cin >> input;
	
	for(int i=0; input[i] != '\0'; i++){
		counter += 1;
	}
	
	cout << "The length of the entered text is: " << counter;
	return 0;
}