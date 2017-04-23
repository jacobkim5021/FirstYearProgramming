#include <iostream>
#include "StringClass.h"

using namespace std;

int main() {
  myStr fred("Fred");
  myStr quote("My best friend is Fred");
  
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
