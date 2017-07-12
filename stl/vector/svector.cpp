/*----------------------------------------------------------------
Copyright (c) 2010 Author: Jagadeesh Vasudevamurthy
Filename: svector.cpp
compile: g++ svector.cpp
Memory leaked: 0 bytes (0%); potentially leaked: 0 bytes (0%)
-----------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <stdexcept> //Without this catch will NOT work on Linux

#ifdef _WIN32 //Will not work in windows7 if U write WIN32
#include "..\..\c\complex.h"
#else
#include "../../c/complex.h"
#endif

using namespace std;

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
bool complex::_display = true ;

/*----------------------------------------------------------------
Multiply integer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(int& x){
  x = x * 10 ;
}

/*----------------------------------------------------------------
apply a function pf on elements of vector a
-----------------------------------------------------------------*/
template <typename T>
static void apply(const char* s, vector<T>& a, void(*pf)(T& x) ) {
  cout << s << endl ;
  cout << "-----------------" << endl ;
  typename vector<T>::iterator itt = a.begin(); //Note typename here.
  //WILL NOT COMPILE IN LINUX without typename but works on Visual studio
  while (itt != a.end()) {
    T& p = *itt ;
    pf(p) ;
    itt++ ;
  }
  cout << endl ;
}

/*----------------------------------------------------------------
a[0] ..... a[9]

begin() will point to a[0]
end() will NOT POINT to a[9], but to one element past a[9]
That means real end is: end()-1 ;
-----------------------------------------------------------------*/
static void understanding_iterator(vector<int>& a) {
  {
    cout << "Understanding forward traversal" << endl ;
    vector<int>::iterator itt = a.begin() ;
    while (itt != a.end()) {
      cout<< *itt << " "  ;
      itt++ ;
    }
    cout << endl ;
  }
  {
    cout << "Understanding reverse traversal" << endl ;
    vector<int>::iterator itt = a.end() ;
    //cout << *itt << endl ; ----------- CORE DUMPS
    while (itt != a.begin()) {
      itt-- ; //decrement iterator before using
      cout<< *itt << " "  ;
    }
    cout << endl ;
  }
  cout << "-----------------" << endl ;
}

/*----------------------------------------------------------------
Understanding access using 
1. a[i]
2. a.at(i)  -- Same as a[i], but does out of bound checks
and throws exception that you can catch

-----------------------------------------------------------------*/
template <typename T>
static void understanding_access(const vector<T>& a, int i) {
  //int p = a[i] ; //core dumps
  try {
    int p = a.at(i) ; //Throws exception. out of bound checks

  }catch(std::out_of_range) {
    cout << " accessing a[" << i << "] but size of array is " << a.size() << endl ;
  }
  cout << "-----------------" << endl ;
}

/*----------------------------------------------------------------
print1
-----------------------------------------------------------------*/
template <typename T>
static void print1(const char* s, const vector<T>& a) {
  cout << s << endl ;
  cout << "-----------------" << endl ;
  cout << "size = " << a.size() << " " ;
  cout << "capacity = " << a.capacity() << " " ;
  cout << endl ;
  for (int i = 0; i < int(a.size()); i++) {
    cout << "a[" << i << "] = " << a[i] << " " ;
  }
  cout << endl ;
  cout << "-----------------" << endl ;
}

/*----------------------------------------------------------------
basic
-----------------------------------------------------------------*/
static void basic() {
  vector<int> a ;
  print1("begin with",a) ;
  for (int i = 0; i < 5; i++){
    a.push_back(i) ;
  }
  print1("After Inserting 5 elements",a) ;
  understanding_iterator(a) ;

  understanding_access(a,6);

  a.pop_back() ;
  a.pop_back() ;
  print1("After deleting last 2 elements",a) ;

  apply("multiply by 10",a,multiply_by_10) ;
  cout << endl ;
  apply("print using iterator",a,print_integer) ;
  cout << endl ;

  a.clear() ;
  print1("Using clear",a) ;
}

