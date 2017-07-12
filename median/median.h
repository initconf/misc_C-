//
//  median.h
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____median__
#define __c____median__

#include "../util/util.h"

class median {
    
    
public:
    //enum { MAX = 150000};
    //enum { MAX = 15000};

    median();
    median(int kth, int max);
    ~median();
    long MAX = 0 ;
    
private:
    int* _array;
    
    
    // unsorted random array of n integers
    void create_unsorted_random_array();
    
    
    // using chapter 9.2  from CLR Book
    // Selection in expected time for
    // medians and order statistics
    
    int randomized_select(int*, int, int, int);
    int randomized_partition(int*, int, int);
    int partition(int *A, int p , int r);
    
    int random_in_range(int min, int max);
};






#endif /* defined(__c____median__) */
