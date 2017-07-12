//
//  ninetynine.h
//  c++
//
//  Created by Aashish Sharma on 7/12/15.
//  Copyright (c) 2015 Aashish Sharma. All rights reserved.
//

#ifndef __c____ninetynine__
#define __c____ninetynine__

#include "../util/util.h"


class ninetynine{
public:
    static const int MAX_COUNT = 99 ;
    static void write_poem();
    static void test_strcat();
    
private:
    static string num2words(int num);
    static void strcat(char* dst, const char* src);
};


#endif /* defined(__c____ninetynine__) */
