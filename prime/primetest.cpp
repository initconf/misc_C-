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


prime::result& Prime(int n, prime::result &summary) {
  prime s;
  int as = 0;

    
    summary.numbers = n ;
    
    clock_t start = clock() ;
    
   int* a = s.school_method(n, &as);

    clock_t end = clock() ;
   // cout <<"Run time for school method " << double(end - start)/CLOCKS_PER_SEC << " secs" << " found : " << as << endl ;
    
    summary._school_method_time =  double(end - start)/CLOCKS_PER_SEC  ;
   
// s.print("School Method", as, a);
    int ss = 0;

    start = clock() ;
    
    int* b = s.prime_of_eratosthenes(n, &ss);

    end = clock() ;
  //  cout <<"Run time for prime_of_eratosthenes " << double(end - start)/CLOCKS_PER_SEC << " secs" << " found : " << ss << endl ;
    summary._seive_time = double(end - start)/CLOCKS_PER_SEC ;

//   s.print("Sieve  Method", ss, b);
 assert(s.verify(as, a, ss, b));
    
    
    int up = 0;
    
    start = clock() ;
    
    int* c = s.upto_prime(n, &up);
 
    end = clock() ;
  //  cout <<"Run time for upto_prime " << double(end - start)/CLOCKS_PER_SEC << " secs" << " found : " << up << endl ;

    summary._upto_prime_time = double(end - start)/CLOCKS_PER_SEC ;
    
 //  s.print("Upto Prime Method", up, c);
   assert(s.verify(ss, b, up, c));
    
    
    
    int ff = 0 ;
    
     start = clock() ;
    int* d = s._populate_factors(n, &ff);
    end = clock() ;
  //  cout <<"Run time for factorization " << double(end - start)/CLOCKS_PER_SEC << " secs" << " found : " << ff << endl ;
    
    summary.factor_time  = double(end - start)/CLOCKS_PER_SEC ;
    
    
   // s.print("factorization Method", ff, d);
    assert(s.verify(ss, b, ff, d));

   //  cout << endl << s._school_method_counter << " | " << s._seive_of_eratosthenes_counter << " | " << s._upto_prime_counter << " | " << s._factorization_prime_count <<  endl ;

    summary.primes_found = ff ;
    summary._upto_prime_counter = s._upto_prime_counter ;
    summary._school_method_counter = s._school_method_counter ;
    summary._seive_of_eratosthenes_counter = s._seive_of_eratosthenes_counter ;
    summary._factorization_prime_count = s._factorization_prime_count ;
    
    
    
  delete [] a;
  delete [] b;
  delete [] c;
  delete [] d ;
    
    return summary ;
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
// _prime(300000);
//_prime(1000);
    
    prime::result summary[15] ;
    
    int range [15] = { 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000, 110000, 120000, 130000, 140000, 150000};
    
    for (int i = 0 ; i < 15 ; ++i)
    {
        cout << endl << endl << "Crunching " << range[i] << endl ;
       summary[i] = Prime(range[i], summary[i]);
    }

    cout << "Num" << " " << "#primes" << " " << "t(school)" << " " << "t(sieve)" << " " << "t(upto)" << " " << "t(factor)" << "#school" << " " << "#sieve" << " " << "#upto" << " " << "#factors" << endl ;

    for (int j = 0 ; j < 15 ; ++j)
    {
        cout << summary[j].numbers << " " <<  summary[j].primes_found << " " << summary[j]._school_method_time << " " << summary[j]._seive_time << " " << summary[j]._upto_prime_time << " " << summary[j].factor_time  << " | " << summary[j]._school_method_counter << " " << summary[j]._seive_of_eratosthenes_counter << " " << summary[j]._upto_prime_counter << " " << summary[j]._factorization_prime_count <<  endl ;
        }
}


#if 0

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed();
  return 0;
}





Num #primes t(school) t(sieve) t(upto) t(factor)|#school #sieve #upto #factors
10000 1229 0.009681 0.000217 0.00345 0.000208 | 117527 31848 776631 36981
20000 2262 0.025789 0.000462 0.011237 0.000443 | 301276 65609 2606169 80799
30000 3245 0.04749 0.000661 0.023277 0.00077 | 523929 99971 5341532 127221
40000 4203 0.07166 0.000845 0.03904 0.000911 | 777675 134692 8939348 175328
50000 5133 0.098667 0.001083 0.057373 0.001185 | 1055976 169695 13312247 224696
60000 6057 0.127299 0.001263 0.079837 0.001427 | 1358766 204887 18514649 275076
70000 6935 0.160048 0.001547 0.105319 0.001742 | 1675555 240316 24252391 326285
80000 7837 0.196851 0.001892 0.132662 0.002111 | 2017481 275816 30949029 378196
90000 8713 0.233104 0.002166 0.163336 0.002353 | 2372121 311479 38233362 430762
100000 9592 0.272436 0.002465 0.197822 0.002602 | 2745694 347223 46314477 483848
110000 10453 0.313125 0.002835 0.234731 0.002938 | 3130613 383093 54980620 537463
120000 11301 0.356035 0.003126 0.276222 0.003221 | 3528840 419057 64242046 591516
130000 12159 0.400827 0.003427 0.318185 0.003533 | 3944118 455074 74344257 645990
140000 13010 0.446595 0.003691 0.368461 0.003838 | 4371403 491158 85092058 700849
150000 13848 0.496871 0.004047 0.413433 0.004145 | 4809061 527330 96384756 756056
Program ended with exit code: 0
#endif 
