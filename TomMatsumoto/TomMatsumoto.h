//
//  TomMatsumoto.h
//  c++
//
//  Created by Aashish Sharma on 7/12/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____TomMatsumoto__
#define __c____TomMatsumoto__

#include "../util/util.h"



class TomMatsumoto {
public:
    static void find_word();
  
private:
    static double get_price_of_word(char *ch);
    static char tolower(char s);
    static bool isalpha(char s);
};



#endif /* defined(__c____TomMatsumoto__) */