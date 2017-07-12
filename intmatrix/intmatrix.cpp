//
//  intmatrix.cpp
//  c++
//
//  Created by Aashish Sharma on 8/7/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#include "intmatrix.h"

int intmatrix::atoi(char *s)
{
    int l = 0;
    
    bool minus = false ;
    do {
        if (s) {
            if (*s == '-') {
                minus  = true;
                s++ ;
            }
        }
    
        if (s) {
            if (*s >= '0' && *s <= '9') {
                l = l * 10 + (*s - '0' );
                s++;
            }
            else {
                return 0;
            }
        }
    }while(*s);
    
    return (minus) ? -l : l ;

}
    
    
char* intmatrix::itoa(int num, char * str, int base=10)
{
    
    int ti=0;
    char tmpary[100];
    
    int i = 0 ;
    bool negative = false ;
    
    if (num == 0)
    {
        str[0] = '0' ;
        str[1] = '\0' ;
        
        //cout <<  "Zero case "<< str << "IS Zero" << endl ;
        return str;
    }
    
    if (num < 0)
    {
        negative = true ;
        num = - num ;
    }
    
    int remainder = 0 ;
    
    do
    {
        
        //cout << "Num is " << num << endl ;
        remainder = num % base ;
        //cout << "remainder is " << remainder << endl ;
        
        
        num = (num- remainder) / base ;
        
        tmpary[ti]= '0'+ remainder ;
        ti++;
        
        //cout << "tmpary is " << tmpary ;
        
        
    }while (num > 0);
    
    tmpary[ti++] = '\0';
    
    i = 0 ;
    
    if (negative)
    {
        str[i] = '-' ;
        i++;
    }
    
    
    for ( int j=strlen(tmpary)- 1 ; j >= 0 ; j--)
    {
        // cout << "tmp ary is "<< tmpary[j] << endl ;
        str[i] = tmpary[j];
        // cout << "str  is "<< str[i] << endl ;
        i++;
    }
    
    str[i++] = '\0';
    
    // cout << "final tmp ary is "<< tmpary << endl ;
    // cout << "Final str  is "<< str << endl ;
    return str;
}





bool intmatrix::isEmpty()
{
    if (_row == 0 && _col ==0 )
    {
        return true;
    }
    return false ;
}


intmatrix::intmatrix()
{
    _row=0;
    _col=0;
    _matrix =  new int [_row][C];
    
    
}


intmatrix::intmatrix(int r, int c)
{
    _row = r ;
    _col = c ;
    
 //   int (*m)[C] = new int [_row][C];
   // int   (*matrix)[C] =  new int [_row][C];
    
    _matrix = new int[_row][C] ;
    
    for (int i = 0 ; i< _row; i++)
    {
        for (int j = 0 ; j < _col ; j++)
        {
            _matrix[i][j]=0 ;
            
        }
    }

}

intmatrix::intmatrix(int r, int c, int value)
{
    _row = r ;
    _col = c ;
    
    _matrix = new int[_row][C] ;
    
    for (int i = 0 ; i< _row; i++)
    {
        for (int j = 0 ; j < _col ; j++)
        {
            _matrix[i][j]=value ;
        }
    }
}


intmatrix::intmatrix(const char *str)
{
    
    
    if (str[0] == '\0')
    {
        intmatrix a;
        _row=0;
        _col=0;
      //  a.init();
    }
    
    int   i = 0 ;
    int row = 0 ;
    int col = 0 ;
    char c_ary[10];

    int c = 0 ;
    int expected_col = 0 ;
    
    //str = { " 1 12|3 24 | 5 6 " };
    
cout << str << endl ;
    
    _matrix = new int [C][C];
        
    i = 0 ;
    
  while(str[i] )
    {
        
     //   if(str[i] == ' ' )
        //    i++;
        
        if (str[i] >= '0' && str[i] <='9')
        {
            while (str[i] >='0' && str[i] <='9' && (str[i] != ' ' || str[i] != '|' ) ){
         //   cout << "String is::" << str[i] << endl ;
                c_ary[c] = str[i] ;
                i++;
                c++;
            }
            
            c_ary[c++]='\0' ;
            
            int num = atoi(c_ary);
           // cout << "Number is " << num << " Row: " << row << " Col " << col <<  endl  ;
           
            _matrix[row][col]= num;
              col++;
            
            if (str[i] == '\0')
            {
                _col++;
                break ;
            }
    
            
        }
        
        if (str[i] == '|' )
        {
            if (row == 0)
            {
                expected_col = col ;
            }
            
            if (expected_col != col)
            {
                cout << "Error Condition" << endl ;
                
            }
            row++;
            col=0;
        }
        
      
        c=0;
        
        _row = row ;
        _col = col ;
        
      
        
     i++;
       
    } // end of outer while

        _row++;
    
    if (row != 0 && expected_col != col)
    {
        cout << "Error Condition 1" << endl ;
        _row=0;
        _col=0;
    }

    
}

