#include <iostream>
using namespace std;

template <typename T>
class Base{
	protected:
		T base_var;
	public:
		Base():base_var(0){}
		
};

template <typename T>
class Derived : public Base<T>{
	private:
		T derived_var;
	public:
		Derived():derived_var(0){}
		void set(int num){this->base_var = num;}
};

int main(){
	Derived<int> obj;
	obj.set(3);
	return 0;
}
