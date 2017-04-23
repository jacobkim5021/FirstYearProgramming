#include <iostream>
#include "Homework.h"
using namespace std;

/*
struct Assignment
{
	char  course[12];  	// CHE 102, MATH 117, etc.
	int	  assnNum; 		// Assignment Number
	int   dueMonth;		// Month due (1-12)
	int   dueDay;		// Day due (1-31)
	char description[50];	// Assignment description
};

struct HomeworkQueue
{
     const Assignment*    assgn;
     HomeworkQueue* next;
};

void print(HomeworkQueue*& q){
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
*/
int compareDate(HomeworkQueue* first, HomeworkQueue* second){
	if(first->assgn->dueMonth > second->assgn->dueMonth){
		return -1;
	}
	else if(first->assgn->dueMonth < second->assgn->dueMonth){
		return 1;
	}
	else if(first->assgn->dueMonth == second->assgn->dueMonth){
		if(first->assgn->dueDay < second->assgn->dueDay){
			return 1;
		}
		else if(first->assgn->dueDay > second->assgn->dueDay){
			return -1;
		}
		else if(first->assgn->dueDay == second->assgn->dueDay){
			return 0;
		}
	}
}

bool enqueue(const Assignment* assignment, HomeworkQueue*& queue){
	if(assignment->course[0] == '\0'){
		cerr << "Error: invalid course name" << endl;
		return false;
	}
	int counter = 0;
	while(assignment->course[counter] != '\0'){
		counter++;
	}
	if(counter > 11){
		cerr << "Error: invalid course name" << endl;
		return false;
	}
	
	/*
	if(assignment->course[12] != '\0'){
		cerr << "Error: invalid course name" << endl;
		return false;
	}
	*/
	
	
	
	HomeworkQueue* node = new HomeworkQueue;
	node->assgn = assignment;
	node->next = NULL;

	if(node->assgn->dueMonth < 1 || node->assgn->dueDay < 1){
		cerr << "Error: invalid due date." << endl;
		return false;
	}
	if(node->assgn->dueMonth > 12 || node->assgn->dueDay > 31){
		cerr << "Error: invalid due date." << endl;
		return false;
	}
	if(queue == NULL){
		queue = node;
		return true;
	}
	else{
		if(compareDate(node, queue) == 1){
			HomeworkQueue* tempNode1 = queue;
			queue = node;
			queue->next = tempNode1;
			return true;
		}
		else if(compareDate(node, queue) == 0){
			if(queue->next == NULL){
				queue->next = node;
				node->next = NULL;
				return true;
			}
			else{
				HomeworkQueue* tempPrevious = queue;
				HomeworkQueue* tempCurrent = queue->next;
				while(compareDate(node, tempCurrent) == 0){
					if(tempCurrent->next == NULL){
						tempCurrent->next = node;
						node->next == NULL;
						return true;
					}
					
					tempPrevious = tempCurrent;
					tempCurrent = tempCurrent->next;
				}
				tempPrevious->next = node;
				node->next = tempCurrent;
				
				return true;
				
				
			}
		}
		else if(compareDate(node, queue) == -1){
			HomeworkQueue* previous = queue;
			HomeworkQueue* current = queue->next;
			
			if(queue->next == NULL){
				queue->next = node;
				node->next = NULL;
				return true;
			}
			
			while(compareDate(node, current) == -1){
				if(current->next == NULL){
					current->next = node;
					node->next = NULL;
					return true;
				}
				
				
				previous = current;
				current = current->next;
			}
			while(compareDate(node, current) == 0){
				if(current->next == NULL){
					current->next = node;
					node->next = NULL;
					return true;
				}
				
				previous = current;
				current = current->next;
			}
			previous->next = node;
			node->next = current;
			
			return true;
			
		}
	}
}

const Assignment* dequeue(HomeworkQueue*& queue){
	if(queue == NULL){
		return NULL;
	}

	const Assignment* tempAssignment = queue->assgn;
	//*tempAssignment = queue->assgn;

	HomeworkQueue* tempNode = queue;
	queue = queue->next;
	tempNode->next = NULL;

	return tempAssignment;
}
/*
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
*/