#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

char clearInput(char* input, int size){
	for(int j = 0 ; j < size ; j++){
		input[j] = '\0';
	}
	return input[size];
}

void clearIntInput(int* array, int size){
	for(int j = 0 ; j < size ; j++){
		array[j] = '\0';
	}
}

char lowercase(char* input, int i){
	if(input[i] > 64 && input[i] < 91){
		input[i] += 32;
	}
	return input[i];
}

int skipToLetter(char* input, int i){
	
	while(lowercase(input, i) < 97 || lowercase(input, i) > 123){
	
		if(input[i] != '\0'){	
			i++;
		}	
		if(input[i] == '\0'){
			break;
		}
	}
	return i;
}

int wordFill(char* input, int i, char* word){
	int w = 0;
	while(lowercase(input, i) > 96 && lowercase(input, i) < 123){
		word[w] = lowercase(input, i);
		
		i++;
		w++;
	}
	return w;
}

int skipWord(char* input, int i){
	while(lowercase(input, i) > 96 && lowercase(input, i) < 123){
		i++;
	}
	return i;
}

int charCompare(char** argv, char* word, int* occurrenceCounter, int argc){
	
	int tempOccurrence = 0;
	
	for(int n = 0 ; n < argc-2 ; n++){
		int argvSize = 0;
		int tempWordSize = 0;
		while(word[tempWordSize] != '\0'){
			tempWordSize++;
		}
		while(argv[n+2][argvSize] != '\0'){
			argvSize++;
		}
		for(int i = 0 ; i < (tempWordSize-argvSize+1) ; i++){
			int argvCounter = 0;
			if(lowercase(argv[n+2], argvCounter) == word[i]){
				while(lowercase(argv[n+2], argvCounter) == word[i] && argvCounter < argvSize){
					argvCounter++;
					i++;
				}
				i--;
			}
			else{
				i++;
			}
			if(argvCounter == argvSize){
				occurrenceCounter[n]++;
			}
			
		}
	}
	
	
}

int main(int argc, char* argv[]){
	
	if(argc < 2){
		cerr << "Error: No arguments.";
		return -1;
	}
	
    ifstream fin;
    ofstream fout;

	int k = 0;
	bool text = false;
	while(argv[1][k] != '\0'){
		if(argv[1][k] == '.'){
			if(argv[1][k+1] == 't' && argv[1][k+2] == 'x' && argv[1][k+3] == 't'){
				text = true;
			}
			else{
				cerr << "Error: Wrong file extension.";
				return -1;
			}
		}
		k++;
	}
	
	if(text){
		fin.open(argv[1]);
		cout << "text = true" << endl;
		char outputText[100];
		int c = 0;
		for(int o = 0 ; argv[1][o]!='\0' ; o++){
			outputText[o] = argv[1][o];
			c++;
		}
		outputText[c-3] = 'a';
		outputText[c-2] = 'n';
		outputText[c-1] = 'l';
		outputText[c] = '\0';
		fout.open(outputText);
	}
	else if(text == false){
		char outputText[100];
		char textAdded[100];
		clearInput(outputText, 100);
		clearInput(textAdded, 100);
		
		for(int o = 0 ; argv[1][o]!='\0' ; o++){
			outputText[o] = argv[1][o];
			textAdded[o] = argv[1][o];
		}
		
		textAdded[k] = '.';
		textAdded[k+1] = 't';
		textAdded[k+2] = 'x';
		textAdded[k+3] = 't';
		textAdded[k+4] = '\0';
		fin.open(textAdded);
		
		outputText[k] = '.';
		outputText[k+1] = 'a';
		outputText[k+2] = 'n';
		outputText[k+3] = 'l';
		outputText[k+4] = '\0';
		fout.open(outputText);
	}
	
	if(!fin.is_open()){
		cerr << "Error: FILE NOT FOUND";
		return -1;
	}
	
	/////////////////////////////////////////////////////////
	
	int i = 0;
	int occurrenceCounter[argc-1];
	
	clearIntInput(occurrenceCounter, argc-2);
	
	int wordCounter = 0;
	int maxWord = 0;
	int minWord = 500;
	float average = 0;
	int wordSize = 0;
	
	char input[1000];
	char word[1000];
	
	clearInput(input, 1000);
	clearInput(word, 1000);
	
	while(fin.getline(input, 1000)){
		for(int n = 0 ; n < argc-2 ; n++){										/////  n == argv argument counter
			int e = 0;															/////  e == input array counter
			while(input[e] != '\0'){											/////  f == argument character counter
				int f = 0;														/////  m == bool
				int m = 1;
				while(lowercase(argv[n+2], f) != '\0' && m == 1){
					if(lowercase(argv[n+2], f) != lowercase(input, e+f)){
						m = 0;
					}
					f++;
				}
				if(m == 1){
					occurrenceCounter[n]++;
					
				}
				e++;
			}
		}
		
		
		i = 0;
		while(input[i] != '\0'){
			wordSize = 0;
			i = skipToLetter(input, i);				//////  <------- 
			if(input[i] == '\0'){
				break;
			}
			
			wordSize = wordFill(input, i, word);
			int ee = 0;
			
			
			//charCompare(argv, word, occurrenceCounter, argc);
			
			average += wordSize;
			
			if(wordSize > maxWord){
				maxWord = wordSize;
			}
			if(wordSize < minWord){
				minWord = wordSize;
			}
			
			i = skipWord(input, i);
			wordCounter++;
			
			clearInput(word, 1000);
		}
		clearInput(input, 1000);
	}
	average = average/wordCounter;
	
	fout << "Number of words: " << wordCounter << endl;
	fout << "Longest word: " << maxWord << endl;
	fout << "Shortest word: " << minWord << endl;
	fout << "Average word length: " << setprecision(2)  << fixed << average << endl;
	
	if(argc > 2){
		for(int m = 2 ; m < argc ; m++){
			fout << "Number of occurrences of " << argv[m] << ": " << occurrenceCounter[m-2] << endl;
		}
	}
	
	fout.close();
    return 0;
}
