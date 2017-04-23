#include <iostream>
#include "StringClass.h"
using namespace std;
/*
class myStr {
 public:
  int length() const;
  int strCmp(const myStr& compareMe) const;
  int strCmp(const char* compareMe) const;
  bool strCpy(const myStr& copyMe);
  bool strCpy(const char* copyMe);
  int subStr(const char* findMe) const;
  int subStr(const myStr& findMe) const;
  int subStr(const char* findMe, int startingAt) const;
  int subStr(const myStr& findMe, int startingAt) const;
  char at(const unsigned int index) const;

  myStr();
  myStr(const myStr& copyMe);
  myStr(const char* copyMe);
  ~myStr();

 private:
  friend std::ostream& operator<<(std::ostream& os, const myStr& s) {
    if (s.strLen == 0)
      return os;
    if (s.dataLen > s.strLen && s.data != 0 && s.data[s.strLen] == 0) {
      os << s.data;
      return os;
    }
    else if (s.data != 0) {
      for (int i = 0; i < s.strLen; ++i) {
	os << s.data[i];
      }
      return os;
    }
    else {
      std::cerr << "Error: Attempted to output string when data is NULL";
      return os;
    }
  };

 private:
  int   strLen;
  int   dataLen;
  char* data;
};

*/
myStr::myStr(){
	this->strLen = 0;
	this->dataLen = 1;
	this->data = new char[1];
	this->data[0] = '\0';
}

myStr::myStr(const myStr& copyMe){
	this->data = new char[copyMe.dataLen];
	int i = 0;
	while(copyMe.data[i] != '\0'){
		this->data[i] = copyMe.data[i];
		i++;
	}
	this->dataLen = copyMe.dataLen;
	this->strLen = copyMe.strLen;
}

myStr::myStr(const char* copyMe){
	int j = 0;
	while(copyMe[j] != '\0'){
		j++;
	}
	this->data = new char[j+1];
	int k = 0;
	while(copyMe[k] != '\0'){
		this->data[k] = copyMe[k];
		//cout << this->data[k] << endl;
		k++;
	}
	this->data[k] = copyMe[k];
	this->dataLen = j+1;
	this->strLen = j;
	
}

myStr::~myStr(){
	this->strLen = -1;
	this->dataLen = -1;
	this->data[0] = '\0';
}

int myStr::length()const{
	return this->strLen;
}

int myStr::strCmp(const myStr& compareMe) const{
	int i = 0;
	int s = 0;
	while(this->data[i] != '\0' || compareMe.data[i] != '\0'){
		if(this->data[i] == compareMe.data[i]){
			s++;
		}
		else if(this->data[i] < compareMe.data[i]){
			return +1;
		}
		else if(this->data[i] > compareMe.data[i]){
			return -1;
		}
		
		i++;
	}
	if(i == s){
		if(this->data[i] == '\0' && compareMe.data[i] != '\0'){
			return +1;
		}
		else{
			return 0;
		}
	}
}
int myStr::strCmp(const char* compareMe) const{
	
	cout << this->data << endl;
	int i = 0;
	int s = 0;
	while(this->data[i] != '\0' || compareMe[i] != '\0'){
		if(this->data[i] == compareMe[i]){
			s++;
		}
		else if(this->data[i] < compareMe[i]){
			return +1;
		}
		else if(this->data[i] > compareMe[i]){
			return -1;
		}
		
		i++;
	}
	if(i == s){
		if(this->data[i] == '\0' && compareMe[i] != '\0'){
			return +1;
		}
		else{
			return 0;
		}
	}
}

bool myStr::strCpy(const myStr& copyMe){
	int n = 0;
	while(copyMe.data[n] != '\0'){
		n++;
	}
	this->data[0] = '\0';
	this->data = new char[n+1];
	int c = 0;
	while(copyMe.data[c] != '\0'){
		this->data[c] = copyMe.data[c];
		c++;
	}
	this->data[c] = copyMe.data[c];
	this->strLen = n;
	this->dataLen = n+1;
}

bool myStr::strCpy(const char* copyMe){
	int m = 0;
	while(copyMe[m] != '\0'){
		m++;
	}
	this->data[0] = '\0';
	this->data = new char[m+1];
	int b = 0;
	while(copyMe[b] != '\0'){
		this->data[b] = copyMe[b];
		b++;
	}
	this->data[b] = copyMe[b];
	this->strLen = m;
	this->dataLen = m+1;
}



int myStr::subStr(const char* findMe) const{
										
	int e = 0;															/////  e == input array counter
	while(this->data[e] != '\0'){											/////  f == argument character counter
		int f = 0;														/////  m == bool
		int m = 1;
		while(findMe[f] != '\0' && m == 1){
			if(findMe[f] != this->data[e+f]){
				m = 0;
			}
			f++;
		}
		if(m == 1){
			return e;
		}
		
		e++;
	}
	return -1;
	
}

int myStr::subStr(const myStr& findMe) const{

	int e = 0;															/////  e == input array counter
	while(this->data[e] != '\0'){											/////  f == argument character counter
		int f = 0;														/////  m == bool
		int m = 1;
		while(findMe.data[f] != '\0' && m == 1){
			if(findMe.data[f] != this->data[e+f]){
				m = 0;
			}
			//cout << e << endl;
			f++;
			
		}
		if(m == 1){
			
			return e;
		}
		
		e++;
	}
	return -1;

}
int myStr::subStr(const char* findMe, int startingAt) const{
	int e = startingAt;															/////  e == input array counter
	while(this->data[e] != '\0'){											/////  f == argument character counter
		int f = 0;														/////  m == bool
		int m = 1;
		while(findMe[f] != '\0' && m == 1){
			if(findMe[f] != this->data[e+f]){
				m = 0;
			}
			f++;
		}
		if(m == 1){
			return e;
		}
		
		e++;
	}
	return -1;
}
int myStr::subStr(const myStr& findMe, int startingAt) const{
	int e = startingAt;															/////  e == input array counter
	while(this->data[e] != '\0'){											/////  f == argument character counter
		int f = 0;														/////  m == bool
		int m = 1;
		while(findMe.data[f] != '\0' && m == 1){
			if(findMe.data[f] != this->data[e+f]){
				m = 0;
			}
			//cout << e << endl;
			f++;
			
		}
		if(m == 1){
			
			return e;
		}
		
		e++;
	}
	return -1;
}
char myStr::at(const unsigned int index) const{
	if(this->strLen < index){
		return 0;
	}
	return this->data[index];
}






/*
int main() {
  myStr fred("Fred");
  myStr quote("My best friend is Fred");
  
  cout << "Fred length is: " << fred.length() << endl; 
  cout << "Quote length is: " << quote.length() << endl;
  cout << "Fred is at index " << quote.subStr(fred) << " in Quote" << endl;

  cout << "fred.strCmp(\"Fred\"): " << fred.strCmp("Fred") << endl;
  cout << "fred.strCmp(quote): " << fred.strCmp(quote) << endl;
  cout << "quote.strCmp(fred): " << quote.strCmp(fred) << endl;
  cout << "quote.subStr(fred): " << quote.subStr(fred) << endl;
  cout << "quote.subStr(fred, 0): " << quote.subStr(fred,0) << endl;
  cout << "quote.subStr(fred, 20): " << quote.subStr(fred,20) << endl;
  const unsigned int i = 5;
  cout << i << "th index of quote is character: " << quote.at(i) << endl;
  
  return 0;
}
*/