//
//  amicable.cpp
//  c++
//
//  Created by Aashish Sharma on 9/24/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "amicable.h"


amicable::amicable(int max)
{
    _factors = new int [max] ;
    
    for (int i = 0 ; i <= max; ++i)
    {
        _factors[i] = 1;
    }
    
    _populate_factors(max);
    
     int counter= 0 ;
    
    for (int i = 1 ; i <= max ; i++)
    {
        
  // cout << "Number: " << i << "  "  << _factors[i] << endl ;
        
        int sum = _factors[i] ;
       
        if (sum < max )
        {
        
            if (_factors[i] == sum && _factors[sum] == i && i != sum && i < sum)
            {
                cout << counter << ". " <<  i << "  and " << sum << endl ;
                counter++ ;
            }
        }
        
        
        // _find_pair(i);
        
    }
    
}


amicable::~amicable()
{
    
    
}


//void amicable::find_pair(int num)
//{
//    int sum = 0 ;
//    
//  //  cout << "Num: " << num ;
//    
//    for (int i = 1 ; i <= num/2 ; ++i)
//    {
//        
//        if (num % i == 0)
//        {
//            sum+=i ;
//      //   cout << " " << i ;
//        }
//    
//    }
//    
//  //  cout << " = " << sum << endl ;
//    
//    int ami_pair= 0 ;
//    
//    for (int i = 1 ; i <= sum/2 ; i++)
//    {
//        if (sum % i == 0)
//        {
//            ami_pair+=i ;
//            
//        }
//    }
//    
//    int counter = 0 ; 
//
//    if (ami_pair == num)
//    {
//        counter ++ ;
//         cout <<  counter << ":"  << num << " and " << sum << endl ;
//    }
//
//    
//}


//int amicable::_get_sum_of_factors(int num)
//{
//    int z = 2;
//    int sum = 1 ;
//    
//
//   
//    while (z * z <= num)
//    {
//        if (num % z == 0)
//        {
//            sum += z  ;
//            num /= z ;
//                   }
//        else
//            z++;
//        
//        
//    }
//    
//    if (num > 1)
//    {
//        cout << num << " "  ;
//        sum += num ;
//    }
//    
//
//    
//    return sum ;
//                
//}

int amicable::_get_sum_of_factors(int num)
{
    
//    int n = num ;
//    int sum = 1 ;
//    
//    for (int i = 2 ; i <= n/i ; i++)
//    {
//        while (n %i == 0 )
//        {
//            cout << " " << i ;
//            sum += i ;
//            n /= i ;
//        }
//    }
//    
//    if (n > 1)
//        sum += n ;
//    
//    return sum ;
    
    int sum = 0 ;
    
 //   cout << "Num: " << num ;
    for (int i = 1 ; i <= num/2 ; ++i)
        {
    
            if (num % i == 0)
            {
                sum+=i ;
          //   cout << " " << i ;
            }
    
        }
    
//    cout << " = " << sum << endl ;
    
    return sum;
}
void amicable::_find_pair(int num)
{
    int sum_factors = _get_sum_of_factors(num);
    
   // cout << "num : " << num << " sum :  " << sum_factors << endl ;
    int sum_factors_sum = _get_sum_of_factors(sum_factors);
    
    if (num == sum_factors_sum)
        cout << "num: amicable Pair : " << num << " " << sum_factors << endl ;
}

void amicable::_populate_factors(int max)
{
    
     clock_t start = clock() ;
    
    for (int i = 2 ; i*i < max ; ++i)
    {

        int k = i ;
        
        while (1)
        {
            int j = i*k ;
            
            if (j > max)
                break ;
            
           // cout << "I : " << i << " J: " << j << " k " << k << endl ;
            
            if (i == j)
            {
                _factors[j] = _factors[j] + i ;
            }
            else
                _factors[j] = _factors[j] +i + k;
        
            k++;
        }
        
    }
    
    clock_t end = clock() ;
    cout <<"Run time for factorization: " << double(end - start)/CLOCKS_PER_SEC << " secs" << endl ;
}