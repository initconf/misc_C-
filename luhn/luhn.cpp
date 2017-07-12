//
//  luhn.cpp
//  c++
//
//  Created by Aashish Sharma on 6/27/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "luhn.h"



bool luhn::check(long long l ){
    
    //cout << l << endl;
    int remainder=0;
    long long division=0;
    
    division=l ;
    
    int a[16];
    
    int i = 15 ;
    do
    {
        remainder=division%10;
        division=division/10;
        a[i] = remainder;
        i-- ;
        //cout << division << "  and remainder is " << remainder<< endl;
    }
    while(division!=0);
        
    for (int i =0 ; i < 16; i++)
    {
        //cout << "i is : " <<i << "  " << a[i] << endl ;
        
        if (i%2 == 0)
        {
            int _num = a[i]*2;
             if (_num > 10)
                 _num = _num -9 ;
            a[i]= _num ;
        
        }
        
    }
    
    int sum=0 ;
    
    for (int i =  0 ; i < 16 ;i++)
    {
        sum += a[i];
    }
    
    if (sum %10 == 0 )
        return true ;
    else
        return false ;
    

}
