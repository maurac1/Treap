// CMSC 341 - Fall 2019 - Project 3
// Simple test/demo of locate function

#include <iostream>
#include "treap.h"

using namespace std;

int main() {

  Treap T;

  T.insert("B", 24);
  T.insert("C", 35);
  T.insert("H", 29);
  T.insert("E", 33);
  T.insert("I", 25);
  T.insert("K", 9);
  T.insert("A", 21);
  T.insert("L", 16);
  T.insert("D", 8);
  T.insert("J", 13);
  T.insert("G", 50);

  bool found;
  data_t val;
  priority_t pri;
  int height;

  found = T.locate("LRL", val, pri, height);

  cout << "\nNode at location 'LRL':\n";
  if (found) {
    cout << "    data = " << val << endl;
    cout << "     pri = " << pri << endl;
    cout << "  height = " << height << endl;
  } else {
    cout << "  not found!\n";
  }

  found = T.locate("RRRL", val, pri, height);

  cout << "\nNode at location 'RRRL':\n";
  if (found) {
    cout << "    data = " << val << endl;
    cout << "     pri = " << pri << endl;
    cout << "  height = " << height << endl;
  } else {
    cout << "  not found!\n";
  }

  found = T.locate("RLR", val, pri, height);

  cout << "\nNode at location 'RRRL':\n";
  if (found) {
    cout << "    data = " << val << endl;
    cout << "     pri = " << pri << endl;
    cout << "  height = " << height << endl;
  } else {
    cout << "  not found!\n";
  }

  return 0;
}
