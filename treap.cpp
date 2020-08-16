// CMSC 341 - Fall 2019 - Project 3
// File: treap.cpp

using namespace std ;

#include "treap.h"

Treap::Treap() {
  _nptr = nullptr ;
}

Treap::Treap(const Treap& other) {
  if(other._nptr == nullptr){
    _nptr = nullptr;
  }else{
    TreapNode *newNode = new TreapNode(*(other._nptr));
    _nptr = newNode;
  }
}

Treap::~Treap() {
  delete _nptr;
}

const Treap& Treap::operator=(const Treap& rhs) {
  if(rhs._nptr == nullptr){
    _nptr = nullptr;
  }else if(this != &rhs){
    delete _nptr;
    TreapNode *newNode = new TreapNode(rhs._nptr->_data, rhs._nptr->_pri);
    newNode->_height = rhs._nptr->_height;
    newNode->_left = rhs._nptr->_left;
    newNode->_right = rhs._nptr->_right;
    _nptr = newNode;
  }
  return *this;
}

// Return -1 if the treap is empty; otherwise, return value in _height.
int Treap::height() const {
  return _nptr ? _nptr->_height : -1 ;
}

// Return the priority of the root node of a Treap.
// Note: numeric_limits<priority_t>::min() returns the minimum value
// of the priority type.  We will only use int priorities, so this is
// the minimum integer value.
priority_t Treap::priority() const {
  return _nptr ? _nptr->_pri : numeric_limits<priority_t>::min() ;
}

const data_t* Treap::find(const data_t& x) {
  // if it's an empty tree return null
  if(_nptr == nullptr){
    return nullptr;
  
  // if the data is found return it
  }else if(_nptr->_data == x){
    data_t * foundData = &_nptr->_data;
    return foundData;

  // if the data is greater than x go left
  }else if(x < _nptr->_data){
    return _nptr->_left.find(x);

  // if the data is smaller than x go right
  }else{
    return _nptr->_right.find(x);
  }

}

// Inorder traversal.  Recommend you NOT change this!!!
void Treap::inorder() {

  if ( empty() ) return ;

  cout << "(" ;
  _nptr->_left.inorder() ;

  cout << _nptr->_data << ":" << priority() << ":" << height() ;

  _nptr->_right.inorder() ;
  cout << ")" ;

  return  ;
}

// Used for debugging and grading.  Interprets the characters in
// position[] as directions in the tree.  E.g., "RLR" means, "starting
// from root, go right, then left, then right."  If position[] is an
// empty string, then it just locats the value a the root.
// See project description for details.
bool Treap::locate (const char position[], data_t& x, priority_t& p, int& h, int offset) {

  if (_nptr == nullptr) return false ;

  if (position[offset] == '\0') {
    x = _nptr->_data ;
    p = _nptr->_pri ;
    h = _nptr->_height ;
    return true ;
  }

  if (position[offset] == 'L') {
    return _nptr->_left.locate(position, x, p, h, offset+1) ;
  }

  if (position[offset] == 'R') {
    return _nptr->_right.locate(position, x, p, h, offset+1) ;
  }

  cerr << "Bad position character!\n" ;
  exit(17) ;

  return false ; 
}


// Basic BST insertion.  Does not allow duplicate values.
//
// Complete this function to do Treap insertion.
//
void Treap::insert(const data_t& x, const priority_t& p) {
  if ( empty() ) {
    _nptr = new TreapNode(x, p) ;
  }

  // if data is smaller than x, go right
  if (_nptr->_data < x) { 
    _nptr->_right.insert(x, p);
    CheckHeap(true, p);
    
  // if data is bigger than x, go left
  } else if (x < _nptr->_data ) {
    _nptr->_left.insert(x, p);
    CheckHeap(false, p);
  }

}

void Treap::UpdateHeight(){
  int leftHeight = _nptr->_left.height();
  int rightHeight = _nptr->_right.height();
  _nptr->_height = 1 + ( leftHeight > rightHeight ? leftHeight : rightHeight );
}

