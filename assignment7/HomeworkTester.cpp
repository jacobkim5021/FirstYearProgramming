#include <iostream>
#include <fstream>
#include "Homework.h"
using namespace std;

void print(HomeworkQueue*& q)
{
	cout << endl;
	HomeworkQueue* temp = q;
	while(temp != NULL)
	{
		cout << temp->assgn->course << " " << temp->assgn->assnNum << " " << temp->assgn->dueMonth 
		     << " " <<  temp->assgn->dueDay <<" " << temp->assgn->description << endl;
		temp = temp->next;
	}
	cout << endl;
}


int main()
{
	HomeworkQueue* q = 0;
	
	Assignment a1 = { "ECE 150", 7, 12, 5, "linked list" };
	enqueue(&a1, q);
	Assignment a2 = {"ECE 150", 6, 11, 25, "struct"};
	enqueue(&a2, q);
	Assignment a3 = {"ECE 100", 3, 12, 5, "final report"};
	enqueue(&a3, q);
	Assignment a4 = {"Math 117", 9, 11, 30, "partial fraction"};
	enqueue(&a4, q);
	Assignment a5 = {"ECE 105", 10, 12, 2, "momentum"};
	enqueue(&a5, q);
	
	print (q);
	
	const Assignment* a;
	
	for(int i = 0; i < 5; i++)
	{
		a = dequeue(q);
		cout <<a->course << " assignment " << a->assnNum << " is taken off the to do list on " << a->dueMonth << '/' << a->dueDay<< endl;
	}
		
	return 0;
}

/*
Sample Output:

ECE 150 6 11 25 struct
Math 117 9 11 30 partial fraction
ECE 105 10 12 2 momentum
ECE 150 7 12 5 linked list
ECE 100 3 12 5 final report

ECE 150 assignment 6 is taken off the to do list on 11/25
Math 117 assignment 9 is taken off the to do list on 11/30
ECE 105 assignment 10 is taken off the to do list on 12/2
ECE 150 assignment 7 is taken off the to do list on 12/5
ECE 100 assignment 3 is taken off the to do list on 12/5

*/

