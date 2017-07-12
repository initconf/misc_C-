/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: Arraytest.cpp

On linux:
g++ Array.cpp Arraytest.cpp
valgrind a.out

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test Array object 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "array.h"

/*----------------------------------------------------------------
test reverse
-----------------------------------------------------------------*/
void test_reverse(const char* t) {
  Array a;
  char s[100];
  a.copy(s, t);    
  a.p("before ", s);
  a.reverse(s);
  a.p("after  ", s);
}

/*----------------------------------------------------------------
test reverse
-----------------------------------------------------------------*/
void test_reverse() {
  test_reverse("Hello");
  test_reverse("even");
  test_reverse("Pack my box with five dozen liquor jugs");
}

/*----------------------------------------------------------------
test string2number
-----------------------------------------------------------------*/
void test_string2number(const char* s) {
  Array a;
  int l = a.string2number(s);
  cout << s << " integer value = " << l << endl;
}

/*----------------------------------------------------------------
test string2number
-----------------------------------------------------------------*/
void test_string2number() {
  test_string2number("1986");
  test_string2number("19a7");
  test_string2number("19868978");
  test_string2number("");
}

/*----------------------------------------------------------------
test remove dups
-----------------------------------------------------------------*/
void test_removedups(const int* a, int l) {
  int* s = new int[l];
  for (int i = 0; i < l; ++i) {
    s[i] = a[i];
  }
  Array t;
  t.p("BEFORE DUP ", s,l);
  int k = t.removedups(s, l);
  t.p("AFTER DUP ", s,k);
  delete[] s;
}

/*----------------------------------------------------------------
test remove dups
-----------------------------------------------------------------*/
void test_removedups() {
  {
    int a[] = { 5, 2, 9, 3, 7 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
  {
    int a[] = { 2, 2 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
  {
    int a[] = { 58, 26, 91, 26, 70, 70, 91, 58, 58, 58, 66 };
    int l = sizeof(a) / sizeof(int);
    test_removedups(a, l);
  }
}

/*----------------------------------------------------------------
test bed
-----------------------------------------------------------------*/
void testbed() {
  test_reverse();
  test_string2number();
  test_removedups();
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  testbed() ;
  return 0 ;
}


#if 0

before  Hello
after   olleH
before  even
after   neve
before  Pack my box with five dozen liquor jugs
after   sguj rouqil nezod evif htiw xob ym kcaP
1986 integer value = 1986
19a7 integer value = 0
19868978 integer value = 19868978
integer value = 0
BEFORE DUP 5 2 9 3 7
AFTER DUP 5 2 9 3 7
BEFORE DUP 2 2
AFTER DUP 2
BEFORE DUP 58 26 91 26 70 70 91 58 58 58 66
AFTER DUP 58 26 91 70 66
Program ended with exit code: 0

#endif

//EOF
