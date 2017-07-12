//
//  iset2.cpp
//  c++
//
//  Created by Aashish Sharma on 8/31/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "iset2.h"

iset::iset()
{
    _set = 0 ;
    
 //   cout << "constructor 1" << endl ;
   
}

iset::iset(const int ary[], int range)
{
    _set = 0 ;
    
  //  cout << "constructor 2" << endl ;
    
    for (int i = 0 ; i < range; ++i)
    {
        setBit(ary[i]);
        
    }
      
}



//////////////////

////    copy consturctor
iset::iset(const iset& rhs)
{
  //  cout << " copy consturctor" << endl ;
    
    _set = 0;
    iset::_copy(rhs);
}

//// helper function for copy constructor
void iset::_copy(const iset& rhs)
{
   // cout << "copy function " << endl ;
    _set = rhs._set;
}

//// equal operator
iset& iset::operator=(const iset& rhs)
{

  //  cout << " = operator " << endl ;
    
    if (this != &rhs)
        iset::_copy(rhs);
    
    return *this;
}

iset& iset::operator[](const int index)
{
    
  //  cout << " operator [] " << endl ;
    
     _mask = 0x01 ;
    
    _mask = _mask  << index  ;
    
   _set = _set & _mask;
    
    return *this  ;
}


ostream& operator<<(ostream &o,  iset& a)
{
    o << " { " ;
    for (int i = 0 ; i < 64 ; ++i)
    {
        if(a.getBit(i))
        {
            o << i << " " ;
        }
    }
    o << "}" ;
    return o ;
}


//////////////////////////////


iset::~iset()
{

}

/////////////// additions ////////

iset operator+( const iset &lhs, const int index )
{
    iset tmp ;
    
    tmp._set = lhs._set ;
    
    tmp.setBit(index);
    
    return tmp;
}

iset operator+(const int index, const iset &rhs )
{
    iset tmp ;
    
    tmp._set = rhs._set ;
    
     tmp.setBit(index);
    return tmp ;
}


iset operator+(const iset &lhs, const iset &rhs)
{
    iset tmp ;
    tmp._set = lhs._set | rhs._set ;
    return tmp ;
}

iset& iset::operator+=(int i)
{
    setBit(i);
    return *this;
}

iset& iset::operator+=(const iset &rhs)
{
    _set = _set | rhs._set ;
    return *this ;
}


////////// substraction

iset operator-( const iset &lhs, const int index )
{
    iset tmp ;
    
    tmp._set = lhs._set ;
    
    tmp.unsetBit(index);
    
    return tmp;
}

iset operator-(const int index, const iset &rhs )
{
    iset tmp ;
    
    tmp._set = rhs._set ;
    
    tmp.unsetBit(index);
    return tmp ;
}


iset operator-(const iset &lhs, const iset &rhs)
{
    iset tmp ;
    tmp._set = lhs._set & ~rhs._set ;
    return tmp ;
}

iset& iset::operator-=(int i)
{
    unsetBit(i);
    return *this;
}

iset& iset::operator-=(const iset &rhs)
{
    _set = _set & ~rhs._set ;
    return *this ;
}

/////// intersection * operator //////////

iset operator*(const iset &lhs, const iset &rhs)
{
    iset tmp;
    tmp._set = lhs._set & rhs._set ;
    return tmp;
}

iset operator*(const int i, const iset &rhs)
{
    iset tmp;
    
    tmp.setBit(i) ;
    tmp._set = tmp._set & rhs._set ;
   
    return tmp;
}



iset operator*(const iset &lhs, const int i)
{
    iset tmp;
    
    tmp.setBit(i) ;
    tmp._set = tmp._set & lhs._set ;
    
    return tmp;
}


iset& iset::operator*=(int i)
{
    setBit(i);
    return *this;
}

iset& iset::operator*=(const iset& rhs)
{
    _set = _set & rhs._set ;
    return *this;
}


iset operator*=(const iset &lhs, const iset &rhs)
{
    iset tmp ;
    tmp._set = lhs._set & rhs._set ;
    return tmp ;
}

///////// == and !=

bool operator==(const iset& a, const iset& b)
{
    
    if (a._set == b._set)
        return true ;
    
    return false ;

}


bool operator!=(const iset& a, const iset& b)
{
    return ! (a == b) ;
}

//////// pre increment -decrement

iset& operator++(iset& a)
{
    bool edge = false ;
    
    if (a.getBit(63) == 1 )
        edge = true ;
    
    a._set = a._set << 1 ;
    
    if(edge)
        a.setBit(0);
    return a;
}

iset& operator--(iset& a)
{
    bool edge = false ;
    
    if (a.getBit(0) == 1)
        edge = true ;
    
    a._set = a._set >> 1 ;

    if(edge)
        a.setBit(63);
    
    return a;
}


iset operator++(iset& a, int m)
{
    iset tmp = a ;
    bool edge = false ;
    
    if (a.getBit(63) == 1 )
        edge = true ;
    
    a._set = a._set << 1 ;
    
    if(edge)
        a.setBit(0);


    return tmp;
}

iset operator--(iset& a, int m)
{
    iset tmp = a;
    bool edge = false ;
    
    if (a.getBit(0) == 1)
        edge = true ;
    
    a._set = a._set >> 1 ;
    
    if(edge)
        a.setBit(63);
    
    return tmp;
}

///////// compliment operator

iset operator~(iset a)
{
    iset tmp ;
    
    tmp._set = ~tmp._set ;
    
    tmp._set = tmp._set & ~a._set;
    
    return tmp  ;
}


//// conversion operator bool ////////

iset::operator bool() const
{
        if (_set > 0 )
            return true;
    return false ;
}

