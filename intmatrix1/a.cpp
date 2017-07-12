void intmatrix1::init(const char *str)
{
    int row=0;
    int col=0;
    int i = 0 ;
    int elements= 0;
    int prev_col=0;
    bool error_condition = false;
    

     cout << str << endl ;
    
    while (str[i] != '\0')
    {
        if (str[i] != ' ' )
        {
   cout << "I: " << i << " Row: " << row << " Col: " << col << " Value: "<< str[i] << " PC: " << prev_col << " " << endl ;
            
            while (str[i] != ' ')
            {
                i++;
            }

            if (str[i] >= '0' && str[i] <= '9')
            {
                elements++;
                col++;
            }

                if (str[i] == '|')
                {
                    
                    if (row == 0)
                    {
                        prev_col = col ;
                    }
                    
                    if (prev_col != col)
                    {
                        cout << "error condition" << endl ;
                       // break ;
                    }
                    row++;
                    col = 0 ;
                }
            }
        
        

         i++;
        }
    
    row++;
    
    
    if (prev_col != col)
    {
        cout << "error condition" << endl ;
        error_condition= true ;
      }
    
    _row= row ;
    _col = col ;
    


    
//    if (! error_condition)
    if ( error_condition)
    {
    
        i = 0 ;
        int j = 0 ;
        
        _matrix = new int[_row][C] ;
        
        row = 0;
        col = 0 ;
        char tmp_num[10];
        

        while (str[i] != '\0')
        {
            //cout << "I is : " << i << "Row " << _row << " COl : " << _col << " Value "<< str[i] << endl ;
            if ( str[i] == '|')
            {
                row++ ;
                col = 0 ;
            }
        
            if (str[i] != ' ' && str[i] >= '0' && str[i] <= '9')
            {
                while (str[i] != ' ')
                {
                    tmp_num[j]= str[i] ;
                    i++;
                }
                
                tmp_num[j++] = '\0' ;
                
                _matrix[row][col]= atoi(tmp_num) ;
                col++;
            }
            
            i++;
        
        }
    }
    
    else {
        _row=0;
        _col = 0 ;
        
        _matrix = new int[_row][C] ;
        
    }
    
}

