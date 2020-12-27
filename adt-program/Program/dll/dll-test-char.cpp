#include <iostream> /* File: dll-test-char.cpp */
using namespace std;
#include "dll.h"
#include "dll-destructor.h"
#include "dll-utilities.h"
#include "dll-insert.h"
#include "dll-remove.h"
int main() 
{
    Dll<char> s;
    s.insert('t'); s.insert('e'); s.insert('b'); s.print();
    cout << "length of s = " << s.size() << endl;
    cout << "delete 'e' : "; s.remove('e'); s.print();
    cout << "insert 'i' : "; s.insert('i'); s.print();
    cout << "delete 'b' : "; s.remove('b'); s.print();
    cout << "insert 'f' : "; s.insert('f'); s.print();
    cout << "delete 't' : "; s.remove('t'); s.print();
    cout << "delete 'z' : "; s.remove('z'); s.print();
    cout << "insert 'n' : "; s.insert('n'); s.print();
    cout << "insert 's' : "; s.insert('s'); s.print(); return 0;
}
