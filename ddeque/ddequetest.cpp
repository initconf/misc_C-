///*----------------------------------------------------------------
//Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
//file: ../complex/complex.cpp ddequetest.cpp
//
//On linux:
//g++ ../complex/complex.cpp ddequetest.cpp
//valgrind a.out
//valgrind --leak-check=full -v a.out
//-- All heap blocks were freed -- no leaks are possible
//
//-----------------------------------------------------------------*/
//
///*----------------------------------------------------------------
//This file test ddeque object
//
//CANNOT CHANGE ANYTHING IN THIS FILE
//-----------------------------------------------------------------*/
//
///*----------------------------------------------------------------
//All includes here
//-----------------------------------------------------------------*/
#include "ddeque.h"
#include "../complex/complex.h"
#include <deque> //Gold STL deque

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = false;

/*----------------------------------------------------------------
Multiply integer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(int& x){
  x = x * 10;
}

/*----------------------------------------------------------------
Multiply integer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(int*& x){
  multiply_by_10(*x);
}

/*----------------------------------------------------------------
Multiply complex by 10
-----------------------------------------------------------------*/
static void multiply_by_10(complex& c){
  int x, y;
  c.getxy(x, y);
  x = x * 10;
  y = y * 10;
  c.setxy(x, y);
}

/*----------------------------------------------------------------
Multiply complex pointer by 10
-----------------------------------------------------------------*/
static void multiply_by_10(complex*& c){
  multiply_by_10(*c);
}

/*----------------------------------------------------------------
Print integer
-----------------------------------------------------------------*/
static void print_obj(int& x){
  cout << x << " ";
}

/*----------------------------------------------------------------
print pointer to integer
-----------------------------------------------------------------*/
static void print_obj(int*& x){
  print_obj(*x);
}

/*----------------------------------------------------------------
Print complex
-----------------------------------------------------------------*/
static void print_obj(complex& c){
  cout << c << " ";
}

/*----------------------------------------------------------------
Printcomplex pointer
-----------------------------------------------------------------*/
static void print_obj(complex*& c){
  print_obj(*c);
}


/*----------------------------------------------------------------
compare integer
-----------------------------------------------------------------*/
static bool compare(const int& x, const int& y){
  return (x == y);
}

/*----------------------------------------------------------------
compare integer pointer
-----------------------------------------------------------------*/
static bool compare(int* const& x, int* const& y){
  return compare(*x, *y);
}

/*----------------------------------------------------------------
compare complex
-----------------------------------------------------------------*/
static bool compare(const complex& x, const complex& y){
  return (x == y);
}

/*----------------------------------------------------------------
compare complex pointer
-----------------------------------------------------------------*/
static bool compare(complex* const& x, complex* const& y){
  return (*x == *y);
}



/*----------------------------------------------------------------
construct an integer object
-----------------------------------------------------------------*/
static void construct_an_integer_object(int x, int& o){
  o = x;
}

/*----------------------------------------------------------------
construct a integer* object
-----------------------------------------------------------------*/
static void construct_an_integer_star_object(int x, int*& o){
  o = new(int)(x);
}

/*----------------------------------------------------------------
construct a complex object
-----------------------------------------------------------------*/
static void construct_an_complex_object(int x, complex& o){
  o.setxy(x, -x);
}

/*----------------------------------------------------------------
construct a complex* object
-----------------------------------------------------------------*/
static void construct_an_complex_star_object(int x, complex*& o){
  o = new(complex)(x, -x);
}

/*----------------------------------------------------------------
delete an object
-----------------------------------------------------------------*/
template <typename T>
static void delete_obj(T& a) {
  delete(a);
}


/*----------------------------------------------------------------
swap
-----------------------------------------------------------------*/
template <typename T>
static void swap1(T& a, T& b) {
  T t = a;
  a = b;
  b = t;
}

///*----------------------------------------------------------------
//print1
//-----------------------------------------------------------------*/
template <typename T>
static void print1(const char* s, ddeque<T>& a, deque<T>& g, bool print = false) {
  cout << s << endl;
  cout << "-----------------" << endl;
    
    cout << "a.size is " << a.size() << endl ;
    
        cout << "g.size is " << g.size() << endl ;
  assert(a.size() == g.size());
  cout << "size = " << a.size() << " ";
  cout << endl;
  for (int i = 0; i < int(a.size()); i++) {
    assert(compare(a[i], g[i]));
    if (print) {
      cout << "a[" << i << "] = " << a[i] << " and ptr is: " << &a[i] << " and g[" << i << "] = " << g[i] << endl   ;
    }
  }
  if (print) {
    cout << endl;
    cout << "-----------------" << endl;
  }
}

//
///*----------------------------------------------------------------
//apply a function pf on elements of ddeque a
//-----------------------------------------------------------------*/
template <typename T>
static void apply(const char* s, ddeque<T>& a, deque<T>& g, void(*pf)(T& x)) {
  cout << s << endl;
  cout << "-----------------" << endl;
  typename ddeque<T>::iterator itt = a.begin(); //Note typename here.
  //WILL NOT COMPILE IN LINUX without typename but works on Visual studio
  //Hard to find this solution.
  typename deque<T>::iterator ittg = g.begin();
  while ((itt != a.end()) && (ittg != g.end())){
    T& p = *itt;
    T& pg = *ittg;
    assert(compare(p, pg));
    pf(p);
    pf(pg);
    ++itt;
    ++ittg;
  }
  cout << endl;
}
//
///*----------------------------------------------------------------
//a.front() -- Returns first element of the ddeque
//a.back()  -- Returns last  element of the ddeque
//a.push_front(v) -- v is inserted as the first element of the ddeque
//a.push_back(v) -- v is inserted as the back element of the ddeque
//a.pop_front() - First element of the ddeque is removed. Nothing is returned
//a.pop_back() - Last element of the ddeque is removed. Nothing is returned
//-----------------------------------------------------------------*/
template <typename T>
static void understanding_access(ddeque<T>& a, deque<T>& g, void(*pf)(int x, T& o)) {
  print1("begin with", a, g);
  const int MAX = 1000;
  Random r;
  for (int i = 0; i < MAX; i++){
    T o;
    T og;
    int y = i + 77;
    pf(y, o);
    pf(y, og);
    if (y % 2) {
      //Even number- Push in front
      a.push_back(o);
      g.push_back(og);
    } else {
      //Even number- Push in back
      a.push_front(o);
      g.push_front(og);
    }
  }
  print1("After insertiing 1000 elements", a, g);
  //shuffle now by MAX times

  for (int i = 0; i < MAX; i++){
    int x1 = i;
    int x2 = (7777 - i) % MAX;
    T& o1 = a[x1];
    T& o1g = g[x1];
    assert(compare(o1, o1g));
    T& o2 = a[x2];
    T& o2g = g[x2];
    assert(compare(o2, o2g));
    swap1(a[x1], a[x2]);
    swap1(g[x1], g[x2]);
    assert(compare(a[x1], g[x1]));
    assert(compare(a[x2], g[x2]));
  }
  print1("After Shuffle", a, g);
  T& y = a.front();
  T& yg = g.front();
    
    cout << " y is " <<  y << " yg is " << yg << endl ; 
  assert(compare(y, yg));
  
  T& z = a.back();
  T& zg = g.back();
  assert(compare(z, zg));
  cout << "The back of the ddeque has " << z << endl;

  print1("After front and back operation", a, g);

  int x = a.size() - 1;
  assert(compare(a[x], g[x]));
  cout << "Random access of a[" << x << "]= " << a[x] << endl;
}

///*----------------------------------------------------------------
//a[0] ..... a[9]
//
//begin() will point to a[0]
//end() will NOT POINT to a[9], but to one element past a[9]
//That means real end is: end()-1 ;
//-----------------------------------------------------------------*/
template <typename T>
static void understanding_iterator(ddeque<T>& a, deque<T>& g, bool display = true) {

//        {
//            cout << "Understanding forward traversal" << endl;
//            typename deque<T>::iterator ittg = g.begin();
//            while ( (ittg != g.end())) {
////                assert(compare(*(itt), *(ittg)));
//                if (display) {
//                    cout << *ittg << " ";
//                }
////                ++itt;
//                ++ittg;
//            }
//            if (display) {
//                cout << endl;
//            }
//        }
    
    
    
    {
        cout << "Understanding forward traversal" << endl;
        
        typename ddeque<T>::iterator itt = a.begin();
        typename deque<T>::iterator ittg = g.begin();
        
        while ((itt != a.end()) && (ittg != g.end())) {
            assert(compare(*(itt), *(ittg)));
            if (display) {
                cout << &*itt << " ";
            }
            ++itt;
            ++ittg;
        }
        if (display) {
            cout << endl;
        }
    }
    
    
    
  {
    cout << "Understanding reverse traversal" << endl;
    typename ddeque<T>::iterator itt = a.end();
    typename deque<T>::iterator ittg = g.end();
    //cout << *itt << endl ; ----------- CORE DUMPS
    while ((itt != a.begin()) && (ittg != g.begin())) {
      --itt; //decrement iterator before using
      --ittg;
      assert(compare(*(itt), *(ittg)));
      if (display) {
        cout << *itt << " ";
      }
    }
    if (display) {
      cout << endl;
    }
  }
  cout << "-----------------" << endl;
}
//
///*----------------------------------------------------------------
//delete until empty
//-----------------------------------------------------------------*/
template <typename T>
static void delete_until_empty(ddeque<T>& a, deque<T>& g, void(*df) (T& c)) {
  cout << "Before deleteing the queue\n";
  bool done = false;
  while (!done) {
    if (a.empty()) {
      assert(g.empty());
      done = true;

    }
    if (g.empty()) {
      assert(a.empty());
      done = true;
    }
    if (done) {
      break;
    } else {
      /* delete back */
      assert(a.size() == g.size());
      T& z = a.back();
      T& zg = g.back();
        
     
     cout << " Z: " << z << " zg: " << zg << endl ;
        
      assert(compare(z, zg));
      if (df) {
        df(z);
        df(zg);
      }
      a.pop_back();
      g.pop_back();
      assert(a.size() == g.size());
    }
    if (a.empty()) {
      assert(g.empty());
      done = true;

    }
    if (g.empty()) {
      assert(a.empty());
      done = true;
    }
    if (done) {
      break;
    } else {
      /* delete front */
      assert(a.size() == g.size());
      T& z = a.front();
      T& zg = g.front();
      assert(compare(z, zg));
      if (df) {
        df(z);
        df(zg);
      }
      a.pop_front();
      g.pop_front();
      assert(a.size() == g.size());
    }
  }
  cout << "Before deleteing the queue\n";
}
//
//
///*----------------------------------------------------------------
//test
//-----------------------------------------------------------------*/
template <typename T>
static void test(ddeque<T>& a, deque<T>& g, void(*pf)(int x, T& o), void(*df) (T& c)) {
  print1("begin with", a, g);
  understanding_access(a, g, pf);
  understanding_iterator(a, g);
  apply("multiply by 10", a, g, multiply_by_10);
  cout << endl;
  apply("print using iterator after multiplying by 10", a, g, print_obj);
  cout << endl;
  delete_until_empty(a, g, df);
}


#if 0


//
//
///*----------------------------------------------------------------
//main
//-----------------------------------------------------------------*/
int main() {
  complex::set_display(verbose);
  {
    ddeque<complex> a;
    a.push_back(complex(7, -8));
  }
  {
    //TEST INTEGER
    ddeque<int> a;
    deque<int>  g; //Gold
    test<int>(a, g, construct_an_integer_object, nullptr);
  }
  {
    //TEST pointer to INTEGER
    ddeque<int*> a;
    deque<int*>  g; //Gold
    test<int*>(a, g, construct_an_integer_star_object, delete_obj);
  }
  {
    //TEST complex
    ddeque<complex> a;
    deque<complex>  g; //Gold
    test<complex>(a, g, construct_an_complex_object, nullptr);
  }
  {
    //TEST pointer to complex

    ddeque<complex*> a;
    deque<complex*>  g; //Gold
    test<complex*>(a, g, construct_an_complex_star_object, delete_obj);
  }
  return 1;
}
//


Inside ddeque constructor
inside ddeque destructor
Inside ddeque constructor
begin with
-----------------
a.size is 0
g.size is 0
size = 0
begin with
-----------------
a.size is 0
g.size is 0
size = 0
After insertiing 1000 elements
-----------------
a.size is 1000
g.size is 1000
size = 1000
After Shuffle
-----------------
a.size is 1000
g.size is 1000
size = 1000
y is 1076 yg is 1076
The back of the ddeque has 1075
After front and back operation
-----------------
a.size is 1000
g.size is 1000
size = 1000
Random access of a[999]= 1075
Understanding forward traversal

Understanding reverse traversal

-----------------
multiply by 10
-----------------


