#include <iostream>
using namespace std;
struct Person {
  char firstName[20];
  char lastName[20];
  int age;
};
int main(){
	Person people[20];
	people[1].firstName = "Jack";
	cout << people[1].firstName << endl;

	return 0;
}
