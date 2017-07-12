#if 0
//
//  ash_test.cpp
//  c++
//
//  Created by Aashish Sharma on 8/31/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "iset64.h" 

int main ()
{
    iset64 a;
    cout << "a = " << a << endl;
    
    a = a + 1 ;
    
     cout << "a = " << a << endl;
    
    iset64 b ;
    b = b + 10 ;
    
    b = b + 11;
    
    iset64 c;
    c = a + b ;
    
  
    cout << "set A = " << a << endl;
    cout << "set B = " << b << endl;
    cout << "set C = " << c << endl;
    
    
    a+=2 ;
    a+=30 ;
    
    b+=30 ;
    b+=2 ;
    
    c+=b ;
    
    cout << "set A = " << a << endl;
    cout << "set B = " << b << endl;
    cout << "set C = " << c << endl;

    a += 63;
    a += 0;
    
    cout << "set A = " << a << endl;
    
    a++ ;

    cout << "set A = " << a << endl;
    
    iset64 blah = a++;
    
    cout << "Blah = " << blah << endl ; 
    
    int x[] = { 1, 3, 6 };
    iset64 d(x, sizeof(x) / sizeof(int));
    cout << "set d = " << d << endl;
    
    d = d - 1 ;
    
    cout << "set d = " << d << endl;
    

    cout << "after c = a - b" << endl ; 
    c = a - b ;
    
    cout << "set A = " << a << endl;
    cout << "set B = " << b << endl;
    cout << "set C = " << c << endl;

    iset64 p ;
    p+= 0;
    p+= 20;
    p+= 63;
    

    cout << "ONLY ======= P: " << p <<endl ;
    assert ( p ==++p) ;
    
    cout << "P: " << p <<endl ;
    
    cout << "P++: " << p++ << endl ;

    cout << "P--: " << p-- << endl ;
    return 0;
}

#endif
