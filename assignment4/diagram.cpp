#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){

	for(int h=0 ; h<60 ; h++){
	
		for(int i=0 ; i<60 ; i++){
			cout << "=";
		}
		
		cout << endl;
		
		for(int k=0 ; k<60 ; k++){
			if(k == h)
				cout << "O";
			else
				cout << " ";
		}
		
		cout << endl;
		
		for(int j=0 ; j<60 ; j++){
			cout << "=";
		}
		
		for(int l=0 ; l < 1000000 ; l++){
			l = (l + l)/2;
		}
		system("cls");
	}


	return 0;
}