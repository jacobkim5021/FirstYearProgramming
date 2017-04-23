#include <iostream>
using namespace std;

int main(){
	int xposition = 1;
	int yposition = 1;
	int x = 10;
	int y = 10;
	char input;
	
	while(input != 'x'){
		for(int h=1 ; h <= y ; h++){
			for(int i=1 ; i <= x ; i++){
				if(i == xposition && h == yposition){
					cout << "O ";
				}
				else{
					cout << "- ";
				}
			}
			cout << endl; 
		}
		cin >> input;
		if(input == 'w'){
			if(yposition == 1){
				yposition = 1;
			}
			else
				yposition -= 1;
		} 
		else if(input == 'a'){
			if(xposition == 1){
				xposition = 1;
			}
			else
				xposition -= 1;
		}
		else if(input == 's'){
			if(yposition == y){
				yposition = y;
			}
			else
				yposition += 1;
		}
		else if(input == 'd'){
			if(xposition == x){
				xposition = x;
			}
			else
				xposition += 1;
		}
		else
			cerr << "w, a, s, d";
		
	}
	
	
	
	
	
	



	return 0;
}



