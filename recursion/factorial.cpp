/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: factorial.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has enumeration class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
Definition of routines of factorial
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
factorial using iteration
-----------------------------------------------------------------*/
long long recursion::factorial_iterative(unsigned n, int& num_mult) {
  long long a = 1;
  num_mult = 0;
  for (int j = n; j > 1; j--) {
    ++num_mult;
    a = a * j;
  }
  return a;
}

/*----------------------------------------------------------------
factorial using recursion
-----------------------------------------------------------------*/
long long recursion::_f_r(unsigned n, int& num_rec){
  //WRITE CODE HERE

    
    num_rec++;
    
    if (n == 0 || n == 1)
        return 1;
    else
        return  n * _f_r(n-1, num_rec);


}

long long recursion::factorial_recursion(unsigned n, int& num_rec) {
  return _f_r(n, num_rec);
}

/*----------------------------------------------------------------
factorial using stack
-----------------------------------------------------------------*/
long long recursion::factorial_stack(unsigned n, int& size_of_stack) {
    
    dstack<long long> stack(1);
    size_of_stack = 0;
    stack.push(1);

  //WRITE CODE HERE
    
    while (n >= 1 )
    {
        stack.push(stack.top()*n);
        size_of_stack++;
        n-- ;
    }
    
    long long a = stack.top();
    
    return a;
}

//EOF

