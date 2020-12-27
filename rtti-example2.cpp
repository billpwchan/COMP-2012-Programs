#include <iostream>
using namespace std;

class A {
  private:
    int a;
  public:
    A(int a = 0) { this->a = a; }
    virtual void print() { cout << "Value of a = " << a << endl; }
};

class B : public A {
  private:
    int b;
  public:
    B(int a, int b) : A(a) { this->b = b; }
    void print() { A::print(); cout << "Value of b = " << b << endl;  }
};

int main() {
  A* aPtr = new B(1,2);
  aPtr->print();
  cout << "The type of object pointed by aPtr is " << typeid(*aPtr).name() << endl;
  return 0;
}
