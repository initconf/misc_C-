/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: recursiontest.cpp

On linux:
g++ ../str/str.cpp factorial.cpp fibonacci.cpp numbinarydigit.cpp hanoi.cpp recursiontest.cpp
valgrind a.out
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test recursion object

CANNOT CHANGE ANYTHING IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "recursion.h"

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = false;

/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void test_factorial() {
  recursion f(verbose);
  cout << "-----------------------Factorial using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_mult = 0;
    long long a = f.factorial_iterative(i, num_mult);
    cout << "factorial_iterative: f(" << i << ")= " << a << " Number of mult = " << num_mult << endl;
  }
  cout << "-----------------------Factorial using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    long long a = f.factorial_recursion(i, num_rec);
    cout << "factorial_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------Factorial using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    long long a = f.factorial_stack(i, size_of_stack);
    cout << "factorial_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_mult = 0;
    assert(a == f.factorial_iterative(i, num_mult));
  }
}

/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
void test_num_binary_digit() {
  recursion f(verbose);
  cout << "-----------------------num_binary_digits using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_itr = 0;
    int a = f.num_binary_digit_iterative(i, num_itr);
    cout << "num_binary_digits_iterative: f(" << i << ")= " << a << " Number of itr = " << num_itr << endl;
  }
  cout << "-----------------------num_binary_digits using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    int a = f.num_binary_digit_recursion(i, num_rec);
    cout << "num_binary_digits_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------num_binary_digits_using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    int a = f.num_binary_digit_stack(i, size_of_stack);
    cout << "num_binary_digits_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.num_binary_digit_iterative(i, num_itr));
  }
  cout << "-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------\n";
  for (int i = 0; i < 300000; ++i) {
    int size_of_stack = 0;
    int num_itr = 0;
    int a = f.num_binary_digit_stack(i, size_of_stack);
   // int b = f.num_binary_digit_recursion(i, num_itr) ;
    if (i % 10000 == 0) {
      cout << "num_binary_digits_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
   //  cout << "f.num_binary_digit_recursion: f(" << i << ")= " << b << " recursion = " << num_itr << endl;

    }
    num_itr = 0;
    assert(a == f.num_binary_digit_iterative(i, num_itr));
    num_itr = 0;
    assert(a == f.num_binary_digit_recursion(i, num_itr));
  }
}

/*----------------------------------------------------------------
test fibonacci
-----------------------------------------------------------------*/
void test_fibonacci() {
  recursion f(verbose);
  cout << "-----------------------fibonacci using iteration-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_itr = 0;
    int a = f.fibonacci_iterative(i, num_itr);
    cout << "fibonacci_iterative: f(" << i << ")= " << a << " Number of itr = " << num_itr << endl;
  }
  cout << "-----------------------fibonacci using recursion-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int num_rec = 0;
    int a = f.fibonacci_recursion(i, num_rec);
    cout << "fibonacci_recursion: f(" << i << ")= " << a << " Number of recursion = " << num_rec << endl;
  }
  cout << "-----------------------fibonacci_using stack-----------------------\n";
  for (int i = 0; i < 30; ++i) {
    int size_of_stack = 0;
    int a = f.fibonacci_stack(i, size_of_stack);
    cout << "fibonacci_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.fibonacci_iterative(i, num_itr));
  }
  cout << "-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------\n";
  for (int i = 0; i < 35; ++i) {
    int size_of_stack = 0;
    int a = f.fibonacci_stack(i, size_of_stack);
    cout << "fibonacci_stack: f(" << i << ")= " << a << " Size of stack = " << size_of_stack << endl;
    int num_itr = 0;
    assert(a == f.fibonacci_iterative(i, num_itr));
    assert(a == f.fibonacci_recursion(i, num_itr));
  }
  cout << "Note that fibonacci_recursion sucks after 34\n";
}

/*----------------------------------------------------------------
test tower of hanoi
-----------------------------------------------------------------*/
void test_hanoi() {
  recursion f(verbose);
  cout << "-----------------------hanoi using recursion-----------------------\n";
  for (int i = 1; i < 5; ++i) {
    int num_itr = 0;
    str s;
    f.hanoi_recursion(i, num_itr, s);
    cout << s << "Number of itr = " << num_itr << endl;
  }

  cout << "-----------------------hanoi_using stack-----------------------\n";
  for (int i = 1; i < 10; ++i) {
    int size_of_stack = 0;
    str ss;
    f.hanoi_stack(i, size_of_stack, ss);
    cout << ss << "Size of stack = " << size_of_stack << endl;

    int num_itr = 0;
    str s;
    f.hanoi_recursion(i, num_itr, s);
    assert(ss == s);
  }
}
#if 0

