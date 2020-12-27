/*
 COMP2012 2017S Lab08
 Header file of the sum class: sum.h
*/

#ifndef SUM_H
#define SUM_H

#include <iostream>
using namespace std;

template <typename T>
class Sum
{
  private:
    T sum;

  public:
    Sum(const T& v) : sum(v) {}
    
    //TO-DO:Implement the member functions below
	
    void operator()(const T& i);

	
    T getSum() const;
	
    template <typename S>
    friend ostream& operator<<(ostream& os, const Sum<S>& s);
    //     os << s.sum;
    //     return os;
    // }
};

//TODO: write your code here
template <typename T>
void Sum<T>::operator()(const T& i){
  this->sum=this->sum+i;
}

template <typename T>
T Sum<T>::getSum() const {
  return this->sum;
}

template <typename S>
ostream& operator<<(ostream& os, const Sum<S>& s){
  os << s.sum;
  return os;
}


#endif /* SUM_H */
