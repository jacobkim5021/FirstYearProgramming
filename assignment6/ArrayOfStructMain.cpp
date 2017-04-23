#include <iostream>
#include <fstream>

#include "ArrayOfStruct.h"

using namespace std;

int read(ifstream & fin, Person people[])
{
	int i = 0;
	
	while (i < 20 && fin >> people[i].firstName)
	{
		fin >> people[i].lastName >> people[i].age ;
		i++;
	}
	return i;
}


int main() {
  ifstream fin ("members.txt");
  if (fin.fail()) {
      cerr << "Error: file not open.\n";
      return -1;
  }
  
  Person people[20];
  int numPeople = read(fin, people);
  cout << "Before Sorting:\n\n";
  displayNames(numPeople, people);
  
  bubbleSort(numPeople, people);
  
  cout << "\n\nAfter Sorting:\n\n";
  displayNames(numPeople, people);
	
  return 0;
}

