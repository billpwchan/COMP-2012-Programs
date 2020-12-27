#include <iostream>
using namespace std;

class B{
protected:
	int a;
};

class C: public B {};
class D: private C {public: D():a(5){}};
int main(){D obj; return 0;}