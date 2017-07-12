//
//  intmatrix.h
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____intmatrix__
#define __c____intmatrix__

#include "../util/util.h"

#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif

class intmatrix {

private:
    enum MAXC{ C=100 } ;
    
    int _row;
    int _col ;
    int (*_matrix)[C] ;
    
   char* itoa(int, char *, int );
    int atoi(char *s) ;
    

public:
     intmatrix();
     intmatrix(int, int);
     intmatrix(int, int, int);
     intmatrix (const char *) ;
//void print(string str) const ;
    
friend  ostream& operator<<(ostream& o, intmatrix& a) ;

     ~intmatrix();
    
    bool isEmpty();
//    bool isEqual(intmatrix);
//    intmatrix add (const intmatrix&);
  //  intmatrix mult (const intmatrix&);
    
    
    bool operator==(const intmatrix sec);
    intmatrix& operator+(const intmatrix &rhs);
    intmatrix& operator*(const intmatrix &rhs);

       
    
};






#endif /* defined(__c____intmatrix__) */
