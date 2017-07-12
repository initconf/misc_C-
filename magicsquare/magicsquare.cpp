//
//  magicsquare.cpp
//  c++
//
//  Created by Aashish Sharma on 7/26/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "magicsquare.h"

void magicsquare::_initialize_array(int x[][5], int ROW, int COL)
{

    for (int _row=0 ; _row < ROW ; _row++)
    {
        for (int _col=0; _col < COL ; _col ++)
        {
            x[_row][_col] = 0 ;
        }
    }
}


void magicsquare::_display_array(int x[][5], int ROW, int COL)
{
    for (int _row=0 ; _row < ROW ; _row++)
    {
        for (int _col=0; _col < COL ; _col ++)
        {
            cout << x[_row][_col] << " " ;
        }
        cout << endl ;
    }
}


void magicsquare::_get_next_row_col(int &x, int &y)
{
    cout << "x is : " << x << " y is : " << y << endl ;
    
    x = 0 ;
    y = 0 ;
}

void magicsquare::print_magic_square(int size )
{
    int ROW = size ;
    const int COL = size ;
    
  //int (*x)[COL] = new int[ROW][COL] ;
    
  int x[ROW][COL] ;
    
    cout << endl << endl ;
    
    cout.width(size);
    cout << "   magicsquare :" << " (" << size << ")                   sum" << endl  << endl ;


    for (int _row=0 ; _row < ROW ; _row++)
    {
        for (int _col=0; _col < COL ; _col ++)
        {
            x[_row][_col] = 0 ;
            
        }
    }
    
    
    int start_row = 0;
    int start_col = COL/2  ;
    
    int _row = 0;
    int _col = 0;
    int new_row = 0 ;
    int new_col = 0 ;
    
    int TOTAL_ELEMENTS = ROW*COL ;
    
    for (int i = 1; i <= TOTAL_ELEMENTS; i++)
    {
        if (i == 1 )
        {
        
             _row = start_row;
             _col = start_col ;
            
        }
        else
        {
             new_row = _row - 1 ;
             new_col = _col - 1;
       
            
            if (new_row <0)
                new_row=ROW-1 ;
            if (new_col <0 )
                new_col=COL-1 ;
            
            if (x[new_row][new_col] != 0)
            {
                new_row = _row+1 ;
                new_col = _col ;
            }
            
            _row = new_row ;
            _col = new_col ;
            
        }
        
        //cout << "_row: " << _row << " _col : " << _col << endl ;
        
        x[_row][_col] = i;

    }
    int rsum = 0 ;
    int csum = 0 ;
    
    for (int _row=0 ; _row < ROW ; _row++)
    {
        
        for (int _col=0; _col < COL ; _col ++)
        {
            cout.width(6);
            cout <<  x[_row][_col]  ;
            rsum+=x[_row][_col];
            
        }
        
        cout << "           " << rsum << endl ;
        rsum = 0 ;
    }

    
    cout  << endl << endl ;
    
    for (int i = 0 ; i <ROW ; i++)
    {
        for (int j=0; j<COL ; j++)
        {
            csum += x[i][j];
            
        }
        
        cout.width(6);
        cout << csum ;
        csum = 0;
    }
    
    cout << endl ;
    
//    delete [] x;
    
}