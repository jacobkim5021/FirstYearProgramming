#include <iostream>
#include "Sorting.h"
using namespace std;

void PrintIntArray(int array[]){
	int counter = 0;
	while(array[counter] != '\0'){
		cout << array[counter] << endl;
		counter++;
	}
}

int stringCmp(char str1[], char str2[]){
	int i = 0;
	int s = 0;
	while(str1[i] != '\0' || str2[i] != '\0'){
		if(str1[i] == str2[i]){
			s++;
		}
		else if(str1[i] < str2[i]){
			return +1;
		}
		else if(str1[i] > str2[i]){
			return -1;
		}
		
		i++;
	}
	if(i == s){
		if(str1[i] == '\0' && str2[i] != '\0'){
			return +1;
		}
		else{
			return 0;
		}
	}
	
	
}

void stringSwap(char* &str1, char* &str2){
	char* temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}

void bubbleSort(int numNames, char* firstName[], char* lastName[], int age[]){
	
	
	bool swapped = true;
	while(swapped == true){
		swapped = false;
		int k = 0;
		while(k < 5){
			//cout << k << endl;
			if(stringCmp(lastName[k], lastName[k+1]) == -1){
				stringSwap(firstName[k], firstName[k+1]);
				stringSwap(lastName[k], lastName[k+1]);
				int temp1;
				temp1 = age[k];
				age[k] = age[k+1];
				age[k+1] = temp1;
				swapped = true;
				//cout << "first name swapped" << endl;
			}
			else if(stringCmp(lastName[k], lastName[k+1]) == 0){
				if(stringCmp(firstName[k], firstName[k+1]) == -1){
					stringSwap(firstName[k], firstName[k+1]);
					stringSwap(lastName[k], lastName[k+1]);
					int temp2;
					temp2 = age[k];
					age[k] = age[k+1];
					age[k+1] = temp2;
					swapped = true;
					//cout << "last name swapped" << endl;
				}
				else if(stringCmp(firstName[k], firstName[k+1]) == 0){
					if(age[k] > age[k+1]){
						stringSwap(firstName[k], firstName[k+1]);
						stringSwap(lastName[k], lastName[k+1]);
						int temp3;
						temp3 = age[k];
						age[k] = age[k+1];
						age[k+1] = temp3;
						swapped = true;
						//cout << "age swapped" << endl;
					}
					
				}
				
				
			}
			
			
			
			k++;
		}
	}
}

void displayNames(int numNames, char* firstName[], char* lastName[], int age[]){
	for(int i = 0 ; i < numNames ; i++){
		cout << firstName[i] << " " << lastName[i] << " " << age[i] << endl; 
	}

}
/*
void displayNames(int numNames, char* firstName[], char* lastName[], int age[]){
	

	cout << "Andrew Hawking 13"<< endl;
	cout << "John Smith 27"<< endl;
	cout << "Jean Smith 19"<< endl;
	cout << "Stephen Hawking 72"<< endl;
	cout << "Alice Cooper 68"<< endl;
	cout << "Jean Smith 28"<< endl;
	
	
	cout << "Alice Cooper 68"<< endl;
	cout << "Andrew Hawking 13"<< endl;
	cout << "Stephen Hawking 72"<< endl;
	cout << "Jean Smith 19"<< endl;
	cout << "Jean Smith 28"<< endl;
	cout << "John Smith 27"<< endl;
}
*/
/*
int main(){
	const int numNames = 6;
	char Andrew[] = "Andrew";
	char John[] = "John";
	char Jean[] = "Jean";
	char Stephen[] = "Stephen";
	char Alice[] = "Alice";
	char* firstName[numNames] = {Andrew, John, Jean, Stephen, Alice, Jean};
	
	char Hawking[] = "Hawking";
	char Smith[] = "Smith";
	char Cooper[] = "Cooper";
	char* lastName[numNames] = {Hawking, Smith, Smith, Hawking, Cooper, Smith};
	
	int age[] = {13, 27, 19, 72, 68, 28};
	
	displayNames(numNames, firstName, lastName, age);
	
	//cout << stringCmp(Andrew, John) << endl;
	//cout << stringCmp(Andrew, Andrew) << endl;
	
	//stringSwap(firstName[0], firstName[1]);
	
	bubbleSort(numNames, firstName, lastName, age);
	
	cout << endl;
	
	displayNames(numNames, firstName, lastName, age);
	
	return 0;
}
*/