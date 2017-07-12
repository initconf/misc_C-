//
//  DealNoDeal.h
//  c++
//
//  Created by Aashish Sharma on 8/8/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____DealNoDeal__
#define __c____DealNoDeal__

#include "../util/util.h" 

#ifdef  __APPLE__ //&& __MACH__
#include <assert.h>
#endif


class DealNoDeal {
    
public:
    DealNoDeal();
    ~DealNoDeal();
    
    struct suitcase {
        int suitcase_num;
        float amount ;
        int open_status;
        
    };
    
    suitcase *s ;
    int *active_list ;
    
    static void display_suitcases(const DealNoDeal)  ;
    static void pick_suitcases(const DealNoDeal, int )  ;
    static void pick_suitcases(const DealNoDeal, int, float&);
    
    static float  banker_offer(const DealNoDeal) ;
    static int select_player_suitcase(const DealNoDeal );
    static void select_player_suitcase(const DealNoDeal, int);
    static float get_suitcase_amount(const DealNoDeal, int );
    

    
private:
    
    int removedups(float* ary, int num );
    enum MAXC {CASES=26};

    
    const float payout[26] = { .01, 1, 5, 10, 25, 50, 75,
                                100, 200, 300, 400, 500, 750,
                                1000, 5000, 10000, 25000, 50000,
                                75000, 100000, 200000, 300000,
                                400000, 500000, 750000, 1000000 };
    

    
    int active_play[26] = {0}; 

    
    
    
};






#endif /* defined(__c____DealNoDeal__) */
