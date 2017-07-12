/*----------------------------------------------------------------
 Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
 file: str.h
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 This file has str class declaration
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 All includes here
 -----------------------------------------------------------------*/
#ifndef str_H
#define str_H

#include "../darray/darray.h"

/*----------------------------------------------------------------
 Declaration of str class
 -----------------------------------------------------------------*/
class str {
public:
    
    str( const char, bool d=true);
    str( const char*, bool d=true);
    str (const int, bool d=true);
    
    
    str();
    str(const str& from, bool verbose);

    str& operator=(const str&);  // equal operator
    str (const str&);  // copy constructor

    
    ~str(){ _remove() ;} // destructor
    
    friend ostream& operator<<(ostream& o, const str& s) ;
    
    
    
    
    static int _strlen(const str& c);
     str& reverse();
    
    
    
    bool operator==(const str&);
    bool operator!=(const str&);
    
    friend str operator+(const int, const str& );
    friend str operator+(const str&, const int);
    friend str operator+(const str&, const char*);
    friend str operator+(const char *c, const str& s);
    friend str operator+(const str&, const char c);
    friend str operator+(const char c, const str&);
    
    friend str operator+(const str& s1, const str& s2);
    
    char& operator[](const int i ) ;
    const char& operator[](int i) const ;
    

    //value_type& operator[](index_type idx);
    //const value_type& operator[](index_type idx) const;
    
    
    friend int string_compare(const str&, const str&);
    
    static int get_size(const str&) ;
    static void set_size(int) ;
    
    char get_string(int i ) const ;
    str& set_string(const char c, const int i)  ;
    str& set_string(int i, char c) = delete ;
    
    void set_display( str&, bool);
    bool get_display(const str & );
    
private:
    
    //    friend class ulongnum ;
    
    darray<char> _string ;
    bool _display ;
    
    
    void _remove()
    {
        // cout  << "inside destructor" << endl ;
    };
    
    
    void _copy(const str&);
    
    
};

#endif
//EOF

