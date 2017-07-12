/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: ddeque.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Definition of routines of ddeque class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
WRITE CODE IN THIS FILE
-----------------------------------------------------------------*/
#include "ddeque.h"

template <typename T>
ddeque<T>::ddeque():_frontq(),_rearq(), _front(0), _rear(0)
{
    if (_display)
    {
        cout << "Inside ddeque constructor" << endl ;
    }
}


template <typename T>
ddeque<T>::ddeque(T c, bool d):_frontq(c, d),_rearq(c, d), _front(0), _rear(0)
{
    if (d)
    {
        cout << "Inside ddeque constructor" << endl ;
    }
}

template <typename T>
ddeque<T>::ddeque(bool d):_frontq(d),_rearq(d), _front(0),  _rear(0)
{
    if (d)
    {
        cout << "Inside ddeque constructor 2" << endl ;
    }
    
}



template <typename T>
ddeque<T>::~ddeque()
{
    if (display())
    {
        cout << "inside ddeque destructor" << endl ;
        
    }
    
    _front = 0 ;
    _rear = 0 ;
    
}


template <typename T>
void ddeque<T>::_set(int pos, const T& a)
{
   
    
    if (pos < _frontq.size()+1)
         _frontq[_frontq.size() - pos  ] = a ;
    else
         _rearq[pos - _frontq.size()] = a ;
}


template <typename T>
T& ddeque<T>::_get(int pos)
{
    if (pos < _frontq.size())
        return _frontq[_frontq.size() - pos - 1];
    else
        return _rearq[pos - _frontq.size()];
    
}

/// copy constructor and equal operator

//template <typename T>
//ddeque<T>::ddeque(const ddeque<T>& s)
//{
//    
//    
//}
//
//
//template <typename T>
//ddeque<T>& ddeque<T>::operator=(const ddeque<T>& rhs)
//{
//    
//    
//}

template <typename T>
int ddeque<T>::size()
{
//        return _frontq.size() + _rearq.size() ;
//    return (_front_r - _front_f)  + (_rear_r - _rear_f) ;
    return (_front)  + (_rear) ;

}


template <typename T>
bool ddeque<T>::empty()
{
//    if ((_frontq.size()  == 0 ) && (_rearq.size() == 0))
    
    if ((_front  == 0 ) && (_rear == 0))
        return true ;
    
    return false ;
}

/// ddqueue operations

// -- Returns first element of the ddeque
template <typename T>
T& ddeque<T>::front()
{
    if (empty())
        assert(0);
    
    return _frontq[_front-1];
    
}

// -- Returns last  element of the ddeque
template <typename T>
T& ddeque<T>::back()
{
    if (empty())
        assert(0);
    
    return _rearq[_rear - 1];
}


//  -- v is inserted as the first element of the ddeque
template <typename T>
void ddeque<T>::push_front(const T v)
{
    _frontq[_front++] = v;
}

// -- v is inserted as the back element of the ddeque
template <typename T>
void ddeque<T>::push_back ( const T v)
{
    _rearq[_rear++] = v ;
}

// - First element of the ddeque is removed. Nothing is returned
template <typename T>
void ddeque<T>::pop_front()
{
    
    if (_front > 0)
        _front-= 1;
    else if (_front ==0)
        _rear_f++ ;
    
}


// - Last element of the ddeque is removed. Nothing is returned
template <typename T>
void ddeque<T>::pop_back()
{
    
    if (_rear > 0)
        _rear -= 1;
    else if (_rear == 0)
        _front_r++ ;
}


/// subscript operators
template <typename T>
const T ddeque<T>::operator[]( int i ) const
{

    if ( i < _front)
        return _frontq[_front -1 - i];
    else if ( i >= _front   && i < _front + _rear)
        return _rearq[i - _front ];
}


template <typename T>
T& ddeque<T>::operator[](int i)
{
    if ( i < _front)
        return _frontq[_front -1 - i];
    else if ( i >= _front   && i < _front + _rear)
        return _rearq[i - _front ];
    
    return _frontq[0] ;
    
}






///// ddqueue operations
//
//// -- Returns first element of the ddeque
//template <typename T>
//T& ddeque<T>::front()
//{
//    if (empty())
//        assert(0);
//    
//    return _get(--_front);
//    
//}
//
//// -- Returns last  element of the ddeque
//template <typename T>
//T& ddeque<T>::back()
//{
//    if (empty())
//        assert(0);
//    
//    return _get(_rear--) ;
//}
//
//
////  -- v is inserted as the first element of the ddeque
//template <typename T>
//void ddeque<T>::push_front(const T v)
//{
//    _frontq[_front++] = v;
//    
////    _set(_front++, v);
//    
//}
//
//// -- v is inserted as the back element of the ddeque
//template <typename T>
//void ddeque<T>::push_back ( const T v)
//{
//    _rearq[_rear++] = v ;
////    _set(_rear++, v);
//
//}
//
//// - First element of the ddeque is removed. Nothing is returned
//template <typename T>
//void ddeque<T>::pop_front()
//{
//  
//     _front--;
//    
//}
//
//
//// - Last element of the ddeque is removed. Nothing is returned
//template <typename T>
//void ddeque<T>::pop_back()
//{
//    _rear-- ;
//}
//
//
///// subscript operators
//template <typename T>
//const T ddeque<T>::operator[]( int i ) const
//{
//    return _get(i);
//}
//
//
//template <typename T>
//T& ddeque<T>::operator[](int i)
//{
//    return _get(i);
//}
