//
//  complex1.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "complex1.h"

char* complex1::itoa(int num, char * str, int base=10)
{
    
    int ti=0;
    char tmpary[100];
    
    int i = 0 ;
    bool negative = false ;
    
    if (num == 0)
    {
        str[0] = '0' ;
        str[1] = '\0' ;
        
        //cout <<  "Zero case "<< str << "IS Zero" << endl ;
        return str;
    }

    if (num < 0)
    {
        negative = true ;
        num = - num ;
    }
    
    int remainder = 0 ;
    
    do
    {
        
     //cout << "Num is " << num << endl ;
         remainder = num % base ;
       //cout << "remainder is " << remainder << endl ;

        
        num = (num- remainder) / base ;

        tmpary[ti]= '0'+ remainder ;
        ti++;
        
        //cout << "tmpary is " << tmpary ;
        
        
    }while (num > 0);
    
    tmpary[ti++] = '\0';
    
    i = 0 ;
    
    if (negative)
    {
        str[i] = '-' ;
        i++;
    }
    

    for ( int j=strlen(tmpary)- 1 ; j >= 0 ; j--)
    {
       // cout << "tmp ary is "<< tmpary[j] << endl ;
         str[i] = tmpary[j];
       // cout << "str  is "<< str[i] << endl ;
                i++;
    }
    
  str[i++] = '\0';
    
   // cout << "final tmp ary is "<< tmpary << endl ;
   // cout << "Final str  is "<< str << endl ;
    return str;
}



void complex1::_strcat(char* dst, char* src)
{
    int dlen = 0 ;
    
    while (*dst)
    {
        dst++;
        dlen++;
    }
    
    
    while (*src)
    {
        *dst=*src;
        src++;
        dst++;
        
    }
    
    *dst = '\0';
    
    
}


char* complex1::num2name(int r, int i)
{
    char* _name = new char[100];
    
   // cout << "I is "<< r <<" Imag is "<< i << endl ;
    char c_real[10] ;
    
    itoa (r, c_real);
    char c_imag[10] ;
    
    itoa (i, c_imag);
    
    
    
    strcpy(_name, c_real);
    
    if (c_imag[0] != '-')
    {
        strcat(_name, "+");
    }
    strcat(_name, c_imag);
    strcat(_name, "i");
   // cout << "NAME IS " << _name << endl ;

    return _name ;
    
}

void complex1::init()
{

    _real= 0 ;
    _imag = 0 ;
    _name =  num2name(_real, _imag);
}

void complex1::init(int real)
{
    _real = real ;
    _imag = 0;
    _name = num2name(_real, _imag);
    
    //strcpy(_name, _real, imag);
    
    
}


void complex1::init(int real, int imag)
{
    _real = real ;
    _imag = imag ;
    _name = num2name(_real, _imag);
    
}

void complex1::print() const
{
 
    cout << this->_name << endl  ;
    
}
void complex1::fini()
{
    //delete[] this->_name;
}
