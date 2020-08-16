// CMSC 341 - Fall 2019 - Project 3
// Basic test driver for the Treap class
// Test of assignment operator


#include <iostream>
#include "treap.h"

using namespace std;

int main() {

  Treap T;
  Treap T1;

  T1.insert("B", 24);
  
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

  T1 = T;

  cout << "\nT1 constructed from T using assignment operator...\n";

  cout << " Treap T: ";
  T.inorder();
  cout << endl;

  cout << "Treap T1: ";
  T1.inorder();
  cout << endl;

  cout << "\nRemove all elements except 'G' from T1...\n";
  
  T1.remove("B");
  T1.remove("C");
  T1.remove("H");
  T1.remove("E");
  T1.remove("I");
  T1.remove("K");
  T1.remove("A");
  T1.remove("L");
  T1.remove("D");
  T1.remove("J");
  
  cout << " Treap T: ";
  T.inorder();
  cout << endl;

  cout << "Treap T1: ";
  T1.inorder();
  cout << endl;

  return 0;
}
