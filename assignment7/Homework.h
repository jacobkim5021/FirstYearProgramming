#ifndef HOMEWORK_H
#define HOMEWORK_H

struct Assignment 
{
	char  course[12];  	// CHE 102, MATH 117, etc.
	int	  assnNum; 		// Assignment Number
	int   dueMonth;		// Month due (1-12)
	int   dueDay;		// Day due (1-31)
	char* description;	// Assignment description
};
 
struct HomeworkQueue 
{
     const Assignment*    assgn;
     HomeworkQueue* next;
};

bool enqueue(const Assignment* assignment, HomeworkQueue*& queue);
const Assignment* dequeue(HomeworkQueue*& queue);

#endif
