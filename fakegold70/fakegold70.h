//
//  fakegold70.h
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____fakegold70__
#define __c____fakegold70__

#include "../util/util.h" 

class fakegold70 {
    
 
    
public:
    enum { MAX = 70 };
    int iteration = 0 ;
    
     fakegold70();
    fakegold70(int i);
    ~fakegold70();
    
    friend  ostream& operator<<(ostream& o, fakegold70& a) ;
    
    int weigh(int, int);
    
    int find_fake(int, int);
    int iterations_fake_safe = 0 ; 
    
    
private:
    int* _safe ;
   
    
    struct bucket {
        int low;
        int high;
    } ;
    
    int spare1;
    int spare2;
    
    
};

#endif /* defined(__c____fakegold70__) */

#if 0 

Random number found is 41
| 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| R | R | R | R | R | R | R |
| 7 | 8 | 9 |10 |11 |12 |13 |
| R | R | R | R | R | R | R |
|14 |15 |16 |17 |18 |19 |20 |
| R | R | R | R | R | R | R |
|21 |22 |23 |24 |25 |26 |27 |
| R | R | R | R | R | R | R |
|28 |29 |30 |31 |32 |33 |34 |
| R | R | R | R | R | R | R |
|35 |36 |37 |38 |39 |40 |41 |
| R | R | R | R | R | R | F |
|42 |43 |44 |45 |46 |47 |48 |
| R | R | R | R | R | R | R |
|49 |50 |51 |52 |53 |54 |55 |
| R | R | R | R | R | R | R |
|56 |57 |58 |59 |60 |61 |62 |
| R | R | R | R | R | R | R |
|63 |64 |65 |66 |67 |68 |69 |
| R | R | R | R | R | R | R |
Found fake coin at : 41
total Iterations = : 6
RUNNING 70 iterations nnow

Found fake coin at : 0 total Iterations = : 6
Found fake coin at : 1 total Iterations = : 6
Found fake coin at : 2 total Iterations = : 5
Found fake coin at : 3 total Iterations = : 6
Found fake coin at : 4 total Iterations = : 4
Found fake coin at : 5 total Iterations = : 6
Found fake coin at : 6 total Iterations = : 5
Found fake coin at : 7 total Iterations = : 6
Found fake coin at : 8 total Iterations = : 6
Found fake coin at : 9 total Iterations = : 6
Found fake coin at : 10 total Iterations = : 5
Found fake coin at : 11 total Iterations = : 6
Found fake coin at : 12 total Iterations = : 6
Found fake coin at : 13 total Iterations = : 6
Found fake coin at : 14 total Iterations = : 6
Found fake coin at : 15 total Iterations = : 6
Found fake coin at : 16 total Iterations = : 7
Found fake coin at : 17 total Iterations = : 2
Found fake coin at : 18 total Iterations = : 6
Found fake coin at : 19 total Iterations = : 5
Found fake coin at : 20 total Iterations = : 6
Found fake coin at : 21 total Iterations = : 4
Found fake coin at : 22 total Iterations = : 6
Found fake coin at : 23 total Iterations = : 5
Found fake coin at : 24 total Iterations = : 6
Found fake coin at : 25 total Iterations = : 6
Found fake coin at : 26 total Iterations = : 6
Found fake coin at : 27 total Iterations = : 5
Found fake coin at : 28 total Iterations = : 6
Found fake coin at : 29 total Iterations = : 6
Found fake coin at : 30 total Iterations = : 6
Found fake coin at : 31 total Iterations = : 6
Found fake coin at : 32 total Iterations = : 6
Found fake coin at : 33 total Iterations = : 7
Found fake coin at : 34 total Iterations = : 7
Found fake coin at : 35 total Iterations = : 6
Found fake coin at : 36 total Iterations = : 5
Found fake coin at : 37 total Iterations = : 6
Found fake coin at : 38 total Iterations = : 4
Found fake coin at : 39 total Iterations = : 6
Found fake coin at : 40 total Iterations = : 5
Found fake coin at : 41 total Iterations = : 6
Found fake coin at : 42 total Iterations = : 6
Found fake coin at : 43 total Iterations = : 6
Found fake coin at : 44 total Iterations = : 5
Found fake coin at : 45 total Iterations = : 6
Found fake coin at : 46 total Iterations = : 6
Found fake coin at : 47 total Iterations = : 6
Found fake coin at : 48 total Iterations = : 6
Found fake coin at : 49 total Iterations = : 6
Found fake coin at : 50 total Iterations = : 7
Found fake coin at : 51 total Iterations = : 7
Found fake coin at : 52 total Iterations = : 6
Found fake coin at : 53 total Iterations = : 5
Found fake coin at : 54 total Iterations = : 6
Found fake coin at : 55 total Iterations = : 6
Found fake coin at : 56 total Iterations = : 6
Found fake coin at : 57 total Iterations = : 6
Found fake coin at : 58 total Iterations = : 6
Found fake coin at : 59 total Iterations = : 7
Found fake coin at : 60 total Iterations = : 3
Found fake coin at : 61 total Iterations = : 6
Found fake coin at : 62 total Iterations = : 5
Found fake coin at : 63 total Iterations = : 6
Found fake coin at : 64 total Iterations = : 6
Found fake coin at : 65 total Iterations = : 6
Found fake coin at : 66 total Iterations = : 6
Found fake coin at : 67 total Iterations = : 6
Found fake coin at : 68 total Iterations = : 7
Found fake coin at : 69 total Iterations = : 7
Program ended with exit code: 0

#endif