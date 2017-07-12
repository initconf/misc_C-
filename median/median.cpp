//
//  median.cpp
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//


// this code implements algorithm from Chapter 9.2 of CLR book
// "N-order statistics and Median"

#include "median.h"

using namespace std;

median::median()
{
    int kth=MAX/2 ;
    
    create_unsorted_random_array();
    
    int i = randomized_select(_array, 1, MAX, kth);
    
    
    cout <<   "nth largest element is: " << i << endl ;
}


median::median(int kth, int max)
{
    
    MAX = max ;
     create_unsorted_random_array();

    clock_t start = clock() ;
    int i = randomized_select(_array, 1, MAX, kth);
    clock_t end = clock() ;
    cout << "I: " << MAX << " kth: " << i << "  Time: " << double(end - start)/CLOCKS_PER_SEC << " secs" << endl ;
  

}

median::~median()
{
    delete [] _array ;
}

// unsorted random array of n integers

void median::create_unsorted_random_array()
{
    _array = new int [MAX] ;

    for (int i = 0 ; i < MAX ; ++i)
    {
       // _array[i] = random_in_range(1,15);
        _array[i] = i ;
    }
    
    srand(time(NULL));
    
    for (int i = 0 ; i < MAX ; ++i)
    {
        int r = rand()%MAX ;
        swap(_array[r],_array[i]);
        
    }
    
//    for (int i = 0; i < MAX ; ++i)
//    {
//        cout << _array[i] << " " ;
//        
//        if (i % (MAX/5) == 0 && i !=0 )
//            cout << endl ;
//    }
}


int median::randomized_select(int *A, int p, int r, int i)
{
    if (p == r)
        return A[p] ;
    
    int q = randomized_partition(A, p, r) ;
    
    int k = q-p+1 ;
    
    if (i == k) // the pivot value is the answer
        return A[q];
    else if (i < k)
    {
        return randomized_select(A, p, q-1, i);
    }
    else
        return randomized_select(A, q+1, r, i-k);
    
}

int median::randomized_partition(int* A, int p, int r)
{
    
    srand(time(NULL));
    
    int i = p + (rand() % (int)(r - p+1));
    
    swap (A[r], A[p]);
    
    return partition(A, p, r);
    
    
}

int median::partition(int *A, int p , int r)
{
    int x = A[r];
    int i = p - 1;
    
    for (int j = p ; j < r-1; j++)
    {
        if (A[j] <= x)
        {
            i += 1;
            swap(A[i], A[j]);
        }
    }
    
    swap(A[i+1], A[r]);
    
    return i+1;
}

int median::random_in_range(int min, int max)
{
    int p = min ;
    int r = max ;
    
    
    return  p + (rand() % (int)(r - p+1));
}