/*----------------------------------------------------------------
questions
-----------------------------------------------------------------*/
static void questions() {
  vector<int> a(10,-1) ;
  print1("Is it -1",a) ;
  cout << "I am reading without assigning a[5] =  " << a[5] << endl ;

  complex c(99,-420) ;
  vector<complex> b(6,c) ;
  print1("Is it 99,-420",b) ;
  cout << "I am reading without assigning b[5] =  " << b[5] << endl ;

  //cout << b[7] << endl ; -- Crashes because you need to push_back before U access
}

/*----------------------------------------------------------------
problem 

MORAL: DO NOT STORE ALIAS TO THE CONTAINER OBJECT
-----------------------------------------------------------------*/
static void problem() {
  vector<complex> vc ;
  print1("begin with ",vc) ;
  vc.push_back(0) ;
  vc.push_back(1) ;
  vc.push_back(2) ;

  print1("After Inserting 0, 1 and 2 ",vc) ;

  complex& c1 = vc[1] ;
  cout << " c1 = " << c1 << endl ;

  for (int i = 3 ; i < 10; ++i) {
    vc.push_back(i) ;
  }
  print1("After Inserting  3 to 10 " ,vc) ;

  //WHAT HAPPENS HERE ?????????????
  //cout << " c1 = " << c1 << endl ; 
}

/*----------------------------------------------------------------
array of integer pointers
-----------------------------------------------------------------*/
static void test_vector_of_ptr_integers(int n){
  vector<int*> a ;
  for (int i = 0; i < n; i++) {
    a.push_back(ALLOC(int)(i * 10)) ;
  }
  vector<int*> b(a) ;
  apply("Contents of vector b",b,print_integer) ;
  bool equal = true ;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false ;
      break ;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  //YOU CANNOT DO THIS with vector
  //cout << "We have not inserted 25th element. Let us see what we get " << endl ;
  //cout << a[25] << endl ;
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    FREE(a[i]) ;
  }
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  FREE(b[i]) ;
  }
  */
}

/*----------------------------------------------------------------
array of user defined type
-----------------------------------------------------------------*/
static void test_vector_of_udt(){
  const int N = 5 ;
  vector<complex> a(N) ;
  for (int i = 0; i < N; i++) {
    a[i].setxy(i,-i) ;
  }
  vector<complex> b(a) ;
  apply("Contents of vector b",b,print_complex) ;
  bool equal = true ;
  for (int i = 0; i < N; i++) {
    if (a[i] != b[i]) {
      equal = false ;
      break ;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  for (int i = 0; i < 3; i++) {
    complex c((i+100),-(i+100)) ;
    a.push_back(c) ;
  }
  apply("Contents of vector a",a,print_complex) ;		
}

/*----------------------------------------------------------------
array of user defined pointer type
-----------------------------------------------------------------*/
static void test_vector_of_ptr_udt(int n){
  vector<complex*> a ;
  for (int i = 0; i < n; i++) {
    a.push_back(ALLOC(complex)(i,-i)) ;
  }
  vector<complex*> b(a);
  apply("Contents of vector b",b,print_complex) ;
  bool equal = true ;
  for (int i = 0; i < n; i++) {
    if (*(a[i]) != *(b[i])) {
      equal = false ;
      break ;
    }
  }
  equal ? cout << " array a == b\n " : cout << " array a != b\n ";
  for (int i = 0; i < n; i++) {
    /* we allocated contents in a. So we delete it */
    FREE(a[i]) ;
  }
  /* Why you should NOT do this */
  /*
  for (int i = 0; i < n; i++) {
  FREE(b[i]) ;
  }
  */
}

/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  basic() ;
  questions() ;
  problem() ;
  test_vector_of_ptr_integers(5) ;
  test_vector_of_udt();
  test_vector_of_ptr_udt(5) ;
  return 1 ;
}

