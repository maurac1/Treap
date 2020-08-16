#ifndef PRINT_H
#define PRINT_H

// Performs a breadth-first search to print the tree prettily
// DO NOT include this when submitting!

#include <vector>
#include <iostream>

void Treap::print() {
  
  std::vector<TreapNode*>* current = new std::vector<TreapNode*>;
  std::vector<TreapNode*>* next = new std::vector<TreapNode*>;
  
  current->push_back(_nptr);

  int subTreeMaxSize = 0;
  for (int i = 1; i <= _nptr->_height; i++)
    subTreeMaxSize = subTreeMaxSize * 2 + 1;

  for (int i = _nptr->_height; i >= 0; i--) {

    for (TreapNode* node : *current) {
 
      for (int j = 0; j < subTreeMaxSize; j++)
	std::cout << " ";
      
      if (node != nullptr) {
	std::cout << node->_data;

	next->push_back(node->_left._nptr);
	next->push_back(node->_right._nptr);
      }
      else {
	std::cout << " ";
	
	next->push_back(nullptr);
	next->push_back(nullptr);
      }

      for (int j = 0; j < subTreeMaxSize + 1; j++)
	std::cout << " ";
    }

    std::cout << std::endl;

    delete current;
    current = next;
    next = new std::vector<TreapNode*>;
    
    subTreeMaxSize /= 2;
  }

  delete current;
  delete next;
  std::cout << std::endl;
}


#endif