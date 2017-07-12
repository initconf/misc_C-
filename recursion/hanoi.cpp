
/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: hanoi.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has enumeration class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*----------------------------------------------------------------
Definition of routines of  hanoi
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
hanoi using recursion

1 -> 3
1 -> 2
3 -> 2
1 -> 3
2 -> 1
2 -> 3
1 -> 3
Number of itr = 7
-----------------------------------------------------------------*/

void recursion::move_disk(char from, char to)
{
    cout << "moving disk from " << from << " to " << to << endl ;
}

void recursion::_t_r(unsigned n, char s, char t, char d, int& num_rec, str& str){
    
     num_rec++ ;
    
    char from = s;
    char with = t ;
    char to = d ;

    str = "Hanoi disks";
    
    if (n <= 1)
    {
          move_disk(from, to);
    }
    else
    {
      _t_r(n-1, from, to, with, num_rec, str);
      move_disk(from, to);
        str = from+to;
      _t_r(n-1, with, from, to, num_rec, str);
    }

    
}

void recursion::hanoi_recursion(unsigned n, int& num_rec, str& s) {
  _t_r(n, '1', '2', '3', num_rec, s);
}



/*----------------------------------------------------------------
hanoi using two stack
-----------------------------------------------------------------*/
// code from https://gist.github.com/zy66543/b0d25bab88917832c6b7

void recursion::hanoi_stack(unsigned n, int& size_of_stack, str& str) {
  size_of_stack = 0;

    dstack<int> from;
    dstack<int> with;
    dstack<int> to;
    
    
    str = "Hanoi disks" ;
    
    int number_of_disks = n; // define the number of disks you want to play
    
    for(int i = number_of_disks; i >= 1; i--)
    from.push(i);
//    printHanoi(from, with, to);
    MoveDisks(from, with, to, number_of_disks, size_of_stack);
 
  //  printHanoi(from, with, to);
    
}

void recursion::MoveLast(dstack<int>& origin, dstack<int>& target, int& size_of_stack)
{
    size_of_stack++;
    
    if(origin.isempty())
    {
        cout << "Error moving the last disk: stack empty." << endl;
        return;
    }
    int tmp = origin.top();
    if(!target.isempty() && tmp >= target.top())
    {
        cout << "Error moving the last disk: the last is larger than the top of the target stack." << endl;
        return;
    }
    origin.pop();
    target.push(tmp);
  //  printHanoi(s1, s2, s3);
}

void recursion::MoveDisks(dstack<int>& origin, dstack<int>& buffer, dstack<int>& target, int n, int& size_of_stack)
{
    
    size_of_stack ++ ;
    
    if(n <= 0)
        return;
    // Move n-1 disks from the origin to the buffer.
    MoveDisks(origin, target, buffer, n-1, size_of_stack);
    
    // Move the last disk from the origin to the target.
    MoveLast(origin, target, size_of_stack);
    
    // Move n-1 disks from the buffer to the target.
    MoveDisks(buffer, origin, target, n-1, size_of_stack);
}

void recursion::printHanoi(dstack<int> s1, dstack<int> s2, dstack<int> s3)
{
    cout << string(30, '-') << endl;
    if(s1.isempty())
        cout << "stack1: empty" << endl;
    else
    {
        cout << "stack1: ";
        while(!s1.isempty())
        {
            cout << s1.top() << " ";
            s1.pop();
        }
        cout << endl;
    }
    if(s2.isempty())
        cout << "stack2: empty" << endl;
    else
    {
        cout << "stack2: ";
        while(!s2.isempty())
        {
            cout << s2.top() << " ";
            s2.pop();
        }
        cout << endl;
    }
    if(s3.isempty())
        cout << "stack3: empty" << endl;
    else
    {
        cout << "stack3: ";
        while(!s3.isempty())
        {
            cout << s3.top() << " ";
            s3.pop();
        }
        cout << endl;
    }
}

//EOF



