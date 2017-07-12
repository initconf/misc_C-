//
//  fakegold70.cpp
//  c++
//
//  Created by Aashish Sharma on 10/1/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "fakegold70.h"

// constructor

fakegold70::fakegold70()
{
    _safe = new int [MAX];
    
    for (int i  = 0 ; i < MAX ; ++i)
    {
        _safe[i] = 2;
    }
    
    srand (time(NULL));
    
    int random_select = rand() % MAX ;
    
    cout << "Random number found is " << random_select << endl ;
    _safe[random_select] = 1 ;
    //_safe[17] = 1 ;


//    for (int i = 0 ; i < MAX ; ++i)
//    {
//        for (int i  = 0 ; i < MAX ; ++i)
//        {
//            _safe[i] = 2;
//        }
//
//     cout << "Random number found is " << i << endl ;
//    _safe[i] = 1 ;
//    
//       cout << " NEW NEW FAKE IS AT : " <<  find_fake(0, MAX-1) << endl ;
//        
//        cout << " ==================================================  " << endl ;
//    }
    
   
}



fakegold70::fakegold70(int loc)
{
    _safe = new int [MAX];
    
    for (int i  = 0 ; i < MAX ; ++i)
    {
        _safe[i] = 2;
    }
    
    
    _safe[loc] = 1 ;
    
}




// destructor
fakegold70::~fakegold70()
{
    
    delete [] _safe;
    
}


// print function

ostream& operator<<(ostream& o, fakegold70& a)
{

    int divider  = a.MAX / 10 ;
    
    if ( divider == 0  )
    {
        divider = 1 ;
    }
    
    o << "divider is " << divider << " A.max " << a.MAX << endl ;
    
    
    for (int j = 0 ; j < a.MAX ; j+=(a.MAX/divider))
    {
        
        for (int i  = j ; i < j+(a.MAX/divider) ; ++i)
        {
            if ( i >= a.MAX)
                break;
            
            //                if (i % (a.MAX/5)  == 0 )
            //                        cout << "-" << endl ;
            
            
            if (i < 10)
            {
                o << "| " << i <<  " "  ;
            }
            else
                o << "|" << i <<  " "  ;
            
            
        }
        cout << "|" << endl ;
        
        for (int i  = j ; i < j+(a.MAX/divider) ; ++i)
        {
            if ( i >= a.MAX)
                break;
            
            
            if (a._safe[i] == 2)
            {
                o << "| R" << " "  ;
            }
            else
                o << "| F" << " "  ;
            
        }
        
        
        o << "|" << endl ;
        
        
    }
    
    
    return o;
    
}


/// weighing - returns the fake gold coin's position. takes low and high limits

int fakegold70::weigh(int low, int high)
{
    int middle = 0 ;
    int range = 0 ;
    bool isODD = false;
    
    while (low < high)
    {
        int sum_low = 0;
        int sum_high = 0 ;
        
        middle = (low+high) / 2 ;
        range = (high-low+1);
        
        if (range % 2 == 0)
            isODD = false ;
        else
            isODD = true ;
        
        
        // check the last two elements in the list
        if ( range == 2)
        {
            if (_safe[low] > _safe[high])
                return high ;
            else
                return low ;
        }
        
        if (isODD)
        {
            for (int i = low ; i <= middle ; ++i)
            {
                
                //  cout << endl << "Odd: low: " << low << " middle " << middle << " i " << i << endl ;
                sum_low += _safe[i] ;
            }
            
            
            for (int i = middle ; i <= high ; ++i)
            {
                //cout << endl  << "Odd: middle: " << middle << " high " << high << " i " << i << endl ;
                sum_high += _safe[i] ;
            }
            
            
        }
        else
        {
            for (int i = low ; i <= middle ; ++i)
            {
                
                // cout << endl << "Even: low: " << low << " middle " << middle << " i " << i << endl ;
                sum_low += _safe[i] ;
            }
            
            
            for (int i = middle+1 ; i <= high ; ++i)
            {
                // cout << endl  << "Even: middle: " << middle << " high " << high << " i " << i << endl ;
                sum_high += _safe[i] ;
            }
            
            
        }
    
    
        
        iteration++ ;
        
        // cout << endl << "low: " << low << "  high: " << high << " middle: " << middle << " sum_low " << sum_low << " sum_high " << sum_high <<  endl ;
        
        
        if (sum_high < sum_low)
        {
            low = middle ;
        }
        else if (sum_high > sum_low)
        {
            high = middle ;
            
        }
        else
            return middle ;
    }
    
    return middle ;
    
}

int fakegold70::find_fake(int low, int high)
{
   
    
    int coins = high - low  +1 ;
    
    int pile_size = (coins - (coins % 3))/3 ;
    
    if (low == high )
    {
            return low ;
    }
    
    
    bucket buck[3] ;
    
    buck[0].low = low + 0 ;
    buck[0].high = low + pile_size - 1;
    
    buck[1].low = buck[0].high + 1 ;
    buck[1].high = low +  2*pile_size -1 ;
    
    buck[2].low =  buck[1].high+ 1;
    buck[2].high = low +  pile_size*3 -1 ;
    
    int spare1 =  low + (coins - (coins - ((3*pile_size))));

    int spare2= 0;
    
    if (3*pile_size+1 < coins)
    {
        spare2 = low + (coins - (coins - ((3*pile_size)+1)));
    }
    
    
    int sum_buck0 = 0;
    int sum_buck1 = 0 ;
    int sum_buck2 = 0 ;
   
    

    
    
    for (int i = low; i < low + pile_size ; ++i)
    {
      // cout << endl << "Add Safe [" << i << "] : " << _safe[i]  ;
        sum_buck0 += _safe[i];
        
    }
    
    for (int i = low + pile_size ; i < low + 2*pile_size ; ++i)
    {
       //cout << endl << "Add Safe 2 [" << i << "] : " << _safe[i]  ;
        sum_buck1 += _safe[i];
        
    }
    
    // start comparisions now
    
    if (sum_buck0 == sum_buck1)
    {  iterations_fake_safe ++ ;
      
        
        //time to weigh sum_buck3
        for (int i = low + 2*pile_size; i < low + 3*pile_size ; ++i)
        {
          //  cout << endl << "Add Safe 3 [" << i << "] : " << _safe[i]  ;
            sum_buck2 += _safe[i];
            
        }
    
    

        
        if (sum_buck1 == sum_buck2)
        { iterations_fake_safe ++ ;
            if (spare2 != 0)
            {
                if (_safe[spare1] < _safe[spare2])
                    return spare1;
                else
                    return spare2;
            }

        }
        else if (sum_buck2 < sum_buck1)
        {  iterations_fake_safe ++ ;
            // start narrowing to bucket3 for the fake coins
           return find_fake(buck[2].low, buck[2].high);
        }
        
    }
    else if (sum_buck1 < sum_buck0)
    {  iterations_fake_safe ++ ;
        return   find_fake(buck[1].low, buck[1].high);
    }
    else if (sum_buck0 < sum_buck1)
    {  iterations_fake_safe ++ ;
        return find_fake(buck[0].low, buck[0].high);
    }

    if (spare2 != 0)
    {
        if (_safe[spare1] < _safe[spare2])
        {  iterations_fake_safe ++ ;
            return spare2;
        }
    }
    else
    {  iterations_fake_safe ++ ;
        return spare1;
    }

    return 0 ;
    
}
