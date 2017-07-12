//
//  stack_min_element.cpp
//  c++
//
//  Created by Aashish Sharma on 10/20/15.
//  Copyright © 2015 Aashish Sharma. All rights reserved.
//

#include "stack_min_element.hpp"


//int main()
//{
//    cout << "Hello world" << endl ;
//    
//    dstack<int> _stack1 ;
//    dstack<int> _min_stack ;
//    
//    darray<int> ary;
//    
//    int rand_num = 0 ;
//     srand (time(NULL));
//    
//    for (int i  = 0 ; i < 100 ; ++i)
//    {
//        rand_num = rand()%1000;
//        ary[i] = rand_num;
//        
//    }
//    
//    for (int i = 0 ; i < 100 ; ++i)
//    {
//    cout << ary[i] << endl  ;
//        _stack1.push(ary[i]);
//        
//        if (_min_stack.isempty())
//            _min_stack.push(ary[i]);
//        
//        if (ary[i] < _min_stack.top())
//        {
//            _min_stack.push(ary[i]);
//        }
//        else
//            _min_stack.push(_min_stack.top());
//        
//    }
//    .
//    
//    cout << "Minimum element in array of 100 elements is " << _min_stack.top() << endl ;
//    return 0; 
//}


#if 0

int main()
{
    min_stack s1;
    
    srand (time(NULL));
    int rand_num = 0 ;
    
    for (int i  = 0 ; i < 100 ; ++i)
    {
        rand_num = rand()%1000;
        s1.push_m(rand_num);
    }

    s1.print_stack();
    
    cout << endl << endl << "Minimum element in array of 100 elements is " << s1.min_element() << endl ;
}




#endif 