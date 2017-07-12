//
//  iset64.h
//  c++
//
//  Created by Aashish Sharma on 8/28/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____iset64__
#define __c____iset64__

#include "../util/util.h"

#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif

// rotate by N
// unsigned int y = n ? (x << n) | (x >> (32 - n)) : x;

class iset64 {
    
public:
    
    iset64();
    iset64(const int [], int);
    
    ~iset64() ;
    
    
    //copy constructor
    iset64(const iset64&);
    
    // equal operator
    iset64& operator=(const iset64& rhs);

    // print
    friend ostream& operator<<(ostream &o, const iset64&);
    

    //iset64& operator+(int i );
    //iset64 operator+(iset64 &rhs);
    friend iset64 operator+(const iset64 &lhs, const int i );
    friend iset64 operator+(const int i,  const iset64 &rhs );
    friend iset64 operator+(const iset64 &lhs,  const  iset64 &rhs );
  
    
    friend iset64 operator-(const iset64 &lhs, const int i );
    friend iset64 operator-(const int i,  const iset64 &rhs );
    friend iset64 operator-(const iset64 &lhs,  const  iset64 &rhs );

    
    friend iset64 operator*(const iset64 &lhs, const iset64 &rhs);
    friend iset64 operator*(const int i, const iset64 &rhs);
    friend iset64 operator*(const iset64 &lhs, const int i);
    
    iset64& operator+=(int i );
    iset64& operator+=(const iset64 &rhs);
    
    
    iset64& operator-=(int i );
    iset64& operator-=(const iset64 &rhs);
    
    iset64& operator*=(int i );
    iset64& operator*=(const iset64 &lhs);
    friend iset64 operator*=(const iset64 &lhs, const iset64 &rhs);
    
//    iset64& operator-(int i );
//    iset64& operator-(iset64 &rhs);
//   
//    iset64& operator-=(int i );
//    iset64& operator-=(iset64 &rhs);
    
    
    
    friend bool operator==(const iset64& a, const iset64& b);
    
    friend bool operator!=(const iset64& a, const iset64& b);
    
    friend iset64& operator++(iset64& a);
    friend iset64& operator--(iset64& a);
    
    friend iset64 operator++(iset64& a, int i );
    friend iset64 operator--(iset64& a, int i );
    
    friend iset64 operator~(iset64 a);
    
    operator bool() const ;
    
protected:
    
    int *setmap;
    void _copy(const iset64& );
   
};


#endif /* defined(__c____iset64__) */


#if 0 

//    char *bitarray = new char[8]; // since 8*8 this array actually contains 64 bits
//
//    char getBit(int index) {
//        return (bitarray[index/8] >> 7-(index & 0x7)) & 0x1;
//    }
//
//    void setBit(int index, int value) {
//        bitarray[index/8] = bitarray[index/8] | (value & 0x1) << 7-(index & 0x7);
//    }


//std::bitset<64> setmap;
//
//int getValue(const bitset<64> s, int i);
//
//void setValue( bitset<64> s, int loc);




//int64_t setmap = 0 ;
//
//bool getBit(int index);
//int setBit( int index, bool b);
//
//
//bool iset64::getBit(int index)
//{
//    return ( (setmap & (1 << index) ) > 0);
//}
//
//int iset64::setBit( int index, bool b)
//{
//    
//    if(b)
//        return (setmap | (1 << index)) ;
//    else {
//        int mask = ~(1 << index);
//        return setmap & mask;
//    }
//}



#endif
