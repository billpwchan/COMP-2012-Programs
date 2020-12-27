#include <iostream>     /* File: dll-test-int.cpp */
using namespace std;

#include "dll.h"
#include "dll-destructor.h"
#include "dll-insert.h"
#include "dll-remove.h"
#include "dll-utilities.h"

int main()
{
    Dll<int> x;
    x.insert(3); x.insert(2); x.insert(5); x.print();
    x.insert(7); x.insert(1); x.print();
    x.remove(0); x.remove(1); x.print();;
    x.insert(8); x.insert(4); x.print();
    x.remove(3); x.remove(8); x.print();
    cout << "5 is " << ((x.contains(5)) ? "" : "not")
         << "in the list\n";
    return 0;
}
