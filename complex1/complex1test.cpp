//
//  complex1test.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "complex1.h"

int main()
{
    
    complex1 a;
    
    a.init();
    a.print();
    a.fini() ;
    
    a.init(5);
    a.print();
    a.fini();
    
    a.init(5,8);
    a.print();
    a.fini();
    
    a.init(-5,-10);
    a.print();
    a.fini();
    
    
    return 0;
    
}

#if 0 
hello 0+0i
5+0i
5+8i
-5-10i
Program ended with exit code: 0
#endif 
