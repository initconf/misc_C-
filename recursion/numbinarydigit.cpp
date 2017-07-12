
/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: num_binary_digit.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has enumeration class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
Definition of routines of numbinarydigit
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
num_binary_digit using iteration
0  1
1  1
4  100
15 1111
16 10000
-----------------------------------------------------------------*/
int recursion::num_binary_digit_iterative(unsigned n, int& num_itr) {
  
    
    darray<char> tmp ;
    int count = 0 ;
       
    int num = n ;
    
    if (n == 0 )
    {
        count ++ ;
         num_itr += 1 ;
    }
    
    while (num >0)
    {
        tmp[count] = num % 2;
        num = num / 2 ;
        count++;
        num_itr += 1 ;
    }
   
    int a = count ;
    
  //WRITE CODE HERE
  return a;
}

/*----------------------------------------------------------------
num_binary_digit using recursion
-----------------------------------------------------------------*/
//  this routine converts number to binary
//int recursion::_d_r(unsigned n, int& num_rec){
//   //WRITE CODE HERE
//    
//    num_rec++;
//    
//    if(n == 0)
//    {
//        return 0;
//    }
//    else
//    {
//      return  (n %2 ) + 10 *  _d_r(n / 2, num_rec);
//    }
//    
//}

int recursion::_d_r(unsigned n, int& num_rec){
    //WRITE CODE HERE
  
    
    if (n /2 != 0)
    {

        _d_r(n / 2, num_rec);
    }
    
     num_rec++;
    return num_rec ;
}


int recursion::num_binary_digit_recursion(unsigned n, int& num_rec) {
  return _d_r(n, num_rec);
}

/*----------------------------------------------------------------
num_binary_digit using stack
-----------------------------------------------------------------*/
int recursion::num_binary_digit_stack(unsigned n, int& size_of_stack) {
    size_of_stack ++ ;
   //WRITE CODE HERE
    
    dstack<int> _stack;
    int num = 0 ;
    if (n == 0)
        _stack.push(0);
    
    while (n !=0)
    {
        num    = n % 2;
        _stack.push(num);
         size_of_stack ++ ;
        n = n / 2 ;
        
    }
    
    int a = 0 ;
    a = _stack.num_elements();
    
  return a;
}

//EOF


