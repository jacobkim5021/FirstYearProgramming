#include <iostream>
using namespace std;

int main(){
	int A, B;
	
	cout << "Enter two integer numbers (each separated by a space): ";
	cin >> A >> B;
	
	int C = A >> B;
	int D = C & 1;

	cout << "The value of Bit " << B << " is " << D;

}