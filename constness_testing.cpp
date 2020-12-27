#include <iostream>
using namespace std;

class PrintProxy {
protected:
	int noPrint;
public:
	PrintProxy() { noPrint=0;}
	void print() const {cout << noPrint << endl;}
	const int getConstNoPrint() const {return noPrint;}
	const int& getConstRefNoPrint() const {return noPrint;}
};

int main() {
	PrintProxy pp;

	int something = pp.getConstRefNoPrint();
	cout << "something" << something << endl;
	something = 10;
	cout << something << endl;
	pp.print();
	return 0;
}

