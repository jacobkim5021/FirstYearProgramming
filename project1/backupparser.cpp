#include <iostream>
#include <fstream>

using namespace std;

char clearInput(char* input, int size){
	for(int j = 0 ; j < size ; j++){
			input[j] = '\0';
		}
	return input[size];
}

int main(int argc, char* argv[]){
	char input[1000];
	int lineCounter = 0;
	
	ifstream fin;
	/*ofstream fout;*/
	
	fin.open(argv[1]);
	/*fout.open("output.txt");*/

	while(fin.getline(input, 1000)){;
		
	lineCounter++;
		
		for(int i = 0 ; i < 1000 ; i++){
			switch(input[i]){
				case '#':
					cout << lineCounter << endl;
					break;
			}
		}
	
		clearInput(input, 1000);
	}
	
	fin.close();
	/*fout.close();*/
	
	return 0;
}