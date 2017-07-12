/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ulongnum.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ulongnum class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ulongnum_H
#define ulongnum_H

#include "../str/str.h"

/*--------------------------------------------------------
class ulongnum
----------------------------------------------------------*/
class ulongnum {
public:

    ulongnum (int num, bool _display=true);
    ulongnum (char *, bool _display=true);
    ulongnum (char , bool _display=true);
    ulongnum (const str&);
    ulongnum ();
    
//    ulongnum& operator=(const ulongnum&); // equal operator
//    ulongnum (const ulongnum& ) ;// copy constructor

    
    
    friend ostream& operator<<(ostream &o, const ulongnum&);
    friend ulongnum operator+(const ulongnum& s1, const ulongnum& s2);
    
    const char operator[]( int i ) const ;
    char& operator[](int i);
    
    int get_size(const ulongnum s1) const;
    
    char get_string_i( const str&, int i) const ;

    ulongnum reverse()  ;
    
private:
    
    bool _display ;
    str _long;
    
    char* itoa(int num, char* str, int base);
    void rev(char str[], int length);
    void _copy(const ulongnum& );
    
};

#endif
//EOF

