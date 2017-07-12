//
//  magicsquare.h
//  c++
//
//  Created by Aashish Sharma on 7/26/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____magicsquare__
#define __c____magicsquare__

#include "../util/util.h"

class magicsquare {
    
public:
   void print_magic_square(int );
    
private:
    
    bool _is_occupied(int* a, int x, int y );
    void _initialize_array(int x[][5], int, int);
    void _display_array(int x[][5], int, int);
    void _get_next_row_col(int &x, int &y);
    
    
};



#endif /* defined(__c____magicsquare__) */
