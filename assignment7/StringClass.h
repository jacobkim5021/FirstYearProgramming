#ifndef MYSTR_H
#define MYSTR_H
#include <iostream>

class myStr {
 public:
  int length() const;
  int strCmp(const myStr&) const;
  int strCmp(const char*) const;
  bool strCpy(const myStr&);
  bool strCpy(const char*);
  int subStr(const char*) const;
  int subStr(const myStr&) const;
  int subStr(const char* findMe, int startingAt) const;
  int subStr(const myStr& findMe, int startingAt) const;
  char at(const unsigned int index) const;

  myStr();
  myStr(const myStr&);
  myStr(const char*);
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

#endif
