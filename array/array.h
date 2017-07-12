//
//  array.h
//  c++
//
//  Created by Aashish Sharma on 6/29/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____array__
#define __c____array__

#include "../util/util.h"



class Array {
public:
    void reverse( char str[]);
    int string2number(const char str[]);
    int removedups(int ary[], int num);
    
    void p(const char str1[], char str[]);
    void p(const char str1[], int* a, int b);
    
    void copy(char* , const char*);


    
private:
    int a_pow_b(int a, int b);
    void bubbleSort(int *a, int num);
    
    
};

#endif /* defined(__c____array__) */