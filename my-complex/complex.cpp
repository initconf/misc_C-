//
//  complex.cpp
//  c++
//
//  Created by Aashish Sharma on 9/24/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "complex.h"


//
//  complex.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "complex.h"

char* complex::itoa(int num, char * str, int base=10)
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



void complex::_strcat(char* dst, char* src)
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


char* complex::num2name(int r, int i, char * _name)
{
    //char* _name = new char[100];
    
    // cout << "I is "<< r <<" Imag is "<< i << endl ;
    char c_real[20] ;
    
    itoa (r, c_real);
    char c_imag[20] ;
    
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

complex::complex()
{
    
    _real= 0 ;
    _imag = 0 ;
    char* _n = new char[100];
    _name =  num2name(_real, _imag, _n);
}

complex::complex(int real)
{
    _real = real ;
    _imag = 0;
    char* _n = new char[100];
    _name = num2name(_real, _imag, _n);
    
    //strcpy(_name, _real, imag);
    
    
}


complex::complex(int real, int imag)
{
    _real = real ;
    _imag = imag ;
    char* _n = new char[100];
    _name = num2name(_real, _imag, _n);
    
}

void complex::print() const
{
    
    cout << this->_name << endl  ;
    
}
complex::~complex()
{
   // cout << "inside the destructor" << endl ;
    _release();
    
}



// print

std::ostream& operator<<(ostream& out, complex &a)
{
    
    if (a._imag >=0 )
    {
        cout << a._real << "+" << a._imag << "i" << " [" << a._name << "]" << endl ;
    }
    else
        cout << a._real << "" << a._imag << "i" << " [" << a._name << "]" << endl ;
        

    
    return out ;
}

// equal overloading

bool complex::operator==(const complex sec)
{
    if (_real == sec._real && _imag == sec._imag)
        return true ;
    else
        return false ;
    
}


bool complex::operator!=(const complex sec)
{
    if (_real == sec._real && _imag == sec._imag)
        return false ;
    else
        return true ;
}

complex complex::setxy(int r, int i)
{

    this->_real = r;
    this->_imag = i ;
    char* _n = new char[100] ;
    _release();
    this->_name =num2name(r,i, _n) ;
    return *this  ;
    
}


// equal operator and copy constructor

void complex::_copy(const complex& rhs)
{
    
   
    
    _real = rhs._real;
    _imag = rhs._imag;
    
    char* _n = new char[100] ;
    _name =  num2name(_real, _imag,_n);
    
}

complex::complex (const complex& rhs)
{
   //  cout << "Copy constructor" << endl ;
    _copy(rhs);
    
}

complex& complex::operator=(const complex& rhs)
{
    
    if (*this != rhs)
    {
        _copy(rhs);
      // _release();
    }
    
    return *this;
}


void complex::_release()
{
  //  delete [] _name ;
    
}