/*----------------------------------------------------------------
Copyright (c) 2013 Author: Jagadeesh Vasudevamurthy
file: intmatrixtest.cpp

On linux:
g++ intmatrix.cpp intmatrixtest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test intmatrix object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "intmatrix.h"

/*----------------------------------------------------------------
test init and fini
-----------------------------------------------------------------*/
void test_init_fini() {
    intmatrix a {} ;
//  a.init() ;
//  a.print("Matrix a") ;
    cout << "Matrix a" << endl << a << endl ;

    intmatrix b {3,4};
//  b.init(3,4) ;
//  b.print("Matrix b") ;
    cout << "Matrix b" << endl << b << endl ;

    intmatrix c {2,0,7};
//  c.init(2,0,7) ;
//  c.print("Matrix c") ;
    cout << "Matrix C" << endl << c << endl ;

    intmatrix d {0,10,7};
    cout << "Matrix D" << endl << d << endl ;
    
//  d.init(0,10,7) ;
//  d.print("Matrix d") ;

    intmatrix e {3,10,7};
//  e.init(3,10,7) ;
 // e.print("Matrix e") ;
    cout << "Matrix e" << endl << e << endl ;

    intmatrix f {"1 2|3 4|5 6"};
//  f.init("1 2|3 4|5 6") ;
 // f.print("Matrix e") ;
    cout << "Matrix f" << endl << f << endl ;
    

    intmatrix g {" 1 2 |3 4 |5 6  "} ;
    assert(f==g);
    assert(g == f);
    
//  g.init(" 1 2 |3 4 |5 6  ") ;
 // g.print("Matrix g") ;
//  assert(f.isEqual(g)) ;
 // assert(g.isEqual(f)) ;

    
    intmatrix h {" 1 2 |3 4 |5 6 8 "} ;
//  h.init(" 1 2 |3 4 |5 6 8 ") ;
 // h.print("Matrix h") ;
    cout << "Matrix H" << endl << h << endl ;
    
  assert(h.isEmpty()) ;
  assert(!(f == h)) ;

//  a.fini() ;
//  b.fini() ;
//  c.fini() ;
//  d.fini() ;
//  e.fini() ;
// f.fini() ;
//  g.fini() ;
}

/*----------------------------------------------------------------
test add1
-----------------------------------------------------------------*/
void test_add1(const char* as, const char* bs, const char* anss) {
    intmatrix a {as} ;
//  a.init(as) ;
//  a.print("Matrix a") ;
    
    
    intmatrix b {bs} ;
    cout << "Matrix B" << endl <<  b << endl ;
    
//  b.init(bs) ;
//  b.print("Matrix b") ;
  
  intmatrix s = a+b ;
  cout << "Matrix S" << endl << s << endl ;

 // s.print("matrix s") ;
  
    intmatrix ans { anss} ;
//  ans.init(anss) ;
//  ans.print("matrix expected ans") ;

    cout << "Matrix expected ans" << endl << ans << endl ;
    
  assert(s == ans) ;
  assert(ans == s) ;
//  a.fini() ;
 // b.fini() ;
 // s.fini() ;
 // ans.fini() ;
}

/*----------------------------------------------------------------
test add
-----------------------------------------------------------------*/
void test_add() {
  test_add1("7 9 11|13 15 17 "," 6 8 10| 12 14 16 ","13 17 21 | 25 29 33") ;
  test_add1("1 2 3|4 5  6 ","1 2  ","") ;
}

/*----------------------------------------------------------------
test mult1
-----------------------------------------------------------------*/
void test_mult1(const char* as, const char* bs, const char* anss) {
    intmatrix a {as};
//  a.init(as) ;
 // a.print("Matrix a") ;
    cout << "Matrix a " << endl << a << endl ;
    
    intmatrix b  {bs} ;
//  b.init(bs) ;
 // b.print("Matrix b") ;
    cout << "Matrix b" << endl << b << endl ;
    
  intmatrix s = a * b ;
//  s.print("matrix s") ;
    
    cout << "Matrix s" << endl << s << endl ;
    
    intmatrix ans {anss} ;
//  ans.init(anss) ;
 // ans.print("matrix expected ans") ;
    
    cout << "Matrix expected ans" << endl << ans << endl ;
    
  assert(s == ans) ;
  assert(ans == s) ;
//  a.fini() ;
 // b.fini() ;
 // s.fini() ;
 // ans.fini() ;
  cout <<"----------------------------------\n" ;
}

/*----------------------------------------------------------------
test mult
-----------------------------------------------------------------*/
void test_mult() {
  test_mult1("1 2 3"," 2 1 3 | 3 3 2| 4 1 2  ","20 10 13") ;
  test_mult1("3 4 2","13 9 7 15|8 7 4 6| 6 4 0 3 ","83 63 37 75") ;
  test_mult1("3","5 2 11|9 4 14","15 6 33|27 12 |42") ;
  const char* a = "3 9 0 2 2 9 5 2|0 2 2 1 9 6 6 8|7 5 6 1 4 9 8 9|3 3 2 9 2 1 7 4|1 9 0 1 2 9 5 2|4 2 0 3 7 3 9 1|5 9 0 6 6 7 8 2|9 3 4 6 8 4 9 1" ;
  const char* b = "6 1 6 0 8 3 0 0|6 8 9 0 6 6 7 2|4 8 2 0 5 4 6 7|2 4 4 2 2 6 9 8|4 8 2 2 4 6 4 1|1 5 5 6 4 7 5 5|7 4 6 5 0 6 5 3|2 3 7 0 1 3 8 5";
  const char* s = "132 170 200  87 128 186 175 106|122 186 166  86  92 182 195 123|197 235 267 104 179 243 253 178|128 140 164  63  86 162 194 140|118 164 184  85 110 174 166  98|138 142 144  83  91 162 137  82|187 222 244 106 160 244 232 141|201 212 210  97 171 230 204 142";
  test_mult1(a,b,s) ;
  test_mult1("7 3|2 5 | 6 8| 9 0","8 14 0 3 1|7 11 5 91 3|8 4 19 5 57","") ;
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
  test_init_fini();
  test_add() ;
  test_mult() ;
}