print using iterator after multiplying by 10
-----------------


Before deleteing the queue
Z: 1075 zg: 1075
Z: 1073 zg: 1073
Z: 1071 zg: 1071
Z: 1069 zg: 1069
Z: 1067 zg: 1067
Z: 1065 zg: 1065
Z: 1063 zg: 1063
Z: 1061 zg: 1061
Z: 1059 zg: 1059
Z: 1057 zg: 1057
Z: 1055 zg: 1055
Z: 1053 zg: 1053
Z: 1051 zg: 1051
Z: 1049 zg: 1049
Z: 1047 zg: 1047
Z: 1045 zg: 1045
Z: 1043 zg: 1043
Z: 1041 zg: 1041
Z: 1039 zg: 1039
Z: 1037 zg: 1037
Z: 1035 zg: 1035
Z: 1033 zg: 1033
Z: 1031 zg: 1031
Z: 1029 zg: 1029
Z: 1027 zg: 1027
Z: 1025 zg: 1025
Z: 1023 zg: 1023
Z: 1021 zg: 1021
Z: 1019 zg: 1019
Z: 1017 zg: 1017
Z: 1015 zg: 1015
Z: 1013 zg: 1013
Z: 1011 zg: 1011
Z: 1009 zg: 1009
Z: 1007 zg: 1007
Z: 1005 zg: 1005
Z: 1003 zg: 1003
Z: 1001 zg: 1001
Z: 999 zg: 999
Z: 997 zg: 997
Z: 995 zg: 995
Z: 993 zg: 993
Z: 991 zg: 991
Z: 989 zg: 989
Z: 987 zg: 987
Z: 985 zg: 985
Z: 983 zg: 983
Z: 981 zg: 981
Z: 979 zg: 979
Z: 977 zg: 977
Z: 975 zg: 975
Z: 973 zg: 973
Z: 971 zg: 971
Z: 969 zg: 969
Z: 967 zg: 967
Z: 965 zg: 965
Z: 963 zg: 963
Z: 961 zg: 961
Z: 959 zg: 959
Z: 957 zg: 957
Z: 955 zg: 955
Z: 953 zg: 953
Z: 951 zg: 951
Z: 949 zg: 949
Z: 947 zg: 947
Z: 945 zg: 945
Z: 943 zg: 943
Z: 941 zg: 941
Z: 939 zg: 939
Z: 937 zg: 937
Z: 935 zg: 935
Z: 933 zg: 933
Z: 931 zg: 931
Z: 929 zg: 929
Z: 927 zg: 927
Z: 925 zg: 925
Z: 923 zg: 923
Z: 921 zg: 921
Z: 919 zg: 919
Z: 917 zg: 917
Z: 915 zg: 915
Z: 913 zg: 913
Z: 911 zg: 911
Z: 909 zg: 909
Z: 907 zg: 907
Z: 905 zg: 905
Z: 903 zg: 903
Z: 901 zg: 901
Z: 899 zg: 899
Z: 897 zg: 897
Z: 895 zg: 895
Z: 893 zg: 893
Z: 891 zg: 891
Z: 889 zg: 889
Z: 887 zg: 887
Z: 885 zg: 885
Z: 883 zg: 883
Z: 881 zg: 881
Z: 879 zg: 879
Z: 877 zg: 877
Z: 875 zg: 875
Z: 873 zg: 873
Z: 871 zg: 871
Z: 869 zg: 869
Z: 867 zg: 867
Z: 865 zg: 865
Z: 863 zg: 863
Z: 861 zg: 861
Z: 859 zg: 859
Z: 857 zg: 857
Z: 855 zg: 855
Z: 853 zg: 853
Z: 851 zg: 851
Z: 849 zg: 849
Z: 847 zg: 847
Z: 845 zg: 845
Z: 843 zg: 843
Z: 841 zg: 841
Z: 839 zg: 839
Z: 837 zg: 837
Z: 835 zg: 835
Z: 833 zg: 833
Z: 831 zg: 831
Z: 829 zg: 829
Z: 827 zg: 827
Z: 825 zg: 825
Z: 823 zg: 823
Z: 821 zg: 821
Z: 819 zg: 819
Z: 817 zg: 817
Z: 815 zg: 815
Z: 813 zg: 813
Z: 811 zg: 811
Z: 809 zg: 809
Z: 807 zg: 807
Z: 805 zg: 805
Z: 803 zg: 803
Z: 801 zg: 801
Z: 799 zg: 799
Z: 797 zg: 797
Z: 795 zg: 795
Z: 793 zg: 793
Z: 791 zg: 791
Z: 789 zg: 789
Z: 787 zg: 787
Z: 785 zg: 785
Z: 783 zg: 783
Z: 781 zg: 781
Z: 779 zg: 779
Z: 777 zg: 777
Z: 775 zg: 775
Z: 773 zg: 773
Z: 771 zg: 771
Z: 769 zg: 769
Z: 767 zg: 767
Z: 765 zg: 765
Z: 763 zg: 763
Z: 761 zg: 761
Z: 759 zg: 759
Z: 757 zg: 757
Z: 755 zg: 755
Z: 753 zg: 753
Z: 751 zg: 751
Z: 749 zg: 749
Z: 747 zg: 747
Z: 745 zg: 745
Z: 743 zg: 743
Z: 741 zg: 741
Z: 739 zg: 739
Z: 737 zg: 737
Z: 735 zg: 735
Z: 733 zg: 733
Z: 731 zg: 731
Z: 729 zg: 729
Z: 727 zg: 727
Z: 725 zg: 725
Z: 723 zg: 723
Z: 721 zg: 721
Z: 719 zg: 719
Z: 717 zg: 717
Z: 715 zg: 715
Z: 713 zg: 713
Z: 711 zg: 711
Z: 709 zg: 709
Z: 707 zg: 707
Z: 705 zg: 705
Z: 703 zg: 703
Z: 701 zg: 701
Z: 699 zg: 699
Z: 697 zg: 697
Z: 695 zg: 695
Z: 693 zg: 693
Z: 691 zg: 691
Z: 689 zg: 689
Z: 687 zg: 687
Z: 685 zg: 685
Z: 683 zg: 683
Z: 681 zg: 681
Z: 679 zg: 679
Z: 677 zg: 677
Z: 675 zg: 675
Z: 673 zg: 673
Z: 671 zg: 671
Z: 669 zg: 669
Z: 667 zg: 667
Z: 665 zg: 665
Z: 663 zg: 663
Z: 661 zg: 661
Z: 659 zg: 659
Z: 657 zg: 657
Z: 655 zg: 655
Z: 653 zg: 653
Z: 651 zg: 651
Z: 649 zg: 649
Z: 647 zg: 647
Z: 645 zg: 645
Z: 643 zg: 643
Z: 641 zg: 641
Z: 639 zg: 639
Z: 637 zg: 637
Z: 635 zg: 635
Z: 633 zg: 633
Z: 631 zg: 631
Z: 629 zg: 629
Z: 627 zg: 627
Z: 625 zg: 625
Z: 623 zg: 623
Z: 621 zg: 621
Z: 619 zg: 619
Z: 617 zg: 617
Z: 615 zg: 615
Z: 613 zg: 613
Z: 611 zg: 611
Z: 609 zg: 609
Z: 607 zg: 607
Z: 605 zg: 605
Z: 603 zg: 603
Z: 601 zg: 601
Z: 599 zg: 599
Z: 597 zg: 597
Z: 595 zg: 595
Z: 593 zg: 593
Z: 591 zg: 591
Z: 589 zg: 589
Z: 587 zg: 587
Z: 585 zg: 585
Z: 583 zg: 583
Z: 581 zg: 581
Z: 579 zg: 579
Z: 577 zg: 577
Z: 575 zg: 575
Z: 573 zg: 573
Z: 571 zg: 571
Z: 569 zg: 569
Z: 567 zg: 567
Z: 565 zg: 565
Z: 563 zg: 563
Z: 561 zg: 561
Z: 559 zg: 559
Z: 557 zg: 557
Z: 555 zg: 555
Z: 553 zg: 553
Z: 551 zg: 551
Z: 549 zg: 549
Z: 547 zg: 547
Z: 545 zg: 545
Z: 543 zg: 543
Z: 541 zg: 541
Z: 539 zg: 539
Z: 537 zg: 537
Z: 535 zg: 535
Z: 533 zg: 533
Z: 531 zg: 531
Z: 529 zg: 529
Z: 527 zg: 527
Z: 525 zg: 525
Z: 523 zg: 523
Z: 521 zg: 521
Z: 519 zg: 519
Z: 517 zg: 517
Z: 515 zg: 515
Z: 513 zg: 513
Z: 511 zg: 511
Z: 509 zg: 509
Z: 507 zg: 507
Z: 505 zg: 505
Z: 503 zg: 503
Z: 501 zg: 501
Z: 499 zg: 499
Z: 497 zg: 497
Z: 495 zg: 495
Z: 493 zg: 493
Z: 491 zg: 491
Z: 489 zg: 489
Z: 487 zg: 487
Z: 485 zg: 485
Z: 483 zg: 483
Z: 481 zg: 481
Z: 479 zg: 479
Z: 477 zg: 477
Z: 475 zg: 475
Z: 473 zg: 473
Z: 471 zg: 471
Z: 469 zg: 469
Z: 467 zg: 467
Z: 465 zg: 465
Z: 463 zg: 463
Z: 461 zg: 461
Z: 459 zg: 459
Z: 457 zg: 457
Z: 455 zg: 455
Z: 453 zg: 453
Z: 451 zg: 451
Z: 449 zg: 449
Z: 447 zg: 447
Z: 445 zg: 445
Z: 443 zg: 443
Z: 441 zg: 441
Z: 439 zg: 439
Z: 437 zg: 437
Z: 435 zg: 435
Z: 433 zg: 433
Z: 431 zg: 431
Z: 429 zg: 429
Z: 427 zg: 427
Z: 425 zg: 425
Z: 423 zg: 423
Z: 421 zg: 421
Z: 419 zg: 419
Z: 417 zg: 417
Z: 415 zg: 415
Z: 413 zg: 413
Z: 411 zg: 411
Z: 409 zg: 409
Z: 407 zg: 407
Z: 405 zg: 405
Z: 403 zg: 403
Z: 401 zg: 401
Z: 399 zg: 399
Z: 397 zg: 397
Z: 395 zg: 395
Z: 393 zg: 393
Z: 391 zg: 391
Z: 389 zg: 389
Z: 387 zg: 387
Z: 385 zg: 385
Z: 383 zg: 383
Z: 381 zg: 381
Z: 379 zg: 379
Z: 377 zg: 377
Z: 375 zg: 375
Z: 373 zg: 373
Z: 371 zg: 371
Z: 369 zg: 369
Z: 367 zg: 367
Z: 365 zg: 365
Z: 363 zg: 363
Z: 361 zg: 361
Z: 359 zg: 359
Z: 357 zg: 357
Z: 355 zg: 355
Z: 353 zg: 353
Z: 351 zg: 351
Z: 349 zg: 349
Z: 347 zg: 347
Z: 345 zg: 345
Z: 343 zg: 343
Z: 341 zg: 341
Z: 339 zg: 339
Z: 337 zg: 337
Z: 335 zg: 335
Z: 333 zg: 333
Z: 331 zg: 331
Z: 329 zg: 329
Z: 327 zg: 327
Z: 325 zg: 325
Z: 323 zg: 323
Z: 321 zg: 321
Z: 319 zg: 319
Z: 317 zg: 317
Z: 315 zg: 315
Z: 313 zg: 313
Z: 311 zg: 311
Z: 309 zg: 309
Z: 307 zg: 307
Z: 305 zg: 305
Z: 303 zg: 303
Z: 301 zg: 301
Z: 299 zg: 299
Z: 297 zg: 297
Z: 295 zg: 295
Z: 293 zg: 293
Z: 291 zg: 291
Z: 289 zg: 289
Z: 287 zg: 287
Z: 285 zg: 285
Z: 283 zg: 283
Z: 281 zg: 281
Z: 279 zg: 279
Z: 277 zg: 277
Z: 275 zg: 275
Z: 273 zg: 273
Z: 271 zg: 271
Z: 269 zg: 269
Z: 267 zg: 267
Z: 265 zg: 265
Z: 263 zg: 263
Z: 261 zg: 261
Z: 259 zg: 259
Z: 257 zg: 257
Z: 255 zg: 255
Z: 253 zg: 253
Z: 251 zg: 251
Z: 249 zg: 249
Z: 247 zg: 247
Z: 245 zg: 245
Z: 243 zg: 243
Z: 241 zg: 241
Z: 239 zg: 239
Z: 237 zg: 237
Z: 235 zg: 235
Z: 233 zg: 233
Z: 231 zg: 231
Z: 229 zg: 229
Z: 227 zg: 227
Z: 225 zg: 225
Z: 223 zg: 223
Z: 221 zg: 221
Z: 219 zg: 219
Z: 217 zg: 217
Z: 215 zg: 215
Z: 213 zg: 213
Z: 211 zg: 211
Z: 209 zg: 209
Z: 207 zg: 207
Z: 205 zg: 205
Z: 203 zg: 203
Z: 201 zg: 201
Z: 199 zg: 199
Z: 197 zg: 197
Z: 195 zg: 195
Z: 193 zg: 193
Z: 191 zg: 191
Z: 189 zg: 189
Z: 187 zg: 187
Z: 185 zg: 185
Z: 183 zg: 183
Z: 181 zg: 181
Z: 179 zg: 179
Z: 177 zg: 177
Z: 175 zg: 175
Z: 173 zg: 173
Z: 171 zg: 171
Z: 169 zg: 169
Z: 167 zg: 167
Z: 165 zg: 165
Z: 163 zg: 163
Z: 161 zg: 161
Z: 159 zg: 159
Z: 157 zg: 157
Z: 155 zg: 155
Z: 153 zg: 153
Z: 151 zg: 151
Z: 149 zg: 149
Z: 147 zg: 147
Z: 145 zg: 145
Z: 143 zg: 143
Z: 141 zg: 141
Z: 139 zg: 139
Z: 137 zg: 137
Z: 135 zg: 135
Z: 133 zg: 133
Z: 131 zg: 131
Z: 129 zg: 129
Z: 127 zg: 127
Z: 125 zg: 125
Z: 123 zg: 123
Z: 121 zg: 121
Z: 119 zg: 119
Z: 117 zg: 117
Z: 115 zg: 115
Z: 113 zg: 113
Z: 111 zg: 111
Z: 109 zg: 109
Z: 107 zg: 107
Z: 105 zg: 105
Z: 103 zg: 103
Z: 101 zg: 101
Z: 99 zg: 99
Z: 97 zg: 97
Z: 95 zg: 95
Z: 93 zg: 93
Z: 91 zg: 91
Z: 89 zg: 89
Z: 87 zg: 87
Z: 85 zg: 85
Z: 83 zg: 83
Z: 81 zg: 81
Z: 79 zg: 79
Z: 77 zg: 77
Before deleteing the queue
inside ddeque destructor
Inside ddeque constructor
begin with
-----------------
a.size is 0
g.size is 0
size = 0
begin with
-----------------
a.size is 0
g.size is 0
size = 0
After insertiing 1000 elements
-----------------
a.size is 1000
g.size is 1000
size = 1000
After Shuffle
-----------------
a.size is 1000
g.size is 1000
size = 1000
y is 0x100407e90 yg is 0x100407ea0
The back of the ddeque has 0x100407e70
After front and back operation
-----------------
a.size is 1000
g.size is 1000
size = 1000
Random access of a[999]= 0x100407e70
Understanding forward traversal

