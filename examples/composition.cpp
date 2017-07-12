//
//  composition.cpp
//  c++
//
//  Created by Aashish Sharma on 8/20/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "composition.h"


#include <iostream>
#include <fstream> 

#include <iomanip>

using namespace std;

#ifdef WIN32
#include <cassert>
#include <ctime>
#include "vld.h"
#else
#include <assert.h>
#include <time.h>
#endif 


#define _NOCOPYOREQUAL_(X) X(const X& a); X& operator=(const X& a) ; 

static const int SHOW = 1 ;

// mstring class

class msting {
public:
    mstring (const char *s=0): _s(0) {
        if (SHOW) {
            cout << "in mstring constructor" ;
            if (s) {
                cout << s ;
            }
            cout << endl ;
            
            }
        _allocate(s) ;
    }
    
    ~mstring() {
        if (SHOW) {
            cout << " in mstring destructor" ;
            if (_s) {
                cout << _s ;
            }
            cout << endl ;
        }
        _free() ;
    }
    
    
    
    
    mstring (const mstring& rhs)
    {
        if (SHOW)
        { cout << "in mstring copy constructor" << rhs << endl ;}
        _allocate(rhs._s);
        
    }
    
    mstring& operator=(const mstring& rhs) {
        if (SHOW)
            cout << "mstring equal constructor" << rhs << endl ;
        if (this != rhs)
        {
            _free();
            _allocate(rhs._s);
            
        }
        return *this ;
    }
    
    operator bool() const {return _s ? true : false; } ;
    
private:
    char *_s;
    void _allocate(const char* s)
    {
        if (s)
        {
        _s  = new char [strlen(s)+1];
        strcpy(_s, s);
        }
    }
    
    void _free() {
        delete [] _s ; _s = 0 ;
    }
};
