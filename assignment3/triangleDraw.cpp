#include <iostream>
using namespace std;

int main(){
	int base;
	int height;
	int spaceCounter = 0;
	
	cout << "Please enter an odd size for the base of the triangle: ";
	cin >> base;
	
	height = base;
	
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
		for(int i=height ; i>0 ; i--){
			cout << "*";
		}
		cout << endl;
		height -= 2;
		
		spaceCounter += 1;
		for(int j = 0 ; j < spaceCounter ; j++){
			cout << " ";
		}
	}
	
	return 0;
}