
//
//  iset64.cpp
//  c++
//
//  Created by Aashish Sharma on 8/28/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "iset64.h"


/////// constructor
iset64::iset64():setmap(0)
{
    setmap = new int[64];
    
    for (int i = 0 ; i < 64 ; ++i)
    {
        setmap[i] = 0;
    }
}

/////// constructor with parameters
iset64::iset64(const int a[], int num)
{
    setmap = new int[64];
    
    for (int i = 0 ; i < 64 ; ++i)
    {
        setmap[i] = 0;
    }
    
    for (int i = 0 ; i < num; ++i)
    {
        setmap[a[i]] = 1 ;
    }
}

//// destructor
iset64::~iset64()
{
    delete [] setmap;
}

////    copy consturctor
iset64::iset64(const iset64& rhs)
{
    setmap = new int[64] ;
    iset64::_copy(rhs);
}

//// helper function for copy constructor
void iset64::_copy(const iset64& rhs)
{
 ////    cout << "copy function " << endl ;
    
    for (int i = 0 ; i < 64; ++i)
    {
       setmap[i] = rhs.setmap[i];
    }
}

//// equal operator
iset64& iset64::operator=(const iset64& rhs)
{
   if (this != &rhs)
       iset64::_copy(rhs);
   
    return *this;
}


ostream& operator<<(ostream &o, const iset64& a)
{
    o << " { " ;
    for (int i = 0 ; i < 64 ; ++i)
    {
        if (a.setmap[i] == 1)
        {
            o << i << " " ;
        }
    }
    o << "}" ;
    return o ;
}

////////// additions to the sets

iset64 operator+( const iset64 &lhs, const int index )
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ;++i)
    {
        tmp.setmap[i] = lhs.setmap[i];
    }
    
    tmp.setmap[index] = 1;
    return tmp;
}

iset64 operator+(const int index, const iset64 &rhs )
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ;++i)
    {
        tmp.setmap[i] = rhs.setmap[i];
    }
    
    tmp.setmap[index] = 1 ;
    return tmp ;
}


iset64 operator+(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ; i++)
    {
        if (lhs.setmap[i] ==1 || rhs.setmap[i] == 1)
            tmp.setmap[i] = 1;
    }
    
    return tmp ;
}

iset64& iset64::operator+=(int i)
{
    setmap[i] = 1;
    return *this;
}

iset64& iset64::operator+=(const iset64 &rhs)
{
    for (int i = 1 ; i < 64 ; i++)
    {
        if (rhs.setmap[i] == 1)
                setmap[i] = 1;
    }
    return *this ;
}

////////// substraction
iset64 operator-( const iset64 &lhs, const int index )
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ;++i)
    {
        tmp.setmap[i] = lhs.setmap[i];
    }
    
    tmp.setmap[index] = 0;
    return tmp;
}

iset64 operator-(const int index, const iset64 &rhs )
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ;++i)
    {
        tmp.setmap[i] = rhs.setmap[i];
    }
    
    tmp.setmap[index] = 0 ;
    
    return tmp ;
}


iset64 operator-(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    
    for (int i = 1 ; i < 64 ; i++)
    {
        tmp.setmap[i] = lhs.setmap[i];
        
        if (lhs.setmap[i] ==1 && rhs.setmap[i] == 1)
            tmp.setmap[i] = 0;
    }
    
    return tmp ;
}

/// -= ////

iset64& iset64::operator-=(const int i)
{
    setmap[i] = 0;
    return *this;
}

iset64& iset64::operator-=(const iset64 &rhs)
{
    for (int i = 1 ; i < 64 ; i++)
    {
        if (rhs.setmap[i] == 1)
            setmap[i] = 0;
    }
    
    return *this ;
}


/////// intersection * operator //////////

iset64 operator*(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp;
    
    for (int i = 0 ; i < 64 ; ++i )
    {
        if (lhs.setmap[i] == 1 && rhs.setmap[i] == 1)
        {
            tmp.setmap[i] = 1;
        }
    }
    
    return tmp;
}