Understanding reverse traversal

-----------------
multiply by 10
-----------------


print using iterator after multiplying by 10
-----------------


Before deleteing the queue
Z: 0x100407e70 zg: 0x100407e80
Z: 0x100407e30 zg: 0x100407e40
Z: 0x100407df0 zg: 0x100407e00
Z: 0x100407db0 zg: 0x100407dc0
Z: 0x100407d70 zg: 0x100407d80
Z: 0x100407d30 zg: 0x100407d40
Z: 0x100407cf0 zg: 0x100407d00
Z: 0x100407cb0 zg: 0x100407cc0
Z: 0x100407c70 zg: 0x100407c80
Z: 0x100407c30 zg: 0x100407c40
Z: 0x100407bf0 zg: 0x100407c00
Z: 0x100407bb0 zg: 0x100407bc0
Z: 0x100407b70 zg: 0x100407b80
Z: 0x100407b30 zg: 0x100407b40
Z: 0x100407af0 zg: 0x100407b00
Z: 0x100407ab0 zg: 0x100407ac0
Z: 0x100407a70 zg: 0x100407a80
Z: 0x100407a30 zg: 0x100407a40
Z: 0x1004079f0 zg: 0x100407a00
Z: 0x1004079b0 zg: 0x1004079c0
Z: 0x100407970 zg: 0x100407980
Z: 0x100407930 zg: 0x100407940
Z: 0x1004078f0 zg: 0x100407900
Z: 0x1004078b0 zg: 0x1004078c0
Z: 0x100407870 zg: 0x100407880
Z: 0x100407830 zg: 0x100407840
Z: 0x1004077f0 zg: 0x100407800
Z: 0x1004077b0 zg: 0x1004077c0
Z: 0x100407770 zg: 0x100407780
Z: 0x100407730 zg: 0x100407740
Z: 0x1004076f0 zg: 0x100407700
Z: 0x1004076b0 zg: 0x1004076c0
Z: 0x100407670 zg: 0x100407680
Z: 0x100407630 zg: 0x100407640
Z: 0x1004075f0 zg: 0x100407600
Z: 0x1004075b0 zg: 0x1004075c0
Z: 0x100407570 zg: 0x100407580
Z: 0x100407530 zg: 0x100407540
Z: 0x1004074f0 zg: 0x100407500
Z: 0x1004074b0 zg: 0x1004074c0
Z: 0x100407470 zg: 0x100407480
Z: 0x100407430 zg: 0x100407440
Z: 0x1004073f0 zg: 0x100407400
Z: 0x1004073b0 zg: 0x1004073c0
Z: 0x100407370 zg: 0x100407380
Z: 0x100407330 zg: 0x100407340
Z: 0x1004072f0 zg: 0x100407300
Z: 0x1004072b0 zg: 0x1004072c0
Z: 0x100407270 zg: 0x100407280
Z: 0x100407230 zg: 0x100407240
Z: 0x1004071f0 zg: 0x100407200
Z: 0x1004071b0 zg: 0x1004071c0
Z: 0x100407170 zg: 0x100407180
Z: 0x100407130 zg: 0x100407140
Z: 0x1004070f0 zg: 0x100407100
Z: 0x1004070b0 zg: 0x1004070c0
Z: 0x100407070 zg: 0x100407080
Z: 0x100407030 zg: 0x100407040
Z: 0x100406ff0 zg: 0x100407000
Z: 0x100406fb0 zg: 0x100406fc0
Z: 0x100406f70 zg: 0x100406f80
Z: 0x100406f30 zg: 0x100406f40
Z: 0x100406ef0 zg: 0x100406f00
Z: 0x100406eb0 zg: 0x100406ec0
Z: 0x100406e70 zg: 0x100406e80
Z: 0x100406e30 zg: 0x100406e40
Z: 0x100406df0 zg: 0x100406e00
Z: 0x100406db0 zg: 0x100406dc0
Z: 0x100406d70 zg: 0x100406d80
Z: 0x100406d30 zg: 0x100406d40
Z: 0x100406cf0 zg: 0x100406d00
Z: 0x100406cb0 zg: 0x100406cc0
Z: 0x100406c70 zg: 0x100406c80
Z: 0x100406c30 zg: 0x100406c40
Z: 0x100406bf0 zg: 0x100406c00
Z: 0x100406bb0 zg: 0x100406bc0
Z: 0x100406b70 zg: 0x100406b80
Z: 0x100406b30 zg: 0x100406b40
Z: 0x100406af0 zg: 0x100406b00
Z: 0x100406ab0 zg: 0x100406ac0
Z: 0x100406a70 zg: 0x100406a80
Z: 0x100406a30 zg: 0x100406a40
Z: 0x1004069f0 zg: 0x100406a00
Z: 0x1004069b0 zg: 0x1004069c0
Z: 0x100406970 zg: 0x100406980
Z: 0x100406930 zg: 0x100406940
Z: 0x1004068f0 zg: 0x100406900
Z: 0x1004068b0 zg: 0x1004068c0
Z: 0x100406870 zg: 0x100406880
Z: 0x100406830 zg: 0x100406840
Z: 0x1004067f0 zg: 0x100406800
Z: 0x1004067b0 zg: 0x1004067c0
Z: 0x100406770 zg: 0x100406780
Z: 0x100406730 zg: 0x100406740
Z: 0x1004066f0 zg: 0x100406700
Z: 0x1004066b0 zg: 0x1004066c0
Z: 0x100406670 zg: 0x100406680
Z: 0x100406630 zg: 0x100406640
Z: 0x1004065f0 zg: 0x100406600
Z: 0x1004065b0 zg: 0x1004065c0
Z: 0x100406570 zg: 0x100406580
Z: 0x100406530 zg: 0x100406540
Z: 0x1004064f0 zg: 0x100406500
Z: 0x1004064b0 zg: 0x1004064c0
Z: 0x100406470 zg: 0x100406480
Z: 0x100406430 zg: 0x100406440
Z: 0x1004063f0 zg: 0x100406400
Z: 0x1004063b0 zg: 0x1004063c0
Z: 0x100406370 zg: 0x100406380
Z: 0x100406330 zg: 0x100406340
Z: 0x1004062f0 zg: 0x100406300
Z: 0x1004062b0 zg: 0x1004062c0
Z: 0x100406270 zg: 0x100406280
Z: 0x100406230 zg: 0x100406240
Z: 0x1004061f0 zg: 0x100406200
Z: 0x1004061b0 zg: 0x1004061c0
Z: 0x100406170 zg: 0x100406180
Z: 0x100406130 zg: 0x100406140
Z: 0x1004060f0 zg: 0x100406100
Z: 0x1004060b0 zg: 0x1004060c0
Z: 0x100406070 zg: 0x100406080
Z: 0x100406030 zg: 0x100406040
Z: 0x100405ff0 zg: 0x100406000
Z: 0x100405fb0 zg: 0x100405fc0
Z: 0x100405f70 zg: 0x100405f80
Z: 0x100405f30 zg: 0x100405f40
Z: 0x100405ef0 zg: 0x100405f00
Z: 0x100405eb0 zg: 0x100405ec0
Z: 0x100405e70 zg: 0x100405e80
Z: 0x100405e30 zg: 0x100405e40
Z: 0x100405df0 zg: 0x100405e00
Z: 0x100405db0 zg: 0x100405dc0
Z: 0x100405d70 zg: 0x100405d80
Z: 0x100405d30 zg: 0x100405d40
Z: 0x100405cf0 zg: 0x100405d00
Z: 0x100405cb0 zg: 0x100405cc0
Z: 0x100405c70 zg: 0x100405c80
Z: 0x100405c30 zg: 0x100405c40
Z: 0x100405bf0 zg: 0x100405c00
Z: 0x100405bb0 zg: 0x100405bc0
Z: 0x100405b70 zg: 0x100405b80
Z: 0x100405b30 zg: 0x100405b40
Z: 0x100405af0 zg: 0x100405b00
Z: 0x100405ab0 zg: 0x100405ac0
Z: 0x100405a70 zg: 0x100405a80
Z: 0x100405a30 zg: 0x100405a40
Z: 0x1004059f0 zg: 0x100405a00
Z: 0x1004059b0 zg: 0x1004059c0
Z: 0x100405970 zg: 0x100405980
Z: 0x100405930 zg: 0x100405940
Z: 0x1004058f0 zg: 0x100405900
Z: 0x1004058b0 zg: 0x1004058c0
Z: 0x100405870 zg: 0x100405880
Z: 0x100405830 zg: 0x100405840
Z: 0x1004057f0 zg: 0x100405800
Z: 0x1004057b0 zg: 0x1004057c0
Z: 0x100405770 zg: 0x100405780
Z: 0x100405730 zg: 0x100405740
Z: 0x1004056f0 zg: 0x100405700
Z: 0x1004056b0 zg: 0x1004056c0
Z: 0x100405670 zg: 0x100405680
Z: 0x100405630 zg: 0x100405640
Z: 0x1004055f0 zg: 0x100405600
Z: 0x1004055b0 zg: 0x1004055c0
Z: 0x100405570 zg: 0x100405580
Z: 0x100405530 zg: 0x100405540
Z: 0x1004054f0 zg: 0x100405500
Z: 0x1004054b0 zg: 0x1004054c0
Z: 0x100405470 zg: 0x100405480
Z: 0x100405430 zg: 0x100405440
Z: 0x1004053f0 zg: 0x100405400
Z: 0x1004053b0 zg: 0x1004053c0
Z: 0x100405370 zg: 0x100405380
Z: 0x100405330 zg: 0x100405340
Z: 0x1004052f0 zg: 0x100405300
Z: 0x1004052b0 zg: 0x1004052c0
Z: 0x100405270 zg: 0x100405280
Z: 0x100405230 zg: 0x100405240
Z: 0x1004051f0 zg: 0x100405200
Z: 0x1004051b0 zg: 0x1004051c0
Z: 0x100405170 zg: 0x100405180
Z: 0x100405130 zg: 0x100405140
Z: 0x1004050f0 zg: 0x100405100
Z: 0x1004050b0 zg: 0x1004050c0
Z: 0x100405070 zg: 0x100405080
Z: 0x100405030 zg: 0x100405040
Z: 0x100404ff0 zg: 0x100405000
Z: 0x100404fb0 zg: 0x100404fc0
Z: 0x100404f70 zg: 0x100404f80
Z: 0x100404f30 zg: 0x100404f40
Z: 0x100404ef0 zg: 0x100404f00
Z: 0x100404eb0 zg: 0x100404ec0
Z: 0x100404e70 zg: 0x100404e80
Z: 0x100404e30 zg: 0x100404e40
Z: 0x100404df0 zg: 0x100404e00
Z: 0x100404db0 zg: 0x100404dc0
Z: 0x100404d70 zg: 0x100404d80
Z: 0x100404d30 zg: 0x100404d40
Z: 0x100404cf0 zg: 0x100404d00
Z: 0x100404cb0 zg: 0x100404cc0
Z: 0x100404c70 zg: 0x100404c80
Z: 0x100404c30 zg: 0x100404c40
Z: 0x100404bf0 zg: 0x100404c00
Z: 0x100404bb0 zg: 0x100404bc0
Z: 0x100404b70 zg: 0x100404b80
Z: 0x100404b30 zg: 0x100404b40
Z: 0x100404af0 zg: 0x100404b00
Z: 0x100404ab0 zg: 0x100404ac0
Z: 0x100404a70 zg: 0x100404a80
Z: 0x100404a30 zg: 0x100404a40
Z: 0x1004049f0 zg: 0x100404a00
Z: 0x1004049b0 zg: 0x1004049c0
Z: 0x100404970 zg: 0x100404980
Z: 0x100404930 zg: 0x100404940
Z: 0x1004048f0 zg: 0x100404900
Z: 0x1004048b0 zg: 0x1004048c0
Z: 0x100404870 zg: 0x100404880
Z: 0x100404830 zg: 0x100404840
Z: 0x1004047f0 zg: 0x100404800
Z: 0x1004047b0 zg: 0x1004047c0
Z: 0x100404770 zg: 0x100404780
Z: 0x100404730 zg: 0x100404740
Z: 0x1004046f0 zg: 0x100404700
Z: 0x1004046b0 zg: 0x1004046c0
Z: 0x100404670 zg: 0x100404680
Z: 0x100404630 zg: 0x100404640
Z: 0x1004045f0 zg: 0x100404600
Z: 0x1004045b0 zg: 0x1004045c0
Z: 0x100404570 zg: 0x100404580
Z: 0x100404530 zg: 0x100404540
Z: 0x1004044f0 zg: 0x100404500
Z: 0x1004044b0 zg: 0x1004044c0
Z: 0x100404470 zg: 0x100404480
Z: 0x100404430 zg: 0x100404440
Z: 0x1004043f0 zg: 0x100404400
Z: 0x1004043b0 zg: 0x1004043c0
Z: 0x100404370 zg: 0x100404380
Z: 0x100404330 zg: 0x100404340
Z: 0x1004042f0 zg: 0x100404300
Z: 0x1004042b0 zg: 0x1004042c0
Z: 0x100404270 zg: 0x100404280
Z: 0x100404230 zg: 0x100404240
Z: 0x1004041f0 zg: 0x100404200
Z: 0x1004041b0 zg: 0x1004041c0
Z: 0x100404170 zg: 0x100404180
Z: 0x100404130 zg: 0x100404140
Z: 0x1004040f0 zg: 0x100404100
Z: 0x1004040b0 zg: 0x1004040c0
Z: 0x100404070 zg: 0x100404080
Z: 0x100404030 zg: 0x100404040
Z: 0x100403ff0 zg: 0x100404000
Z: 0x100403fb0 zg: 0x100403fc0
Z: 0x100403f70 zg: 0x100403f80
Z: 0x100403f30 zg: 0x100403f40
Z: 0x100403ef0 zg: 0x100403f00
Z: 0x100403eb0 zg: 0x100403ec0
Z: 0x100403e70 zg: 0x100403e80
Z: 0x100403e30 zg: 0x100403e40
Z: 0x100403df0 zg: 0x100403e00
Z: 0x100403db0 zg: 0x100403dc0
Z: 0x100403d70 zg: 0x100403d80
Z: 0x100403d30 zg: 0x100403d40
Z: 0x100403cf0 zg: 0x100403d00
Z: 0x100403cb0 zg: 0x100403cc0
Z: 0x100403c70 zg: 0x100403c80
Z: 0x100403c30 zg: 0x100403c40
Z: 0x100403bf0 zg: 0x100403c00
Z: 0x100403bb0 zg: 0x100403bc0
Z: 0x100403b70 zg: 0x100403b80
Z: 0x100403b30 zg: 0x100403b40
Z: 0x100403af0 zg: 0x100403b00
Z: 0x100403ab0 zg: 0x100403ac0
Z: 0x100403a70 zg: 0x100403a80
Z: 0x100403a30 zg: 0x100403a40
Z: 0x1004039f0 zg: 0x100403a00
Z: 0x1004039b0 zg: 0x1004039c0
Z: 0x100403970 zg: 0x100403980
Z: 0x100403930 zg: 0x100403940
Z: 0x1004038f0 zg: 0x100403900
Z: 0x1004038b0 zg: 0x1004038c0
Z: 0x100403870 zg: 0x100403880
Z: 0x100403830 zg: 0x100403840
Z: 0x1004037f0 zg: 0x100403800
Z: 0x1004037b0 zg: 0x1004037c0
Z: 0x100403770 zg: 0x100403780
Z: 0x100403730 zg: 0x100403740
Z: 0x1004036f0 zg: 0x100403700
Z: 0x1004036b0 zg: 0x1004036c0
Z: 0x100403670 zg: 0x100403680
Z: 0x100403630 zg: 0x100403640
Z: 0x1004035f0 zg: 0x100403600
Z: 0x1004035b0 zg: 0x1004035c0
Z: 0x100403570 zg: 0x100403580
Z: 0x100403530 zg: 0x100403540
Z: 0x1004034f0 zg: 0x100403500
Z: 0x1004034b0 zg: 0x1004034c0
Z: 0x100403470 zg: 0x100403480
Z: 0x100403430 zg: 0x100403440
Z: 0x1004033f0 zg: 0x100403400
Z: 0x1004033b0 zg: 0x1004033c0
Z: 0x100403370 zg: 0x100403380
Z: 0x100403330 zg: 0x100403340
Z: 0x1004032f0 zg: 0x100403300
Z: 0x1004032b0 zg: 0x1004032c0
Z: 0x100403270 zg: 0x100403280
Z: 0x100403230 zg: 0x100403240
Z: 0x1004031f0 zg: 0x100403200
Z: 0x1004031b0 zg: 0x1004031c0
Z: 0x100403170 zg: 0x100403180
Z: 0x100403130 zg: 0x100403140
Z: 0x1004030f0 zg: 0x100403100
Z: 0x1004030b0 zg: 0x1004030c0
Z: 0x100403070 zg: 0x100403080
Z: 0x100403030 zg: 0x100403040
Z: 0x100402ff0 zg: 0x100403000
Z: 0x100402fb0 zg: 0x100402fc0
Z: 0x100402f70 zg: 0x100402f80
Z: 0x100402f30 zg: 0x100402f40
Z: 0x100402ef0 zg: 0x100402f00
Z: 0x100402eb0 zg: 0x100402ec0
Z: 0x100402e70 zg: 0x100402e80
Z: 0x100402e30 zg: 0x100402e40
Z: 0x100402df0 zg: 0x100402e00
Z: 0x100402db0 zg: 0x100402dc0
Z: 0x100402d70 zg: 0x100402d80
Z: 0x100402d30 zg: 0x100402d40
Z: 0x100402cf0 zg: 0x100402d00
Z: 0x100402cb0 zg: 0x100402cc0
Z: 0x100402c70 zg: 0x100402c80
Z: 0x100402c30 zg: 0x100402c40
Z: 0x100402bf0 zg: 0x100402c00
Z: 0x100402bb0 zg: 0x100402bc0
Z: 0x100402b70 zg: 0x100402b80
Z: 0x100402b30 zg: 0x100402b40
Z: 0x100402af0 zg: 0x100402b00
Z: 0x100402ab0 zg: 0x100402ac0
Z: 0x100402a70 zg: 0x100402a80
Z: 0x100402a30 zg: 0x100402a40
Z: 0x1004029f0 zg: 0x100402a00
Z: 0x1004029b0 zg: 0x1004029c0
Z: 0x100402970 zg: 0x100402980
Z: 0x100402930 zg: 0x100402940
Z: 0x1004028f0 zg: 0x100402900
Z: 0x1004028b0 zg: 0x1004028c0
Z: 0x100402870 zg: 0x100402880
Z: 0x100402830 zg: 0x100402840
Z: 0x1004027f0 zg: 0x100402800
Z: 0x1004027b0 zg: 0x1004027c0
Z: 0x100402770 zg: 0x100402780
Z: 0x100402730 zg: 0x100402740
Z: 0x1004026f0 zg: 0x100402700
Z: 0x1004026b0 zg: 0x1004026c0
Z: 0x100402670 zg: 0x100402680
Z: 0x100402630 zg: 0x100402640
Z: 0x1004025f0 zg: 0x100402600
Z: 0x1004025b0 zg: 0x1004025c0
Z: 0x100402570 zg: 0x100402580
Z: 0x100402530 zg: 0x100402540
Z: 0x1004024f0 zg: 0x100402500
Z: 0x1004024b0 zg: 0x1004024c0
Z: 0x100402470 zg: 0x100402480
Z: 0x100402430 zg: 0x100402440
Z: 0x1004023f0 zg: 0x100402400
Z: 0x1004023b0 zg: 0x1004023c0
Z: 0x100402370 zg: 0x100402380
Z: 0x100402330 zg: 0x100402340
Z: 0x1004022f0 zg: 0x100402300
Z: 0x1004022b0 zg: 0x1004022c0
Z: 0x100402270 zg: 0x100402280
Z: 0x100402230 zg: 0x100402240
Z: 0x1004021f0 zg: 0x100402200
Z: 0x1004021b0 zg: 0x1004021c0
Z: 0x100402170 zg: 0x100402180
Z: 0x100402130 zg: 0x100402140
Z: 0x100401790 zg: 0x1004017a0
Z: 0x100401750 zg: 0x100401760
Z: 0x100401710 zg: 0x100401720
Z: 0x1004016d0 zg: 0x1004016e0
Z: 0x100401690 zg: 0x1004016a0
Z: 0x100401650 zg: 0x100401660
Z: 0x100401610 zg: 0x100401620
Z: 0x1004015d0 zg: 0x1004015e0
Z: 0x100401590 zg: 0x1004015a0
Z: 0x100401550 zg: 0x100401560
Z: 0x100401510 zg: 0x100401520
Z: 0x1004014d0 zg: 0x1004014e0
Z: 0x100401490 zg: 0x1004014a0
Z: 0x100401450 zg: 0x100401460
Z: 0x100401410 zg: 0x100401420
Z: 0x1004013d0 zg: 0x1004013e0
Z: 0x100401390 zg: 0x1004013a0
Z: 0x100401350 zg: 0x100401360
Z: 0x100401310 zg: 0x100401320
Z: 0x1004012d0 zg: 0x1004012e0
Z: 0x100401290 zg: 0x1004012a0
Z: 0x100401250 zg: 0x100401260
Z: 0x100401210 zg: 0x100401220
Z: 0x1004011d0 zg: 0x1004011e0
Z: 0x100401190 zg: 0x1004011a0
Z: 0x1004020f0 zg: 0x100402100
Z: 0x1004020b0 zg: 0x1004020c0
Z: 0x100402070 zg: 0x100402080
Z: 0x100402030 zg: 0x100402040
Z: 0x100401ff0 zg: 0x100402000
Z: 0x100401fb0 zg: 0x100401fc0
Z: 0x100401f70 zg: 0x100401f80
Z: 0x100401f30 zg: 0x100401f40
Z: 0x100401ef0 zg: 0x100401f00
Z: 0x100401eb0 zg: 0x100401ec0
Z: 0x100401e70 zg: 0x100401e80
Z: 0x100401e30 zg: 0x100401e40
Z: 0x100401df0 zg: 0x100401e00
Z: 0x100401db0 zg: 0x100401dc0
Z: 0x100401d70 zg: 0x100401d80
Z: 0x100401d30 zg: 0x100401d40
Z: 0x100401cf0 zg: 0x100401d00
Z: 0x100401cb0 zg: 0x100401cc0
Z: 0x100401c70 zg: 0x100401c80
Z: 0x100401c30 zg: 0x100401c40
Z: 0x100401bf0 zg: 0x100401c00
Z: 0x100401bb0 zg: 0x100401bc0
Z: 0x100401b70 zg: 0x100401b80
Z: 0x100401b30 zg: 0x100401b40
Z: 0x100401af0 zg: 0x100401b00
Z: 0x100401ab0 zg: 0x100401ac0
Z: 0x100401a70 zg: 0x100401a80
Z: 0x100401a30 zg: 0x100401a40
Z: 0x1004019f0 zg: 0x100401a00
Z: 0x1004019b0 zg: 0x1004019c0
Z: 0x100401970 zg: 0x100401980
Z: 0x100401930 zg: 0x100401940
Z: 0x1004018f0 zg: 0x100401900
Z: 0x1004018b0 zg: 0x1004018c0
Z: 0x100401870 zg: 0x100401880
Z: 0x100401830 zg: 0x100401840
Z: 0x1004017f0 zg: 0x100401800
Z: 0x1004017b0 zg: 0x1004017c0
Z: 0x1004003e0 zg: 0x1004003f0
Z: 0x1004003a0 zg: 0x1004003b0
Z: 0x100400360 zg: 0x100400370
Z: 0x100400320 zg: 0x100400330
Z: 0x1004002e0 zg: 0x1004002f0
Z: 0x1004002a0 zg: 0x1004002b0
Z: 0x100400580 zg: 0x100400590
Z: 0x100400540 zg: 0x100400550
Z: 0x100400500 zg: 0x100400510
Z: 0x1004004c0 zg: 0x1004004d0
Z: 0x100400480 zg: 0x100400490
Z: 0x100400440 zg: 0x100400450
Z: 0x100401150 zg: 0x100401160
Z: 0x100401110 zg: 0x100401120
Z: 0x1004010d0 zg: 0x1004010e0
Z: 0x100401090 zg: 0x1004010a0
Z: 0x100401050 zg: 0x100401060
Z: 0x100401010 zg: 0x100401020
Z: 0x100400fd0 zg: 0x100400fe0
Z: 0x100400f90 zg: 0x100400fa0
Z: 0x100400f50 zg: 0x100400f60
Z: 0x100400f10 zg: 0x100400f20
Z: 0x100400ed0 zg: 0x100400ee0
Z: 0x100400e90 zg: 0x100400ea0
Z: 0x100400e50 zg: 0x100400e60
Z: 0x100400e10 zg: 0x100400e20
Z: 0x100400dd0 zg: 0x100400de0
Z: 0x100400d90 zg: 0x100400da0
Z: 0x100400d50 zg: 0x100400d60
Z: 0x100400d10 zg: 0x100400d20
Z: 0x100400cd0 zg: 0x100400ce0
Z: 0x100400c90 zg: 0x100400ca0
Z: 0x100400c50 zg: 0x100400c60
Z: 0x100400c10 zg: 0x100400c20
Z: 0x100400bd0 zg: 0x100400be0
Z: 0x100400b90 zg: 0x100400ba0
Z: 0x100400b50 zg: 0x100400b60
Z: 0x100400b10 zg: 0x100400b20
Z: 0x100400ad0 zg: 0x100400ae0
Z: 0x100400a90 zg: 0x100400aa0
Z: 0x100400a50 zg: 0x100400a60
Z: 0x100400a10 zg: 0x100400a20
Z: 0x1004009d0 zg: 0x1004009e0
Z: 0x100400990 zg: 0x1004009a0
Z: 0x100400950 zg: 0x100400960
Z: 0x100400910 zg: 0x100400920
Z: 0x1004008d0 zg: 0x1004008e0
Z: 0x100400890 zg: 0x1004008a0
Z: 0x100400850 zg: 0x100400860
Z: 0x100400810 zg: 0x100400820
Z: 0x1004007d0 zg: 0x1004007e0
Z: 0x100400790 zg: 0x1004007a0
Z: 0x100400750 zg: 0x100400760
Z: 0x100400710 zg: 0x100400720
Z: 0x1004006d0 zg: 0x1004006e0
Z: 0x100400690 zg: 0x1004006a0
Z: 0x100400650 zg: 0x100400660
Z: 0x100400610 zg: 0x100400620
Z: 0x1004005d0 zg: 0x1004005e0
Z: 0x100400160 zg: 0x100400170
Z: 0x100400120 zg: 0x100400130
Z: 0x1004000b0 zg: 0x1004000f0
Z: 0x100400180 zg: 0x1004000a0
Before deleteing the queue
inside ddeque destructor
Inside ddeque constructor
begin with
-----------------
a.size is 0
g.size is 0
size = 0
begin with
-----------------
a.size is 0
g.size is 0
size = 0
After insertiing 1000 elements
-----------------
a.size is 1000
g.size is 1000
size = 1000
After Shuffle
-----------------
a.size is 1000
g.size is 1000
size = 1000
y is 1076-i1076 yg is 1076-i1076
The back of the ddeque has 1075-i1075
After front and back operation
-----------------
a.size is 1000
g.size is 1000
size = 1000
Random access of a[999]= 1075-i1075
Understanding forward traversal

