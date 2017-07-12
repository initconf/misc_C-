//
//  TomMatsumoto.cpp
//  c++
//
//  Created by Aashish Sharma on 7/12/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "TomMatsumoto.h"

char TomMatsumoto::tolower(char s)
{
    if (( s >= 'A' && s <= 'Z'))
    {
        s=(s - 'A') + 'a' ;
    }
    return s;
    
}

bool TomMatsumoto::isalpha(char c)
{
    return  ((c >='A' && c <= 'Z') || (c >= 'a' && c <= 'z') )? true : false ;
}


double TomMatsumoto::get_price_of_word(char *ch)
{
    const double price_list[] = {1, 0.01, 0.02, 0.03, 2.0, 0.04, 0.05, 0.06, 3.0, 0.07, 0.08, 0.09, 0.10, 0.11, 4.00, 0.12, 0.13, 0.14, 0.15, 0.16, 5.00, 0.17, 0.18, 0.19, 6.00, 0.20};
    
    double price=0.0 ;
    
    //cout << "length of string is :" << len -1  << endl ;
    
   while (*ch)
    {
        if ( isalpha(*ch))
        {
       // cout << "CH is : " << *ch << " lower is : " << tolower(*ch) << " "  ;
        int num = tolower(*ch) - 'a' ;
        //cout << "number is : " << num << "price is :: " << price_list[num] << endl  ;
        price +=  price_list[num] ;
        
        }
        ch++;
    }
    
    return price ;
}

void TomMatsumoto::find_word()
{
    
#ifdef _WIN32
    ifstream data("c:/tmp/words");
#elif  __APPLE__ && __MACH__
    //ifstream data("/Users/aashish/code/c++/objects/TomMatsumoto/words");
    ifstream data("/Users/aashish/code/c++/objects/TomMatsumoto/english-words");
#endif
    
//
    
    double most_expensive = 0.0;
    string most_expensive_word  = "" ;
    
    
    for (std::string line; std::getline(data, line); )
    {
       // std::cout << line << " " << line.length() << std::endl;
        
        //cout << line << endl ;
        
       double price =  TomMatsumoto::get_price_of_word(&line[0]);
        
        
        if (price == 25.00 ){
               std::cout << line << " has price: $" << price << std::endl;
        }
        
        
        if (price > most_expensive)
        {
            most_expensive = price ;
            most_expensive_word = line ;
        }

        
    }
    
    cout << "most expensive word in dictionary is : " << most_expensive_word << "   priced at: $" << most_expensive << endl ;
    
}


  