/*--------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
//  test_factorial();
//  test_num_binary_digit();
//  test_fibonacci();
  test_hanoi();
  return 0;
}

//EOF



-----------------------Factorial using iteration-----------------------
factorial_iterative: f(0)= 1 Number of mult = 0
factorial_iterative: f(1)= 1 Number of mult = 0
factorial_iterative: f(2)= 2 Number of mult = 1
factorial_iterative: f(3)= 6 Number of mult = 2
factorial_iterative: f(4)= 24 Number of mult = 3
factorial_iterative: f(5)= 120 Number of mult = 4
factorial_iterative: f(6)= 720 Number of mult = 5
factorial_iterative: f(7)= 5040 Number of mult = 6
factorial_iterative: f(8)= 40320 Number of mult = 7
factorial_iterative: f(9)= 362880 Number of mult = 8
factorial_iterative: f(10)= 3628800 Number of mult = 9
factorial_iterative: f(11)= 39916800 Number of mult = 10
factorial_iterative: f(12)= 479001600 Number of mult = 11
factorial_iterative: f(13)= 6227020800 Number of mult = 12
factorial_iterative: f(14)= 87178291200 Number of mult = 13
factorial_iterative: f(15)= 1307674368000 Number of mult = 14
factorial_iterative: f(16)= 20922789888000 Number of mult = 15
factorial_iterative: f(17)= 355687428096000 Number of mult = 16
factorial_iterative: f(18)= 6402373705728000 Number of mult = 17
factorial_iterative: f(19)= 121645100408832000 Number of mult = 18
factorial_iterative: f(20)= 2432902008176640000 Number of mult = 19
factorial_iterative: f(21)= -4249290049419214848 Number of mult = 20
factorial_iterative: f(22)= -1250660718674968576 Number of mult = 21
factorial_iterative: f(23)= 8128291617894825984 Number of mult = 22
factorial_iterative: f(24)= -7835185981329244160 Number of mult = 23
factorial_iterative: f(25)= 7034535277573963776 Number of mult = 24
factorial_iterative: f(26)= -1569523520172457984 Number of mult = 25
factorial_iterative: f(27)= -5483646897237262336 Number of mult = 26
factorial_iterative: f(28)= -5968160532966932480 Number of mult = 27
factorial_iterative: f(29)= -7055958792655077376 Number of mult = 28
-----------------------Factorial using recursion-----------------------
factorial_recursion: f(0)= 1 Number of recursion = 1
factorial_recursion: f(1)= 1 Number of recursion = 1
factorial_recursion: f(2)= 2 Number of recursion = 2
factorial_recursion: f(3)= 6 Number of recursion = 3
factorial_recursion: f(4)= 24 Number of recursion = 4
factorial_recursion: f(5)= 120 Number of recursion = 5
factorial_recursion: f(6)= 720 Number of recursion = 6
factorial_recursion: f(7)= 5040 Number of recursion = 7
factorial_recursion: f(8)= 40320 Number of recursion = 8
factorial_recursion: f(9)= 362880 Number of recursion = 9
factorial_recursion: f(10)= 3628800 Number of recursion = 10
factorial_recursion: f(11)= 39916800 Number of recursion = 11
factorial_recursion: f(12)= 479001600 Number of recursion = 12
factorial_recursion: f(13)= 6227020800 Number of recursion = 13
factorial_recursion: f(14)= 87178291200 Number of recursion = 14
factorial_recursion: f(15)= 1307674368000 Number of recursion = 15
factorial_recursion: f(16)= 20922789888000 Number of recursion = 16
factorial_recursion: f(17)= 355687428096000 Number of recursion = 17
factorial_recursion: f(18)= 6402373705728000 Number of recursion = 18
factorial_recursion: f(19)= 121645100408832000 Number of recursion = 19
factorial_recursion: f(20)= 2432902008176640000 Number of recursion = 20
factorial_recursion: f(21)= -4249290049419214848 Number of recursion = 21
factorial_recursion: f(22)= -1250660718674968576 Number of recursion = 22
factorial_recursion: f(23)= 8128291617894825984 Number of recursion = 23
factorial_recursion: f(24)= -7835185981329244160 Number of recursion = 24
factorial_recursion: f(25)= 7034535277573963776 Number of recursion = 25
factorial_recursion: f(26)= -1569523520172457984 Number of recursion = 26
factorial_recursion: f(27)= -5483646897237262336 Number of recursion = 27
factorial_recursion: f(28)= -5968160532966932480 Number of recursion = 28
factorial_recursion: f(29)= -7055958792655077376 Number of recursion = 29
-----------------------Factorial using stack-----------------------
factorial_stack: f(0)= 1 Size of stack = 0
factorial_stack: f(1)= 1 Size of stack = 1
factorial_stack: f(2)= 2 Size of stack = 2
factorial_stack: f(3)= 6 Size of stack = 3
factorial_stack: f(4)= 24 Size of stack = 4
factorial_stack: f(5)= 120 Size of stack = 5
factorial_stack: f(6)= 720 Size of stack = 6
factorial_stack: f(7)= 5040 Size of stack = 7
factorial_stack: f(8)= 40320 Size of stack = 8
factorial_stack: f(9)= 362880 Size of stack = 9
factorial_stack: f(10)= 3628800 Size of stack = 10
factorial_stack: f(11)= 39916800 Size of stack = 11
factorial_stack: f(12)= 479001600 Size of stack = 12
factorial_stack: f(13)= 6227020800 Size of stack = 13
factorial_stack: f(14)= 87178291200 Size of stack = 14
factorial_stack: f(15)= 1307674368000 Size of stack = 15
factorial_stack: f(16)= 20922789888000 Size of stack = 16
factorial_stack: f(17)= 355687428096000 Size of stack = 17
factorial_stack: f(18)= 6402373705728000 Size of stack = 18
factorial_stack: f(19)= 121645100408832000 Size of stack = 19
factorial_stack: f(20)= 2432902008176640000 Size of stack = 20
factorial_stack: f(21)= -4249290049419214848 Size of stack = 21
factorial_stack: f(22)= -1250660718674968576 Size of stack = 22
factorial_stack: f(23)= 8128291617894825984 Size of stack = 23
factorial_stack: f(24)= -7835185981329244160 Size of stack = 24
factorial_stack: f(25)= 7034535277573963776 Size of stack = 25
factorial_stack: f(26)= -1569523520172457984 Size of stack = 26
factorial_stack: f(27)= -5483646897237262336 Size of stack = 27
factorial_stack: f(28)= -5968160532966932480 Size of stack = 28
factorial_stack: f(29)= -7055958792655077376 Size of stack = 29
-----------------------num_binary_digits using iteration-----------------------
num_binary_digits_iterative: f(0)= 1 Number of itr = 1
num_binary_digits_iterative: f(1)= 1 Number of itr = 1
num_binary_digits_iterative: f(2)= 2 Number of itr = 2
num_binary_digits_iterative: f(3)= 2 Number of itr = 2
num_binary_digits_iterative: f(4)= 3 Number of itr = 3
num_binary_digits_iterative: f(5)= 3 Number of itr = 3
num_binary_digits_iterative: f(6)= 3 Number of itr = 3
num_binary_digits_iterative: f(7)= 3 Number of itr = 3
num_binary_digits_iterative: f(8)= 4 Number of itr = 4
num_binary_digits_iterative: f(9)= 4 Number of itr = 4
num_binary_digits_iterative: f(10)= 4 Number of itr = 4
num_binary_digits_iterative: f(11)= 4 Number of itr = 4
num_binary_digits_iterative: f(12)= 4 Number of itr = 4
num_binary_digits_iterative: f(13)= 4 Number of itr = 4
num_binary_digits_iterative: f(14)= 4 Number of itr = 4
num_binary_digits_iterative: f(15)= 4 Number of itr = 4
num_binary_digits_iterative: f(16)= 5 Number of itr = 5
num_binary_digits_iterative: f(17)= 5 Number of itr = 5
num_binary_digits_iterative: f(18)= 5 Number of itr = 5
num_binary_digits_iterative: f(19)= 5 Number of itr = 5
num_binary_digits_iterative: f(20)= 5 Number of itr = 5
num_binary_digits_iterative: f(21)= 5 Number of itr = 5
num_binary_digits_iterative: f(22)= 5 Number of itr = 5
num_binary_digits_iterative: f(23)= 5 Number of itr = 5
num_binary_digits_iterative: f(24)= 5 Number of itr = 5
num_binary_digits_iterative: f(25)= 5 Number of itr = 5
num_binary_digits_iterative: f(26)= 5 Number of itr = 5
num_binary_digits_iterative: f(27)= 5 Number of itr = 5
num_binary_digits_iterative: f(28)= 5 Number of itr = 5
num_binary_digits_iterative: f(29)= 5 Number of itr = 5
-----------------------num_binary_digits using recursion-----------------------
num_binary_digits_recursion: f(0)= 1 Number of recursion = 1
num_binary_digits_recursion: f(1)= 1 Number of recursion = 1
num_binary_digits_recursion: f(2)= 2 Number of recursion = 2
num_binary_digits_recursion: f(3)= 2 Number of recursion = 2
num_binary_digits_recursion: f(4)= 3 Number of recursion = 3
num_binary_digits_recursion: f(5)= 3 Number of recursion = 3
num_binary_digits_recursion: f(6)= 3 Number of recursion = 3
num_binary_digits_recursion: f(7)= 3 Number of recursion = 3
num_binary_digits_recursion: f(8)= 4 Number of recursion = 4
num_binary_digits_recursion: f(9)= 4 Number of recursion = 4
num_binary_digits_recursion: f(10)= 4 Number of recursion = 4
num_binary_digits_recursion: f(11)= 4 Number of recursion = 4
num_binary_digits_recursion: f(12)= 4 Number of recursion = 4
num_binary_digits_recursion: f(13)= 4 Number of recursion = 4
num_binary_digits_recursion: f(14)= 4 Number of recursion = 4
num_binary_digits_recursion: f(15)= 4 Number of recursion = 4
num_binary_digits_recursion: f(16)= 5 Number of recursion = 5
num_binary_digits_recursion: f(17)= 5 Number of recursion = 5
num_binary_digits_recursion: f(18)= 5 Number of recursion = 5
num_binary_digits_recursion: f(19)= 5 Number of recursion = 5
num_binary_digits_recursion: f(20)= 5 Number of recursion = 5
num_binary_digits_recursion: f(21)= 5 Number of recursion = 5
num_binary_digits_recursion: f(22)= 5 Number of recursion = 5
num_binary_digits_recursion: f(23)= 5 Number of recursion = 5
num_binary_digits_recursion: f(24)= 5 Number of recursion = 5
num_binary_digits_recursion: f(25)= 5 Number of recursion = 5
num_binary_digits_recursion: f(26)= 5 Number of recursion = 5
num_binary_digits_recursion: f(27)= 5 Number of recursion = 5
num_binary_digits_recursion: f(28)= 5 Number of recursion = 5
num_binary_digits_recursion: f(29)= 5 Number of recursion = 5
-----------------------num_binary_digits_using stack-----------------------
num_binary_digits_stack: f(0)= 1 Size of stack = 1
num_binary_digits_stack: f(1)= 1 Size of stack = 2
num_binary_digits_stack: f(2)= 2 Size of stack = 3
num_binary_digits_stack: f(3)= 2 Size of stack = 3
num_binary_digits_stack: f(4)= 3 Size of stack = 4
num_binary_digits_stack: f(5)= 3 Size of stack = 4
num_binary_digits_stack: f(6)= 3 Size of stack = 4
num_binary_digits_stack: f(7)= 3 Size of stack = 4
num_binary_digits_stack: f(8)= 4 Size of stack = 5
num_binary_digits_stack: f(9)= 4 Size of stack = 5
num_binary_digits_stack: f(10)= 4 Size of stack = 5
num_binary_digits_stack: f(11)= 4 Size of stack = 5
num_binary_digits_stack: f(12)= 4 Size of stack = 5
num_binary_digits_stack: f(13)= 4 Size of stack = 5
num_binary_digits_stack: f(14)= 4 Size of stack = 5
num_binary_digits_stack: f(15)= 4 Size of stack = 5
num_binary_digits_stack: f(16)= 5 Size of stack = 6
num_binary_digits_stack: f(17)= 5 Size of stack = 6
num_binary_digits_stack: f(18)= 5 Size of stack = 6
num_binary_digits_stack: f(19)= 5 Size of stack = 6
num_binary_digits_stack: f(20)= 5 Size of stack = 6
num_binary_digits_stack: f(21)= 5 Size of stack = 6
num_binary_digits_stack: f(22)= 5 Size of stack = 6
num_binary_digits_stack: f(23)= 5 Size of stack = 6
num_binary_digits_stack: f(24)= 5 Size of stack = 6
num_binary_digits_stack: f(25)= 5 Size of stack = 6
num_binary_digits_stack: f(26)= 5 Size of stack = 6
num_binary_digits_stack: f(27)= 5 Size of stack = 6
num_binary_digits_stack: f(28)= 5 Size of stack = 6
num_binary_digits_stack: f(29)= 5 Size of stack = 6
-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------
num_binary_digits_stack: f(0)= 1 Size of stack = 1
num_binary_digits_stack: f(10000)= 14 Size of stack = 15
num_binary_digits_stack: f(20000)= 15 Size of stack = 16
num_binary_digits_stack: f(30000)= 15 Size of stack = 16
num_binary_digits_stack: f(40000)= 16 Size of stack = 17
num_binary_digits_stack: f(50000)= 16 Size of stack = 17
num_binary_digits_stack: f(60000)= 16 Size of stack = 17
num_binary_digits_stack: f(70000)= 17 Size of stack = 18
num_binary_digits_stack: f(80000)= 17 Size of stack = 18
num_binary_digits_stack: f(90000)= 17 Size of stack = 18
num_binary_digits_stack: f(100000)= 17 Size of stack = 18
num_binary_digits_stack: f(110000)= 17 Size of stack = 18
num_binary_digits_stack: f(120000)= 17 Size of stack = 18
num_binary_digits_stack: f(130000)= 17 Size of stack = 18
num_binary_digits_stack: f(140000)= 18 Size of stack = 19
num_binary_digits_stack: f(150000)= 18 Size of stack = 19
num_binary_digits_stack: f(160000)= 18 Size of stack = 19
num_binary_digits_stack: f(170000)= 18 Size of stack = 19
num_binary_digits_stack: f(180000)= 18 Size of stack = 19
num_binary_digits_stack: f(190000)= 18 Size of stack = 19
num_binary_digits_stack: f(200000)= 18 Size of stack = 19
num_binary_digits_stack: f(210000)= 18 Size of stack = 19
num_binary_digits_stack: f(220000)= 18 Size of stack = 19
num_binary_digits_stack: f(230000)= 18 Size of stack = 19
num_binary_digits_stack: f(240000)= 18 Size of stack = 19
num_binary_digits_stack: f(250000)= 18 Size of stack = 19
num_binary_digits_stack: f(260000)= 18 Size of stack = 19
num_binary_digits_stack: f(270000)= 19 Size of stack = 20
num_binary_digits_stack: f(280000)= 19 Size of stack = 20
num_binary_digits_stack: f(290000)= 19 Size of stack = 20
-----------------------fibonacci using iteration-----------------------
fibonacci_iterative: f(0)= 0 Number of itr = 0
fibonacci_iterative: f(1)= 1 Number of itr = 0
fibonacci_iterative: f(2)= 1 Number of itr = 2
fibonacci_iterative: f(3)= 2 Number of itr = 3
fibonacci_iterative: f(4)= 3 Number of itr = 4
fibonacci_iterative: f(5)= 5 Number of itr = 5
fibonacci_iterative: f(6)= 8 Number of itr = 6
fibonacci_iterative: f(7)= 13 Number of itr = 7
fibonacci_iterative: f(8)= 21 Number of itr = 8
fibonacci_iterative: f(9)= 34 Number of itr = 9
fibonacci_iterative: f(10)= 55 Number of itr = 10
fibonacci_iterative: f(11)= 89 Number of itr = 11
fibonacci_iterative: f(12)= 144 Number of itr = 12
fibonacci_iterative: f(13)= 233 Number of itr = 13
fibonacci_iterative: f(14)= 377 Number of itr = 14
fibonacci_iterative: f(15)= 610 Number of itr = 15
fibonacci_iterative: f(16)= 987 Number of itr = 16
fibonacci_iterative: f(17)= 1597 Number of itr = 17
fibonacci_iterative: f(18)= 2584 Number of itr = 18
fibonacci_iterative: f(19)= 4181 Number of itr = 19
fibonacci_iterative: f(20)= 6765 Number of itr = 20
fibonacci_iterative: f(21)= 10946 Number of itr = 21
fibonacci_iterative: f(22)= 17711 Number of itr = 22
fibonacci_iterative: f(23)= 28657 Number of itr = 23
fibonacci_iterative: f(24)= 46368 Number of itr = 24
fibonacci_iterative: f(25)= 75025 Number of itr = 25
fibonacci_iterative: f(26)= 121393 Number of itr = 26
fibonacci_iterative: f(27)= 196418 Number of itr = 27
fibonacci_iterative: f(28)= 317811 Number of itr = 28
fibonacci_iterative: f(29)= 514229 Number of itr = 29
-----------------------fibonacci using recursion-----------------------
fibonacci_recursion: f(0)= 0 Number of recursion = 1
fibonacci_recursion: f(1)= 1 Number of recursion = 1
fibonacci_recursion: f(2)= 1 Number of recursion = 3
fibonacci_recursion: f(3)= 2 Number of recursion = 5
fibonacci_recursion: f(4)= 3 Number of recursion = 9
fibonacci_recursion: f(5)= 5 Number of recursion = 15
fibonacci_recursion: f(6)= 8 Number of recursion = 25
fibonacci_recursion: f(7)= 13 Number of recursion = 41
fibonacci_recursion: f(8)= 21 Number of recursion = 67
fibonacci_recursion: f(9)= 34 Number of recursion = 109
fibonacci_recursion: f(10)= 55 Number of recursion = 177
fibonacci_recursion: f(11)= 89 Number of recursion = 287
fibonacci_recursion: f(12)= 144 Number of recursion = 465
fibonacci_recursion: f(13)= 233 Number of recursion = 753
fibonacci_recursion: f(14)= 377 Number of recursion = 1219
fibonacci_recursion: f(15)= 610 Number of recursion = 1973
fibonacci_recursion: f(16)= 987 Number of recursion = 3193
fibonacci_recursion: f(17)= 1597 Number of recursion = 5167
fibonacci_recursion: f(18)= 2584 Number of recursion = 8361
fibonacci_recursion: f(19)= 4181 Number of recursion = 13529
fibonacci_recursion: f(20)= 6765 Number of recursion = 21891
fibonacci_recursion: f(21)= 10946 Number of recursion = 35421
fibonacci_recursion: f(22)= 17711 Number of recursion = 57313
fibonacci_recursion: f(23)= 28657 Number of recursion = 92735
fibonacci_recursion: f(24)= 46368 Number of recursion = 150049
fibonacci_recursion: f(25)= 75025 Number of recursion = 242785
fibonacci_recursion: f(26)= 121393 Number of recursion = 392835
fibonacci_recursion: f(27)= 196418 Number of recursion = 635621
fibonacci_recursion: f(28)= 317811 Number of recursion = 1028457
fibonacci_recursion: f(29)= 514229 Number of recursion = 1664079
-----------------------fibonacci_using stack-----------------------
fibonacci_stack: f(0)= 0 Size of stack = 0
fibonacci_stack: f(1)= 1 Size of stack = 0
fibonacci_stack: f(2)= 1 Size of stack = 1
fibonacci_stack: f(3)= 2 Size of stack = 2
fibonacci_stack: f(4)= 3 Size of stack = 3
fibonacci_stack: f(5)= 5 Size of stack = 4
fibonacci_stack: f(6)= 8 Size of stack = 5
fibonacci_stack: f(7)= 13 Size of stack = 6
fibonacci_stack: f(8)= 21 Size of stack = 7
fibonacci_stack: f(9)= 34 Size of stack = 8
fibonacci_stack: f(10)= 55 Size of stack = 9
fibonacci_stack: f(11)= 89 Size of stack = 10
fibonacci_stack: f(12)= 144 Size of stack = 11
fibonacci_stack: f(13)= 233 Size of stack = 12
fibonacci_stack: f(14)= 377 Size of stack = 13
fibonacci_stack: f(15)= 610 Size of stack = 14
fibonacci_stack: f(16)= 987 Size of stack = 15
fibonacci_stack: f(17)= 1597 Size of stack = 16
fibonacci_stack: f(18)= 2584 Size of stack = 17
fibonacci_stack: f(19)= 4181 Size of stack = 18
fibonacci_stack: f(20)= 6765 Size of stack = 19
fibonacci_stack: f(21)= 10946 Size of stack = 20
fibonacci_stack: f(22)= 17711 Size of stack = 21
fibonacci_stack: f(23)= 28657 Size of stack = 22
fibonacci_stack: f(24)= 46368 Size of stack = 23
fibonacci_stack: f(25)= 75025 Size of stack = 24
fibonacci_stack: f(26)= 121393 Size of stack = 25
fibonacci_stack: f(27)= 196418 Size of stack = 26
fibonacci_stack: f(28)= 317811 Size of stack = 27
fibonacci_stack: f(29)= 514229 Size of stack = 28
-----------------------num_binary_digits_using stack TEST FOR 300000-----------------------
fibonacci_stack: f(0)= 0 Size of stack = 0
fibonacci_stack: f(1)= 1 Size of stack = 0
fibonacci_stack: f(2)= 1 Size of stack = 1
fibonacci_stack: f(3)= 2 Size of stack = 2
fibonacci_stack: f(4)= 3 Size of stack = 3
fibonacci_stack: f(5)= 5 Size of stack = 4
fibonacci_stack: f(6)= 8 Size of stack = 5
fibonacci_stack: f(7)= 13 Size of stack = 6
fibonacci_stack: f(8)= 21 Size of stack = 7
fibonacci_stack: f(9)= 34 Size of stack = 8
fibonacci_stack: f(10)= 55 Size of stack = 9
fibonacci_stack: f(11)= 89 Size of stack = 10
fibonacci_stack: f(12)= 144 Size of stack = 11
fibonacci_stack: f(13)= 233 Size of stack = 12
fibonacci_stack: f(14)= 377 Size of stack = 13
fibonacci_stack: f(15)= 610 Size of stack = 14
fibonacci_stack: f(16)= 987 Size of stack = 15
fibonacci_stack: f(17)= 1597 Size of stack = 16
fibonacci_stack: f(18)= 2584 Size of stack = 17
fibonacci_stack: f(19)= 4181 Size of stack = 18
fibonacci_stack: f(20)= 6765 Size of stack = 19
fibonacci_stack: f(21)= 10946 Size of stack = 20
fibonacci_stack: f(22)= 17711 Size of stack = 21
fibonacci_stack: f(23)= 28657 Size of stack = 22
fibonacci_stack: f(24)= 46368 Size of stack = 23
fibonacci_stack: f(25)= 75025 Size of stack = 24
fibonacci_stack: f(26)= 121393 Size of stack = 25
fibonacci_stack: f(27)= 196418 Size of stack = 26
fibonacci_stack: f(28)= 317811 Size of stack = 27
fibonacci_stack: f(29)= 514229 Size of stack = 28
fibonacci_stack: f(30)= 832040 Size of stack = 29
fibonacci_stack: f(31)= 1346269 Size of stack = 30
fibonacci_stack: f(32)= 2178309 Size of stack = 31
fibonacci_stack: f(33)= 3524578 Size of stack = 32
fibonacci_stack: f(34)= 5702887 Size of stack = 33
Note that fibonacci_recursion sucks after 34
-----------------------hanoi using recursion-----------------------

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from Number of itr = 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from Number of itr = 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from Number of itr = 7

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from Number of itr = 15
-----------------------hanoi_using stack-----------------------

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 4

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 10

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 22

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 46

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 94

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 190

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 382

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 766

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from Size of stack = 1534

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 3 to 2

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 2 to 1

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 3 to 1

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
moving disk from 1 to 2

in darray 2 constructor:
In darray Destructor
moving disk from 3 to 2
moving disk from 1 to 3

in darray 2 constructor:
In darray Destructor

in darray 2 constructor:
In darray Destructor
moving disk from 2 to 1
moving disk from 2 to 3

in darray 2 constructor:
In darray Destructor
moving disk from 1 to 3
Program ended with exit code: 0

#endif
