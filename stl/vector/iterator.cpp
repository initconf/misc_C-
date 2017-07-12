/*----------------------------------------------------------------
Copyright (c) 2011 Author: Jagadeesh Vasudevamurthy
Filename: iterator.cpp
compile: g++ iterator.cpp
-----------------------------------------------------------------*/
#include <iostream>
using namespace std;

#ifdef _WIN32
#include <vld.h>  //comment this line, if you have NOT installed Visual leak detector
#endif

/*--------------------------------------------------------
class iarray_iterator
----------------------------------------------------------*/
class iarray_iterator {
public:
  iarray_iterator(int* x = 0): _current(x) {}
  ~iarray_iterator() {}
  // *(itt)
  const int& operator*() const{
    return *(_current) ;
  }
  //++itt 
  iarray_iterator& operator++() {
    ++(_current) ;
    return *this ;
  }
  //if (itt != x.end()
  bool operator!=(const iarray_iterator& rhs) {
    return (_current != rhs._current) ;
  }
private:
  int* _current ;
};

/*--------------------------------------------------------
class iarray
----------------------------------------------------------*/
class iarray {
  enum {START = 0, END = 3} ;
public:
  typedef iarray_iterator iterator ;
  iarray() { for (int i = START; i < END; i++) _a[i] = i*10 ; }
  ~iarray(){} ;

  iterator begin() {return iterator(&(_a[START])); }
  iterator end() {return iterator(&_a[END]) ; }

private:
  int _a[END] ;
};

/*--------------------------------------------------------
Main program
----------------------------------------------------------*/
int main() {
  iarray x ;
  //iarray_iterator itt = x.begin() ;
  iarray::iterator itt = x.begin() ;
  while (itt != x.end()) {
    const int& p = *(itt) ;
    cout << p << " " ;
    ++itt ;
  }
  cout << endl ;
  return 0 ;
}
