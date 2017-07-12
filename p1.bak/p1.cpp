//
//  p1.cpp
//  c++
//
//  Created by Aashish Sharma on 6/22/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "p1.h"

// private function to calculate power
// since pow function cannot be used without math.h

int p1::a_pow_b(int a, int b) {
    
    int result=1;
    
    for (int ct=1; ct <= b; ct++)
    {
        result = result*a;
        
    }
    
    
    return result ;
}

void p1::a_power_b() {

    int a =0;
    int b = 0 ;
    int counter=8 ;
    int result=0;

    std::cout << endl ;
    std::cout << "===============a^b table ===============" << endl ;
    
    std::cout << "a      b           a^b" << endl ;
    
    for (counter=1 ; counter < 8; counter++)
    {
        a = counter ;
        b = a+1 ;
     
        result=1;
        
        result = a_pow_b(a,b);
        
        std::cout << a <<"      "<< b <<"   "<<"        "<< result << endl ;
    }
    
}




void p1::print_n_n2_n3() {
    
    std::cout << endl ;
    
    std::cout << "===============n n^2 n^3 table ===============" << endl ;
    int start=1;
    int end =10 ;
    
    std::cout << "n             n^2             n^3" << endl ;
    
    for (int count= start; count <= end ; count ++)
    {
        
        int n2 = a_pow_b(count,2);
        int n3 = a_pow_b(count,3);
        
        std::cout << count << "              "<< n2 <<"              "<< n3 <<endl ;
        
        
    }

    
}

void p1::two_power_n() {
    
    
    std::cout << endl ;
    std::cout << "===============2 2^n table ===============" << endl ;
    
    int start=1;
    int end =20 ;

        std::cout << "n             2^n" << endl ;
    
    for (int count= start; count <= end ; count ++)
    {
        
        int result = a_pow_b(2,count);
        
        std::cout  << count <<" "<< result << endl ;

        
    }
    
}


void p1::a1(){
    
    std::cout << endl ;
    std::cout << "===============a1 ===============" << endl ;

    std::cout << endl ;
    
    int a1=6;
 
    for (int out = 1; out <= a1; out++)
    {
        for (int in=1; in <= out; in ++)
        {
            std::cout << in << '\t'  ;
        }
        
        std::cout << endl ;
    }
}

void p1::a2(){
    

    std::cout << endl ;
    std::cout << "===============a2 ===============" << endl ;
    
    int a1=6;
    
    for (int out = 1; out <= a1; out++)
    {
        for (int in=a1; in > out; in--)
        {
            std::cout << '\t';
        }
        
        for (int num=out; num >=1; num--)
        {
            std::cout << num << '\t'  ;
        }
   
        std::cout << endl ;
    }
}


void p1::a3(){
    


    std::cout << endl ;
    std::cout << "===============a3 ===============" << endl ;

    
        int a1=6;
        
        for (int out = a1; out >= 1; out--)
        {
            for (int in=1; in <= out; in ++)
            {
                std::cout << in << '\t'  ;
            }
            
            std::cout << endl ;
        }
}


void p1::a4(){
    
    std::cout << endl ;
    std::cout << "===============a4 ===============" << endl ;

    
    int a1=6;
    
    for (int out = a1; out >= 1; out--)
    {
        for (int in=a1; in > out; in--)
        {
            std::cout << '\t';
        }
        
        for (int num=1; num <=out; num++)
        {
            std::cout << num << '\t'  ;
        }
        
        std::cout << endl ;
    }
}


void p1::print_usa(){
    
std:cout <<" this is an expmple of print_usa function" << endl ;
    
    
    std::cout << "xxx       x      xxxx x       xxx"      << endl ;
    std::cout << " x        x     x     xx       x"       << endl ;
    std::cout << " x        x     x             x x"      << endl ;
    std::cout << " x        x     x            x   x"     << endl ;
    std::cout << " x        x     x           x      x"   << endl ;
    std::cout << " x        x     x           x      x"   << endl ;
    std::cout << " x        x       xxx       xxxxxxxx"   << endl ;
    std::cout << " x        x           xx   x        x"  << endl ;
    std::cout << " x        x             x  x        x"  << endl ;
    std::cout << " x        x             x  x        x"  << endl ;
    std::cout << " xx      xx     xx      x  x        x"  << endl ;
    std::cout << " xxxxxxxxx      xx xxxxx  xxx      xxx" << endl ;
    
    
    
}

