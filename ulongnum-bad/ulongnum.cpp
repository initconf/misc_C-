/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"

/*----------------------------------------------------------------
Definition of routines of ulongnum class
WRITE YOUR CODE
-----------------------------------------------------------------*/
//static bool verbose = true;


void ulongnum::rev(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

// Implementation of itoa()
char* ulongnum::itoa(int num, char* str, int base=10)
{
    int i = 0;
    bool isNegative = false;
    
    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    
    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }
    
    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
    
    str[i] = '\0'; // Append string terminator

    
    // Reverse the string
    rev(str, i);
    
    return str;
}





/////////////////// helper functions /////////////////////

// constructors

ulongnum::ulongnum (int num, bool _display):_long(num)
{
    if(_display)
    {
        cout << "In ulongnum int num constructor" << endl ;
    }
    
    char *_blah = new char[10000];
    itoa(num, _blah, 10);
    
    cout << "_blah is " << _blah << endl ;

    str tmp(_blah, true);
    
    _long = tmp ;
    
};

ulongnum::ulongnum():_long(0)
{
    str tmp(0);
    _long = tmp ;
}


ulongnum::ulongnum(char *c, bool _display):_long(c),_display(_display)
{
    cout << "  in ulongnum constructor " << *c << endl ;
    
}

ulongnum::ulongnum(char c, bool _display):_long(c),_display(_display)
{
    cout << "  in ulongnum constructor 2  " << c << endl ;
    
}

/// print overloading <<

ostream& operator<<(ostream &o, const ulongnum& _data)
{
    
   o << _data._long << endl ;
    return (o);
}



///*----------------------------------------------------------------
// Helper: copy function
// -----------------------------------------------------------------*/
//void ulongnum::_copy(const ulongnum& from) {
//
//}
//
///*----------------------------------------------------------------
// Copy constructor
// -----------------------------------------------------------------*/
//ulongnum::ulongnum (const ulongnum& b)
//{
//    if (_display) {
//        cout << "In ulongnum copy Constructor " << b << endl;
//    }
//    _copy(b);
//}
//
///*----------------------------------------------------------------
// equal operator
// -----------------------------------------------------------------*/
//ulongnum& ulongnum::operator=(const ulongnum& rhs) {
//    if (rhs._display) {
//        cout << "In  ulongnum equal operator " << rhs._long << endl;
//    }
//    if (this != &rhs) {
//    //    _release();
//        _copy(rhs);
//    }
//    return *this;
//}







///////// [] overload

char ulongnum::get_string_i(const str& s, int i) const
{
    return   s.get_string(i);
}

const char ulongnum::operator[](int i) const
{
    return _long[i] ;
}


char& ulongnum::operator[](int i)
{
    return _long[i]  ;
}


ulongnum operator+(const ulongnum& s1, const ulongnum& s2)
{
    ulongnum result(0, true);

    
    cout << "S1 is : " << s1 << endl ;
    cout << "S2 is : " << s2 << endl ;

    int _sum_s1 = 0 ;
    int _sum_s2 = 0;
    int num = 0 ;
    int sum = 0 ;
    ulongnum num1 = s1;
    ulongnum num2 = s2 ;
    int result_counter = 0 ;

    int s1_counter = s1.get_size(num1) - 1;
    int s2_counter = s2.get_size(num2) - 1 ;
    int counter = s1_counter  ;
    
    if (s1_counter < s2_counter)
    {
        result  = s2 ;
        counter = s2_counter ;
    }
    
    num1.reverse();
    num2.reverse();
    

    cout << "Num 1 " << num1 << endl ;
    cout << "Num 2 " << num2 << endl ;
    
    
    for (int i = 0, carry = 0; i < (int) max(s1.get_size(num1), s2.get_size(num2)) || carry; ++i)
    {
    
        if (s1[i] != '\0')
        {
            _sum_s1 = s1[i] - '0' ;
        }
        else
            _sum_s1 = 0 ;
        
        if (s2[i] != '\0')
        {
            _sum_s2 = s2[i] - '0' ;
        }
        else
            _sum_s2 = 0 ;
        
        if (carry)
        {
            _sum_s1 += carry ;
            carry =  0 ;
        }
        
        sum = _sum_s1 + _sum_s2 ;
        
        if (sum > 10 )
            num = sum - 10 ;
        else
            num = sum ;
        
        carry = sum / 10 ;
        result[result_counter++] = num + '0' ;
        result[result_counter] = '\0';
//        ++result_counter ;
        
//        cout << result << endl ;
        
        cout << "s1[" << i << "] " << s1[i] << " s2[" << i <<"] " << s2[i] << " sum : " << sum << " num: " << num << " carry: " << carry << "result " << result << "  " << result.reverse() <<  endl ;

//        cout << "s1[" << i << "] " << s1[i] << " s2[" << i <<"] " << s2[i] << " sum : " << sum << " num: " << num << " carry: " << carry << endl ;
    
        
        
    }
    
    cout << "result is now " << result ;
    
    return result;
    
    
}

int ulongnum::get_size(const ulongnum s1) const
{
    return s1._long.get_size(s1._long);
    
}

ulongnum ulongnum::reverse()
{
    
     _long = _long.reverse() ;
    
    return *this ;
}
