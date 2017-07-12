/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: primetest.cpp

On linux:
g++ prime.cpp primetest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test prime object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "prime.h"

/*----------------------------------------------------------------
Compute prime up to n (all numbers that cannot divide n except 1 and n)

if n = 30
prime numbers are: 2 3 5 7  11 13 17 19 23 29
-----------------------------------------------------------------*/
void _prime(int n) {
   prime s;
  int as = 0;
  int* a = s.school_method(n, &as);
  s.print("School Method", as, a);
  int ss = 0;
  int* b = s.prime_of_eratosthenes(n, &ss);
  s.print("Sieve  Method", ss, b);
  assert(s.verify(as, a, ss, b));
  int up = 0 ; 
  int* c = s.upto_prime(n, &up);
  s.print("Upto-Prime  Method", up, c);
  assert(s.verify(as, a, up, c));
  delete [] a;
  delete [] b;
  delete [] c; 

}


/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
 _prime(30);
 _prime(1000);
 _prime(10000);
}


#if 0
/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}
#endif
//EOF

