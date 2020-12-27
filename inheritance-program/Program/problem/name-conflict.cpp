#include <iostream> /* File: name-conflict.cpp */
using namespace std;

void print(int x, int y) { cout << x << " , " << y << '\n'; }

class B
{
  private:
    int x, y;
  public:
    B(int p = 1, int q = 2) : x(p), y(q)
        { cout << "Base class constructor: "; print(x, y); }
    void f() const { cout << "Base class: "; print(x, y); } 
};

class D : public B 
{ 
  private: 
    float x, y;
  public:
    D() : x(10.0), y(20.0) { cout << "Derived class constructor\n"; }
    void f() const { cout << "Derived class: "; print(x, y); B::f(); }
};

void smart(const B* z) { cout << "Inside smart(): "; z->f(); } 

int main()
{
    B base(5, 6); cout << endl; 
    D derive; cout << endl;

    B* b = &base; b->f(); cout << endl;
    D* d = &derive; d->f(); cout << endl;

    b = &derive; b->f(); cout << endl;

    smart(b); cout << endl; 
    smart(d); cout << endl;
    return 0;
}
