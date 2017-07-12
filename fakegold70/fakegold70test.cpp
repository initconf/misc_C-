//
//  fakegold70test.cpp
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "fakegold70.h"




int main()
{
    
    fakegold70 f;
    
    cout << f;
    
    int low = 0 ;
    int high = f.MAX -1 ;
    
//    cout << "Found fake coin at : " <<     f.weigh(low, high) << endl ;
//    
//    cout << "total Iterations = : " << f.iteration << endl ;
    
    cout << "NEW: find_fake found fake coin at : " <<  f.find_fake(low, high) << " with iterations of " << f.iterations_fake_safe <<  endl ;
    
    cout << " RUNNING 70 iterations nnow " << endl << endl ;
    
//    for (int i = 0 ; i < f.MAX ; i++)
//    {
//        fakegold70 ff(i);
//        
//        low = 0 ;
//        high = f.MAX  ;
//        
//        cout << "Found fake coin at : " <<     ff.weigh(low, high) ;
//        
//        cout << " total Iterations = : " << ff.iteration << endl ;
//        
//        ff.iteration = 0 ;
//        
//    }
    
    for (int i = 0 ; i < f.MAX ; i++)
    {
        fakegold70 fb(i);
        
        low = 0 ;
        high = fb.MAX -1 ;

        cout << "NEW: find_fake returns : " <<  fb.find_fake(low, high) << " with iterations of " << fb.iterations_fake_safe <<  endl ;
        fb.iterations_fake_safe = 0 ;
   
        
        
    }
    
    
    return 0;
}

#if 0

Random number found is 17
| 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| R | R | R | R | R | R | R |
| 7 | 8 | 9 |10 |11 |12 |13 |
| R | R | R | R | R | R | R |
|14 |15 |16 |17 |18 |19 |20 |
| R | R | R | F | R | R | R |
|21 |22 |23 |24 |25 |26 |27 |
| R | R | R | R | R | R | R |
|28 |29 |30 |31 |32 |33 |34 |
| R | R | R | R | R | R | R |
|35 |36 |37 |38 |39 |40 |41 |
| R | R | R | R | R | R | R |
|42 |43 |44 |45 |46 |47 |48 |
| R | R | R | R | R | R | R |
|49 |50 |51 |52 |53 |54 |55 |
| R | R | R | R | R | R | R |
|56 |57 |58 |59 |60 |61 |62 |
| R | R | R | R | R | R | R |
|63 |64 |65 |66 |67 |68 |69 |
| R | R | R | R | R | R | R |
NEW: find_fake found fake coin at : 17 with iterations of 4
RUNNING 70 iterations nnow

NEW: find_fake returns : 0 with iterations of 4
NEW: find_fake returns : 1 with iterations of 4
NEW: find_fake returns : 2 with iterations of 4
NEW: find_fake returns : 3 with iterations of 4
NEW: find_fake returns : 4 with iterations of 4
NEW: find_fake returns : 5 with iterations of 4
NEW: find_fake returns : 6 with iterations of 3
NEW: find_fake returns : 7 with iterations of 4
NEW: find_fake returns : 8 with iterations of 4
NEW: find_fake returns : 9 with iterations of 4
NEW: find_fake returns : 10 with iterations of 4
NEW: find_fake returns : 11 with iterations of 4
NEW: find_fake returns : 12 with iterations of 4
NEW: find_fake returns : 13 with iterations of 3
NEW: find_fake returns : 14 with iterations of 4
NEW: find_fake returns : 15 with iterations of 4
NEW: find_fake returns : 16 with iterations of 4
NEW: find_fake returns : 17 with iterations of 4
NEW: find_fake returns : 18 with iterations of 4
NEW: find_fake returns : 19 with iterations of 4
NEW: find_fake returns : 20 with iterations of 3
NEW: find_fake returns : 21 with iterations of 2
NEW: find_fake returns : 22 with iterations of 2
NEW: find_fake returns : 23 with iterations of 4
NEW: find_fake returns : 24 with iterations of 4
NEW: find_fake returns : 25 with iterations of 4
NEW: find_fake returns : 26 with iterations of 4
NEW: find_fake returns : 27 with iterations of 4
NEW: find_fake returns : 28 with iterations of 4
NEW: find_fake returns : 29 with iterations of 3
NEW: find_fake returns : 30 with iterations of 4
NEW: find_fake returns : 31 with iterations of 4
NEW: find_fake returns : 32 with iterations of 4
NEW: find_fake returns : 33 with iterations of 4
NEW: find_fake returns : 34 with iterations of 4
NEW: find_fake returns : 35 with iterations of 4
NEW: find_fake returns : 36 with iterations of 3
NEW: find_fake returns : 37 with iterations of 4
NEW: find_fake returns : 38 with iterations of 4
NEW: find_fake returns : 39 with iterations of 4
NEW: find_fake returns : 40 with iterations of 4
NEW: find_fake returns : 41 with iterations of 4
NEW: find_fake returns : 42 with iterations of 4
NEW: find_fake returns : 43 with iterations of 3
NEW: find_fake returns : 44 with iterations of 2
NEW: find_fake returns : 45 with iterations of 2
NEW: find_fake returns : 46 with iterations of 4
NEW: find_fake returns : 47 with iterations of 4
NEW: find_fake returns : 48 with iterations of 4
NEW: find_fake returns : 49 with iterations of 4
NEW: find_fake returns : 50 with iterations of 4
NEW: find_fake returns : 51 with iterations of 4
NEW: find_fake returns : 52 with iterations of 3
NEW: find_fake returns : 53 with iterations of 4
NEW: find_fake returns : 54 with iterations of 4
NEW: find_fake returns : 55 with iterations of 4
NEW: find_fake returns : 56 with iterations of 4
NEW: find_fake returns : 57 with iterations of 4
NEW: find_fake returns : 58 with iterations of 4
NEW: find_fake returns : 59 with iterations of 3
NEW: find_fake returns : 60 with iterations of 4
NEW: find_fake returns : 61 with iterations of 4
NEW: find_fake returns : 62 with iterations of 4
NEW: find_fake returns : 63 with iterations of 4
NEW: find_fake returns : 64 with iterations of 4
NEW: find_fake returns : 65 with iterations of 4
NEW: find_fake returns : 66 with iterations of 3
NEW: find_fake returns : 67 with iterations of 2
NEW: find_fake returns : 68 with iterations of 2
NEW: find_fake returns : 69 with iterations of 1
Program ended with exit code: 0

#endif