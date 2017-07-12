#include "../util/util.h"

#include "../p1/p1.h"

void testbed()
{
    
    
    p1 a;
    
    a.print_usa();
     a.a_power_b();
    a.two_power_n();
    a.print_n_n2_n3();
    
    a.a1();
    a.a2();
    a.a3();
    a.a4();
    
    
}

int main(int argc, const char * argv[]) {

    testbed();
    
    

    return 0;
    
}

#if 0
this is an expmple of print_usa function
xxx       x      xxxx x       xxx
x        x     x     xx       x
x        x     x             x x
x        x     x            x   x
x        x     x           x      x
x        x     x           x      x
x        x       xxx       xxxxxxxx
x        x           xx   x        x
x        x             x  x        x
x        x             x  x        x
xx      xx     xx      x  x        x
xxxxxxxxx      xx xxxxx  xxx      xxx

===============a^b table ===============
a      b           a^b
1      2           1
2      3           8
3      4           81
4      5           1024
5      6           15625
6      7           279936
7      8           5764801

===============2 2^n table ===============
2             2^n
2              2
2              4
2              8
2              16
2              32
2              64
2              128
2              256
2              512
2              1024
2              2048
2              4096
2              8192
2              16384
2              32768
2              65536
2              131072
2              262144
2              524288
2              1048576

===============n n^2 n^3 table ===============
n             n^2             n^3
1              1              1
2              4              8
3              9              27
4              16              64
5              25              125
6              36              216
7              49              343
8              64              512
9              81              729
10              100              1000

===============a1 ===============

1
1	2
1	2	3
1	2	3	4
1	2	3	4	5
1	2	3	4	5	6

===============a2 ===============
1
2	1
3	2	1
4	3	2	1
5	4	3	2	1
6	5	4	3	2	1

===============a3 ===============
1	2	3	4	5	6
1	2	3	4	5
1	2	3	4
1	2	3
1	2
1

===============a4 ===============
1	2	3	4	5	6
1	2	3	4	5
1	2	3	4
1	2	3
1	2
1
Program ended with exit code: 0

#endif
