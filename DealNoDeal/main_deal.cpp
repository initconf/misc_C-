//
//  main_deal.cpp
//  c++
//
//  Created by Aashish Sharma on 8/9/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "DealNoDeal.h"

/*
char* print_amout (int value)
{
    char s[10] = {} ;
    
    if (value> 1000)
        value = value / 1000 ;
    
    s=itoa(value);
    
    strcat(s,"K");
    
    s[strlen[s]+1)='\0' ;
      
    return s ;
}
 */

int playgame()
{
    
        
    
    cout << "Welcome to the Game of Deal or NoDeal" << endl ;
    cout << "--------------------------------------" << endl ;
    
    DealNoDeal game ;
    
    DealNoDeal::display_suitcases(game);
    int PlayerSuitcase = DealNoDeal::select_player_suitcase(game);
    
    DealNoDeal::display_suitcases(game);
    
    
    
    int picks = 6 ;
    int banker_offer_amount = 0 ;
    
    for (int i = picks ; i > 0 ; i--)
    {
        
        cout << endl << endl << endl <<  "Round " << picks - i+1 << " pick: " << i << " suitcases" << endl ;
        
        DealNoDeal::pick_suitcases(game, i);
        
        
        DealNoDeal::display_suitcases(game);
        
        banker_offer_amount =  DealNoDeal::banker_offer(game);
        
        cout << endl << "Banker offer is : " << banker_offer_amount << endl ;

    }
    
    cout << "Remaining: " ;
    int total_remaining = 0 ;
    
    for (int i =0 ; i < 26; i++)
    {
        if (game.active_list[i] == 0 )
        {
            cout << i << " " ;
            total_remaining++;
            
        }
    }
    
    while (total_remaining > 2)
    {
        
        DealNoDeal::pick_suitcases(game, 1);
        
        DealNoDeal::display_suitcases(game);
        
        banker_offer_amount =  DealNoDeal::banker_offer(game);
        
        cout << endl << "Banker offer is : " << banker_offer_amount << endl ;
        total_remaining-- ;
        
        
    }
    
    int win_amount = DealNoDeal::get_suitcase_amount(game, PlayerSuitcase) ;
    
    cout << "Amount selected in PlayerSuitCase [" << PlayerSuitcase << "] is : " << win_amount ;
    
    cout << endl << endl  << endl << endl << endl << endl << endl << endl << endl ;
    
    return win_amount  ;
}


void PlayMillionaire()
{
    
    float value = 0 ;
    int game_count = 0 ;
    
    while ( value < 999999)
    {
        value=playgame();
        game_count++;
    }
    
    cout << "You got millionaire after playing " << game_count << " games " << endl ;
    
    cout << " YIPPEEE YUPPPPEEEE BOOOOOMM BOOOOOOOOOOMM...... WE got a WINNER HERE " << endl ;

    
    
}

void PlayPoor()
{
    float value = 1000000 ;
    int game_count = 0 ;
    
    
    while ( value > 1)
    {
        value = playgame();
        game_count++ ;
        
    }
    
    cout << "You got poor after playing " << game_count << " games " << endl ;
}

void PlayRandom()
{
    DealNoDeal game;
    int value = playgame();

}

