//
//  ninetynine.cpp
//  c++
//
//  Created by Aashish Sharma on 7/12/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "ninetynine.h"


void ninetynine::test_strcat()
{
    char return_str[] = { "blah" }  ;
    
    
    const char* quantifiers[] = {
        "Zero", "Ten", "Twenty", "Thrity", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        
    };
    
    const char* tens[] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thriteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eightteen", "Nineteen"
    };
    
    
    int quotient = 2 ;
    int remainder = 3;
    
    cout << "Q is :" << quantifiers[quotient] << " R is :" << tens[remainder] << endl ;
    
    char space = ' ' ;
    
    ninetynine::strcat(return_str, &space );
    ninetynine::strcat(return_str, quantifiers[quotient]);
    ninetynine::strcat(return_str, &space );
    ninetynine::strcat(return_str, tens[remainder] );
    cout << "Return string is : " << return_str << endl ;
    
    
}



void ninetynine::strcat(char* dst, const char* src)
{
    int dlen = 0 ;
    
    while (*dst)
    {
        dst++;
        dlen++;
    }
    
    
    while (*src)
    {
        *dst=*src;
        src++;
        dst++;
        
    }
    
    *dst = '\0';

    
}

 string ninetynine::num2words(int num)
{
    std::string return_str = "" ;
    
    
    
     const char* quantifiers[] = {
       "Zero", "Ten", "Twenty", "Thrity", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        
    };
    
     const char* tens[] = {
        "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
        "Eleven", "Twelve", "Thriteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
        "Eightteen", "Nineteen"
    };
    
    
    cout << endl ;
    
    if (num > 19)
    {
        int remainder = num % 10;
        int quotient = (num -  remainder )/10 ;
        
        //cout << quotient << " Remainder is " << remainder << endl ;
        //cout << quantifiers[quotient] << " " << tens[remainder] << endl  ;
        
        //ninetynine::strcat(return_str, quantifiers[quotient]);
        //ninetynine::strcat(return_str, &space );
        //ninetynine::strcat(return_str, tens[remainder] );
       // cout << "Return string is " << quantifiers[quotient] << " " << tens[remainder] << " " << return_str << endl ;
        
        return_str = quantifiers[quotient];
        return_str += ' ' ;
        if (remainder != 0 )
            return_str += tens[remainder] ;
        
        return_str += ' ' ;
        return_str += "bottles" ;
        
    }
    else
    {
        return_str += tens[num] ;
        return_str += ' ' ;
        if (num == 1)
            return_str += "bottle" ;
        else
            return_str += "bottles" ;

    
    }
     //cout << "Return string is " << return_str << endl ;

        return return_str ;
}

void ninetynine::write_poem()
{
    

    
    const char* line[] = {
            " of beer on the wall,",
            " of beer,",
            "Take one down, pass it around,",
            " of beer on the wall"
    };
    
    const char * punchuation[] = { ",", "." };
    
    for (int i = 99; i > 0 ; i-- )
    {
        string word = ninetynine::num2words(i);
        
        string punch = i>1?punchuation[0]:punchuation[1];
        
        cout << word << line[0] << endl << word << line[1] << endl << line[2] << ninetynine::num2words(i-1) << line[3] << punch << endl ;
    }
    
    
}