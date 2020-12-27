#include <iostream>     /* File: max-match-arg.cpp */
using namespace std;
template <typename T>
T my_max(const T& a, const T& b) { return (a > b) ? a : b; }

int main() 
{
    cout << my_max(3, 5) << endl;     // T is int;
    cout << my_max(4.3, 5.6) << endl; // T is double
}