void PlayInteractive()
{
    
    cout << "Welcome to the Game of Deal or NoDeal" << endl ;
    cout << "--------------------------------------" << endl ;
    
    DealNoDeal game ;
    int PlayerSuitcase ;
    bool BankerOfferAccepted = false ;
    
    DealNoDeal::display_suitcases(game);
    
   do
    {
        cout << " What suitcase do you want to select" << endl ;
        cin >> PlayerSuitcase ;
    }
    while (PlayerSuitcase <0 || PlayerSuitcase > 25);
    
    DealNoDeal::select_player_suitcase(game, PlayerSuitcase);
    
    DealNoDeal::display_suitcases(game);
    
 
    int  slabs[] = { 6, 5, 4, 3, 2, 1, 1, 1, 1, 1 };

    int round = 0 ;
    int picks=0;
    int selection ;
    float amount ;

    
    int opened_suitcase = 0 ;
    int suitcase_left = 26;

    char ans[10] = { "no"};
    
    picks=slabs[round];
    
    do
    {
        cout << endl << endl << endl ;
        
        cout << "Round: " << round+1 <<  endl ;
        

        cout << "Select " << picks  << " suitcases now " << endl ;
       
        
        do
        {
            cout << "Enter suitcase number (you may not enter Selected Suitcase or already opened suitcase)::" << endl ;
            cin >> selection  ;
        }while (game.s[selection].open_status!=0 );
        
        
        DealNoDeal::pick_suitcases(game, selection, amount);
        
        DealNoDeal::display_suitcases(game);
       // cout << endl << " ================== " << endl << "Suitcase opened: " << selection << " Amount: " << amount << endl;
        opened_suitcase++;
        suitcase_left = 25 - opened_suitcase ;
        
        cout << endl << "Remaining (unopened) Suitcases: " << suitcase_left ;
        
        
        picks-- ;
        
        if (picks == 0)
        {
            round ++ ;
            picks = slabs[round];
            
            int banker_offer_amount =  DealNoDeal::banker_offer(game);
            cout << endl << "Banker offer is : " << banker_offer_amount << endl ;
            
            do
            {
                cout << "Do you accept banker's offer" << endl ;
                cin >> ans;
            }while (!(strcmp (ans, "yes") == 0 || strcmp (ans, "no") == 0));

            if (strcmp (ans, "yes") == 0 )
            {
                BankerOfferAccepted = true ;
                break ;
            }
        }
        

    }while (suitcase_left > 1) ;
    
     DealNoDeal::display_suitcases(game);
    
    
    if (! BankerOfferAccepted)
    {
         int choice = 0 ;
        
        do {
                cout << endl << "NOw you got three choices" << endl ;
                
                cout << "1) Take bankers offer " << endl ;
                cout << "2) Take your suitcase " << endl ;
                cout << "3) Take the last remaining suitcase " << endl ;
                
                cout << endl << "Enter your choice" << endl ;
                
                cin >> choice  ;
            
        } while (choice < 0 || choice > 3); 
        
                switch (choice)
                {
                    case 1: {
                        int banker_offer_amount =  DealNoDeal::banker_offer(game);
                        cout << endl << "Banker offer is : " << banker_offer_amount << endl ;
                        break ;
                    }
                    case 2: {
                        
                        DealNoDeal::pick_suitcases(game, PlayerSuitcase, amount);
                        DealNoDeal::display_suitcases(game);
                        
                        break ;
                        
                    }
                    case 3:{
                        int remaining = 0 ;
                        
                        for (int i = 0 ; i < 26; i++)
                        {
                            if (game.active_list[i] == 0)
                            {
                                // cout << i << " " << d.s[i].open_status << " " ;
                                remaining = i ;
                            }
                            
                        }

                        DealNoDeal::pick_suitcases(game, remaining, amount);
                        DealNoDeal::display_suitcases(game);
                        
                        break ;
                        
                    }
                }
        
    }
    else
    {
        int banker_offer_amount =  DealNoDeal::banker_offer(game);
        cout << endl << "Banker offer is : " << banker_offer_amount << endl ;
        
        cout << endl << "YOu've WON : " << banker_offer_amount << endl ;
        cout << endl ;
    }
    
    
    if (suitcase_left >= 0 || BankerOfferAccepted)
        {
            game.s[PlayerSuitcase].open_status = 0 ;
            
            cout << endl << endl << "Do you want to see whats in your pick" << endl ;
            cout << " Amount inside your suitcase [" << PlayerSuitcase << "]: " <<  game.s[PlayerSuitcase].amount << endl ;
            
            if (game.s[PlayerSuitcase].amount >= 500000)
            {
                cout << " YIPPEEE YUPPPPEEEE BOOOOOMM BOOOOOOOOOOMM...... WE got a WINNER HERE " << endl ;
            }
        }
    
}


int main()
{
     int choice = 0 ;

    do {
        
    
            cout << "How do you want to play the game " << endl ;
            cout << "1) Single Interactive game" << endl ;
            cout << "2) Single Computer Game" << endl ;
            cout << "3) Non-Interactive: Play to Millionarie " << endl ;
            cout << "4) Non-Interactive: Play to poor " << endl ;
        
        
            cin >> choice ;
    } while (choice < 1 || choice > 4) ;
    
    switch(choice)
    {
        case 1: PlayInteractive(); break ;
        case 2: PlayRandom(); break ;
        case 3: PlayMillionaire(); break ;
        case 4: PlayPoor(); break ;
    }
    
    
}


#if 0 

==============
Poor Run:
Unopened Suitcases: 0 17 25
Opened Suitcases: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 19 20 21 22 23 24
1e+06 + 5000 + Total = 1005000 Closed Suitcases 2

Banker offer is : 502500
Suitcase Opened: 25 Amount: 5000