Understanding reverse traversal

-----------------
multiply by 10
-----------------


print using iterator after multiplying by 10
-----------------


Before deleteing the queue
Z: 1075-i1075 zg: 1075-i1075
Z: 1073-i1073 zg: 1073-i1073
Z: 1071-i1071 zg: 1071-i1071
Z: 1069-i1069 zg: 1069-i1069
Z: 1067-i1067 zg: 1067-i1067
Z: 1065-i1065 zg: 1065-i1065
Z: 1063-i1063 zg: 1063-i1063
Z: 1061-i1061 zg: 1061-i1061
Z: 1059-i1059 zg: 1059-i1059
Z: 1057-i1057 zg: 1057-i1057
Z: 1055-i1055 zg: 1055-i1055
Z: 1053-i1053 zg: 1053-i1053
Z: 1051-i1051 zg: 1051-i1051
Z: 1049-i1049 zg: 1049-i1049
Z: 1047-i1047 zg: 1047-i1047
Z: 1045-i1045 zg: 1045-i1045
Z: 1043-i1043 zg: 1043-i1043
Z: 1041-i1041 zg: 1041-i1041
Z: 1039-i1039 zg: 1039-i1039
Z: 1037-i1037 zg: 1037-i1037
Z: 1035-i1035 zg: 1035-i1035
Z: 1033-i1033 zg: 1033-i1033
Z: 1031-i1031 zg: 1031-i1031
Z: 1029-i1029 zg: 1029-i1029
Z: 1027-i1027 zg: 1027-i1027
Z: 1025-i1025 zg: 1025-i1025
Z: 1023-i1023 zg: 1023-i1023
Z: 1021-i1021 zg: 1021-i1021
Z: 1019-i1019 zg: 1019-i1019
Z: 1017-i1017 zg: 1017-i1017
Z: 1015-i1015 zg: 1015-i1015
Z: 1013-i1013 zg: 1013-i1013
Z: 1011-i1011 zg: 1011-i1011
Z: 1009-i1009 zg: 1009-i1009
Z: 1007-i1007 zg: 1007-i1007
Z: 1005-i1005 zg: 1005-i1005
Z: 1003-i1003 zg: 1003-i1003
Z: 1001-i1001 zg: 1001-i1001
Z: 999-i999 zg: 999-i999
Z: 997-i997 zg: 997-i997
Z: 995-i995 zg: 995-i995
Z: 993-i993 zg: 993-i993
Z: 991-i991 zg: 991-i991
Z: 989-i989 zg: 989-i989
Z: 987-i987 zg: 987-i987
Z: 985-i985 zg: 985-i985
Z: 983-i983 zg: 983-i983
Z: 981-i981 zg: 981-i981
Z: 979-i979 zg: 979-i979
Z: 977-i977 zg: 977-i977
Z: 975-i975 zg: 975-i975
Z: 973-i973 zg: 973-i973
Z: 971-i971 zg: 971-i971
Z: 969-i969 zg: 969-i969
Z: 967-i967 zg: 967-i967
Z: 965-i965 zg: 965-i965
Z: 963-i963 zg: 963-i963
Z: 961-i961 zg: 961-i961
Z: 959-i959 zg: 959-i959
Z: 957-i957 zg: 957-i957
Z: 955-i955 zg: 955-i955
Z: 953-i953 zg: 953-i953
Z: 951-i951 zg: 951-i951
Z: 949-i949 zg: 949-i949
Z: 947-i947 zg: 947-i947
Z: 945-i945 zg: 945-i945
Z: 943-i943 zg: 943-i943
Z: 941-i941 zg: 941-i941
Z: 939-i939 zg: 939-i939
Z: 937-i937 zg: 937-i937
Z: 935-i935 zg: 935-i935
Z: 933-i933 zg: 933-i933
Z: 931-i931 zg: 931-i931
Z: 929-i929 zg: 929-i929
Z: 927-i927 zg: 927-i927
Z: 925-i925 zg: 925-i925
Z: 923-i923 zg: 923-i923
Z: 921-i921 zg: 921-i921
Z: 919-i919 zg: 919-i919
Z: 917-i917 zg: 917-i917
Z: 915-i915 zg: 915-i915
Z: 913-i913 zg: 913-i913
Z: 911-i911 zg: 911-i911
Z: 909-i909 zg: 909-i909
Z: 907-i907 zg: 907-i907
Z: 905-i905 zg: 905-i905
Z: 903-i903 zg: 903-i903
Z: 901-i901 zg: 901-i901
Z: 899-i899 zg: 899-i899
Z: 897-i897 zg: 897-i897
Z: 895-i895 zg: 895-i895
Z: 893-i893 zg: 893-i893
Z: 891-i891 zg: 891-i891
Z: 889-i889 zg: 889-i889
Z: 887-i887 zg: 887-i887
Z: 885-i885 zg: 885-i885
Z: 883-i883 zg: 883-i883
Z: 881-i881 zg: 881-i881
Z: 879-i879 zg: 879-i879
Z: 877-i877 zg: 877-i877
Z: 875-i875 zg: 875-i875
Z: 873-i873 zg: 873-i873
Z: 871-i871 zg: 871-i871
Z: 869-i869 zg: 869-i869
Z: 867-i867 zg: 867-i867
Z: 865-i865 zg: 865-i865
Z: 863-i863 zg: 863-i863
Z: 861-i861 zg: 861-i861
Z: 859-i859 zg: 859-i859
Z: 857-i857 zg: 857-i857
Z: 855-i855 zg: 855-i855
Z: 853-i853 zg: 853-i853
Z: 851-i851 zg: 851-i851
Z: 849-i849 zg: 849-i849
Z: 847-i847 zg: 847-i847
Z: 845-i845 zg: 845-i845
Z: 843-i843 zg: 843-i843
Z: 841-i841 zg: 841-i841
Z: 839-i839 zg: 839-i839
Z: 837-i837 zg: 837-i837
Z: 835-i835 zg: 835-i835
Z: 833-i833 zg: 833-i833
Z: 831-i831 zg: 831-i831
Z: 829-i829 zg: 829-i829
Z: 827-i827 zg: 827-i827
Z: 825-i825 zg: 825-i825
Z: 823-i823 zg: 823-i823
Z: 821-i821 zg: 821-i821
Z: 819-i819 zg: 819-i819
Z: 817-i817 zg: 817-i817
Z: 815-i815 zg: 815-i815
Z: 813-i813 zg: 813-i813
Z: 811-i811 zg: 811-i811
Z: 809-i809 zg: 809-i809
Z: 807-i807 zg: 807-i807
Z: 805-i805 zg: 805-i805
Z: 803-i803 zg: 803-i803
Z: 801-i801 zg: 801-i801
Z: 799-i799 zg: 799-i799
Z: 797-i797 zg: 797-i797
Z: 795-i795 zg: 795-i795
Z: 793-i793 zg: 793-i793
Z: 791-i791 zg: 791-i791
Z: 789-i789 zg: 789-i789
Z: 787-i787 zg: 787-i787
Z: 785-i785 zg: 785-i785
Z: 783-i783 zg: 783-i783
Z: 781-i781 zg: 781-i781
Z: 779-i779 zg: 779-i779
Z: 777-i777 zg: 777-i777
Z: 775-i775 zg: 775-i775
Z: 773-i773 zg: 773-i773
Z: 771-i771 zg: 771-i771
Z: 769-i769 zg: 769-i769
Z: 767-i767 zg: 767-i767
Z: 765-i765 zg: 765-i765
Z: 763-i763 zg: 763-i763
Z: 761-i761 zg: 761-i761
Z: 759-i759 zg: 759-i759
Z: 757-i757 zg: 757-i757
Z: 755-i755 zg: 755-i755
Z: 753-i753 zg: 753-i753
Z: 751-i751 zg: 751-i751
Z: 749-i749 zg: 749-i749
Z: 747-i747 zg: 747-i747
Z: 745-i745 zg: 745-i745
Z: 743-i743 zg: 743-i743
Z: 741-i741 zg: 741-i741
Z: 739-i739 zg: 739-i739
Z: 737-i737 zg: 737-i737
Z: 735-i735 zg: 735-i735
Z: 733-i733 zg: 733-i733
Z: 731-i731 zg: 731-i731
Z: 729-i729 zg: 729-i729
Z: 727-i727 zg: 727-i727
Z: 725-i725 zg: 725-i725
Z: 723-i723 zg: 723-i723
Z: 721-i721 zg: 721-i721
Z: 719-i719 zg: 719-i719
Z: 717-i717 zg: 717-i717
Z: 715-i715 zg: 715-i715
Z: 713-i713 zg: 713-i713
Z: 711-i711 zg: 711-i711
Z: 709-i709 zg: 709-i709
Z: 707-i707 zg: 707-i707
Z: 705-i705 zg: 705-i705
Z: 703-i703 zg: 703-i703
Z: 701-i701 zg: 701-i701
Z: 699-i699 zg: 699-i699
Z: 697-i697 zg: 697-i697
Z: 695-i695 zg: 695-i695
Z: 693-i693 zg: 693-i693
Z: 691-i691 zg: 691-i691
Z: 689-i689 zg: 689-i689
Z: 687-i687 zg: 687-i687
Z: 685-i685 zg: 685-i685
Z: 683-i683 zg: 683-i683
Z: 681-i681 zg: 681-i681
Z: 679-i679 zg: 679-i679
Z: 677-i677 zg: 677-i677
Z: 675-i675 zg: 675-i675
Z: 673-i673 zg: 673-i673
Z: 671-i671 zg: 671-i671
Z: 669-i669 zg: 669-i669
Z: 667-i667 zg: 667-i667
Z: 665-i665 zg: 665-i665
Z: 663-i663 zg: 663-i663
Z: 661-i661 zg: 661-i661
Z: 659-i659 zg: 659-i659
Z: 657-i657 zg: 657-i657
Z: 655-i655 zg: 655-i655
Z: 653-i653 zg: 653-i653
Z: 651-i651 zg: 651-i651
Z: 649-i649 zg: 649-i649
Z: 647-i647 zg: 647-i647
Z: 645-i645 zg: 645-i645
Z: 643-i643 zg: 643-i643
Z: 641-i641 zg: 641-i641
Z: 639-i639 zg: 639-i639
Z: 637-i637 zg: 637-i637
Z: 635-i635 zg: 635-i635
Z: 633-i633 zg: 633-i633
Z: 631-i631 zg: 631-i631
Z: 629-i629 zg: 629-i629
Z: 627-i627 zg: 627-i627
Z: 625-i625 zg: 625-i625
Z: 623-i623 zg: 623-i623
Z: 621-i621 zg: 621-i621
Z: 619-i619 zg: 619-i619
Z: 617-i617 zg: 617-i617
Z: 615-i615 zg: 615-i615
Z: 613-i613 zg: 613-i613
Z: 611-i611 zg: 611-i611
Z: 609-i609 zg: 609-i609
Z: 607-i607 zg: 607-i607
Z: 605-i605 zg: 605-i605
Z: 603-i603 zg: 603-i603
Z: 601-i601 zg: 601-i601
Z: 599-i599 zg: 599-i599
Z: 597-i597 zg: 597-i597
Z: 595-i595 zg: 595-i595
Z: 593-i593 zg: 593-i593
Z: 591-i591 zg: 591-i591
Z: 589-i589 zg: 589-i589
Z: 587-i587 zg: 587-i587
Z: 585-i585 zg: 585-i585
Z: 583-i583 zg: 583-i583
Z: 581-i581 zg: 581-i581
Z: 579-i579 zg: 579-i579
Z: 577-i577 zg: 577-i577
Z: 575-i575 zg: 575-i575
Z: 573-i573 zg: 573-i573
Z: 571-i571 zg: 571-i571
Z: 569-i569 zg: 569-i569
Z: 567-i567 zg: 567-i567
Z: 565-i565 zg: 565-i565
Z: 563-i563 zg: 563-i563
Z: 561-i561 zg: 561-i561
Z: 559-i559 zg: 559-i559
Z: 557-i557 zg: 557-i557
Z: 555-i555 zg: 555-i555
Z: 553-i553 zg: 553-i553
Z: 551-i551 zg: 551-i551
Z: 549-i549 zg: 549-i549
Z: 547-i547 zg: 547-i547
Z: 545-i545 zg: 545-i545
Z: 543-i543 zg: 543-i543
Z: 541-i541 zg: 541-i541
Z: 539-i539 zg: 539-i539
Z: 537-i537 zg: 537-i537
Z: 535-i535 zg: 535-i535
Z: 533-i533 zg: 533-i533
Z: 531-i531 zg: 531-i531
Z: 529-i529 zg: 529-i529
Z: 527-i527 zg: 527-i527
Z: 525-i525 zg: 525-i525
Z: 523-i523 zg: 523-i523
Z: 521-i521 zg: 521-i521
Z: 519-i519 zg: 519-i519
Z: 517-i517 zg: 517-i517
Z: 515-i515 zg: 515-i515
Z: 513-i513 zg: 513-i513
Z: 511-i511 zg: 511-i511
Z: 509-i509 zg: 509-i509
Z: 507-i507 zg: 507-i507
Z: 505-i505 zg: 505-i505
Z: 503-i503 zg: 503-i503
Z: 501-i501 zg: 501-i501
Z: 499-i499 zg: 499-i499
Z: 497-i497 zg: 497-i497
Z: 495-i495 zg: 495-i495
Z: 493-i493 zg: 493-i493
Z: 491-i491 zg: 491-i491
Z: 489-i489 zg: 489-i489
Z: 487-i487 zg: 487-i487
Z: 485-i485 zg: 485-i485
Z: 483-i483 zg: 483-i483
Z: 481-i481 zg: 481-i481
Z: 479-i479 zg: 479-i479
Z: 477-i477 zg: 477-i477
Z: 475-i475 zg: 475-i475
Z: 473-i473 zg: 473-i473
Z: 471-i471 zg: 471-i471
Z: 469-i469 zg: 469-i469
Z: 467-i467 zg: 467-i467
Z: 465-i465 zg: 465-i465
Z: 463-i463 zg: 463-i463
Z: 461-i461 zg: 461-i461
Z: 459-i459 zg: 459-i459
Z: 457-i457 zg: 457-i457
Z: 455-i455 zg: 455-i455
Z: 453-i453 zg: 453-i453
Z: 451-i451 zg: 451-i451
Z: 449-i449 zg: 449-i449
Z: 447-i447 zg: 447-i447
Z: 445-i445 zg: 445-i445
Z: 443-i443 zg: 443-i443
Z: 441-i441 zg: 441-i441
Z: 439-i439 zg: 439-i439
Z: 437-i437 zg: 437-i437
Z: 435-i435 zg: 435-i435
Z: 433-i433 zg: 433-i433
Z: 431-i431 zg: 431-i431
Z: 429-i429 zg: 429-i429
Z: 427-i427 zg: 427-i427
Z: 425-i425 zg: 425-i425
Z: 423-i423 zg: 423-i423
Z: 421-i421 zg: 421-i421
Z: 419-i419 zg: 419-i419
Z: 417-i417 zg: 417-i417
Z: 415-i415 zg: 415-i415
Z: 413-i413 zg: 413-i413
Z: 411-i411 zg: 411-i411
Z: 409-i409 zg: 409-i409
Z: 407-i407 zg: 407-i407
Z: 405-i405 zg: 405-i405
Z: 403-i403 zg: 403-i403
Z: 401-i401 zg: 401-i401
Z: 399-i399 zg: 399-i399
Z: 397-i397 zg: 397-i397
Z: 395-i395 zg: 395-i395
Z: 393-i393 zg: 393-i393
Z: 391-i391 zg: 391-i391
Z: 389-i389 zg: 389-i389
Z: 387-i387 zg: 387-i387
Z: 385-i385 zg: 385-i385
Z: 383-i383 zg: 383-i383
Z: 381-i381 zg: 381-i381
Z: 379-i379 zg: 379-i379
Z: 377-i377 zg: 377-i377
Z: 375-i375 zg: 375-i375
Z: 373-i373 zg: 373-i373
Z: 371-i371 zg: 371-i371
Z: 369-i369 zg: 369-i369
Z: 367-i367 zg: 367-i367
Z: 365-i365 zg: 365-i365
Z: 363-i363 zg: 363-i363
Z: 361-i361 zg: 361-i361
Z: 359-i359 zg: 359-i359
Z: 357-i357 zg: 357-i357
Z: 355-i355 zg: 355-i355
Z: 353-i353 zg: 353-i353
Z: 351-i351 zg: 351-i351
Z: 349-i349 zg: 349-i349
Z: 347-i347 zg: 347-i347
Z: 345-i345 zg: 345-i345
Z: 343-i343 zg: 343-i343
Z: 341-i341 zg: 341-i341
Z: 339-i339 zg: 339-i339
Z: 337-i337 zg: 337-i337
Z: 335-i335 zg: 335-i335
Z: 333-i333 zg: 333-i333
Z: 331-i331 zg: 331-i331
Z: 329-i329 zg: 329-i329
Z: 327-i327 zg: 327-i327
Z: 325-i325 zg: 325-i325
Z: 323-i323 zg: 323-i323
Z: 321-i321 zg: 321-i321
Z: 319-i319 zg: 319-i319
Z: 317-i317 zg: 317-i317
Z: 315-i315 zg: 315-i315
Z: 313-i313 zg: 313-i313
Z: 311-i311 zg: 311-i311
Z: 309-i309 zg: 309-i309
Z: 307-i307 zg: 307-i307
Z: 305-i305 zg: 305-i305
Z: 303-i303 zg: 303-i303
Z: 301-i301 zg: 301-i301
Z: 299-i299 zg: 299-i299
Z: 297-i297 zg: 297-i297
Z: 295-i295 zg: 295-i295
Z: 293-i293 zg: 293-i293
Z: 291-i291 zg: 291-i291
Z: 289-i289 zg: 289-i289
Z: 287-i287 zg: 287-i287
Z: 285-i285 zg: 285-i285
Z: 283-i283 zg: 283-i283
Z: 281-i281 zg: 281-i281
Z: 279-i279 zg: 279-i279
Z: 277-i277 zg: 277-i277
Z: 275-i275 zg: 275-i275
Z: 273-i273 zg: 273-i273
Z: 271-i271 zg: 271-i271
Z: 269-i269 zg: 269-i269
Z: 267-i267 zg: 267-i267
Z: 265-i265 zg: 265-i265
Z: 263-i263 zg: 263-i263
Z: 261-i261 zg: 261-i261
Z: 259-i259 zg: 259-i259
Z: 257-i257 zg: 257-i257
Z: 255-i255 zg: 255-i255
Z: 253-i253 zg: 253-i253
Z: 251-i251 zg: 251-i251
Z: 249-i249 zg: 249-i249
Z: 247-i247 zg: 247-i247
Z: 245-i245 zg: 245-i245
Z: 243-i243 zg: 243-i243
Z: 241-i241 zg: 241-i241
Z: 239-i239 zg: 239-i239
Z: 237-i237 zg: 237-i237
Z: 235-i235 zg: 235-i235
Z: 233-i233 zg: 233-i233
Z: 231-i231 zg: 231-i231
Z: 229-i229 zg: 229-i229
Z: 227-i227 zg: 227-i227
Z: 225-i225 zg: 225-i225
Z: 223-i223 zg: 223-i223
Z: 221-i221 zg: 221-i221
Z: 219-i219 zg: 219-i219
Z: 217-i217 zg: 217-i217
Z: 215-i215 zg: 215-i215
Z: 213-i213 zg: 213-i213
Z: 211-i211 zg: 211-i211
Z: 209-i209 zg: 209-i209
Z: 207-i207 zg: 207-i207
Z: 205-i205 zg: 205-i205
Z: 203-i203 zg: 203-i203
Z: 201-i201 zg: 201-i201
Z: 199-i199 zg: 199-i199
Z: 197-i197 zg: 197-i197
Z: 195-i195 zg: 195-i195
Z: 193-i193 zg: 193-i193
Z: 191-i191 zg: 191-i191
Z: 189-i189 zg: 189-i189
Z: 187-i187 zg: 187-i187
Z: 185-i185 zg: 185-i185
Z: 183-i183 zg: 183-i183
Z: 181-i181 zg: 181-i181
Z: 179-i179 zg: 179-i179
Z: 177-i177 zg: 177-i177
Z: 175-i175 zg: 175-i175
Z: 173-i173 zg: 173-i173
Z: 171-i171 zg: 171-i171
Z: 169-i169 zg: 169-i169
Z: 167-i167 zg: 167-i167
Z: 165-i165 zg: 165-i165
Z: 163-i163 zg: 163-i163
Z: 161-i161 zg: 161-i161
Z: 159-i159 zg: 159-i159
Z: 157-i157 zg: 157-i157
Z: 155-i155 zg: 155-i155
Z: 153-i153 zg: 153-i153
Z: 151-i151 zg: 151-i151
Z: 149-i149 zg: 149-i149
Z: 147-i147 zg: 147-i147
Z: 145-i145 zg: 145-i145
Z: 143-i143 zg: 143-i143
Z: 141-i141 zg: 141-i141
Z: 139-i139 zg: 139-i139
Z: 137-i137 zg: 137-i137
Z: 135-i135 zg: 135-i135
Z: 133-i133 zg: 133-i133
Z: 131-i131 zg: 131-i131
Z: 129-i129 zg: 129-i129
Z: 127-i127 zg: 127-i127
Z: 125-i125 zg: 125-i125
Z: 123-i123 zg: 123-i123
Z: 121-i121 zg: 121-i121
Z: 119-i119 zg: 119-i119
Z: 117-i117 zg: 117-i117
Z: 115-i115 zg: 115-i115
Z: 113-i113 zg: 113-i113
Z: 111-i111 zg: 111-i111
Z: 109-i109 zg: 109-i109
Z: 107-i107 zg: 107-i107
Z: 105-i105 zg: 105-i105
Z: 103-i103 zg: 103-i103
Z: 101-i101 zg: 101-i101
Z: 99-i99 zg: 99-i99
Z: 97-i97 zg: 97-i97
Z: 95-i95 zg: 95-i95
Z: 93-i93 zg: 93-i93
Z: 91-i91 zg: 91-i91
Z: 89-i89 zg: 89-i89
Z: 87-i87 zg: 87-i87
Z: 85-i85 zg: 85-i85
Z: 83-i83 zg: 83-i83
Z: 81-i81 zg: 81-i81
Z: 79-i79 zg: 79-i79
Z: 77-i77 zg: 77-i77
Before deleteing the queue
inside ddeque destructor
Inside ddeque constructor
begin with
-----------------
a.size is 0
g.size is 0
size = 0
begin with
-----------------
a.size is 0
g.size is 0
size = 0
After insertiing 1000 elements
-----------------
a.size is 1000
g.size is 1000
size = 1000
After Shuffle
-----------------
a.size is 1000
g.size is 1000
size = 1000
y is 1076-i1076 yg is 1076-i1076
The back of the ddeque has 1075-i1075
After front and back operation
-----------------
a.size is 1000
g.size is 1000
size = 1000
Random access of a[999]= 1075-i1075
Understanding forward traversal

