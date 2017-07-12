//
//  TestPerpetualCalendar.cpp
//  c++
//
//  Created by Aashish Sharma on 7/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//


#include "PerpetualCalendar.h"

void get_day_of_the_week(char* mm, int dd, int yy)
{
    PerpetualCalendar p;
    
    cout << endl << "Entered : " << mm << " " << dd << " " << yy << "   " ;
    
    const char*  months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                            "Jul" , "Aug", "Sep", "Oct", "Now", "Dec"
                          };
    
    
    const char* wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    
    
//    int num_elements = sizeof (months)/sizeof (char*);
    
//  for (int i = 0 ; i < num_elements; i++)
//  {
//      cout << months[i] << "  " << endl ;
//  }
    
   // cout << "enter date: ( Ex: Novermber 12 1929) " ;
    
    //char mm[15];
    
   // int dd = 0 ;
    //int yy = 0 ;
    
    //cin >> mm >> dd >> yy ;
    
    int valid_y=0;
    int valid_m=0;
    int valid_d=0;
    
    
    if (p.validate_year(yy))
    {
        //cout << "Year entered is : " << yy << endl ;
        valid_y=1;
    }
    else
        cout << "Invalid YEAR!! Please enter between 1755 - 2033" << endl ;
    
    
    
    if (p.validate_day(dd))
    {
        // cout << "day entered is : " << dd << endl ;
        valid_d=1 ;
    }
    else
        cout << "Invalid DAY!! Please enter between 1 and 31" << endl ;

    
    int month  = p.validate_month(mm);
    
    if (month)
    {
        //cout << "month entered is : " << mm << endl ;
        valid_m=1;
    }
    else
        cout << "Invalid MONTH: " << mm << "  doesn't exist:" << endl  ;
    
    if (month == 2 && dd == 29 && !p.is_leap(yy))
    {
        cout << "INVALID DATE!!!: Does not exist " << mm << " " << dd << " " << yy << endl ;
        valid_d = 0 ;
    }
    
    
    if (valid_d && valid_m && valid_y)
    {
    
        int  var = p.get_year_map(yy);
    
        //cout << "Year is : " << yy << "year year map is : " << var ;
        //  int month = p.validate_month(mm) ;
        //cout << "var is : " <<  var << "Month is : "<< month << endl ;
    
        int month_map = p.get_month_mapping(var, month);
    
        //cout << "Month map is " << month_map << endl  ;
        // enum weekday { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday  } ;
    
        int _day =  p.get_calendar_mapping(dd, month_map);
    
        //cout << "Day is : " << _day << endl ;
    
        cout << "Day of the week on "<< mm << " " << dd << " " << yy << " is : "  << wday[_day] <<endl;
    
    }
    
}

void test_day_of_the_week()
{
    
    const char* dates[]  = { "Jan 30 1649", "Feb 29 1960" };
    
    for (int i=0 ; i < sizeof(dates)/sizeof (char*); i++)
    {
        cout << dates[i] << endl ;
        
    }
}


int main() {

   // get_day_of_the_week();


        get_day_of_the_week("Oct", 12, 1493);
        get_day_of_the_week("May", 29, 1493);
        get_day_of_the_week("Jan", 30, 1649);
        get_day_of_the_week("Jul",  4, 1776);
        get_day_of_the_week("Jul", 14, 1789);
        get_day_of_the_week("Jun", 18, 1815);
        get_day_of_the_week("Jun", 28, 1914);
        get_day_of_the_week("Oct", 25, 1917);
        get_day_of_the_week("Jun", 26, 1919);
        get_day_of_the_week("Mar", 23, 1933);
        get_day_of_the_week("Aug",  6, 1845);
        get_day_of_the_week("Oct", 22, 1960);
        get_day_of_the_week("Nov",  9, 1989);
        get_day_of_the_week("May",  2, 2011);
        get_day_of_the_week("Apr", 30, 1945);
        get_day_of_the_week("Feb", 29, 1960);
        get_day_of_the_week("Feb", 29, 1964);
        get_day_of_the_week("Feb", 29, 1972);
        get_day_of_the_week("Feb", 29, 1976);
        get_day_of_the_week("Feb", 29, 1980);
        get_day_of_the_week("Feb", 29, 1896);
        get_day_of_the_week("Feb", 29, 1924);
        get_day_of_the_week("Mar", 1, 1925);
    
    cout << endl  << "============================= corner cases and invalid data =============================" << endl ;
    
    
        get_day_of_the_week("Feb", 29, 1925);
        get_day_of_the_week("Blah", 0, 0000);
    
    
    
    return 0 ;
}

#if 0
Entered : Oct 12 1493   Invalid YEAR!! Please enter between 1755 - 2033

Entered : May 29 1493   Invalid YEAR!! Please enter between 1755 - 2033

Entered : Jan 30 1649   Invalid YEAR!! Please enter between 1755 - 2033

Entered : Jul 4 1776   Day of the week on Jul 4 1776 is : Thursday

Entered : Jul 14 1789   Day of the week on Jul 14 1789 is : Tuesday

Entered : Jun 18 1815   Day of the week on Jun 18 1815 is : Sunday

Entered : Jun 28 1914   Day of the week on Jun 28 1914 is : Sunday

Entered : Oct 25 1917   Day of the week on Oct 25 1917 is : Thursday

Entered : Jun 26 1919   Day of the week on Jun 26 1919 is : Thursday

Entered : Mar 23 1933   Day of the week on Mar 23 1933 is : Thursday

Entered : Aug 6 1845   Day of the week on Aug 6 1845 is : Wednesday

Entered : Oct 22 1960   Day of the week on Oct 22 1960 is : Saturday

Entered : Nov 9 1989   Day of the week on Nov 9 1989 is : Thursday

Entered : May 2 2011   Day of the week on May 2 2011 is : Monday

Entered : Apr 30 1945   Day of the week on Apr 30 1945 is : Monday

Entered : Feb 29 1960   Day of the week on Feb 29 1960 is : Monday

Entered : Feb 29 1964   Day of the week on Feb 29 1964 is : Saturday

Entered : Feb 29 1972   Day of the week on Feb 29 1972 is : Tuesday

Entered : Feb 29 1976   Day of the week on Feb 29 1976 is : Sunday

Entered : Feb 29 1980   Day of the week on Feb 29 1980 is : Friday

Entered : Feb 29 1896   Day of the week on Feb 29 1896 is : Saturday

Entered : Feb 29 1924   Day of the week on Feb 29 1924 is : Friday

Entered : Mar 1 1925   Day of the week on Mar 1 1925 is : Sunday

============================= corner cases and invalid data =============================

Entered : Feb 29 1925   INVALID DATE!!!: Does not exist Feb 29 1925

Entered : Blah 0 0   Invalid YEAR!! Please enter between 1755 - 2033
Invalid DAY!! Please enter between 1 and 31
Invalid MONTH: Blah  doesn't exist:
Program ended with exit code: 0

#endif 