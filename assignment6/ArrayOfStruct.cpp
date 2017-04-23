#include <iostream>
#include "ArrayOfStruct.h"
using namespace std;

/*struct Person{
	char firstName[20];
	char lastName[20];
	int age;
};*/

int stringCmp(char str1[], char str2[]){
	int i = 0;
	int s = 0;
	while(str1[i] != '\0' || str2[i] != '\0'){
		if(str1[i] == str2[i] || (str1[i] - 32) == str2[i] || (str2[i] - 32) == str1[i]){
			s++;
		}
		else if(str1[i] < str2[i]){
            if(str1[i] > 96 && str2[i] > 96){
                return +1;
            }
            else if(str1[i] < 91 && str2[i] < 91){
                return +1;
            }
            else if(str1[i] < 91 && str2[i] > 96){
                if(str2[i] - 32 > str1[i]){
                    return +1;
                }
                else{
                    return -1;
                }
            }
		}
		else if(str1[i] > str2[i]){
            if(str1[i] > 96 && str2[i] > 96){
                return -1;
            }
            else if(str1[i] < 91 && str2[i] < 91){
                return -1;
            }
            else if(str1[i] > 96 && str2[i] < 91){
                if(str1[i] - 32 > str2[i]){
                    return -1;
                }
                else{
                    return +1;
                }
            }
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


void peopleSwap(Person* &people, int k){
    Person temp = people[k];
    people[k] = people[k+1];
    people[k+1] = temp;
}

void bubbleSort(int numPeople, Person people[]){


	bool swapped = true;
	while(swapped == true){
		swapped = false;
		int k = 0;
		while(k < (numPeople-1)){
			//cout << k << endl;
			if(stringCmp(people[k].lastName, people[k+1].lastName) == -1){
				peopleSwap(people, k);
				int temp1;

				swapped = true;
				//cout << "first name swapped" << endl;
			}
			else if(stringCmp(people[k].lastName, people[k+1].lastName) == 0){
				if(stringCmp(people[k].firstName, people[k+1].firstName) == -1){
					peopleSwap(people, k);
                    int temp2;

                    swapped = true;
					//cout << "last name swapped" << endl;
				}
				else if(stringCmp(people[k].firstName, people[k+1].firstName) == 0){
					if(people[k].age > people[k+1].age){
						peopleSwap(people, k);
                        int temp3;

                        swapped = true;
						//cout << "age swapped" << endl;
					}
				}
			}
			k++;
		}
	}
}

void displayNames(int numPeople, Person people[]){
    for(int i = 0 ; i < numPeople ; i++){
        cout << people[i].firstName << " " << people[i].lastName << " " << people[i].age << endl;
    }
}

/*
int main(){
	Person people[20];

	return 0;
}*/