0.01								(1000)
(1)         0	X	X	X	X		(5000)
(5)                                 (10000)
(10)		X	X	X	X	X		(25000)
(25)								(50000)
(50)		X	X	X	X	X		(75000)
(75)								(100000)
(100)		X	X	|17| X	X		(200000)
(200)								(300000)
(300)		X	X	X	X	X		(400000)
(400)								(500000)
(500)		X						(750000)
(750)								1e+06
Unopened Suitcases: 0 17
Opened Suitcases: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 18 19 20 21 22 23 24 25
1e+06 + Total = 1000000 Closed Suitcases 1

Banker offer is : 1000000
Amount selected in PlayerSuitCase is : 0


You got poor after playing 2679 games
Program ended with exit code: 0


======== Second RUN ==========================


Banker offer is : 5150
Suitcase Opened: 24 Amount: 300

0.01								(1000)
(1)         |0| X	X	X	X		(5000)
(5)                                 10000
(10)		X	X	X	X	X		(25000)
(25)								(50000)
(50)		X	X	X	X	X		(75000)
(75)								(100000)
(100)		X	X	X	X	X		(200000)
(200)								(300000)
(300)		X	X	X	X	X		(400000)
(400)								(500000)
(500)		25						(750000)
(750)								(1e+06)
Unopened Suitcases: 0 25
Opened Suitcases: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
10000 + Total = 10000 Closed Suitcases 1

Banker offer is : 10000
Amount selected in PlayerSuitCase is : 0


You got poor after playing 7849 games

===========================

MILLIONARIRE RUN
_________________


Banker offer is : 250000
Suitcase Opened: 24 Amount: 0.01

(0.01)								(1000)
(1)         X	X	X	X	X		(5000)
(5)                                 (10000)
(10)		X	X	X	X	X		(25000)
(25)								(50000)
(50)		X	X	X	X	|14| 	(75000)
(75)								(100000)
(100)		X	X	X	X	X		(200000)
(200)								(300000)
(300)		X	X	X	X	X		(400000)
(400)								500000
(500)		25						(750000)
(750)								1e+06
Unopened Suitcases: 14 25
Opened Suitcases: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 15 16 17 18 19 20 21 22 23 24
500000 + Total = 500000 Closed Suitcases 1

Banker offer is : 500000
Amount selected in PlayerSuitCase is : 1000000

You got millionaire after playing 4390 games


======= RUN 2 =============

Banker offer is : 255
Suitcase Opened: 23 Amount: 10

(0.01)								(1000)
(1)         X	X	X	X	X		(5000)
(5)                                 (10000)
(10)		X	X	X	X	X		(25000)
(25)								(50000)
(50)		X	X	X	X	X		(75000)
(75)								(100000)
(100)		X	X	X	X	X		(200000)
(200)								(300000)
(300)		X	X	X	X	24		(400000)
(400)								(500000)
500         |25| 					(750000)
(750)								1e+06
Unopened Suitcases: 24 25
Opened Suitcases: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
500 + Total = 500 Closed Suitcases 1

Banker offer is : 500
Amount selected in PlayerSuitCase [25] is : 1000000


You got millionaire after playing 1594 games


======== RUN 3 ==================

Suitcase Opened: 25 Amount: 100000

(0.01)								(1000)
(1)         0	X	X	|3| X		5000
(5)                                 (10000)
(10)		X	X	X	X	X		(25000)
(25)								(50000)
(50)		X	X	X	X	X		(75000)
(75)								(100000)
(100)		X	X	X	X	X		(200000)
(200)								(300000)
(300)		X	X	X	X	X		(400000)
(400)								(500000)
(500)		X						(750000)
(750)								1e+06
Unopened Suitcases: 0 3
Opened Suitcases: 1 2 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
5000 + Total = 5000 Closed Suitcases 1

Banker offer is : 5000
Amount selected in PlayerSuitCase [3] is : 1000000


You got millionaire after playing 840 games


===== Interactive RUN ========

Banker offer is : 125000
Do you accept banker's offer
no

(0.01)								(1000)
(1)         |0| X	X	X	X		(5000)
(5)                                 (10000)
(10)		X	X	X	X	X		(25000)
(25)								50000
(50)		X	X	X	X	X		(75000)
(75)								(100000)
(100)		X	X	X	X	X		200000
(200)								(300000)
(300)		X	X	X	X	X		(400000)
(400)								(500000)
(500)		25						(750000)
(750)								(1e+06)
Unopened Suitcases: 0 25
Opened Suitcases: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
NOw you got three choices
1) Take bankers offer
2) Take your suitcase
3) Take the last remaining suitcase

Enter your choice
2
Suitcase Opened: 0 Amount: 200000


Do you want to see whats in your pick
Amount inside your suitcase [0]: 200000



#endif
