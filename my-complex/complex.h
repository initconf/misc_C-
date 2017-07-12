//
//  complex.h
//  c++
//
//  Created by Aashish Sharma on 9/24/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____complex__
#define __c____complex__

#include "../util/util.h"

using namespace std;

class complex {
    
private:
    int _real ;
    int _imag ;
    char * _name ;
    
    void _strcat (char *, char *);
    char* itoa(int, char *, int );
    char *num2name(int, int, char*);
    
    void _copy(const complex& rhs);
    void _release();
    
public:
    complex();
    complex(int);
    complex(int, int);
    void print() const;
    ~complex();
    
    friend  ostream& operator<<(ostream& o, complex& a) ;
    
    bool operator==(const complex sec);
    bool operator!=(const complex sec);
    
    complex setxy(int, int);
    
    //equal operator and copy constructor
    
    complex (const complex& rhs);
    complex& operator=(const complex& rhs);
    
};


#endif /* defined(__c____complex__) */
