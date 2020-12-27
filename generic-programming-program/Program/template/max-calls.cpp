#include <iostream>     /* File: max-calls.cpp */
using namespace std;
template <typename T>
T my_max(const T& a, const T& b) { return (a > b) ? a : b; }

int main()
{
    int x = 4, y = 8;
    cout << my_max(x, y) << " is a bigger number!" << endl;

    string a("cheetah"), b("gorilla");
    cout << my_max(a, b) << " is stronger!" << endl;
    return 0;
}
