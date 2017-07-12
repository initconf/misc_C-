//
//  local_test.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "intmatrix1.h"


void test_init_fini() {
    intmatrix1 a ;
    a.init() ;
    a.init(3,4) ;
  

   // a.init(3,4, 7) ;

    cout << "Matrix Emptyness is : " << a.isEmpty() << endl ;
    
    a.print("Matrix B") ;
    a.fini();
    
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

//EOF


#endif 