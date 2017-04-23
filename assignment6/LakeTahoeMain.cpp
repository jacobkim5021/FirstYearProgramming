#include <iostream>
#include "LakeTahoe.h"

using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "Usage Error: " << argv[0] << " <filename>" << endl;
    exit(-1);
  }

  float lake[420][210];
  if (!readTahoeData(argv[1], lake)) {
    cerr << "Unable to read datafile: " << argv[1] << endl;
    exit(-1);
  }

  cleanData(lake);
  cout << "Lake Tahoe area is: " << area(lake) << endl;
  cout << "Lake Tahoe volume is: " << volume(lake) << endl;

  return 0;
}
