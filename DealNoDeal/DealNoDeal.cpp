//
//  DealNoDeal.cpp
//  c++
//
//  Created by Aashish Sharma on 8/8/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "DealNoDeal.h"

using namespace std;

// constructor definition

DealNoDeal::DealNoDeal()
{
    
    active_list = new int[26] ;
    
    s = new suitcase[CASES];

    float amount[26] ;
    
    for (int i = 0 ; i < 26; i++)
    {
        amount[i] = payout[i];
        active_list[i] = 0 ; 
        
    }
    
    // applying sattolo shuffle (a version of fisher-yates algorithm to shuffle the $ amount in the suitcases
    //https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
    
    srand (time(NULL));
    for (int i = CASES-1; i > 0 ; i--)
    {
        int r = rand()%CASES ;
        swap(amount[r], amount[i]);
    }
    
    // fill the suitcases to get them ready now
    
    for (int i=0; i < CASES; i++)
    {
       
        s[i].amount = amount[i];
        s[i].open_status=false;
        s[i].suitcase_num = i ;
    }
    
}

//destructor definition
DealNoDeal::~DealNoDeal()
{

    

    
}


int get_num_digits(int num )
{
    int digit = 0 ;
    int remainder = 0;
    int quotient = 0 ;
    
    if (num < 1  )
        return 4;
    
    while (num > 0)
    {
     remainder = num % 10;
     quotient = (num -  remainder )/10 ;
        digit++ ;
        num = quotient ;
    }
    
    return digit ;
}


int get_suitcase_status(const DealNoDeal d, float f )
{
    
    for (int i =0 ; i < 26; i++)
    {
        if (d.s[i].amount == f)
        {
            return d.s[i].open_status ;
        }
    }
    
    return 0 ;
}

void DealNoDeal::display_suitcases(const DealNoDeal d)
{
    
    int pay_counter = 0 ;
    int suit_counter  = 0 ;
    
    int line = 1 ;
    bool printing_suitcases = false ;
    
   // cout.width(80);
 
    cout << endl ;
    int num_digits = 0 ;
    
   while ( pay_counter < 13)
   {
       
     //  cout << "value of Pay: " << pay_counter << " " <<  d.payout[pay_counter] << " " << d.s[pay_counter].amount << endl ;
       
        if (d.payout[pay_counter] > 0 )
            num_digits = 10 - get_num_digits(d.payout[pay_counter]) ;
       
      // cout << "Num_digits is : " << num_digits << "for : " << d.payout[pay_counter] <<  endl ;

       
       int status=get_suitcase_status(d, d.payout[pay_counter] );
       
       // cout << "Status is :" << status << endl ;
       
       if (status == 1)
       {
          // cout.right;
           cout.width(num_digits);
           cout.fill(' ');
           cout << "(" << d.payout[pay_counter] << ")\t\t" ;
       }
       else if (status == 0 || status == 2 )
       {
          // cout.left;
           cout.width(10);
           cout.fill(' ');

           cout << d.payout[pay_counter] << "\t\t" ;
       }

      

       int disp = 0 ;
       
       if (suit_counter < 26 && line %2 == 0)
       {
           
           printing_suitcases = true;
    
               do {
                
                if ( d.s[suit_counter].open_status == 1)
                {
                    cout << "X" << "\t" ;
                }
                else if (d.s[suit_counter].open_status ==  0)
                {
                    cout  << suit_counter << "\t" ;
                }
                else if ( d.s[suit_counter].open_status == 2)
                {
                    cout  << "|" << suit_counter << "|" << " " ;
                }
                
                   suit_counter++ ;
                   
                    //cout <<  a.s[i].amount << "\t";
                
                if (disp  == 5  )
                {
                    break ;
                    
                }
             
                   disp++ ;
                   
               }while (disp < 5  && suit_counter < 26 );
           
            //suit_counter++;
       }
       
       
       if (suit_counter == 26)
       {
           cout << "\t\t\t\t";
           suit_counter++;
       }

       

       if(!printing_suitcases)
       {
           cout << "\t\t\t\t\t" ;
       }
       
       printing_suitcases=false;
       
     //  cout << "Pay counter is : " << pay_counter+12 << endl  ;
       
       status=get_suitcase_status(d, d.payout[pay_counter+13] );
       
      // cout << "Status is :" << status << endl ;
       
       if (status == 1)
       {
           cout.left;
           cout.width(0);
           cout.fill(' ');
           cout << "\t(" << d.payout[pay_counter+13] << ")"  ;
       }
       else if (status == 0 || status == 2)
       {
           cout.right;
           cout.width(0);
           cout.fill(' ');
           cout  << "\t" << d.payout[pay_counter+13]  ;
       }
       
       line ++ ;
       pay_counter++;
       
       //  cout << "value of Pay: " << pay_counter+13 << endl ;
       cout << endl ;
    }
    
    cout << "Unopened Suitcases: " ;
 
    for (int i = 0 ; i < 26; i++)
    {
        if (d.active_list[i] == 0)
        {
           // cout << i << " " << d.s[i].open_status << " " ;
            cout << i << " " ;
        }
        
    }
    
    
    cout << endl << "Opened Suitcases: " ;
    
    for (int i = 0 ; i < 26; i++)
    {
        if (d.active_list[i] != 0)
        {
            // cout << i << " " << d.s[i].open_status << " " ;
            cout << i << " " ;
        }
        
    }

}


