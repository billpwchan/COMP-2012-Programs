#include <iostream>
using namespace std;

class A {
  private:
    int a;
  public:
    A(int a) { this->a = a; }
    virtual void print() { cout << "The value of a is " << a << endl; }
};

class B : public A {
  private:
    int b;
  public:
    B(int a, int b) : A(a) { this->b = b; }
    void print() { A::print(); cout << "The value of b is " << b << endl; }
};

int main() {
  A objA(1);
  B objB(2,3);
  A* aPtr1 = &objB;
  B* bPtr1 = dynamic_cast<B*>(aPtr1);
  if(bPtr1 != NULL)
    cout << "Conversion: dynamic_cast<B*>(aPtr1) is done successfully" << endl;
  else
    cout << "Conversion: dynamic_cast<B*>(aPtr1) is failed" << endl;

  A* aPtr2 = &objA;
  B* bPtr2 = dynamic_cast<B*>(aPtr2);
  if(bPtr2 != NULL)
    cout << "Conversion: dynamic_cast<B*>(aPtr2) is done successfully" << endl;
  else
    cout << "Conversion: dynamic_cast<B*>(aPtr2) is failed" << endl;
  return 0;
}
