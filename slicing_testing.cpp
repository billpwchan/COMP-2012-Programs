#include <iostream>
using namespace std;

class Base {
private: 
	int a;
	int b;
public:
	Base():a(1),b(2){};
	Base(int a, int b):a(a),b(b){
		cout << "Base constructor"<<endl;
	}

};

class Derived:public Base{
private:
	int c;
	int d;
public:
	Derived():Base(),c(3),d(4){}
	Derived(int c, int d):Base(1,2), c(c),d(d){
		cout << "Derived constructor"<<endl;
	}
	virtual int get_c(){return c;}
};


int main(){
	Derived derived(3,4);
	Base* base = &derived;
	cout << base->get_c()<<endl;
	return 0;
}
