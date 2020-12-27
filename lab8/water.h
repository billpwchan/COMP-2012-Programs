/*
  COMP2012 2017S Lab08
  Header file of the water class: water.h
*/


#ifndef WATER_H
#define WATER_H

#include <iostream>
using namespace std;

class Water
{
  private:
    float weight;

  public:
    Water() : weight(0) {};
    Water(float w) : weight(w) {};

    Water operator+(const Water& a) ;
    Water operator/(const int& i) ;
    friend ostream& operator<<(ostream& os, const Water& w) ;

};

//TODO: write your code here
Water Water::operator+(const Water& a){
  return Water(this->weight+a.weight);
}

Water Water::operator/(const int& i){
  return Water(this->weight/i);
}

ostream& operator<<(ostream& os, const Water& w){
  os << w.weight << " ";
  return os;
}

#endif /* WATER_H */
