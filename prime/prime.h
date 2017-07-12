//
//  prime.h
//  c++
//
//  Created by Aashish Sharma on 7/25/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____prime__
#define __c____prime__


#include "../util/util.h"

#ifdef  __APPLE__ //&& __MACH__
    #include <assert.h>
#endif




class prime {
    
public:
    int* school_method(int, int*);
    int* prime_of_eratosthenes(int, int*);
    int* upto_prime(int, int*);
    int* _populate_factors(int, int*);
    
    
    void print(const char*, int, int*);
    bool verify(int, int*, int, int*);
    
    int _upto_prime_counter = 0  ;
    int _school_method_counter = 0  ;
    int _seive_of_eratosthenes_counter = 0 ;
    int _factorization_prime_count = 0 ; 
    
    struct result {
        int numbers = 0;
        int primes_found = 0 ;
        unsigned int _upto_prime_counter = 0;
        unsigned int _school_method_counter = 0 ;
        unsigned int _seive_of_eratosthenes_counter = 0 ;
        unsigned int _factorization_prime_count = 0 ;
        double _upto_prime_time = 0 ;
        double _school_method_time = 0;
        double _seive_time = 0;
        double factor_time = 0;
    };
private:
    bool _is_prime(const int);
    float _sq_root(int );
    
 
    
};


#endif /* defined(__c____prime__) */
