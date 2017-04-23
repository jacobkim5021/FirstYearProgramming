#include <iostream>
using namespace std;

int main(){
	int wall;		//distance from left wall to right wall INCLUDING wall characters
	int	snake;		//snake length INCLUDING head and tail characters
	int distance;  //Wall to tail distance EXCLUDING wall and tail characters
	cout << "Wall-to-wall dimension: ";
	cin >> wall;
	cout << "Snake length: ";
	cin >> snake;
	cout << "Wall-to-snake tail distance: ";
	cin >> distance;

	if (wall < 2 || snake < 0 || distance < 0 || snake > wall-2 || distance > wall-2){
		cerr << "Error: Invalid dimensions/lengths.";
		return -1;
	}
	
	cout << "|";
	
	for(int i = 1 ; i <= wall-2 ; i++){
		if (distance >= i){
			cout << " ";
		}
		else if (distance < i && snake > 0){
			if (distance + snake == i){
				cout << "O";
			}
			else
				cout << "*";
		}
		else if (i > distance + snake){
			cout << " ";
		}	
	}
	
	cout << "|";
	
	return 0;
}