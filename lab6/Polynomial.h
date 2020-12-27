#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Fraction.h"
using namespace std;

class Polynomial {
  public:
    // Constructors and destructor
    Polynomial();
    Polynomial(const Polynomial& p);
    ~Polynomial();

    //Accessor
    int getDeg() const{return this->deg;}
    Fraction* getCoef() const{return this->coef;}

    // Mutator
    void addCoef(const Fraction& f, const int deg);

    // Arithmetic operators (+, -, *) Optional: (/, %)
    /* TODO */

    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;

//    // Assignment operators (=, +=, -=)
//    /* TODO */
    const Polynomial& operator=(const Polynomial& p);
    const Polynomial& operator+=(const Polynomial& p);
    const Polynomial& operator-=(const Polynomial& p);

    // Other functions (<<)
    friend ostream& operator<<(ostream& os, const Polynomial& p);
    /* TODO */

  private:
    // Reduce function
    Polynomial& reduce();

    // Member variables
    Fraction* coef;
    int deg;
};

#endif