//http://stackoverflow.com/questions/1608181/unique-random-numbers-in-an-integer-array-in-the-c-programming-language
// The Floyd algorithm

void DealNoDeal::pick_suitcases(const DealNoDeal d, int num_pick)
{
    
  //  int active_list[26];
    
    //cout << endl << endl << "num pick: " << num_pick << endl ;
    
    // applying The Floyd algorithm
    int remaining_cases = 0 ;
    
    for (int i = 0 ; i < CASES ; i ++ )
    {
        if (!d.s[i].open_status )
        {
            remaining_cases++ ;
        }
    }

    
    int M = num_pick ;
    const int N = remaining_cases  ;
    
    // using The Floyd algorithm
    
    unsigned char is_used[26] = {0};
    int in = 0 ;
    int im = 0;
    
    srand (time(NULL));
    
    for (in = N - M ; in < N && im < M ; ++in )
    {
        int r = rand() % (in + 1 );

   ////    cout <<  "Random number is: " << r  <<  endl ;
        
        while (d.s[r].open_status)
        {
            r+=1 ;
            if (r >= CASES)
                r=0;
        }
        
        assert(!d.s[r].open_status);
       
    
        d.s[r].open_status=true ;
        d.active_list[r]=1 ;
        
 //      cout <<  "Suitcase Opened: " << r << " Amount: " << d.s[r].amount << " Open: " << d.s[r].open_status << endl ;
              cout <<  "Suitcase Opened: " << r << " Amount: " << d.s[r].amount << endl ;
       
        im++;
    }
    
    assert(im == M );
    
}


/////////////

void DealNoDeal::pick_suitcases(DealNoDeal d, int pick, float &amount)
{
    
        d.s[pick].open_status=true ;
        d.active_list[pick]=1 ;
        
        //      cout <<  "Suitcase Opened: " << r << " Amount: " << d.s[r].amount << " Open: " << d.s[r].open_status << endl ;
        cout <<  "Suitcase Opened: " << pick << " Amount: " << d.s[pick].amount << endl ;
   
    amount = d.s[pick].amount ;
}



////////////////





float DealNoDeal::get_suitcase_amount(const DealNoDeal d, int suit_no)
{
        return d.s[suit_no].amount ;
}

int DealNoDeal::select_player_suitcase(const DealNoDeal d)
{
    srand (time(NULL));
    int selected = rand()%26;
    d.s[selected].open_status=2 ;
    
    cout << endl << endl << "Suitcase: " <<  selected << " Selected by the player" << endl ;
    
    return selected ; 
}


void DealNoDeal::select_player_suitcase(const DealNoDeal d, int selected)
{
    d.s[selected].open_status=2 ;
    cout << endl << endl << "Suitcase: " <<  selected << " Selected by the player" << endl ;

}


float DealNoDeal::banker_offer(const DealNoDeal d)
{
    cout << endl ;
    
    long long  amount = 0 ;
    int closed_suitcases = 0 ;
    
    for (int i =0 ; i < CASES ; i++)
    {
        if (d.s[i].open_status == 0 || d.s[i].open_status == 2 )
        {
           //// cout << d.s[i].amount << " + " ;
            amount+=d.s[i].amount ;
            closed_suitcases ++ ;
        }
    }
    
   //// cout << endl << "Total = " << amount << " Closed Suitcases " <<  closed_suitcases << " " << endl ;
    
    return amount / closed_suitcases ;
}


