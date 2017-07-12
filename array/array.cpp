//
//  Array.cpp
//  c++
//
//  Created by Aashish Sharma on 6/29/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "Array.h"

void Array::copy( char* s,  const char* t)
{

    for (int i = 0 ; i < 100; i++)
    {
        s[i] = '\0' ;
    }
    
   do
    {
      *s = *t;
        s++;
        t++;
    } while (*t != '\0');
}

int Array::a_pow_b(int a, int b) {
    
    int result=1;
    
    for (int ct=1; ct <= b; ct++)
    {
        result = result*a;
        
    }
    
    
    return result ;
}

void Array::p(const char str1[], char str[])
{
    //cout << "strlen is :" << strlen(str1) << endl ;

    while (*str1 != '\0')
        {
        
        std::cout << *str1 ;
            str1++;
        }

    std::cout << " " ;
    
    while (*str != '\0')
    {
        
        std::cout << *str ;
        str++;
    }
    
    std::cout << endl ;
    
}

void Array::p(const char str1[], int* a, int b)
{
    for (int i=0; i < strlen(str1); i++)
    {

            std::cout << str1[i] ;
    }

    
    for (int c=0; c < b ;c++)
    {
        std::cout << a[c] << " " ;
    }
    
    std::cout << endl ;
}

void Array::reverse( char str[])
{
    unsigned long len = strlen(str);
    
    for (int i = 0; i < strlen(str)/2; i++)
    {
        std::swap(str[i], str[len - i - 1]);
    }
    
}



int Array::string2number(const char str[])
{
    unsigned long  len=strlen(str);
    int value = 0 ;
    int result = 0;
    
    for (int i = int(len)-1 ; i >= 0 ; )
    {
        //cout << int (str[i]) - '0'  << endl;
        int t = int (str[i]) - '0' ;
        
        if (t < 0 || t > 9)
        {
            result = 0 ;
            break ;
        }
        
        i--;
        
        result += t * (a_pow_b(10, value));
//      cout << "resut is : " << result << " t is " << t << " value is : " << value <<  endl ;
        value ++ ;
    }
    
//    cout << "resut is : " << result << endl ;
    return result ;
    
}

void Array::bubbleSort(int *ary, int num)
{
    for (int i =0 ; i <= num ; i++)
    {
        for (int j = 0; j < num-1 ; j++)
        {
            if (ary[j+1] < ary[j])
            {
                std::swap(ary[j], ary[j+1]);
            }
        }
    }

    
}


int Array::removedups(int* ary, int num )
{
    
    for (int i =0 ; i < num ; i++)
    {
       // cout << "i : " << i << endl ;
        
        for (int j = i+1 ; j < num ; j++)
        {
          //  cout << "j : " << j << endl;
           // cout << "ary[" << i << "] : "<< ary[i] << "ary[" << j << "]= " << ary[j] << endl ;
            
            if (ary[i] == ary[j])
            {
             //   cout << "Dup is found " << ary[j] <<  endl ;
                for (int c=j; c< num; c++)
                {
                    ary[c]=ary[c+1];
                }
                num-=1;
                j--; 
            }
        }
        
    }

    
    return num ; 
    
    
}