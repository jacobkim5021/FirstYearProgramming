#ifndef SORTING_H
#define SORTING_H

void PrintIntArray(int array[]);

bubbleSort(int numNames, char* firstName[], char* lastName[], int age[]);
// Purpose:
//     - Sort names of a group of people with known age 
//	   - Sort criteria: By last name in alphabetical order, and then by first name
//     - Bubble sort algorithm used for the sorting process
// Parameter:
//     1. number of name entries to be sorted
//	   2. base address of the array of first names
//	   3. base address of the corresponding array of last names associated with the first name array
//     4. base address of the corresponding array of age values associated with each full name
// Returns:
//     - None

void displayNames(int numNames, char* firstName[], char* lastName[], int age[]);
// Purpose:
//     - Output an array of full names and their associated age to the screen
// Parameters:
//     1. number of name entries to be displayed to screen
//	   2. base address of the array of first names
//	   3. base address of the corresponding array of last names associated with the first name array
//     4. base address of the corresponding array of age values associated with each full name
// Returns:
//     - None

//int stringCmp(char str1[], char str2[]);
// Purpose:
//     - Compare two text strings and check if they are equal
// Parameters:
//	   - base address of the first and second text strings (call by value)
// Returns:
//     - One of three possibilities:
//			0  = the two strings are identical
//			+1 = str1 is lexicographically earlier than str2
//			-1 = str2 is lexicographically earlier than str1

void stringSwap(char* &str1, char* &str2);
// Purpose:
//     - Swap two text strings
// Parameters:
//	   - base address of the first and second text strings (call by reference)
// Returns:
//     - None

#endif
