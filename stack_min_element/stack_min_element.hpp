//
//  stack_min_element.hpp
//  c++
//
//  Created by Aashish Sharma on 10/20/15.
//  Copyright © 2015 Aashish Sharma. All rights reserved.
//

#ifndef stack_min_element_hpp
#define stack_min_element_hpp

#include "../util/util.h"
#include "../dstack/dstack.h"
#include "../str/str.h"


class min_stack
{
public:
    
    void push_m(int i)
    {
        push_mm(i);
    }
    
    int top_m()
    {
       return top_mm();
    }
    
    void pop_m()
    {
        pop_mm();
        
    }
    
    int min_element()
    {
        return _min_stack_top();
    }
    
    void print_stack()
    {
        print();

    }
    
    static void print(int& x) {
        cout << x << " ";
    }
    
private:
    
    dstack<int> _stack1 ;
    dstack<int> _min_stack ;
    
    void push_mm(int i)
    {
        _stack1.push(i);
        if (_min_stack.isempty())
        {
            _min_stack.push(i);
        }
        
        else if (i <= _min_stack.top())
        {
            _min_stack.push(i);
        }
        else
            _min_stack.push(_min_stack.top());
        
    }

    int top_mm ()
    {
        return _stack1.top();
        
    }
    
    int _min_stack_top()
    {
        return _min_stack.top();
    }
    
    void pop_mm ()
    {
        
        _stack1.pop();
        _min_stack.pop();
        
    }


    void print()
    {
        this->_stack1.for_each_element_of_stack_from_top_to_bottom(print);
        
    }
    
    
};


#endif /* stack_min_element_hpp */
