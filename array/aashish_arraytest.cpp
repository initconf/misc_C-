//
//  arraytest.cpp
//  c++
//
//  Created by Aashish Sharma on 6/29/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#if 0
================================================================
Before : HELLO
After  : OLLEH

Before : even
After  : neve

Before : Pack my box with five dozen liquor jugs
After  : sguj rouqil nezod evif htiw xob ym kcaP



String : 1986   Result: 1986
String : 19a7   Result: 0
String : 19868978   Result: 19868978
String : abc   Result: 0



Before: (5): 5 2 9 3 7
Afer:   (5) :5 2 9 3 7

Before: (2): 2 2
Afer:   (1) :2

Before: (11): 58 26 91 26 70 70 91 58 58 58 66
Afer:   (5) :58 26 91 70 66


Program ended with exit code: 0

================================================================
#endif

#include "array.h"

void case_1()
{
    Array a;
    
    char b[] =  "HELLO";
    
    int num_elements ;
    
    num_elements = sizeof(b)/sizeof (char);
    
    //cout << "num elements are : " << num_elements << endl  ;
    
    cout << "Before : " << b << endl ;
    a.reverse (b);
    cout << "After  : " << b << endl ;
    
    cout << endl ;
    
    char c[]= "even";

    cout << "Before : " << c << endl ;
    a.reverse (c);
    cout << "After  : " << c << endl ;

    cout << endl ;
    
    char d[]= "Pack my box with five dozen liquor jugs";

    cout << "Before : " << d << endl ;
    a.reverse (d);
    cout << "After  : " << d << endl ;

    cout << endl ;
}

void case_2()
{
    
    const char* b[]= { "1986", "19a7", "19868978", "abc" };
    
    Array A;
    
    int num = sizeof(b)/sizeof(char*);
    
    for (int ct=0 ; ct < num; ct++)
    {
        cout << "String : " << b[ct] ;

        int result =  A.str_2_int(b[ct]);
        
      //  cout << "   Result: " << result << "                [ A.str_2_int(" << b[ct] << ")=" << result << endl ;
        
          cout << "   Result: " << result << endl ;
        
    }
}

void case_3_output(int c[], int num)
{
    
    Array A;

    cout << endl << "Before: (" << num << "): " ;
    
    for (int i = 0 ; i < num ; i++)
    {
        cout << c[i] << " "  ;
    }
    
    cout << endl ;
    
    int newsize= A.dedup(c, num);
    
    cout << "Afer:   (" << newsize << ") :"  ;
    
    for (int i = 0 ; i < newsize ; i++)
    {
        cout << c[i] << " "  ;
    }
    cout << endl ;

}

void case_3()
{

    int a[] = { 5,2,9,3,7 };
   
   int  num = sizeof(a)/sizeof (int);
    
   case_3_output(a, num);
    

    int b[] = { 2,2};

    num = sizeof(b)/sizeof (int);
    
    case_3_output(b, num);
    
    
    int c[] = { 58, 26, 91, 26, 70, 70, 91, 58, 58, 58, 66 } ;
    
    num = sizeof(c)/sizeof (int);
    
    case_3_output(c, num);
   

}

int main() {
    
    case_1();
    
    cout << endl ;
    cout << endl ;

    case_2();
    
    cout << endl ;
    cout << endl ;
    
    case_3() ;
    
    cout << endl ;
    cout << endl ;
    
    
    return 0;
}