void Treap::CheckHeap(bool isLeft, priority_t p){
  
  if(p > _nptr->_pri && _nptr != nullptr){
    
    // if it's the left child, rotate left
    if(isLeft){
      rotateLeft();
      CheckHeap(isLeft, p);

    // if it's the right child rotate right
    }else{
      rotateRight();
      CheckHeap(isLeft, p);
    }
    
    
  }
  UpdateHeight();
}

void Treap::rotateRight(){
  TreapNode *xNode = _nptr;

  _nptr = _nptr->_left._nptr;
  xNode->_left._nptr = _nptr->_right._nptr;
  _nptr->_right._nptr = xNode;
  _nptr->_right.UpdateHeight();
  UpdateHeight();
  CheckHeap(false, _nptr->_pri);

}

void Treap::rotateLeft(){

  
  TreapNode *yNode = _nptr;

  _nptr = _nptr->_right._nptr;
  yNode->_right._nptr = _nptr->_left._nptr;
  _nptr->_left._nptr = yNode;
  _nptr->_left.UpdateHeight();
  UpdateHeight();
  CheckHeap(true, _nptr->_pri);
}

bool Treap::remove(const data_t& x) {
  
  // if the tree is empty
  if(_nptr == nullptr){
    return false;
  }else if(_nptr->_data == x){

    // if no children
    if(_nptr->_left._nptr == nullptr && _nptr->_right._nptr == nullptr){
      
      delete _nptr;
      _nptr = nullptr;
      
      

    // if just a left child
    }else if(_nptr->_left._nptr != nullptr && _nptr->_right._nptr == nullptr){
      rotateRight();
      _nptr->_right.remove(x);
      UpdateHeight();

    // if just a right child
    }else if(_nptr->_right._nptr != nullptr && _nptr->_left._nptr == nullptr){
      rotateLeft();
      _nptr->_left.remove(x);
      UpdateHeight();
    
    // if two children
    }else{
  
      // if the left side is smaller than the right
      if(_nptr->_right._nptr->_pri < _nptr->_left._nptr->_pri){
        rotateRight();
        _nptr->_right.remove(x);
        UpdateHeight();

      // if the right side is smaller than the left
      }else if(_nptr->_left._nptr->_pri < _nptr->_right._nptr->_pri){
        rotateLeft();
        _nptr->_left.remove(x);
        UpdateHeight();

      // if both sides have equal height
      }else{
        // default right
        rotateRight();
        _nptr->_right.remove(x);
        UpdateHeight();
      }
    }
    
    return true;

  // if data is smaller than current value
  }else if(_nptr->_data < x){
    if(_nptr->_right.remove(x)){
      UpdateHeight();
      CheckHeap(false, _nptr->_pri);
      return true;
    }else{
      return false;
    }

  // if data is bigger than current value
  }else{
    if(_nptr->_left.remove(x)){
      UpdateHeight();
      CheckHeap(true, _nptr->_pri);
      return true;
    }else{
      return false;
    }
  }
  UpdateHeight();
}


// Treap::dump() just calls TreapNode::dump()
void Treap::dump() {
  if ( !empty() ) _nptr->dump() ;
}

ostream& operator<< (ostream& os, const Treap& T) {
  os << T._nptr ; 
  return os ;
}


TreapNode::TreapNode() : _height(0) {
  // Empty constructor body
}

TreapNode::TreapNode(const data_t& x, const priority_t& p) 
  : _data(x), _pri(p), _height(0) { 
  // Empty constructor body
}

TreapNode::~TreapNode() {
  // Empty destructor
  // Retained for debugging
}

// Dump the contents of a node
void TreapNode::dump() {
  cout << "===== TreapNode::dump()\n" ;
  cout << "      this = " << this << endl ; 
  cout << "      left = " << _left << endl ; 
  cout << "      right= " << _right << endl ; 
  cout << "      data = " << _data << endl ;
  cout << "      height = " << _height << endl ;
  _left.dump() ;
  _right.dump() ;
}

