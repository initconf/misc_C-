//
//  iset642.h
//  c++
//
//  Created by Aashish Sharma on 8/31/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//


// Intersection is a binary AND (x & y)
// Union is a binary OR (x | y)
// Set difference is a binary AND NOT (x & ~y)
// Symmetric set difference is a binary XOR (x ^ y)


#ifndef __c____iset642__
#define __c____iset642__

#include "../util/util.h"


#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif

class iset64 {
  
public:
    iset64();
    iset64(const int [], int );
    ~iset64();
    
    iset64(const iset64& rhs);
    iset64& operator=(const iset64& rhs);
    iset64& operator=(int i);
   
    bool operator[] (const int index );
   
   
    friend ostream& operator<<(ostream &o,  iset64& a);
    
    
    friend iset64 operator+(const iset64 &lhs, const int index );
    friend iset64 operator+(const int index, const iset64 &rhs );
    friend  iset64 operator+(const iset64 &lhs, const iset64 &rhs);
    iset64& operator+=(int i);
    iset64& operator+=(const iset64 &rhs);
    
    friend iset64 operator-( const iset64 &lhs, const int index );
    friend iset64 operator-(const int index, const iset64 &rhs );
    friend iset64 operator-(const iset64 &lhs, const iset64 &rhs);
    iset64& operator-=(const int i);
    iset64& operator-=(const iset64 &rhs);

    
    
    friend iset64  operator*(const iset64 &lhs, const iset64 &rhs);
    friend iset64  operator*(const int i, const iset64 &rhs);
    friend iset64  operator*(const iset64 &lhs, const int i);
    
    iset64& operator*=(int i);
    iset64& operator*=(const iset64& rhs);
    friend iset64  operator*=(const iset64 &lhs, const iset64 &rhs);
    
    
    
    friend bool operator==(const iset64& a, const iset64& b);
    friend bool operator!=(const iset64& a, const iset64& b);
    friend iset64& operator++(iset64& a);
    friend iset64& operator--(iset64& a);
    friend iset64 operator++(iset64& a, int m);
    friend iset64 operator--(iset64& a, int m);
   
    friend iset64 operator~(iset64 a);
   
    operator bool() const;
    operator uint64_t() const;
    
    
protected:
    uint64_t _set ;
    uint64_t _mask ;
    
    void _copy(const iset64& rhs);
    
    
    void setBit(int index)
    {
         _mask = 0x01 ;
        _mask = _mask << index ;
        
        _set = _set | _mask ;
    }

    bool getBit(int index)
    {
         _mask = 0x01 ;
        
        _mask = _mask  << index  ;
        
        bool result = _set & _mask;
        
        return result ;
    }
    
    void unsetBit(int index)
    {
        _mask = 0x01 ;
        _mask = _mask << index ;
        
        _set = _set & ~_mask ;
    }

    
};



#endif /* defined(__c____iset642__) */
