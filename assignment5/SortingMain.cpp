#include <iostream>
#include "Sorting.h"
using namespace std;

int main() {

	// ** INITIALIZATION **
	// For basic testing, a list of 6 names is created (along with the corresponding age)
	const int numNames = 6;
	char* firstName[numNames] = {"Andrew", "John", "Jean", "Stephen", "Alice", "Jean"};
	char* lastName[numNames] = {"Hawking", "Smith", "Smith", "Hawking", "Cooper", "Smith"};
	int age[] = {13, 27, 19, 72, 68, 28};

	// STEP 1: Show on screen the list of names and ages BEFORE sorting
	cout << "Before sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	// STEP 2: Sort the list according to last name (in alphabetical order) and then by first name
	bubbleSort(numNames, firstName, lastName, age);

	// STEP 3: Show on screen the list of names and ages AFTER sorting
	cout << endl << "After sorting:"<< endl;
	displayNames(numNames, firstName, lastName, age);

	PrintIntArray(age);
	
	return 0;
}
