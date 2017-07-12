
/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: fibonacci.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has enumeration class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
Definition of routines of fibonacci
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
0 1 2 3 4 5 6 7  8   9 10 11 12
0 1 1 2 3 5 8 13 21 34 55 89 144
-----------------------------------------------------------------*/
int recursion::fibonacci_iterative(unsigned n, int& num_itr) {
  num_itr = 0;
  //WRITE CODE HERE

    if (n == 0) return 0;
    if (n == 1) return 1;
    
    num_itr ++ ;
    
    int prevPrev = 0;
    int prev = 1;
    int a = 0;
    
    for (int i = 2; i <= n; i++)
    {
        a = prev + prevPrev;
        prevPrev = prev;
        prev = a;
        num_itr++ ;
    }

  return a;
}

/*----------------------------------------------------------------
Fibonacci using recursion
-----------------------------------------------------------------*/
int recursion::_fib_r(unsigned n, int& num_rec){
    
    num_rec++ ;
    
    if (n == 0)     return 0 ;
    if (n == 1)    return 1;
    
    return _fib_r(n-1, num_rec) + _fib_r(n-2, num_rec) ;
}


int recursion::fibonacci_recursion(unsigned n, int& num_rec) {
  return _fib_r(n, num_rec);
}

/*----------------------------------------------------------------
Fibonacci using stack
-----------------------------------------------------------------*/

//
//1) Take an empty stack. Push the initial values of 1 and 1 into it. The stack now has two elements.
//2) X=pop(). Y=pop(). Z=X+Y.
//3) Push Y. Push X. Push Z.
//4) Go back to step 2.
//

int recursion::fibonacci_stack(unsigned n, int& size_of_stack) {
    
    dstack<int> _stack;

    size_of_stack = 0 ;
    
    if (n == 0) return 0 ;
    if (n == 1) return 1 ;
    
    _stack.push(0);
    _stack.push(1);

    int x = 0 ;
    int y = 0 ;
    int z = 0 ;
    
    for (int i = 2 ; i <=n ; ++i)
    {
        x  = _stack.top();
        _stack.pop();
        y = _stack.top();
        _stack.pop();
        z = x+y;
        _stack.push(y);
        _stack.push(x);
        _stack.push(z);
        
        size_of_stack++ ;
    }
    
    int a = _stack.top();
    
    return a;
}

//EOF

