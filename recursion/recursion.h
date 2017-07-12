/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: recursion.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has recursion class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef recursion_H
#define recursion_H

#include "../util/util.h"
#include "../dstack/dstack.h" 
#include "../str/str.h" 



/*----------------------------------------------------------------
Declaration of recursion class
-----------------------------------------------------------------*/
class recursion{
public:
  recursion(bool d = false) :_display(d){}
  bool display() const {
    return _display;
  }
  long long factorial_iterative(unsigned n, int& num_mult);
  long long factorial_recursion(unsigned n, int& num_rec);
  long long factorial_stack(unsigned n, int& size_of_stack);

  int num_binary_digit_iterative(unsigned n, int& num_itr);
  int num_binary_digit_recursion(unsigned n, int& num_rec);
  int num_binary_digit_stack(unsigned n, int& size_of_stack);

  int fibonacci_iterative(unsigned n, int& num_itr);
  int fibonacci_recursion(unsigned n, int& num_rec);
  int fibonacci_stack(unsigned n, int& size_of_stack);

  void hanoi_recursion(unsigned n, int& num_rec, str& s);
  void hanoi_stack(unsigned n, int& size_of_stack, str& s);


private:
  //CAN HAVE ANY FUNCTIONS HERE
  //CANNOT USE STL
  bool _display;


    long long _f_r(unsigned n, int& num_rec);
    int _fib_r(unsigned n, int& num_rec);
    void _t_r(unsigned n, char s, char t, char d, int& num_rec, str& str);
    void move_disk(char from, char to);
    
    void MoveLast(dstack<int>& origin, dstack<int>& target, int& size_of_stack);
    void MoveDisks(dstack<int>& origin, dstack<int>& buffer, dstack<int>& target, int n, int& size_of_stack);
    void printHanoi(dstack<int> s1, dstack<int> s2, dstack<int> s3);
    
    
    
    int _d_r(unsigned n, int& num_rec) ;
    
    

};

#endif
//EOF

