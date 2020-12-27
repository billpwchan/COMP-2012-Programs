#include <iostream>

using namespace std;

class test{
	private:
		int some_var;
	public:
		test(){some_var = 0;}
		test(int input = 100){some_var = input;}
		print(){cout << some_var << endl;}
};

int main(){
	test something;
	someting.print();
}
