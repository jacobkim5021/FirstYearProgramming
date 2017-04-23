#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int cycles;
	char word[9] = "!ECE150!";
	int position[8];
	char middle[61];
	
	for(int s=0 ; s<60 ; s++){
		middle[s] = ' ';
	}
	
	middle[61] = '\0';
	
	for(int a=0 ; a<8 ; a++){
		position[a] = a;
	}
	
	cout << "How many cycles? ";
	
	cin >> cycles;
	
	for(int g=0 ; g<cycles ; g++){
		for(int h=0 ; h<61 ; h++){
			for(int i=0 ; i<60 ; i++){
				cout << "=";
			}
			
			cout << endl;
			if(h==60){
				for(int u=0 ; u<8 ; u++){
					middle[u] = word[u];
				}
				middle[59] = ' ';
			}
			for(int k=0 ; k<60 ; k++){
				if(k == h){
					for(int z=0 ; z<8 ; z++){
						if(position[z] < 60){
							middle[k+z] = word[z];	
						}
					}
					k += 8;
				}
				else{
					for(int m = 8 ; m > 0 ; m--){
						if(position[m-1] > 59)
							middle[8-m] = word[8-(position[m-1]%59)];
						else
							middle[k] = ' ';
					}
					
				}
			}
			
			for(int f=0 ; f<60 ; f++){
				cout << middle[f];
			}
			
			cout << endl;
			
			for(int j=0 ; j<60 ; j++){
				cout << "=";
			}
			
			cout << endl;
			
			for(int l=0 ; l < 1000000 ; l++){
				l = (l + l)/2;
			}
			
			for(int b=0 ; b<8 ; b++){
				position[b] = position[b] + 1;
			}
			
		}
			for(int d=0 ; d<8 ; d++){
				position[d] = d;
			}
	}
	
	return 0;
}