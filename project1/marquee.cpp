#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
	
	char marquee[8] = {'!', 'E', 'C', 'E', '1', '5', '0', '!'};
	int position[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	char frame[60] = {0};
	int number_loops;
	//int count = 0;
	
	cin >> number_loops;

	for (int i = 0; i < number_loops; ++ i) {
		
		for (int j = 0; j < 61; j++) {
			
			// reset to initial state
			
			for (int k = 0; k < 60; ++ k) {
				frame[k] = ' ';
			}
			
			// assigning letters to frame array
			for (int a = 0; a < 8; ++ a) {
				frame[position[a]] = marquee[a];
			}
			
			for (int c = 0; c < 8; ++ c) {
				if (position[c] < 60) {
					position[c] ++;
				} else {
					position[c] = 0;
				}
			}
			
			for (int d = 0; d < 60; ++ d) {
				cout << "=";
			}
			
			cout << endl;
			
			for (int e = 0; e < 60; ++ e) {
				cout << frame[e];
			}
			
			cout << endl;
			
			for (int f = 0; f < 60; ++ f) {
				cout << "=";
			}
	
			if (j != 60) {
				system("cls");
			} else {
				system("cls");
				for (int d = 0; d < 60; ++ d) {
					cout << "=";
				}
				
				cout << endl;
				
				cout << "!ECE150!";
				
				cout << endl;
				
				for (int d = 0; d < 60; ++ d) {
					cout << "=";
					
				for (int c = 0; c < 8; ++ c) {
					if (position[c] < 60) {
						position[c] ++;
					} else {
						position[c] = 0;
					}
				}
				
				}
			}
		}
	}	
}