/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  return 0 ;
}



//EOF

#if 0

Matrix a;
Empty Matrix
Matrix b
0 0 0 0
0 0 0 0
0 0 0 0
Matrix c


Matrix d
Matrix e
7 7 7 7 7 7 7 7 7 7
7 7 7 7 7 7 7 7 7 7
7 7 7 7 7 7 7 7 7 7
1 2|3 4|5 6
Matrix e
1 2
3 4
5 6
1 2 |3 4 |5 6
Matrix g
1 2
3 4
5 6
1 2 |3 4 |5 6 8
Error Condition 1
Matrix h
Empty Matrix
7 9 11|13 15 17
Matrix a
7 9 11
13 15 17
6 8 10| 12 14 16
Matrix b
6 8 10
12 14 16
matrix s
13 17 21
25 29 33
13 17 21 | 25 29 33
matrix expected ans
13 17 21
25 29 33
1 2 3|4 5  6
Matrix a
1 2 3
4 5 6
1 2
Matrix b
1 2
Error condition
matrix s
Empty Matrix

matrix expected ans

1 2 3
Matrix a
1 2 3
2 1 3 | 3 3 2| 4 1 2
Matrix b
2 1 3
3 3 2
4 1 2
REsult is
20 10 13
matrix s
20 10 13
20 10 13
matrix expected ans
20 10 13
----------------------------------
3 4 2
Matrix a
3 4 2
13 9 7 15|8 7 4 6| 6 4 0 3
Matrix b
13 9 7 15
8 7 4 6
6 4 0 3
REsult is
83 63 37 75
matrix s
83 63 37 75
83 63 37 75
matrix expected ans
83 63 37 75
----------------------------------
3
Matrix a
3 63 37 75
13 15 17 0
5 2 11|9 4 14
Matrix b
5 2 11
9 4 14
Matrix cannot be multiplied here
matrix s
Empty Matrix
15 6 33|27 12 |42
Error Condition
Error Condition 1
matrix expected ans
Empty Matrix
----------------------------------
3 9 0 2 2 9 5 2|0 2 2 1 9 6 6 8|7 5 6 1 4 9 8 9|3 3 2 9 2 1 7 4|1 9 0 1 2 9 5 2|4 2 0 3 7 3 9 1|5 9 0 6 6 7 8 2|9 3 4 6 8 4 9 1
Matrix a
3 9 0 2 2 9 5 2
0 2 2 1 9 6 6 8
7 5 6 1 4 9 8 9
3 3 2 9 2 1 7 4
1 9 0 1 2 9 5 2
4 2 0 3 7 3 9 1
5 9 0 6 6 7 8 2
9 3 4 6 8 4 9 1
6 1 6 0 8 3 0 0|6 8 9 0 6 6 7 2|4 8 2 0 5 4 6 7|2 4 4 2 2 6 9 8|4 8 2 2 4 6 4 1|1 5 5 6 4 7 5 5|7 4 6 5 0 6 5 3|2 3 7 0 1 3 8 5
Matrix b
6 1 6 0 8 3 0 0
6 8 9 0 6 6 7 2
4 8 2 0 5 4 6 7
2 4 4 2 2 6 9 8
4 8 2 2 4 6 4 1
1 5 5 6 4 7 5 5
7 4 6 5 0 6 5 3
2 3 7 0 1 3 8 5
REsult is
132 170 200 87 128 186 175 106
122 186 166 86 92 182 195 123
197 235 267 104 179 243 253 178
128 140 164 63 86 162 194 140
118 164 184 85 110 174 166 98
138 142 144 83 91 162 137 82
187 222 244 106 160 244 232 141
201 212 210 97 171 230 204 142
matrix s
132 170 200 87 128 186 175 106
122 186 166 86 92 182 195 123
197 235 267 104 179 243 253 178
128 140 164 63 86 162 194 140
118 164 184 85 110 174 166 98
138 142 144 83 91 162 137 82
187 222 244 106 160 244 232 141
201 212 210 97 171 230 204 142
132 170 200  87 128 186 175 106|122 186 166  86  92 182 195 123|197 235 267 104 179 243 253 178|128 140 164  63  86 162 194 140|118 164 184  85 110 174 166  98|138 142 144  83  91 162 137  82|187 222 244 106 160 244 232 141|201 212 210  97 171 230 204 142
matrix expected ans
132 170 200 87 128 186 175 106
122 186 166 86 92 182 195 123
197 235 267 104 179 243 253 178
128 140 164 63 86 162 194 140
118 164 184 85 110 174 166 98
138 142 144 83 91 162 137 82
187 222 244 106 160 244 232 141
201 212 210 97 171 230 204 142
----------------------------------
7 3|2 5 | 6 8| 9 0
Matrix a
7 3
2 5
6 8
9 0
8 14 0 3 1|7 11 5 91 3|8 4 19 5 57
Matrix b
8 14 0 3 1
7 11 5 91 3
8 4 19 5 57
Matrix cannot be multiplied here
matrix s
Empty Matrix

matrix expected ans

----------------------------------
Program ended with exit code: 0

#endif