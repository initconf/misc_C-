//
//  intmatrix1.h
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____intmatrix1__
#define __c____intmatrix1__

#include "../util/util.h"

#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif

class intmatrix1 {

private:
    enum MAXC{ C=100 } ;
    
    int _row;
    int _col ;
    int (*_matrix)[C] ;
    
   char* itoa(int, char *, int );
    int atoi(char *s) ; 

public:
    void init();
    void init(int, int);
    void init(int, int, int);
    void init (const char *) ;
    void print(string str) const ;
    void fini();
    
    bool isEmpty();
    bool isEqual(intmatrix1);
    intmatrix1 add (const intmatrix1&);
    intmatrix1 mult (const intmatrix1&);
       
    
};






#endif /* defined(__c____intmatrix1__) */