Understanding reverse traversal

-----------------
multiply by 10
-----------------


print using iterator after multiplying by 10
-----------------


Before deleteing the queue
Z: 1075-i1075 zg: 1075-i1075
Z: 1073-i1073 zg: 1073-i1073
Z: 1071-i1071 zg: 1071-i1071
Z: 1069-i1069 zg: 1069-i1069
Z: 1067-i1067 zg: 1067-i1067
Z: 1065-i1065 zg: 1065-i1065
Z: 1063-i1063 zg: 1063-i1063
Z: 1061-i1061 zg: 1061-i1061
Z: 1059-i1059 zg: 1059-i1059
Z: 1057-i1057 zg: 1057-i1057
Z: 1055-i1055 zg: 1055-i1055
Z: 1053-i1053 zg: 1053-i1053
Z: 1051-i1051 zg: 1051-i1051
Z: 1049-i1049 zg: 1049-i1049
Z: 1047-i1047 zg: 1047-i1047
Z: 1045-i1045 zg: 1045-i1045
Z: 1043-i1043 zg: 1043-i1043
Z: 1041-i1041 zg: 1041-i1041
Z: 1039-i1039 zg: 1039-i1039
Z: 1037-i1037 zg: 1037-i1037
Z: 1035-i1035 zg: 1035-i1035
Z: 1033-i1033 zg: 1033-i1033
Z: 1031-i1031 zg: 1031-i1031
Z: 1029-i1029 zg: 1029-i1029
Z: 1027-i1027 zg: 1027-i1027
Z: 1025-i1025 zg: 1025-i1025
Z: 1023-i1023 zg: 1023-i1023
Z: 1021-i1021 zg: 1021-i1021
Z: 1019-i1019 zg: 1019-i1019
Z: 1017-i1017 zg: 1017-i1017
Z: 1015-i1015 zg: 1015-i1015
Z: 1013-i1013 zg: 1013-i1013
Z: 1011-i1011 zg: 1011-i1011
Z: 1009-i1009 zg: 1009-i1009
Z: 1007-i1007 zg: 1007-i1007
Z: 1005-i1005 zg: 1005-i1005
Z: 1003-i1003 zg: 1003-i1003
Z: 1001-i1001 zg: 1001-i1001
Z: 999-i999 zg: 999-i999
Z: 997-i997 zg: 997-i997
Z: 995-i995 zg: 995-i995
Z: 993-i993 zg: 993-i993
Z: 991-i991 zg: 991-i991
Z: 989-i989 zg: 989-i989
Z: 987-i987 zg: 987-i987
Z: 985-i985 zg: 985-i985
Z: 983-i983 zg: 983-i983
Z: 981-i981 zg: 981-i981
Z: 979-i979 zg: 979-i979
Z: 977-i977 zg: 977-i977
Z: 975-i975 zg: 975-i975
Z: 973-i973 zg: 973-i973
Z: 971-i971 zg: 971-i971
Z: 969-i969 zg: 969-i969
Z: 967-i967 zg: 967-i967
Z: 965-i965 zg: 965-i965
Z: 963-i963 zg: 963-i963
Z: 961-i961 zg: 961-i961
Z: 959-i959 zg: 959-i959
Z: 957-i957 zg: 957-i957
Z: 955-i955 zg: 955-i955
Z: 953-i953 zg: 953-i953
Z: 951-i951 zg: 951-i951
Z: 949-i949 zg: 949-i949
Z: 947-i947 zg: 947-i947
Z: 945-i945 zg: 945-i945
Z: 943-i943 zg: 943-i943
Z: 941-i941 zg: 941-i941
Z: 939-i939 zg: 939-i939
Z: 937-i937 zg: 937-i937
Z: 935-i935 zg: 935-i935
Z: 933-i933 zg: 933-i933
Z: 931-i931 zg: 931-i931
Z: 929-i929 zg: 929-i929
Z: 927-i927 zg: 927-i927
Z: 925-i925 zg: 925-i925
Z: 923-i923 zg: 923-i923
Z: 921-i921 zg: 921-i921
Z: 919-i919 zg: 919-i919
Z: 917-i917 zg: 917-i917
Z: 915-i915 zg: 915-i915
Z: 913-i913 zg: 913-i913
Z: 911-i911 zg: 911-i911
Z: 909-i909 zg: 909-i909
Z: 907-i907 zg: 907-i907
Z: 905-i905 zg: 905-i905
Z: 903-i903 zg: 903-i903
Z: 901-i901 zg: 901-i901
Z: 899-i899 zg: 899-i899
Z: 897-i897 zg: 897-i897
Z: 895-i895 zg: 895-i895
Z: 893-i893 zg: 893-i893
Z: 891-i891 zg: 891-i891
Z: 889-i889 zg: 889-i889
Z: 887-i887 zg: 887-i887
Z: 885-i885 zg: 885-i885
Z: 883-i883 zg: 883-i883
Z: 881-i881 zg: 881-i881
Z: 879-i879 zg: 879-i879
Z: 877-i877 zg: 877-i877
Z: 875-i875 zg: 875-i875
Z: 873-i873 zg: 873-i873
Z: 871-i871 zg: 871-i871
Z: 869-i869 zg: 869-i869
Z: 867-i867 zg: 867-i867
Z: 865-i865 zg: 865-i865
Z: 863-i863 zg: 863-i863
Z: 861-i861 zg: 861-i861
Z: 859-i859 zg: 859-i859
Z: 857-i857 zg: 857-i857
Z: 855-i855 zg: 855-i855
Z: 853-i853 zg: 853-i853
Z: 851-i851 zg: 851-i851
Z: 849-i849 zg: 849-i849
Z: 847-i847 zg: 847-i847
Z: 845-i845 zg: 845-i845
Z: 843-i843 zg: 843-i843
Z: 841-i841 zg: 841-i841
Z: 839-i839 zg: 839-i839
Z: 837-i837 zg: 837-i837
Z: 835-i835 zg: 835-i835
Z: 833-i833 zg: 833-i833
Z: 831-i831 zg: 831-i831
Z: 829-i829 zg: 829-i829
Z: 827-i827 zg: 827-i827
Z: 825-i825 zg: 825-i825
Z: 823-i823 zg: 823-i823
Z: 821-i821 zg: 821-i821
Z: 819-i819 zg: 819-i819
Z: 817-i817 zg: 817-i817
Z: 815-i815 zg: 815-i815
Z: 813-i813 zg: 813-i813
Z: 811-i811 zg: 811-i811
Z: 809-i809 zg: 809-i809
Z: 807-i807 zg: 807-i807
Z: 805-i805 zg: 805-i805
Z: 803-i803 zg: 803-i803
Z: 801-i801 zg: 801-i801
Z: 799-i799 zg: 799-i799
Z: 797-i797 zg: 797-i797
Z: 795-i795 zg: 795-i795
Z: 793-i793 zg: 793-i793
Z: 791-i791 zg: 791-i791
Z: 789-i789 zg: 789-i789
Z: 787-i787 zg: 787-i787
Z: 785-i785 zg: 785-i785
Z: 783-i783 zg: 783-i783
Z: 781-i781 zg: 781-i781
Z: 779-i779 zg: 779-i779
Z: 777-i777 zg: 777-i777
Z: 775-i775 zg: 775-i775
Z: 773-i773 zg: 773-i773
Z: 771-i771 zg: 771-i771
Z: 769-i769 zg: 769-i769
Z: 767-i767 zg: 767-i767
Z: 765-i765 zg: 765-i765
Z: 763-i763 zg: 763-i763
Z: 761-i761 zg: 761-i761
Z: 759-i759 zg: 759-i759
Z: 757-i757 zg: 757-i757
Z: 755-i755 zg: 755-i755
Z: 753-i753 zg: 753-i753
Z: 751-i751 zg: 751-i751
Z: 749-i749 zg: 749-i749
Z: 747-i747 zg: 747-i747
Z: 745-i745 zg: 745-i745
Z: 743-i743 zg: 743-i743
Z: 741-i741 zg: 741-i741
Z: 739-i739 zg: 739-i739
Z: 737-i737 zg: 737-i737
Z: 735-i735 zg: 735-i735
Z: 733-i733 zg: 733-i733
Z: 731-i731 zg: 731-i731
Z: 729-i729 zg: 729-i729
Z: 727-i727 zg: 727-i727
Z: 725-i725 zg: 725-i725
Z: 723-i723 zg: 723-i723
Z: 721-i721 zg: 721-i721
Z: 719-i719 zg: 719-i719
Z: 717-i717 zg: 717-i717
Z: 715-i715 zg: 715-i715
Z: 713-i713 zg: 713-i713
Z: 711-i711 zg: 711-i711
Z: 709-i709 zg: 709-i709
Z: 707-i707 zg: 707-i707
Z: 705-i705 zg: 705-i705
Z: 703-i703 zg: 703-i703
Z: 701-i701 zg: 701-i701
Z: 699-i699 zg: 699-i699
Z: 697-i697 zg: 697-i697
Z: 695-i695 zg: 695-i695
Z: 693-i693 zg: 693-i693
Z: 691-i691 zg: 691-i691
Z: 689-i689 zg: 689-i689
Z: 687-i687 zg: 687-i687
Z: 685-i685 zg: 685-i685
Z: 683-i683 zg: 683-i683
Z: 681-i681 zg: 681-i681
Z: 679-i679 zg: 679-i679
Z: 677-i677 zg: 677-i677
Z: 675-i675 zg: 675-i675
Z: 673-i673 zg: 673-i673
Z: 671-i671 zg: 671-i671
Z: 669-i669 zg: 669-i669
Z: 667-i667 zg: 667-i667
Z: 665-i665 zg: 665-i665
Z: 663-i663 zg: 663-i663
Z: 661-i661 zg: 661-i661
Z: 659-i659 zg: 659-i659
Z: 657-i657 zg: 657-i657
Z: 655-i655 zg: 655-i655
Z: 653-i653 zg: 653-i653
Z: 651-i651 zg: 651-i651
Z: 649-i649 zg: 649-i649
Z: 647-i647 zg: 647-i647
Z: 645-i645 zg: 645-i645
Z: 643-i643 zg: 643-i643
Z: 641-i641 zg: 641-i641
Z: 639-i639 zg: 639-i639
Z: 637-i637 zg: 637-i637
Z: 635-i635 zg: 635-i635
Z: 633-i633 zg: 633-i633
Z: 631-i631 zg: 631-i631
Z: 629-i629 zg: 629-i629
Z: 627-i627 zg: 627-i627
Z: 625-i625 zg: 625-i625
Z: 623-i623 zg: 623-i623
Z: 621-i621 zg: 621-i621
Z: 619-i619 zg: 619-i619
Z: 617-i617 zg: 617-i617
Z: 615-i615 zg: 615-i615
Z: 613-i613 zg: 613-i613
Z: 611-i611 zg: 611-i611
Z: 609-i609 zg: 609-i609
Z: 607-i607 zg: 607-i607
Z: 605-i605 zg: 605-i605
Z: 603-i603 zg: 603-i603
Z: 601-i601 zg: 601-i601
Z: 599-i599 zg: 599-i599
Z: 597-i597 zg: 597-i597
Z: 595-i595 zg: 595-i595
Z: 593-i593 zg: 593-i593
Z: 591-i591 zg: 591-i591
Z: 589-i589 zg: 589-i589
Z: 587-i587 zg: 587-i587
Z: 585-i585 zg: 585-i585
Z: 583-i583 zg: 583-i583
Z: 581-i581 zg: 581-i581
Z: 579-i579 zg: 579-i579
Z: 577-i577 zg: 577-i577
Z: 575-i575 zg: 575-i575
Z: 573-i573 zg: 573-i573
Z: 571-i571 zg: 571-i571
Z: 569-i569 zg: 569-i569
Z: 567-i567 zg: 567-i567
Z: 565-i565 zg: 565-i565
Z: 563-i563 zg: 563-i563
Z: 561-i561 zg: 561-i561
Z: 559-i559 zg: 559-i559
Z: 557-i557 zg: 557-i557
Z: 555-i555 zg: 555-i555
Z: 553-i553 zg: 553-i553
Z: 551-i551 zg: 551-i551
Z: 549-i549 zg: 549-i549
Z: 547-i547 zg: 547-i547
Z: 545-i545 zg: 545-i545
Z: 543-i543 zg: 543-i543
Z: 541-i541 zg: 541-i541
Z: 539-i539 zg: 539-i539
Z: 537-i537 zg: 537-i537
Z: 535-i535 zg: 535-i535
Z: 533-i533 zg: 533-i533
Z: 531-i531 zg: 531-i531
Z: 529-i529 zg: 529-i529
Z: 527-i527 zg: 527-i527
Z: 525-i525 zg: 525-i525
Z: 523-i523 zg: 523-i523
Z: 521-i521 zg: 521-i521
Z: 519-i519 zg: 519-i519
Z: 517-i517 zg: 517-i517
Z: 515-i515 zg: 515-i515
Z: 513-i513 zg: 513-i513
Z: 511-i511 zg: 511-i511
Z: 509-i509 zg: 509-i509
Z: 507-i507 zg: 507-i507
Z: 505-i505 zg: 505-i505
Z: 503-i503 zg: 503-i503
Z: 501-i501 zg: 501-i501
Z: 499-i499 zg: 499-i499
Z: 497-i497 zg: 497-i497
Z: 495-i495 zg: 495-i495
Z: 493-i493 zg: 493-i493
Z: 491-i491 zg: 491-i491
Z: 489-i489 zg: 489-i489
Z: 487-i487 zg: 487-i487
Z: 485-i485 zg: 485-i485
Z: 483-i483 zg: 483-i483
Z: 481-i481 zg: 481-i481
Z: 479-i479 zg: 479-i479
Z: 477-i477 zg: 477-i477
Z: 475-i475 zg: 475-i475
Z: 473-i473 zg: 473-i473
Z: 471-i471 zg: 471-i471
Z: 469-i469 zg: 469-i469
Z: 467-i467 zg: 467-i467
Z: 465-i465 zg: 465-i465
Z: 463-i463 zg: 463-i463
Z: 461-i461 zg: 461-i461
Z: 459-i459 zg: 459-i459
Z: 457-i457 zg: 457-i457
Z: 455-i455 zg: 455-i455
Z: 453-i453 zg: 453-i453
Z: 451-i451 zg: 451-i451
Z: 449-i449 zg: 449-i449
Z: 447-i447 zg: 447-i447
Z: 445-i445 zg: 445-i445
Z: 443-i443 zg: 443-i443
Z: 441-i441 zg: 441-i441
Z: 439-i439 zg: 439-i439
Z: 437-i437 zg: 437-i437
Z: 435-i435 zg: 435-i435
Z: 433-i433 zg: 433-i433
Z: 431-i431 zg: 431-i431
Z: 429-i429 zg: 429-i429
Z: 427-i427 zg: 427-i427
Z: 425-i425 zg: 425-i425
Z: 423-i423 zg: 423-i423
Z: 421-i421 zg: 421-i421
Z: 419-i419 zg: 419-i419
Z: 417-i417 zg: 417-i417
Z: 415-i415 zg: 415-i415
Z: 413-i413 zg: 413-i413
Z: 411-i411 zg: 411-i411
Z: 409-i409 zg: 409-i409
Z: 407-i407 zg: 407-i407
Z: 405-i405 zg: 405-i405
Z: 403-i403 zg: 403-i403
Z: 401-i401 zg: 401-i401
Z: 399-i399 zg: 399-i399
Z: 397-i397 zg: 397-i397
Z: 395-i395 zg: 395-i395
Z: 393-i393 zg: 393-i393
Z: 391-i391 zg: 391-i391
Z: 389-i389 zg: 389-i389
Z: 387-i387 zg: 387-i387
Z: 385-i385 zg: 385-i385
Z: 383-i383 zg: 383-i383
Z: 381-i381 zg: 381-i381
Z: 379-i379 zg: 379-i379
Z: 377-i377 zg: 377-i377
Z: 375-i375 zg: 375-i375
Z: 373-i373 zg: 373-i373
Z: 371-i371 zg: 371-i371
Z: 369-i369 zg: 369-i369
Z: 367-i367 zg: 367-i367
Z: 365-i365 zg: 365-i365
Z: 363-i363 zg: 363-i363
Z: 361-i361 zg: 361-i361
Z: 359-i359 zg: 359-i359
Z: 357-i357 zg: 357-i357
Z: 355-i355 zg: 355-i355
Z: 353-i353 zg: 353-i353
Z: 351-i351 zg: 351-i351
Z: 349-i349 zg: 349-i349
Z: 347-i347 zg: 347-i347
Z: 345-i345 zg: 345-i345
Z: 343-i343 zg: 343-i343
Z: 341-i341 zg: 341-i341
Z: 339-i339 zg: 339-i339
Z: 337-i337 zg: 337-i337
Z: 335-i335 zg: 335-i335
Z: 333-i333 zg: 333-i333
Z: 331-i331 zg: 331-i331
Z: 329-i329 zg: 329-i329
Z: 327-i327 zg: 327-i327
Z: 325-i325 zg: 325-i325
Z: 323-i323 zg: 323-i323
Z: 321-i321 zg: 321-i321
Z: 319-i319 zg: 319-i319
Z: 317-i317 zg: 317-i317
Z: 315-i315 zg: 315-i315
Z: 313-i313 zg: 313-i313
Z: 311-i311 zg: 311-i311
Z: 309-i309 zg: 309-i309
Z: 307-i307 zg: 307-i307
Z: 305-i305 zg: 305-i305
Z: 303-i303 zg: 303-i303
Z: 301-i301 zg: 301-i301
Z: 299-i299 zg: 299-i299
Z: 297-i297 zg: 297-i297
Z: 295-i295 zg: 295-i295
Z: 293-i293 zg: 293-i293
Z: 291-i291 zg: 291-i291
Z: 289-i289 zg: 289-i289
Z: 287-i287 zg: 287-i287
Z: 285-i285 zg: 285-i285
Z: 283-i283 zg: 283-i283
Z: 281-i281 zg: 281-i281
Z: 279-i279 zg: 279-i279
Z: 277-i277 zg: 277-i277
Z: 275-i275 zg: 275-i275
Z: 273-i273 zg: 273-i273
Z: 271-i271 zg: 271-i271
Z: 269-i269 zg: 269-i269
Z: 267-i267 zg: 267-i267
Z: 265-i265 zg: 265-i265
Z: 263-i263 zg: 263-i263
Z: 261-i261 zg: 261-i261
Z: 259-i259 zg: 259-i259
Z: 257-i257 zg: 257-i257
Z: 255-i255 zg: 255-i255
Z: 253-i253 zg: 253-i253
Z: 251-i251 zg: 251-i251
Z: 249-i249 zg: 249-i249
Z: 247-i247 zg: 247-i247
Z: 245-i245 zg: 245-i245
Z: 243-i243 zg: 243-i243
Z: 241-i241 zg: 241-i241
Z: 239-i239 zg: 239-i239
Z: 237-i237 zg: 237-i237
Z: 235-i235 zg: 235-i235
Z: 233-i233 zg: 233-i233
Z: 231-i231 zg: 231-i231
Z: 229-i229 zg: 229-i229
Z: 227-i227 zg: 227-i227
Z: 225-i225 zg: 225-i225
Z: 223-i223 zg: 223-i223
Z: 221-i221 zg: 221-i221
Z: 219-i219 zg: 219-i219
Z: 217-i217 zg: 217-i217
Z: 215-i215 zg: 215-i215
Z: 213-i213 zg: 213-i213
Z: 211-i211 zg: 211-i211
Z: 209-i209 zg: 209-i209
Z: 207-i207 zg: 207-i207
Z: 205-i205 zg: 205-i205
Z: 203-i203 zg: 203-i203
Z: 201-i201 zg: 201-i201
Z: 199-i199 zg: 199-i199
Z: 197-i197 zg: 197-i197
Z: 195-i195 zg: 195-i195
Z: 193-i193 zg: 193-i193
Z: 191-i191 zg: 191-i191
Z: 189-i189 zg: 189-i189
Z: 187-i187 zg: 187-i187
Z: 185-i185 zg: 185-i185
Z: 183-i183 zg: 183-i183
Z: 181-i181 zg: 181-i181
Z: 179-i179 zg: 179-i179
Z: 177-i177 zg: 177-i177
Z: 175-i175 zg: 175-i175
Z: 173-i173 zg: 173-i173
Z: 171-i171 zg: 171-i171
Z: 169-i169 zg: 169-i169
Z: 167-i167 zg: 167-i167
Z: 165-i165 zg: 165-i165
Z: 163-i163 zg: 163-i163
Z: 161-i161 zg: 161-i161
Z: 159-i159 zg: 159-i159
Z: 157-i157 zg: 157-i157
Z: 155-i155 zg: 155-i155
Z: 153-i153 zg: 153-i153
Z: 151-i151 zg: 151-i151
Z: 149-i149 zg: 149-i149
Z: 147-i147 zg: 147-i147
Z: 145-i145 zg: 145-i145
Z: 143-i143 zg: 143-i143
Z: 141-i141 zg: 141-i141
Z: 139-i139 zg: 139-i139
Z: 137-i137 zg: 137-i137
Z: 135-i135 zg: 135-i135
Z: 133-i133 zg: 133-i133
Z: 131-i131 zg: 131-i131
Z: 129-i129 zg: 129-i129
Z: 127-i127 zg: 127-i127
Z: 125-i125 zg: 125-i125
Z: 123-i123 zg: 123-i123
Z: 121-i121 zg: 121-i121
Z: 119-i119 zg: 119-i119
Z: 117-i117 zg: 117-i117
Z: 115-i115 zg: 115-i115
Z: 113-i113 zg: 113-i113
Z: 111-i111 zg: 111-i111
Z: 109-i109 zg: 109-i109
Z: 107-i107 zg: 107-i107
Z: 105-i105 zg: 105-i105
Z: 103-i103 zg: 103-i103
Z: 101-i101 zg: 101-i101
Z: 99-i99 zg: 99-i99
Z: 97-i97 zg: 97-i97
Z: 95-i95 zg: 95-i95
Z: 93-i93 zg: 93-i93
Z: 91-i91 zg: 91-i91
Z: 89-i89 zg: 89-i89
Z: 87-i87 zg: 87-i87
Z: 85-i85 zg: 85-i85
Z: 83-i83 zg: 83-i83
Z: 81-i81 zg: 81-i81
Z: 79-i79 zg: 79-i79
Z: 77-i77 zg: 77-i77
Before deleteing the queue
inside ddeque destructor
Program ended with exit code: 1

#endif