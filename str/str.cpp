/*----------------------------------------------------------------
 Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
 file: str.cpp
 
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 This file has class definition
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 All includes here
 -----------------------------------------------------------------*/
#include "str.h"



/*----------------------------------------------------------------
 WRITE CODE HERE
 -----------------------------------------------------------------*/
static bool verbose = false;







///////////////// helper functions end ////////////////////////////


str::str():_string(0), _display(verbose)
{
    _display=false;
    
    
    _string.set_display(_display);
    _string[0] = '\0' ;
    
}

str::str(const char c, bool verbose):_string(c), _display(verbose)
{
    
    //  cout << "inside 1st constructor" << endl ;
    
    _display = verbose ;
    _string.set_display(_display);
    
    for (int i = 0; i < 1; i++)
    {
        _string[i] = c;
        
    }
    
    _string[1] = '\0';
    
    
}


str::str(const char* c, bool verbose):_string(c), _display(verbose)
{
    //  cout << "inside 2nd constructor" << endl ;
    _display = verbose ;
    
    _string.set_display(_display);
    
    int i = 0 ;
    
    while (*c != '\0')
    {
        _string[i] = *c;
        i++;
        c++;
    }
    
    
    _string[i] = '\0' ;
    
}

str::str (const int a, bool d):_string(a),_display(verbose)
{
    //  cout << "inside 3rd constructor" << endl ;
    _string.set_display(_display);
    
}


/// third constructor

str::str(const str& from)
{
    _display = from._display;
    
    _copy(from);
    
}


str::str(const str& from, bool verbose)
{
    _display = verbose;
    _string.set_display(_display);
    
    _copy(from);
    
}

void str::_copy(const str& from)
{
    int i = 0;
    
    
    while (from._string[i] != '\0')
    {
        _string[i] = from._string[i];
        i++;
    }
    
    _string[i] = '\0' ;
}



// print capability

// invalid operands to binary expression error
// gone away when used const str& s


ostream& operator<<(ostream& o, const str& s)
{
    
    
    
    int len = s._strlen(s);
    
    for (int i = 0 ; i < len ; ++i )
    {
        o << s._string[i] ;
    }
    
    
    return (o);
    
}


int str::_strlen(const str& c)
{
    int len = 0 ;
    
    while( c._string[len] != '\0')
    {
        len++;
    }
    
    return len;
    
    
}



str& str::reverse()  
{
    int len = _strlen(*this);
    
    for (int i = 0; i <len/2  ; i++)
    {
        char tmp = this->_string[i] ;
        this->_string[i] = this->_string[len-i-1] ;
        this->_string[len -i-1] = tmp ;
    }
    
    return *this;
}



//// operator overloadings


str& str::operator=(const str& from)
{
    _display = from._display ;
    
    _copy(from);
    
    return *this;
}


bool str::operator==(const str& from)
{
    int len1 = this->_strlen(*this);
    
    int len2 = from._strlen(from);
    
    if (len1 == len2)
    {
        for (int i  = 0 ; i < len1 ; ++i )
        {
            if (this->_string[i] != from._string[i])
                return false ;
        }
    }
    
    return true ;
    
}

bool str::operator!=(const str& from)
{
    return (! (*this == from));
}


/// string compare

int string_compare(const str& s1, const str& s2)
{
    
    int len1 = s1._strlen(s1);
    int len2 = s2._strlen(s2);
    
    int i = 0;
    
    if (len1 == len2)
    {
        for ( i  = 0 ; s1._string[i] && s2._string[i] ; ++i)
        {
            if (s1._string[i] == s2._string[i] )
                continue;
            else
                break ;
        }
        
        if (s1._string[i] == s1._string[i])
            return 0;
        else if (s1._string[i] > s1._string[i])
            return 1;
        else
            return -1 ;
    }
    else
        return -1 ;
}



// s3 = 'a' + s1;

str operator+( const int c, const str& s)
{
    
    str tmp(c, false);
    //    cout  << s._string << endl ;
    
    // cout << c << endl ;
    
    int len=s._strlen(s) ;
    
    int count = 1;
    
    for (int i = 0; i < len; ++i)
    {
        tmp._string[count+i] = s._string[i];
    }
    
    return tmp ;
    
}


str operator+( const str& s, const int c)
{
    
    str tmp(s) ;
    
    int len=s._strlen(s) ;
    
    tmp._string[len] = (char) c;
    
    tmp._string[len+1] = '\0';
    return tmp ;
    
}


str operator+(const str& s, const char *c)
{
    
    str tmp(s);
    
    int len=tmp._strlen(s);
    
    while(*c != '\0' )
    {
        tmp._string[len] = *c ;
        c++;
        len++;
    }
    tmp._string[len] = '\0' ;
    
    return tmp ;
    
}

str operator+(const char *c, const str& s)
{
    
    str tmp(*c, false);
    
    int len=s._strlen(s) ;
    
    int count = 1;
    
    for (int i = 0; i < len; ++i)
    {
        tmp._string[count+i] = s._string[i];
    }
    
    return tmp ;
    
}


////////

str operator+(const char c, const str& s)
{
    
    str tmp(c, false);
    
    int len=s._strlen(s) ;
    
    int count = 1;
    
    for (int i = 0; i < len; ++i)
    {
        tmp._string[count+i] = s._string[i];
    }
    
    return tmp ;
    
}

str operator+(const str& s, const char c)
{
    
    str tmp(s);
    
    int len=tmp._strlen(s);
    
    tmp._string[len] = c ;
    len++;
    
    tmp._string[len] = '\0' ;
    
    return tmp ;
}

///////////






str operator+(const str& s1, const str& s2)
{
    
    str tmp(s1, false);
    
    int len=s2._strlen(s2) ;
    
    int count = 1;
    
    for (int i = 0; i < len; ++i)
    {
        tmp._string[count+i] = s2._string[i];
    }
    
    return tmp ;
    
}


int str::get_size(const str& s)
{
    return s._strlen(s);
    
}

char str::get_string(int i ) const
{
    return _string[i] ;
}

char& str::operator[](const int i)
{
    
    return _string[i];
    
}

const char& str::operator[](int i) const
{
    return _string[i];
}

void str::set_display( str& s, bool d)
{
    s._string.set_display(d) ;
    
}

bool str::get_display(const str &s)
{
    return _string.display();
    
}


str& str::set_string(const char c, const int i ) 
{
    _string[i] = c;
    
    return *this ;
    
}