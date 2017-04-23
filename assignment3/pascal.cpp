#include <iostream>
using namespace std;

int main(){
	int input;
	
	cout << "Number of 1s: ";
	cin >> input;
	
	int array[input];

	for(int i=0 ; i < input ; i++){
		array[i] = 1;
	}
	
	for(int h=0 ; h < input ; h++){
		cout << array[h] << " ";
	}
	
	cout << endl;
	
	int d = 1;
	
	for(int k = 1 ; k < input ; k++){
		cout << array[0] << " ";
		for(int j=1 ; j < input - d; j++){
			array[j] += array[j-1];
			cout << array[j] << " ";
		}
		cout << endl;
		d += 1;
	}
	
	return 0;
}