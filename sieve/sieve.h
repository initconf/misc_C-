//
//  sieve.h
//  c++
//
//  Created by Aashish Sharma on 7/25/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____sieve__
#define __c____sieve__


#include "../util/util.h"

#ifdef  __APPLE__ //&& __MACH__
    #include <assert.h>
#endif




class sieve {
public:
    int* school_method(int, int*);
    int* sieve_of_eratosthenes(int, int*);
    int* upto_prime(int, int*);
    void print(const char*, int, int*);
    bool verify(int, int*, int, int*);
    
    int _upto_prime_counter = 0  ;
    int _school_method_counter = 0  ;
    int _seive_of_eratosthenes_counter = 0 ;
    
private:
    bool _is_prime(const int);
    float _sq_root(int );
    
 
    
};


#endif /* defined(__c____sieve__) */