//void intmatrix::print(string str) const
std::ostream& operator<<(ostream& out, intmatrix &a)
{
    
    int row = a._row;
    int col = a._col;
    
    //cout << str << endl ;
    
    if (row == 0 && col == 0 )
        out << "Empty Matrix " << endl ;

    for (int i = 0 ; i< row; i++)
    {
        for (int j = 0 ; j < col ; j++)
        {
          out << a._matrix[i][j] << " " ;
        }
        out << endl ;
    }

    return out ;
}


intmatrix::~intmatrix()
{
    
   //delete []_matrix;
}



//bool intmatrix::isEqual(intmatrix sec)
bool intmatrix::operator==(const intmatrix sec)
{
  
   if ((this->_row == sec._row ) || ( this->_col == sec._col))
   {
    
   // this->print("THIS Matrix");
    
   // sec.print("Second Matrix");
    
   // cout <<" This row:" << this->_row << " This col: " << this->_col << endl ;
    
   // cout <<" 2nd row:" << sec._row << " 2nd col: " << sec._col << endl ;
    
    for (int i = 0; i < sec._row ; i++ )
    {
  
        for (int j = 0 ; j < sec._col ; j++)
        {
            //cout << "I,J: " << i << " " <<  j << " This:" << this->_matrix[i][j] << " Second: "<< sec._matrix[i][j] << endl ;
            if (this->_matrix[i][j] != sec._matrix[i][j])
                return false ;
                
        }
    }
    
    return true;
   }
    else
        return false ;
    
}




intmatrix& intmatrix::operator+(const intmatrix &sec)
{
    
 
    if (this->_row == sec._row && this->_col == sec._col)
    {
    
        intmatrix b {this->_row, this->_col} ;
//        b.init(this->_row, this->_col);
    
    for (int i = 0 ; i < this->_row; i++)
    {
        for (int j = 0  ; j < this->_col; j++)
        {
            b._matrix[i][j] = this->_matrix[i][j] + sec._matrix[i][j];
        }
    }
    
    return b ;
    }
    else{
        cout << "Error condition" << endl ;
        intmatrix a {} ;
  //          a.init();
            return a;
    }
}


//intmatrix& operator=(const intmatrix rhs);
//intmatrix& operator+(const intmatrix rhs);


//intmatrix intmatrix::mult(const intmatrix &sec)
intmatrix& intmatrix::operator*(const intmatrix &sec)
{

    if (! ( this->_col == sec._row ))
    {
        cout << "Matrix cannot be multiplied here" << endl ;
        intmatrix a {};
     //   a.init();
        return a;
    }
    
    intmatrix result ;
    int sum = 0 ; 
    
    result._matrix = new int [this->_row][C] ;
    
    
   // this->print("THIS Matrix mult");
    
   // sec.print("Second Matrix mult ");
    
    for (int row = 0 ; row < this->_row ; row++)
    {
        for (int  col = 0 ; col < sec._col; col++)
        {
            for( int inner = 0 ; inner < this->_col; inner++)
            {
                sum += this->_matrix[row][inner] * sec._matrix[inner][col] ;
            }
            
            result._matrix[row][col] = sum ;
            sum=0;
            result._row=row;
            result._col=col ;
        }
    }

    result._row++;
    result._col++;
    
    cout << "result is" << endl << result << endl ;
   // result.print("REsult is ");
    
    return result ;
 
   
    
}


