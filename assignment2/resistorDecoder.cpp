#include <iostream>
using namespace std;

int main(){
	char input[4];
	cout << "Enter the four resistor color codes: ";
	cin >> input;
	double firstband;
	double secondband;
	double thirdband;
	double fourthband;
	
	switch (input[0]) {
		case 'k':
			firstband = 0;
			break;
		case 'n':
			firstband = 1;
			break;
		case 'R':
			firstband = 2;
			break;
		case 'O':
			firstband = 3;
			break;
		case 'Y':
			firstband = 4;
			break;
		case 'G':
			firstband = 5;
			break;
		case 'B':
			firstband = 6;
			break;
		case 'V':
			firstband = 7;
			break;
		case 'y':
			firstband = 8;
			break;
		case 'W':
			firstband = 9;
			break;
		default:
			cerr << "Error: Invalid color code entered!";
			return -1;
	}
	
	switch (input[1]) {
		case 'k':
			secondband = 0;
			break;
		case 'n':
			secondband = 1;
			break;
		case 'R':
			secondband = 2;
			break;
		case 'O':
			secondband = 3;
			break;
		case 'Y':
			secondband = 4;
			break;
		case 'G':
			secondband = 5;
			break;
		case 'B':
			secondband = 6;
			break;
		case 'V':
			secondband = 7;
			break;
		case 'y':
			secondband = 8;
			break;
		case 'W':
			secondband = 9;
			break;
		default:
			cerr << "Error: Invalid color code entered!";	
			return -1;
	}
	
	switch (input[2]) {
		case 'k':
			thirdband = 1;
			break;
		case 'n':
			thirdband = 10;
			break;
		case 'R':
			thirdband = 100;
			break;
		case 'O':
			thirdband = 1000;
			break;
		case 'Y':
			thirdband = 10000;
			break;
		case 'G':
			thirdband = 100000;
			break;
		case 'B':
			thirdband = 1000000;
			break;
		case 'V':
			thirdband = 10000000;
			break;
		case 'y':
			thirdband = 100000000;
			break;
		case 'W':
			thirdband = 1000000000;
			break;
		case 'd':
			thirdband = 0.1;
			break;
		case 'S':
			thirdband = 0.01;
			break;
		default:
			cerr << "Error: Invalid color code entered!";
			return -1;
	}
	
	switch (input[3]) {
		case 'n':
			fourthband = 0.01;
			break;
		case 'R':
			fourthband = 0.02;
			break;
		case 'G':
			fourthband = 0.005;
			break;
		case 'B':
			fourthband = 0.0025;
			break;
		case 'V':
			fourthband = 0.001;
			break;
		case 'y':
			fourthband = 0.0005;
			break;
		case 'd':
			fourthband = 0.05;
			break;
		case 'S':
			fourthband = 0.1;
			break;
		case 'N':
			fourthband = 0.2;
			break;
		default:
			cerr << "Error: Invalid color code entered!";
			return -1;
	}
	
	double codeValue = (firstband*10 + (secondband))*thirdband;
	double errorValue = codeValue*fourthband;
	
	cout << "Resistance is " << codeValue << " (+/-" << errorValue << " ohms tolerance)"; 

	

	
	return 0;
}