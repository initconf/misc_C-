/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "../util/util.h"
#include "../darray/darray.h"

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
----------------------------------------------------------*/
template <typename T>
class ddeque_iterator {
public:
    
    ddeque_iterator();
    ddeque_iterator(ddeque<T>* x, int c):_ptr_object(x),_current(c)
    {
//        cout << "x is " << x << " _frontq : " <<   &x->_frontq  << " and c is : " << c << " end is " << &x->_frontq + sizeof(T)*c <<   endl ;
//         cout << "x is " << x << " _rearq : " <<   &x->_rearq  << " and c is : " << c << " end is " << &x->_rearq + sizeof(T)*c<< endl ;
//        cout << "Inside ddeque_iterator constructor" << endl ;
        
    }
    ddeque_iterator(const ddeque_iterator<T>& x) { _ptr_object = x._ptr_object, _current = x._current; }
    ddeque_iterator& operator=(const ddeque_iterator<T>& x) { _ptr_object = x._ptr_object; _current = x._current; return *this; }
    
//    ddeque_iterator(const ddeque_iterator& di):_ptr_object(di._ptr_object) {}
//    ddeque_iterator& operator=(const ddeque_iterator& s) { _ptr_object = s._ptr_object ; _current = s._current ; }
    
    
    ddeque_iterator& operator++() { ++_ptr_object ; return *this; }
    ddeque_iterator& operator--() { --_ptr_object ; return *this; }
    
//    ddeque_iterator operator++(int) { ddeque_iterator tmp(*this) ; operator++(); return tmp;}
    ddeque_iterator operator++(int)=delete ;
    ddeque_iterator operator--(int)=delete ;
    
    
    bool operator==(const ddeque_iterator&rhs) { return _ptr_object == rhs._ptr_object; }
    bool operator!=(const ddeque_iterator&rhs) { return _ptr_object != rhs._ptr_object; }
//   const ddeque<T>& operator*() const {return (_ptr_object->_get(_current)); }
    
    T& operator*(){ return _ptr_object->_get(_current); }

   
    ~ddeque_iterator() {};
    
private:
  ddeque<T>* _ptr_object;
  int _current;
};




///////###################################################
///////###################################################
///////###################################################
/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
///////###################################################
///////###################################################
///////###################################################

template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */
 
    typedef ddeque_iterator<T> iterator;
    friend class ddeque_iterator < T > ; //ddeque_iterator can access ddeque private part

    iterator begin() { return iterator(this, _front);  }
    iterator end() { return iterator(this, _rear+1); }
    

    ddeque();
    ddeque(T, bool d=true);
    ddeque( bool);
    
    ~ddeque();
    

    ddeque(const ddeque<T>& s)=delete ;
    ddeque<T>& operator=(const ddeque<T>& rhs)=delete;
    
    
    
    T& front() ;                    // -- Returns first element of the ddeque
    T& back()  ;                    // -- Returns last  element of the ddeque
    void push_front(const T v) ;    //  -- v is inserted as the first element of the ddeque
    void push_back ( const T v);    // -- v is inserted as the back element of the ddeque
    void pop_front()  ;             // - First element of the ddeque is removed. Nothing is returned
    void pop_back() ;               // - Last element of the ddeque is removed. Nothing is returned
    
    
    const T operator[]( int i ) const ;
    T& operator[](int i);
    
    bool display() const
    {
        return _display ;
    }
    
    void set_display(bool x)
    {
        darray<T>::set_display(x);
        _display = x ;
    }
    
    int size();
    bool empty();
        
    
private:
  /* MUST USE only darray<T>. You can use multiples of darray<T> */
  /* Can have some private variables */
  /* CAN HAVE ANY PRIVATE FUNCION */
    
    darray<T> _frontq;
    darray<T> _rearq ;
    
    bool _display = true ;
    
    int _front ;
    int _rear ;
    
    int _rear_f;
    int _front_r;
    
    
    
    void _set(int pos, const T& a);
    T& _get(int pos);

};

#include "ddeque.hpp"

#endif
//EOF