iset64 operator*(const int i, const iset64 &rhs)
{
    iset64 tmp;
    
    for (int i = 0 ; i < 64 ; ++i )
    {
        tmp.setmap[i] = 0;
    }
    
    if (rhs.setmap[i] == 1)
    {
        tmp.setmap[i] = 1;
    }
    
    return tmp;
}



iset64 operator*(const iset64 &lhs, const int i)
{
    iset64 tmp;
    
    for (int i = 0 ; i < 64 ; ++i )
    {
        tmp.setmap[i] = 0;
    }
    
    if (lhs.setmap[i] ==1 )
    {
            tmp.setmap[i] = 1;
    }
    
    return tmp;
    
}


iset64& iset64::operator*=(int i)
{
    
    for (int j = 0 ; j < 64 ; ++j)
    {
        if (i == j && setmap[i] == 1  )
        {
           setmap[j] = 1;
        }
        else
           setmap[j] = 0;
    }
        return *this;
}

iset64& iset64::operator*=(const iset64& rhs)
{
    for (int j = 0 ; j < 64 ; ++j)
    {
        if (setmap[j] == rhs.setmap[j] )
        {
            setmap[j] = 1;
        }
        else
            setmap[j] = 0;
    }
    return *this;
}


iset64 operator*=(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ; ++i)
    {
       if (lhs.setmap[i] == 1 && rhs.setmap[i] == 1)
            tmp.setmap[i] = 0;
    }
    
    return tmp ;
}


///////// == and !=

bool operator==(const iset64& a, const iset64& b)
{
    for (int i = 0 ; i < 64; ++i )
    {
        if (a.setmap[i] != b.setmap[i])
            return false ;
    }
    return true ;
}


bool operator!=(const iset64& a, const iset64& b)
{
    return ! (a == b) ;
}

//////// pre increment -decrement

iset64& operator++(iset64& a)
{
    bool edge = false ;
    
    if (a.setmap[63] == 1)
        edge = true ;

    for (int i = 62 ; i >=0 ; --i)
    {
        a.setmap[i+1] = a.setmap[i];
    }
    
    if(edge)
        a.setmap[0] = 1;
    
    return a;
}

iset64& operator--(iset64& a)
{
    bool edge = false ;
    
    if (a.setmap[0] == 1)
        edge = true ;
    
    for (int i = 1 ; i < 64 ; ++i)
    {
            a.setmap[i-1] = a.setmap[i];
    }
    
    if(edge)
        a.setmap[63] = 1;
    
    return a;
}


iset64 operator++(iset64& a, int m)
{
    iset64 tmp = a ;
    bool edge = false ;
    
    if (a.setmap[63] == 1)
        edge = true ;
    
    for (int i = 62 ; i >=0 ; --i)
    {
        a.setmap[i+1] = a.setmap[i];
    }
    
    if(edge)
        a.setmap[0] = 1;
    return tmp;
}

iset64 operator--(iset64& a, int m)
{
    iset64 tmp = a;
    bool edge = false ;
    
    if (a.setmap[0] == 1)
        edge = true ;
    
    for (int i = 1 ; i < 64 ; ++i)
    {
        a.setmap[i-1] = a.setmap[i];
    }
    
    if(edge)
        a.setmap[63] = 1;
    return tmp;
}

///////// compliment operator

iset64 operator~(iset64 a)
{
    iset64 tmp ;
    
    for (int i = 0 ; i < 64 ; ++i )
    {
        tmp.setmap[i] = 1;
        
        if (a.setmap[i] == 1)
            tmp.setmap[i] = 0;
    }
    return tmp  ;
}


//// conversion operator bool ////////

iset64::operator bool() const
{
    for (int i = 0 ; i < 64 ; i++)
    {
        if (setmap[i] == 1)
            return true;
        
    }
    return false ;
}


