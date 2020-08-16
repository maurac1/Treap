// CMSC 341 - Fall 2019 - Project 3
// File: treap.h

#ifndef _TREAP_H
#define _TREAP_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <limits>

typedef std::string data_t ; 
typedef int priority_t ;

class Grader ;
class TreapNode ;

class Treap {

  friend Grader ; // Used for grading
  
  friend std::ostream& operator<< (std::ostream& os, const Treap& T) ;

public:

  // Constructors, Destructor, Assignment Operator
  
  Treap() ;
  Treap(const Treap& other) ;

  ~Treap() ;

  const Treap& operator=(const Treap& rhs) ;

  //
  // Other member functions
  //
  
  // Returns true if tree is empty; false otherwise.
  bool empty() const { return _nptr == nullptr ; }  

  // Returns height of the tree/node.
  int height() const ;

  // Returns priority of the root node of a tree.
  priority_t priority() const ;

  // Search for a value; return pointer to data or nullptr if the
  // value is not found.
  const data_t* find(const data_t& x) ;

  // Insert the value-priority pair.
  void insert(const data_t& x, const priority_t& p) ;

  // Remove node with given data value; return true if successful and
  // false otherwise.
  bool remove(const data_t& x) ;

  // Perform an inorder traversal and print nodes.
  void inorder() ;

  // Probe the tree.  If a node is at the given position, return the
  // data (x), priority (p), and height (h).
  // See project description for details.
  bool locate (const char position[], data_t& x, priority_t &p, int &h, int offset=0) ;

  // Print data about all nodes 
  void dump() ;

private:
  TreapNode *_nptr ;        // Pointer to node (data)

  // Update height after insertion/deletion.
  void updateHeight() ;

  // Check and repair max-heap property
  void checkHeap() ;

  // Left and right rotations; called by checkHeap()
  void rotateRight() ;
  void rotateLeft() ;

  // Write the tree data to an array
  int toArray(data_t keys[], int last) ;

  // Find inorder predecessor, remove from the tree, and return
  // pointer to the node
  TreapNode *removeMaxNode() ;

  // Find inorder successor, remove from the tree, and return pointer
  // ot the node
  TreapNode *removeMinNode() ;

} ;

std::ostream& operator<< (std::ostream& os, const Treap& T) ;

class TreapNode {

  friend Grader ;
  friend Treap ;

public:
  TreapNode() ;
  TreapNode(const data_t& x, const priority_t& p) ;
  ~TreapNode() ;

  void dump() ;

private:
  data_t _data;             // Data value
  priority_t _pri;          // Priority
  int _height;              // Height
  Treap _left, _right;      // Left and right child trees
} ;

#endif

