//
//  complex1.h
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____complex1__
#define __c____complex1__

#include "../util/util.h"

using namespace std;

class complex1 {

private:
    int _real ;
    int _imag ;
    char * _name ;
    
    void _strcat (char *, char *);
    char* itoa(int, char *, int );
    char *num2name(int, int); 
    
public:
    void init();
    void init(int);
    void init(int, int);
    void print() const;
    void fini();
    
};
























#endif /* defined(__c____complex1__) */
