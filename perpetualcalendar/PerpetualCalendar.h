//
//  PerpetualCalendar.h
//  c++
//
//  Created by Aashish Sharma on 7/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____PerpetualCalendar__
#define __c____PerpetualCalendar__

#include "../util/util.h"


class PerpetualCalendar {
public:
    bool is_leap(int );
    int validate_month(char mm[]);
    int validate_year (int yy);
    bool validate_day (int dd);
    
    int get_month_mapping(int, int );
    int get_calendar_mapping(int, int);
    int get_year_map(int);
    
    
    
private:
    int strcmp(char *s1,  char *s2);
    void copy( char* s,  const char* t);
    char* split(char *s, char *delimit);
    
    
    
};



#endif /* defined(__c____PerpetualCalendar__) */
