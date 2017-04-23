#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	cout << setprecision(2) << fixed;
	float price, discount, tax;
	float a, b;
	
	cout << "Enter the offer price of the item: ";
	cin >> price;
	cout << "Discount rate (%): ";
	cin >> discount;
	cout << "Tax rate (%): ";
	cin >> tax;

	discount = discount * 0.01;
	tax = tax * 0.01;
	
	a = price - price * discount;
	b = a + a * tax;
	
	cout << "The net price of the item is: " << b;
	
	
}