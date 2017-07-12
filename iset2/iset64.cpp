//
//  iset642.cpp
//  c++
//
//  Created by Aashish Sharma on 8/31/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "iset64.h"

iset64::iset64()
{
    _set = 0 ;
    
 //   cout << "constructor 1" << endl ;
   
}

iset64::iset64(const int ary[], int range)
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
iset64::iset64(const iset64& rhs)
{
  //  cout << " copy consturctor" << endl ;
    
    _set = 0;
    iset64::_copy(rhs);
}

//// helper function for copy constructor
void iset64::_copy(const iset64& rhs)
{
   // cout << "copy function " << endl ;
    _set = rhs._set;
}

//// equal operator
iset64& iset64::operator=(const iset64& rhs)
{

  //  cout << " = operator " << endl ;
    
    if (this != &rhs)
        iset64::_copy(rhs);
    
    return *this;
}


iset64& iset64::operator=(int i)
{
    
    _mask = 0x01 ;
    
    _mask = _mask << i ;
    
    _set = _set | _mask ;
        
    return *this;

}

 bool iset64::operator[](const int index)
{
 
    _mask = 0x01 ;
    
    _mask = _mask  << index  ;
    
    bool result = _set & _mask;
    
    return result ;

    
}


//const uint64_t& iset64::operator[](const int index) const
//{
//    
//  uint64_t _mask = 0x01 ;
//    
//    _mask = _mask  << index  ;
//    
//    uint64_t result = _set & _mask;
//    
//    return result ;
//
//    
//}


ostream& operator<<(ostream &o,  iset64& a)
{
    o << " { " ;
    for (int i = 0 ; i < 64 ; ++i)
    {
        if(a.getBit(i))
  //    if(a[i])
        {
            o << i << " " ;
        }
    }
    o << "}" ;
    return o ;
}


//////////////////////////////


iset64::~iset64()
{

}

/////////////// additions ////////

iset64 operator+( const iset64 &lhs, const int index )
{
    iset64 tmp ;
    
    tmp._set = lhs._set ;
    
    tmp.setBit(index);
    
    return tmp;
}

iset64 operator+(const int index, const iset64 &rhs )
{
    iset64 tmp ;
    
    tmp._set = rhs._set ;
    
     tmp.setBit(index);
    return tmp ;
}


iset64 operator+(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    tmp._set = lhs._set | rhs._set ;
    return tmp ;
}

iset64& iset64::operator+=(int i)
{
    setBit(i);
    return *this;
}

iset64& iset64::operator+=(const iset64 &rhs)
{
    _set = _set | rhs._set ;
    return *this ;
}


////////// substraction

iset64 operator-( const iset64 &lhs, const int index )
{
    iset64 tmp ;
    
    tmp._set = lhs._set ;
    
    tmp.unsetBit(index);
    
    return tmp;
}

iset64 operator-(const int index, const iset64 &rhs )
{
    iset64 tmp ;
    
    tmp._set = rhs._set ;
    
    tmp.unsetBit(index);
    return tmp ;
}


iset64 operator-(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    tmp._set = lhs._set & ~rhs._set ;
    return tmp ;
}

iset64& iset64::operator-=(int i)
{
    unsetBit(i);
    return *this;
}

iset64& iset64::operator-=(const iset64 &rhs)
{
    _set = _set & ~rhs._set ;
    return *this ;
}

/////// intersection * operator //////////

iset64 operator*(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp;
    tmp._set = lhs._set & rhs._set ;
    return tmp;
}

iset64 operator*(const int i, const iset64 &rhs)
{
    iset64 tmp;
    
    tmp.setBit(i) ;
    tmp._set = tmp._set & rhs._set ;
   
    return tmp;
}



iset64 operator*(const iset64 &lhs, const int i)
{
    iset64 tmp;
    
    tmp.setBit(i) ;
    tmp._set = tmp._set & lhs._set ;
    
    return tmp;
}


iset64& iset64::operator*=(int i)
{
    setBit(i);
    return *this;
}

iset64& iset64::operator*=(const iset64& rhs)
{
    _set = _set & rhs._set ;
    return *this;
}


iset64 operator*=(const iset64 &lhs, const iset64 &rhs)
{
    iset64 tmp ;
    tmp._set = lhs._set & rhs._set ;
    return tmp ;
}

///////// == and !=

bool operator==(const iset64& a, const iset64& b)
{
    
    if (a._set == b._set)
        return true ;
    
    return false ;

}


bool operator!=(const iset64& a, const iset64& b)
{
    return ! (a == b) ;
}

//////// pre increment -decrement

iset64& operator++(iset64& a)
{
    bool edge = false ;
    
 if (a.getBit(63) == 1 )
        edge = true ;
    
    a._set = a._set << 1 ;
    
    if(edge)
        a.setBit(0);
    return a;
}

iset64& operator--(iset64& a)
{
    bool edge = false ;
    
    if (a.getBit(0) == 1)
        edge = true ;
    
    a._set = a._set >> 1 ;

    if(edge)
        a.setBit(63);
    
    return a;
}


iset64 operator++(iset64& a, int m)
{
    iset64 tmp = a ;
    bool edge = false ;
    
    if (a.getBit(63) == 1 )
        edge = true ;
    
    a._set = a._set << 1 ;
    
    if(edge)
        a.setBit(0);


    return tmp;
}

iset64 operator--(iset64& a, int m)
{
    iset64 tmp = a;
    bool edge = false ;
    
    if (a.getBit(0) == 1)
        edge = true ;
    
    a._set = a._set >> 1 ;
    
    if(edge)
        a.setBit(63);
    
    return tmp;
}

///////// compliment operator

iset64 operator~(iset64 a)
{
    iset64 tmp ;
    
    tmp._set = ~tmp._set ;
    
    tmp._set = tmp._set & ~a._set;
    
    return tmp  ;
}


//// conversion operator bool ////////

iset64::operator bool() const
{
        if (_set > 0 )
            return true;
    return false ;
}

iset64::operator uint64_t() const
{
    return 1;
}

