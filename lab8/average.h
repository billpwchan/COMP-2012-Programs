/*
  COMP2012 2017S Lab08
  Header file of the average class: average.h
 */

#ifndef AVERAGE_H
#define AVERAGE_H

#include "sum.h"

template <typename T>
class Average : public Sum<T>
{
  private:
    int size;

  public:
    Average(const T& v, int s) : Sum<T>(v), size(s) {}

    void operator()(const T& i) ;
    int getSize() const;
    template <typename S>
    friend ostream& operator<<(ostream& os, const Average<S>& a);
   //  		os << a.getSum()/a.getSize();
			// return os;
   //  }
};

//TODO write your code here
template <typename T>
void Average<T>::operator()(const T& i){
	Sum<T>::operator()(i);
	this->size++;
}

template <typename T>
int Average<T>::getSize() const{
	return this->size;
}

template <typename T>
ostream& operator<<(ostream& os, const Average<T>& a){
	os << a.getSum()/a.getSize();
	return os;
}

#endif /* AVERAGE_H */
