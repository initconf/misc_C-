//
//  iset2.h
//  c++
//
//  Created by Aashish Sharma on 8/31/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//


// Intersection is a binary AND (x & y)
// Union is a binary OR (x | y)
// Set difference is a binary AND NOT (x & ~y)
// Symmetric set difference is a binary XOR (x ^ y)


#ifndef __c____iset2__
#define __c____iset2__

#include "../util/util.h"


#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif

class iset {
  
public:
    iset();
    iset(const int [], int );
    ~iset();
    
    iset(const iset& rhs);
    iset& operator=(const iset& rhs);
    iset& operator[] (const int index );
   
    friend ostream& operator<<(ostream &o,  iset& a);
    
    
    friend iset operator+(const iset &lhs, const int index );
    friend iset operator+(const int index, const iset &rhs );
    friend  iset operator+(const iset &lhs, const iset &rhs);
    iset& operator+=(int i);
    iset& operator+=(const iset &rhs);
    
    friend iset operator-( const iset &lhs, const int index );
    friend iset operator-(const int index, const iset &rhs );
    friend iset operator-(const iset &lhs, const iset &rhs);
    iset& operator-=(const int i);
    iset& operator-=(const iset &rhs);

    
    
    friend iset  operator*(const iset &lhs, const iset &rhs);
    friend iset  operator*(const int i, const iset &rhs);
    friend iset  operator*(const iset &lhs, const int i);
    
    iset& operator*=(int i);
    iset& operator*=(const iset& rhs);
    friend iset  operator*=(const iset &lhs, const iset &rhs);
    
    
    
    friend bool operator==(const iset& a, const iset& b);
    friend bool operator!=(const iset& a, const iset& b);
    friend iset& operator++(iset& a);
    friend iset& operator--(iset& a);
    friend iset operator++(iset& a, int m);
    friend iset operator--(iset& a, int m);
   
    friend iset operator~(iset a);
   
    operator bool() const;
    
    
protected:
    uint64_t _set ;
    uint64_t _mask ;
    
    void _copy(const iset& rhs);
    
    
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



#endif /* defined(__c____iset2__) */
