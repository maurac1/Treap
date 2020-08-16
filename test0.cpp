// CMSC 341 - Fall 2019 - Project 3
// Basic test driver for the Treap class
// Creates the treap example from the project write-up

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

  cout << endl;
  T.inorder();
  cout << endl;

  T.dump();
  
  return 0;
}
