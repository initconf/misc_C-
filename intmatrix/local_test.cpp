//
//  local_test.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "intmatrix.h"


void test_init_fini() {
   // intmatrix a {3,4};
   // a.init() ;
//    a.init(3,4) ;
  

    intmatrix one {"2,3,4"};
    intmatrix two {"1,2,3|4,2,4|2,3,5"};
    
    intmatrix three {};
    
    three = one * two ;
    
 //   three.print("Matrix Three");
    
    cout << "Matrix three is " << three << endl ;
    
    intmatrix four {"22, 22, 38"};
    
    if (four == three)
    {
        cout << "Matrix four is equal to matrix three" << endl ; 
    }
    
   // a.init(3,4, 7) ;

   // cout << "Matrix Emptyness is : " << a.isEmpty() << endl ;
    
   // a.print("Matrix B") ;
    //a.fini();
    
}


/*----------------------------------------------------------------
 test bed
 -----------------------------------------------------------------*/
void testbed() {
    test_init_fini();
    //test_add() ;
    // test_mult() ;
}

#if 0
/*----------------------------------------------------------------
 main
 -----------------------------------------------------------------*/
int main() {
   testbed() ;
    return 0 ;
}

#endif
//EOF

