//
//  sieve.cpp
//  c++
//
//  Created by Aashish Sharma on 7/25/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "sieve.h"

float sieve::_sq_root(int n) //Newton–Raphson method
{
    
    float x = n;
    float y = 1;
    float e = 0.0001; /* e decides the accuracy level*/
    
    while(x - y > e)
    {
            x = (x + y)/2;
            y = n/x;
    }
        return x;
}

bool sieve::_is_prime(const int n)
{
    for (int i = 2; i <= _sq_root(n); i++)
    //for (int i = 2; i <= n/2; i++)
    {
        _school_method_counter++ ;
        
       if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int* sieve::school_method(int n, int* as)
{
    int count = *as ;
    int* a = new int[n] ;
    
    for (int i = 2 ; i <= n; i++)
    {
        
        
        if( _is_prime(i))
        {
            a[count] = i ;
            count++;
        }
    }
    *as=count ;
    return a ;
}


int* sieve::sieve_of_eratosthenes(int n, int* as)
{
  
    int* tmp = new int[n] ;
    
    // generate list of integers from 2 to N
    
    for (int i=2 ; i <=n ; i++)
    {
        tmp[i-2] = i ;
    }
    
    int next_num = 0 ;
    
    for (int i = 0 ; i <= n ; i++)
    {
        next_num = tmp[i] ;
        
        
        for (int j = i+next_num; j <= n ; j += next_num)
        {
            _seive_of_eratosthenes_counter++;
            
            if (next_num == 0 )
                break ;
            
          //  cout << " i " << i << " j " << j << " next_num " << next_num << " tmp[" << j << "] : " << tmp[j] << endl ;
            tmp[j] = 0;
        }
    }
    
   int count = 0 ;
    
    // count remaining non-zero elements
    for (int i = 0; i <=n ; i++)
    {
        if (tmp[i] != 0 )
            count ++ ;
    }
    
    int* a = new int [count];
    
    for (int i = 0 ; i <=count; i++)
    {
        a[i] = 0; 
    }
    
    int num = *as;
    
    // assign the prime numbers to a to be exported back
    for (int i = 0 ; i <=n ; i++)
    {
        if (tmp[i] != 0 )
        {
            a[num] = tmp[i] ;
            num++ ;
            
        }
    }
    
    *as=num ;
    
    delete [] tmp ;
    
    return a;
}


int* sieve::upto_prime(int num, int* num_elements)
{

    int* prime_list = new int (num);

    
    //initialize the array.
//    for (int i = 0 ; i < num ; i++)
//    {
//        prime_list[i] = 1;
//    }
    
    //setup 2 as first prime number
    
    int j = 0 ;
    prime_list[j] = 2;
    bool prime_found = true ;
    
    //since table is populated with 2
    // we've found first prime number
    
    int total_primes = 1;
    int counter = 0 ;
    
    for (int i = 3; i< num; ++i)
    {
        prime_found = true ;
       //cout << endl << " I : " << i  ;
        
        for (int k = 0; k < total_primes  ; k++)
        {
            _upto_prime_counter++ ;
            
            if (i != prime_list[k])
            {
                //cout << " k " << k << " prime_list[k]: " << prime_list[k] << endl ;
                
                if (i % prime_list[k] == 0 )
                {
                    //cout << endl << i << " is not a prime " << endl ;
                    prime_found = false ;
                    break;
                }
            }       
        }
        
        if (prime_found)
        {
            
            prime_list[total_primes] = i ;
            total_primes += 1 ;
        }
        
      /////////#      counter = 0 ;
        

    }
    
    
    *num_elements = total_primes ;
    
    return prime_list ;
    
}


void sieve::print(const char* s, int as, int* a)
{
 
    cout << s << " " << as << " prime numbers" << endl ;
    
    for (int i = 0 ; i < as ; i++)
    {
        cout  <<  a[i] << " "  ;
    }
    
    cout << endl << endl  ;
    
}

bool sieve::verify(int as, int* a, int ss, int* b)
{
    if (as != ss )
    {
        return false ;
    }
    
    for (int i = 0 ; i < as; i++ )
    {
        if (a[i] != b[i])
        {
            return false;
        }
        
    }
    
    return true;
}