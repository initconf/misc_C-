/*----------------------------------------------------------------
 Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
 file: luhntest.cpp
 
 On linux:
 g++ luhn.cpp luhntest.cpp
 valgrind a.out
 
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 This file test luhn object
 -----------------------------------------------------------------*/

/*----------------------------------------------------------------
 All includes here
 -----------------------------------------------------------------*/
#include "luhn.h"

/*----------------------------------------------------------------
 https://www.paypalobjects.com/en_US/vhelp/paypalmanager_help/credit_card_numbers.htm
 -----------------------------------------------------------------*/
void test1() {
    static const long long list[] = { 378282246310005, 371449635398431, 378734493671000, 5610591081018250, 30569309025904, 38520000023237, 6011111111111117, 6011000990139424, 3530111333300000, 5105105105105100, 4111111111111111, 4012888888881881 };
    int s = sizeof(list) / sizeof(long long);
    for (int i = 0; i < s; ++i) {
        luhn a;
        assert(a.check(list[i]));
    }
}

void ash_test1() {
    static const long long list[] = { 378282246310005, 371449635398431, 378734493671000, 5610591081018250, 30569309025904, 38520000023237, 6011111111111117, 6011000990139424, 3530111333300000, 5105105105105100, 4111111111111111, 4012888888881881 };
    int s = sizeof(list) / sizeof(long long);
    
    for (int i = 0; i < s; ++i) {
        luhn a;
        if (a.check(list[i]))
            cout << "valid credit card number: " << list[i] << endl ;
        else
            cout << "Invalid credit card number: " << list[i] << endl;

    }
}

void ash_testbed() {
    luhn a;
   if ( a.check(4012888888881881))
       cout << "valid credit card number" << endl ;
   else
       cout << "Invalid credit card number" << endl;
    
    if (a.check(378282246310005))
        cout << "valid credit card number" << endl ;
    else
        cout << "Invalid credit card number" << endl;
    
    if (a.check(4012888888881880))
        cout << "valid credit card number" << endl ;
    else
        cout << "Invalid credit card number" << endl;
    
    if (a.check(4222222222222))
        cout << "valid credit card number" << endl ;
    else
        cout << "Invalid credit card number" << endl;
    
    ash_test1();
}


/*----------------------------------------------------------------
 test bed
 -----------------------------------------------------------------*/
void testbed() {
    luhn a;
    assert(a.check(4012888888881881));
    assert(a.check(378282246310005));
    assert(a.check(4012888888881880) == false);
    assert(a.check(4222222222222));
    test1();
}

/*----------------------------------------------------------------
 main
 -----------------------------------------------------------------*/
int main() {
    
    ash_testbed();
   testbed();
    return 0;
}

#if 0 
valid credit card number
Invalid credit card number
Invalid credit card number
Invalid credit card number
Invalid credit card number: 378282246310005
Invalid credit card number: 371449635398431
Invalid credit card number: 378734493671000
Invalid credit card number: 5610591081018250
Invalid credit card number: 30569309025904
valid credit card number: 38520000023237
valid credit card number: 6011111111111117
valid credit card number: 6011000990139424
valid credit card number: 3530111333300000
Invalid credit card number: 5105105105105100
valid credit card number: 4111111111111111
valid credit card number: 4012888888881881
Assertion failed: (a.check(378282246310005)), function testbed, file /Users/aashish/code/c++/objects/luhn/luhntest.cpp, line 78.
(lldb)

#endif 

//EOF